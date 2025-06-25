#!/usr/bin/env python3

from dingo_control.Gaits import GaitController
from dingo_control.StanceController import StanceController
from dingo_control.SwingLegController import SwingController
from dingo_utilities import clipped_first_order_filter
from dingo_control.State import BehaviorState, State
from dingo_msgs.msg import TaskSpace, JointSpace, Angle

import numpy as np
from transforms3d.euler import euler2mat, quat2euler
from transforms3d.quaternions import qconjugate, quat2axangle
from transforms3d.axangles import axangle2mat

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from std_msgs.msg import Header
from math import degrees

class Controller(Node):
    """Controller and planner object using rclpy."""

    def __init__(self, config, inverse_kinematics):
        super().__init__('controller')

        self.config = config
        self.inverse_kinematics = inverse_kinematics

        ################# ROS PUBLISHER FOR TASK SPACE & JOINT SPACE ##############
        self.task_space_pub = self.create_publisher(TaskSpace, 'task_space_goals', 10)
        self.joint_space_pub = self.create_publisher(JointSpace, 'joint_space_goals', 10)

        self.smoothed_yaw = 0.0
        self.contact_modes = np.zeros(4)
        self.gait_controller = GaitController(self.config)
        self.swing_controller = SwingController(self.config)
        self.stance_controller = StanceController(self.config)

        self.hop_transition_mapping = {
            BehaviorState.REST: BehaviorState.HOP,
            BehaviorState.HOP: BehaviorState.FINISHHOP,
            BehaviorState.FINISHHOP: BehaviorState.REST,
            BehaviorState.TROT: BehaviorState.HOP
        }
        self.trot_transition_mapping = {
            BehaviorState.REST: BehaviorState.TROT,
            BehaviorState.TROT: BehaviorState.REST,
            BehaviorState.HOP: BehaviorState.TROT,
            BehaviorState.FINISHHOP: BehaviorState.TROT
        }
        self.activate_transition_mapping = {
            BehaviorState.DEACTIVATED: BehaviorState.REST,
            BehaviorState.REST: BehaviorState.DEACTIVATED
        }

    def step_gait(self, state, command):
        """Calculate desired foot locations for the next timestep."""
        contact_modes = self.gait_controller.contacts(state.ticks)
        new_foot_locations = np.zeros((3, 4))
        for leg_index in range(4):
            contact_mode = contact_modes[leg_index]
            foot_location = state.foot_locations[:, leg_index]
            if contact_mode == 1:
                new_location = self.stance_controller.next_foot_location(leg_index, state, command)
            else:
                swing_proportion = (
                    self.gait_controller.subphase_ticks(state.ticks) / self.config.swing_ticks
                )
                new_location = self.swing_controller.next_foot_location(
                    swing_proportion,
                    leg_index,
                    state,
                    command
                )
            new_foot_locations[:, leg_index] = new_location
        return new_foot_locations, contact_modes

    def publish_task_space_command(self, rotated_foot_locations):
        msg = TaskSpace()
        
        msg.fr_foot = Point()
        msg.fr_foot.x = rotated_foot_locations[0, 0] - self.config.LEG_ORIGINS[0, 0]
        msg.fr_foot.y = rotated_foot_locations[1, 0] - self.config.LEG_ORIGINS[1, 0]
        msg.fr_foot.z = rotated_foot_locations[2, 0] - self.config.LEG_ORIGINS[2, 0]

        msg.fl_foot = Point()
        msg.fl_foot.x = rotated_foot_locations[0, 1] - self.config.LEG_ORIGINS[0, 1]
        msg.fl_foot.y = rotated_foot_locations[1, 1] - self.config.LEG_ORIGINS[1, 1]
        msg.fl_foot.z = rotated_foot_locations[2, 1] - self.config.LEG_ORIGINS[2, 1]

        msg.rr_foot = Point()
        msg.rr_foot.x = rotated_foot_locations[0, 2] - self.config.LEG_ORIGINS[0, 2]
        msg.rr_foot.y = rotated_foot_locations[1, 2] - self.config.LEG_ORIGINS[1, 2]
        msg.rr_foot.z = rotated_foot_locations[2, 2] - self.config.LEG_ORIGINS[2, 2]

        msg.rl_foot = Point()
        msg.rl_foot.x = rotated_foot_locations[0, 3] - self.config.LEG_ORIGINS[0, 3]
        msg.rl_foot.y = rotated_foot_locations[1, 3] - self.config.LEG_ORIGINS[1, 3]
        msg.rl_foot.z = rotated_foot_locations[2, 3] - self.config.LEG_ORIGINS[2, 3]

        # msg.fr_foot = Point(
        #     rotated_foot_locations[0, 0] - self.config.LEG_ORIGINS[0, 0],
        #     rotated_foot_locations[1, 0] - self.config.LEG_ORIGINS[1, 0],
        #     rotated_foot_locations[2, 0] - self.config.LEG_ORIGINS[2, 0]
        # )
        # msg.fl_foot = Point(
        #     rotated_foot_locations[0, 1] - self.config.LEG_ORIGINS[0, 1],
        #     rotated_foot_locations[1, 1] - self.config.LEG_ORIGINS[1, 1],
        #     rotated_foot_locations[2, 1] - self.config.LEG_ORIGINS[2, 1]
        # )
        # msg.rr_foot = Point(
        #     rotated_foot_locations[0, 2] - self.config.LEG_ORIGINS[0, 2],
        #     rotated_foot_locations[1, 2] - self.config.LEG_ORIGINS[1, 2],
        #     rotated_foot_locations[2, 2] - self.config.LEG_ORIGINS[2, 2]
        # )
        # msg.rl_foot = Point(
        #     rotated_foot_locations[0, 3] - self.config.LEG_ORIGINS[0, 3],
        #     rotated_foot_locations[1, 3] - self.config.LEG_ORIGINS[1, 3],
        #     rotated_foot_locations[2, 3] - self.config.LEG_ORIGINS[2, 3]
        # )
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        self.task_space_pub.publish(msg)

    def publish_joint_space_command(self, angle_matrix):
        msg = JointSpace()
        #FR
        msg.fr_foot = Angle()
        msg.fr_foot.theta1 = degrees(angle_matrix[0, 0])
        msg.fr_foot.theta2 = degrees(angle_matrix[1, 0])
        msg.fr_foot.theta3 = degrees(angle_matrix[2, 0])
        # msg.fr_foot = Angle(
        #     degrees(angle_matrix[0, 0]),
        #     degrees(angle_matrix[1, 0]),
        #     degrees(angle_matrix[2, 0])
        # )
        #FL
        msg.fl_foot = Angle()
        msg.fl_foot.theta1 = degrees(angle_matrix[0, 0])
        msg.fl_foot.theta2 = degrees(angle_matrix[1, 0])
        msg.fl_foot.theta3 = degrees(angle_matrix[2, 0])
        # msg.fl_foot = Angle(
        #     degrees(angle_matrix[0, 1]),
        #     degrees(angle_matrix[1, 1]),
        #     degrees(angle_matrix[2, 1])
        # )
        #RR
        msg.rr_foot = Angle()
        msg.rr_foot.theta1 = degrees(angle_matrix[0, 0])
        msg.rr_foot.theta2 = degrees(angle_matrix[1, 0])
        msg.rr_foot.theta3 = degrees(angle_matrix[2, 0])
        # msg.rr_foot = Angle(
        #     degrees(angle_matrix[0, 2]),
        #     degrees(angle_matrix[1, 2]),
        #     degrees(angle_matrix[2, 2])
        # )
        #RL
        msg.rl_foot = Angle()
        msg.rl_foot.theta1 = degrees(angle_matrix[0, 0])
        msg.rl_foot.theta2 = degrees(angle_matrix[1, 0])
        msg.rl_foot.theta3 = degrees(angle_matrix[2, 0])
        # msg.rl_foot = Angle(
        #     degrees(angle_matrix[0, 3]),
        #     degrees(angle_matrix[1, 3]),
        #     degrees(angle_matrix[2, 3])
        # )
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        self.joint_space_pub.publish(msg)

    def run(self, state, command):
        """Steps the controller forward one timestep."""

        previous_state = state.behavior_state

        if command.joystick_control_event:
            state.behavior_state = self.activate_transition_mapping[state.behavior_state]
        elif command.trot_event:
            state.behavior_state = self.trot_transition_mapping[state.behavior_state]
        elif command.hop_event:
            state.behavior_state = self.hop_transition_mapping[state.behavior_state]

        if previous_state != state.behavior_state:
            self.get_logger().info(f"State changed from {previous_state} to {state.behavior_state}")

        if state.behavior_state == BehaviorState.TROT:
            state.foot_locations, contact_modes = self.step_gait(state, command)
            rotated = euler2mat(command.roll, command.pitch, 0.0) @ state.foot_locations

            yaw, pitch, roll = state.euler_orientation
            correction_factor = 0.8
            max_tilt = 0.4
            roll_comp = correction_factor * np.clip(roll, -max_tilt, max_tilt)
            pitch_comp = correction_factor * np.clip(pitch, -max_tilt, max_tilt)
            rmat = euler2mat(roll_comp, pitch_comp, 0)
            rotated = rmat.T @ rotated

            state.joint_angles = self.inverse_kinematics(rotated, self.config)
            state.rotated_foot_locations = rotated

        elif state.behavior_state == BehaviorState.REST:
            yaw_prop = command.yaw_rate / self.config.max_yaw_rate
            self.smoothed_yaw += self.config.dt * clipped_first_order_filter(
                self.smoothed_yaw,
                yaw_prop * -self.config.max_stance_yaw,
                self.config.max_stance_yaw_rate,
                self.config.yaw_time_constant,
            )
            state.foot_locations = (
                self.config.default_stance +
                np.array([0, 0, command.height])[:, np.newaxis]
            )
            rotated = euler2mat(command.roll, command.pitch, self.smoothed_yaw) @ state.foot_locations
            rotated = self.stabilise_with_IMU(rotated, state.euler_orientation)
            state.joint_angles = self.inverse_kinematics(rotated, self.config)
            state.rotated_foot_locations = rotated

        state.ticks += 1
        state.pitch = command.pitch
        state.roll = command.roll
        state.height = command.height

    def stabilise_with_IMU(self, foot_locations, orientation):
        yaw, pitch, roll = orientation
        correction_factor = 0.5
        max_tilt = 0.4
        roll_comp = correction_factor * np.clip(-roll, -max_tilt, max_tilt)
        pitch_comp = correction_factor * np.clip(-pitch, -max_tilt, max_tilt)
        rmat = euler2mat(roll_comp, pitch_comp, 0)
        return rmat.T @ foot_locations
