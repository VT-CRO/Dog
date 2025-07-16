#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
import numpy as np
import sys
import signal
import platform
import time

from dingo_peripheral_interfacing.IMU import IMU
from dingo_control.Controller import Controller
from dingo_input_interfacing.InputInterface import InputInterface
from dingo_control.State import State
from dingo_control.Kinematics import four_legs_inverse_kinematics
from dingo_control.Config import Configuration

from dingo_input_interfacing.InputController import InputController


class DingoNode(Node):
    def __init__(self, is_sim=0, is_physical=0, use_imu=False):
        super().__init__('dingo_node')

        self.is_sim = is_sim
        self.is_physical = is_physical
        self.use_imu = use_imu
        self.message_rate = 50

        # Config and hardware
        self.config = Configuration()
        if self.is_physical:
            from dingo_servo_interfacing.HardwareInterface import HardwareInterface
            from dingo_control.Config import Leg_linkage
            linkage = Leg_linkage(self.config)
            self.hardware_interface = HardwareInterface(linkage)
            if self.use_imu:
                self.imu = IMU(port="/dev/ttyACM0")
                self.imu.flush_buffer()
        else:
            self.hardware_interface = None
            self.imu = IMU(port="/dev/ttyACM0") if self.use_imu else None

        # Controller
        self.controller = Controller(
            self.config,
            four_legs_inverse_kinematics
        )
        self.state = State()
        self.input_interface = InputInterface(self.config)
        self.input_Controller = InputController(1, platform.processor())

        # Publishers

        #TODO: CHANGE THESE PUBLISEHRS WITh NEW CONTROLLER_MANAGER Controller names
        if self.is_sim:
            self.command_topics = [
                "/notspot_controller/FR1_joint/command",
                "/notspot_controller/FR2_joint/command",
                "/notspot_controller/FR3_joint/command",
                "/notspot_controller/FL1_joint/command",
                "/notspot_controller/FL2_joint/command",
                "/notspot_controller/FL3_joint/command",
                "/notspot_controller/RR1_joint/command",
                "/notspot_controller/RR2_joint/command",
                "/notspot_controller/RR3_joint/command",
                "/notspot_controller/RL1_joint/command",
                "/notspot_controller/RL2_joint/command",
                "/notspot_controller/RL3_joint/command",
            ]
            self.publishers = [
                self.create_publisher(Float64, topic, 10)
                for topic in self.command_topics
            ]
        else:
            self.publishers = []

        self.timer = self.create_timer(1.0 / self.message_rate, self.loop)
        self.active = False

        self.get_logger().info("DingoNode initialized")

    def loop(self):
        if not self.active:
            self.get_logger().info("Waiting for L1 to activate robot...")
            command = self.input_interface.get_command(self.state, self.message_rate)
            if command.joystick_control_event == 1:
                self.active = True
                self.get_logger().info("Robot activated.")
            return

        command = self.input_interface.get_command(self.state, self.message_rate)
        if command.joystick_control_event == 1:
            self.get_logger().info("Deactivating Robot")
            self.active = False
            return

        if self.use_imu:
            quat_orientation = self.imu.read_orientation()
        else:
            quat_orientation = np.array([1, 0, 0, 0])
        self.state.quat_orientation = quat_orientation

        self.controller.run(self.state, command)

        if self.is_sim:
            rows, cols = self.state.joint_angles.shape
            for col in range(cols):
                for row in range(rows):
                    idx = rows * col + row
                    msg = Float64()
                    msg.data = self.state.joint_angles[row, col]
                    self.publishers[idx].publish(msg)

        if self.is_physical:
            self.hardware_interface.set_actuator_positions(self.state.joint_angles)


def signal_handler(sig, frame):
    rclpy.shutdown()
    sys.exit(0)


def main():
    args = sys.argv
    if len(args) != 3:
        is_sim = 0
        is_physical = 0
    else:
        is_sim = int(args[1])
        is_physical = int(args[2])

    use_imu = False  # change if needed

    rclpy.init()
    signal.signal(signal.SIGINT, signal_handler)

    node = DingoNode(is_sim, is_physical, use_imu)

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
