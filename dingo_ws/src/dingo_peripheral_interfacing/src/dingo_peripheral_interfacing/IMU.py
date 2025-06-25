#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import numpy as np
import time
import board
import adafruit_bno055
import math as m


class IMU(Node):
    def __init__(self):
        super().__init__('imu_node')

        self.i2c = board.I2C()  # uses board.SCL and board.SDA
        self.sensor = adafruit_bno055.BNO055_I2C(self.i2c)
        self.last_euler = np.array([0.0, 0.0, 0.0])
        self.start_time = time.time()

        # Optional: create a timer to publish or log IMU data at 10 Hz
        self.timer = self.create_timer(0.1, self.read_orientation)

        self.get_logger().info("IMU node initialized.")

    def read_orientation(self):
        """Reads Euler angles from the BNO055 and logs them."""
        try:
            euler = self.sensor.euler
            if euler is None:
                raise ValueError("Euler reading is None")

            yaw, pitch, roll = euler
            yaw = m.radians(360 - yaw) if yaw is not None else 0.0
            pitch = m.radians(-pitch) if pitch is not None else 0.0
            roll = m.radians(roll - 30) if roll is not None else 0.0

            self.last_euler = np.array([yaw, pitch, roll])
            self.get_logger().info(
                f"Yaw: {np.degrees(yaw):.2f}°, Pitch: {np.degrees(pitch):.2f}°, Roll: {np.degrees(roll):.2f}°"
            )
        except Exception as e:
            self.get_logger().warn(f"IMU read failed: {str(e)}")
            self.last_euler = np.array([0.0, 0.0, 0.0])

        return self.last_euler


def main(args=None):
    rclpy.init(args=args)
    imu_node = IMU()
    try:
        rclpy.spin(imu_node)
    except KeyboardInterrupt:
        pass
    finally:
        imu_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
