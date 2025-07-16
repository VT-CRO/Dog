import rclpy
from rclpy.node import Node

import numpy as np
import sys
import time

from std_msgs.msg import Float64, Bool
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import Joy

from dingo_msgs.msg import TaskSpace, JointSpace
from dingo_control import Controller, State, BehaviorState, Configuration, four_legs_inverse_kinematics
from dingo_input_interfacing import InputInterface
from dingo_servo_interfacing import HardwareInterface
from dingo_control import Leg_linkage

class DingoDriver(Node):
    def __init__(self, is_sim, is_physical, use_imu, active_legs):
        super().__init__('dingo_driver')

        self.is_sim = is_sim
        self.is_physical = is_physical
        self.use_imu = use_imu

        self.active_legs = np.array(active_legs).astype(bool)  # [FL, FR, RL, RR]

        self.message_rate = 50
        self.dt = 1.0 / self.message_rate
        self.external_commands_enabled = 0

        self.create_subscription(JointSpace, '/joint_space_cmd', self.run_joint_space_command, 10)
        self.create_subscription(TaskSpace, '/task_space_cmd', self.run_task_space_command, 10)
        self.create_subscription(Bool, '/emergency_stop_status', self.update_emergency_stop_status, 10)

        if self.is_sim:
            self.sim_command_topics = [f"/{leg}_leg_group/commands" for leg in ["fl", "fr", "rl", "rr"]]
            self.sim_publisher_array = [
                self.create_publisher(Float64MultiArray, topic, 10) for topic in self.sim_command_topics
            ]

        self.config = Configuration()
        if self.is_physical:
            self.linkage = Leg_linkage(self.config)
            self.hardware_interface = HardwareInterface(self.linkage)
            self.hardware_interface.relax_all_motors()

        self.controller = Controller(self.config, four_legs_inverse_kinematics)
        self.state = State()
        self.input_interface = InputInterface(self.config, self.get_logger())

        self.subscription = self.create_subscription(
            Joy,
            "joy",
            self.input_interface.input_callback,
            10
        )

        self.timer = self.create_timer(self.dt, self.run)

    def joystick_callback(self):
        self.get_logger().info("DO NOTHING > JOY")

    def run(self):
        if self.state.currently_estopped:
            self.get_logger().warn("E-stop active. Waiting...")
            return

        command = self.input_interface.get_command(self.state, self.message_rate)
        self.controller.run(self.state, command)

        self.controller.publish_joint_space_command(self.state.joint_angles)
        self.controller.publish_task_space_command(self.state.rotated_foot_locations)

        if self.is_sim:
            self.publish_joints_to_sim(self.state.joint_angles)

        if self.is_physical:
            # Freeze inactive legs
            joint_angles = self.state.joint_angles.copy()
            for i, active in enumerate(self.active_legs):
                if not active:
                    joint_angles[:, i] = 0  # or keep as is
            self.hardware_interface.set_actuator_positions(joint_angles, self.active_legs)

    def update_emergency_stop_status(self, msg):
        self.state.currently_estopped = msg.data
        if msg.data:
            self.get_logger().warn("Emergency stop engaged!")
        else:
            self.get_logger().info("Emergency stop released")

    def run_task_space_command(self, msg):
        if self.external_commands_enabled and not self.state.currently_estopped:
            foot_locations = np.array([
                [msg.fr_foot[0], msg.fl_foot[0], msg.rr_foot[0], msg.rl_foot[0]],
                [msg.fr_foot[1], msg.fl_foot[1], msg.rr_foot[1], msg.rl_foot[1]],
                [msg.fr_foot[2], msg.fl_foot[2], msg.rr_foot[2], msg.rl_foot[2]]
            ])
            joint_angles = self.controller.inverse_kinematics(foot_locations, self.config)

            if self.is_sim:
                self.publish_joints_to_sim(joint_angles)
            if self.is_physical:
                for i, active in enumerate(self.active_legs):
                    if not active:
                        joint_angles[:, i] = 0
                self.hardware_interface.set_actuator_positions(joint_angles)
        else:
            self.get_logger().error("Robot not accepting external commands!")

    def run_joint_space_command(self, msg):
        if self.external_commands_enabled and not self.state.currently_estopped:
            joint_angles = np.array([
                [msg.fr_foot[0], msg.fl_foot[0], msg.rr_foot[0], msg.rl_foot[0]],
                [msg.fr_foot[1], msg.fl_foot[1], msg.rr_foot[1], msg.rl_foot[1]],
                [msg.fr_foot[2], msg.fl_foot[2], msg.rr_foot[2], msg.rl_foot[2]],
            ])
            if self.is_sim:
                self.publish_joints_to_sim(joint_angles)
            if self.is_physical:
                for i, active in enumerate(self.active_legs):
                    if not active:
                        joint_angles[:, i] = 0
                self.hardware_interface.set_actuator_positions(joint_angles)
        else:
            self.get_logger().error("Robot not accepting external commands!")

    def publish_joints_to_sim(self, joint_angles):
        for i, pub in enumerate(self.sim_publisher_array):
            msg = Float64MultiArray()
            msg.data = joint_angles[:, i].tolist() if self.active_legs[i] else [0.0, 0.0, 0.0]
            pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    args = sys.argv

    if len(args) != 8:
        print("Usage: dingo_driver.py is_sim is_physical use_imu is_fl_active is_fr_active is_rl_active is_rr_active")
        is_sim = 0
        is_physical = 1
        use_imu = 1
        active_legs = [1, 1, 1, 1]
    else:
        is_sim = int(args[1])
        is_physical = int(args[2])
        use_imu = int(args[3])
        active_legs = list(map(int, args[4:8]))

    driver = DingoDriver(is_sim, is_physical, use_imu, active_legs)
    rclpy.spin(driver)
    driver.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

# #!/usr/bin/env python3

# import rclpy
# from rclpy.node import Node

# import numpy as np
# import sys
# import time
# import socket
# import signal

# from std_msgs.msg import Float64, Bool
# from dingo_msgs.msg import ElectricalMeasurements
# from dingo_msgs.msg import TaskSpace, JointSpace, Angle
# from sensor_msgs.msg import Joy

# from dingo_control import Controller
# from dingo_input_interfacing import InputInterface
# from dingo_control import State, BehaviorState
# from dingo_control import four_legs_inverse_kinematics
# from dingo_control import Configuration

# # Only import hardware if running physical
# from dingo_servo_interfacing import HardwareInterface
# # from dingo_peripheral_interfacing import IMU
# from dingo_control import Leg_linkage
# from std_msgs.msg import Float64MultiArray

# class DingoDriver(Node):
#     def __init__(self, is_sim, is_physical, use_imu):
#         super().__init__('dingo_driver')

#         self.is_sim = is_sim
#         self.is_physical = is_physical
#         self.use_imu = use_imu

#         active_legs = list(map(int, sys.argv[4].split(',')))  # [FL, FR, RL, RR]

#         self.message_rate = 50
#         self.dt = 1.0 / self.message_rate

#         self.external_commands_enabled = 0

#         # Subscribers
#         self.create_subscription(JointSpace, '/joint_space_cmd', self.run_joint_space_command, 10)
#         self.create_subscription(TaskSpace, '/task_space_cmd', self.run_task_space_command, 10)
#         self.create_subscription(Bool, '/emergency_stop_status', self.update_emergency_stop_status, 10)


#         # Publishers for sim joint commands
#         # if self.is_sim:
#         #     self.sim_command_topics = [
#         #         f"/dingo_controller/{leg}_{theta}/command"
#         #         for leg in ["FR", "FL", "RR", "RL"]
#         #         for theta in ["theta1", "theta2", "theta3"]
#         #     ]
#         #     self.sim_publisher_array = [
#         #         self.create_publisher(Float64, topic, 10)
#         #         for topic in self.sim_command_topics
#         #     ]

#         if self.is_sim:
#             # one publisher per LEG GROUP (array)
#             self.sim_command_topics = [
#                 f"/{leg}_leg_group/commands"
#                 for leg in ["fl", "fr", "rl", "rr"]
#             ]
#             self.sim_publisher_array = [
#                 self.create_publisher(Float64MultiArray, topic, 10)
#                 for topic in self.sim_command_topics
#             ]


#         self.config = Configuration()
#         if self.is_physical:
#             self.linkage = Leg_linkage(self.config)
#             self.hardware_interface = HardwareInterface(self.linkage)


#         self.hardware_interface.relax_all_motors()

#         # if self.use_imu:
#         #     self.imu = IMU()
#         # else:
#         #     self.imu = None

#         self.controller = Controller(self.config, four_legs_inverse_kinematics)
#         self.state = State()
#         self.input_interface = InputInterface(self.config, self.get_logger())

#         self.subscription = self.create_subscription(
#             Joy,
#             "joy",
#             self.input_interface.input_callback,
#             10
#         )

#         self.get_logger().info("Input listener and driver initialized")

#         # Main loop timer
#         self.timer = self.create_timer(self.dt, self.run)



#     def run(self):
#         if self.state.currently_estopped:
#             self.get_logger().warn("E-stop active. Waiting...")
#             return

#         command = self.input_interface.get_command(self.state, self.message_rate)
#         self.controller.run(self.state, command)

#         self.controller.publish_joint_space_command(self.state.joint_angles)
#         self.controller.publish_task_space_command(self.state.rotated_foot_locations)

#         if self.is_sim:
#             self.publish_joints_to_sim(self.state.joint_angles)
#         if self.is_physical:
#             self.hardware_interface.set_actuator_positions(self.state.joint_angles)

#     def update_emergency_stop_status(self, msg):
#         self.state.currently_estopped = msg.data
#         if msg.data:
#             self.get_logger().warn("Emergency stop engaged!")
#         else:
#             self.get_logger().info("Emergency stop released")

#     def run_task_space_command(self, msg):
#         if self.external_commands_enabled and not self.state.currently_estopped:
#             foot_locations = np.array([
#                 [msg.fr_foot[0], msg.fl_foot[0], msg.rr_foot[0], msg.rl_foot[0]],
#                 [msg.fr_foot[1], msg.fl_foot[1], msg.rr_foot[1], msg.rl_foot[1]],
#                 [msg.fr_foot[2], msg.fl_foot[2], msg.rr_foot[2], msg.rl_foot[2]]
#             ])
#             joint_angles = self.controller.inverse_kinematics(foot_locations, self.config)

#             if self.is_sim:
#                 self.publish_joints_to_sim(joint_angles)
#             if self.is_physical:
#                 self.hardware_interface.set_actuator_positions(joint_angles)

#         else:
#             self.get_logger().error("Robot not accepting external commands!")

#     def run_joint_space_command(self, msg):
#         if self.external_commands_enabled and not self.state.currently_estopped:
#             joint_angles = np.array([
#                 [msg.fr_foot[0], msg.fl_foot[0], msg.rr_foot[0], msg.rl_foot[0]],
#                 [msg.fr_foot[1], msg.fl_foot[1], msg.rr_foot[1], msg.rl_foot[1]],
#                 [msg.fr_foot[2], msg.fl_foot[2], msg.rr_foot[2], msg.rl_foot[2]],
#             ])
#             if self.is_sim:
#                 self.publish_joints_to_sim(joint_angles)
#             if self.is_physical:
#                 self.hardware_interface.set_actuator_positions(joint_angles)
#         else:
#             self.get_logger().error("Robot not accepting external commands!")

#     # def publish_joints_to_sim(self, joint_angles):
#     #     flat_angles = joint_angles.flatten()
#     #     for pub, angle in zip(self.sim_publisher_array, flat_angles):
#     #         msg = Float64()
#     #         msg.data = angle
#     #         pub.publish(msg)

#     def publish_joints_to_sim(self, joint_angles):
#         # joint_angles: 3x4 (rows: theta1,2,3; cols: fl, fr, rl, rr)
#         for i, pub in enumerate(self.sim_publisher_array):
#             msg = Float64MultiArray()
#             # get one column for this leg
#             leg_angles = joint_angles[:, i]
#             msg.data = leg_angles.tolist()
#             pub.publish(msg)
#             self.get_logger().debug(f"Publishing to {self.sim_command_topics[i]}: {leg_angles.tolist()}")



# def main(args=None):
#     rclpy.init(args=args)

#     # Parse args from sys.argv
#     args = sys.argv
#     if len(args) != 4:
#         is_sim = 0
#         is_physical = 1
#         use_imu = 1
#     else:
#         is_sim = int(args[1])
#         is_physical = int(args[2])
#         use_imu = int(args[3])

#     driver = DingoDriver(is_sim, is_physical, use_imu)
#     rclpy.spin(driver)

#     driver.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()
