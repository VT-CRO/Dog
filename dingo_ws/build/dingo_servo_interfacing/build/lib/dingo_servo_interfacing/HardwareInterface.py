#!/usr/bin/env python3

from adafruit_servokit import ServoKit
import numpy as np
import math as m
from rclpy.logging import get_logger

import platform

ON_PI = platform.machine().startswith('arm') or platform.node() == "raspberrypi"


logger = get_logger('HardwareInterface')


class HardwareInterface:
    def __init__(self, link):
        self.link = link

        # Always define these: they describe your robot, simulation or not
        self.pins = np.array([[14, 10, 2, 6],
                              [13, 9, 1, 5],
                              [12, 8, 0, 4]])

        self.servo_multipliers = np.array([[-1, 1, 1, -1],
                                           [1, -1, 1, -1],
                                           [1, -1, 1, -1]])

        self.complementary_angle = np.array([[180, 0, 0, 180],
                                             [0, 180, 0, 180],
                                             [0, 180, 0, 180]])

        self.physical_calibration_offsets = np.array(
            [[75, 130, 113, 73],
             [29, 13, 33, 15],
             [26, 12, 30, 4]]
        )

        self.servo_angles = np.zeros((3, 4))

        # Only do ServoKit + create() if on Pi
        if ON_PI:
            from adafruit_servokit import ServoKit
            self.kit = ServoKit(channels=16)
            self.create()
        else:
            print("ServoKit skipped: not on Pi")
            self.kit = None

    def create(self):
        for i in range(16):
            self.kit.servo[i].actuation_range = 180
            self.kit.servo[i].set_pulse_width_range(self.pwm_min, self.pwm_max)

    def set_actuator_positions(self, joint_angles):
        possible_joint_angles = impose_physical_limits(joint_angles)
        self.joint_angles_to_servo_angles(possible_joint_angles)

        for leg_index in range(4):
            for axis_index in range(3):
                try:
                    self.kit.servo[self.pins[axis_index, leg_index]].angle = self.servo_angles[axis_index, leg_index]
                except Exception as e:
                    return
                    #logger.warn(f"I2C IO error on servo command: {e}")

    def relax_all_motors(self, servo_list=np.ones((3, 4))):
        for leg_index in range(4):
            for axis_index in range(3):
                if servo_list[axis_index, leg_index] == 1:
                    self.kit.servo[self.pins[axis_index, leg_index]].angle = None

    def joint_angles_to_servo_angles(self, joint_angles):
        for leg in range(4):
            THETA2, THETA3 = joint_angles[1:, leg]
            THETA0 = lower_leg_angle_to_servo_angle(self.link, m.pi/2 - THETA2, THETA3 + np.pi/2)

            self.servo_angles[0, leg] = m.degrees(joint_angles[0, leg])
            self.servo_angles[1, leg] = m.degrees(THETA2)
            self.servo_angles[2, leg] = m.degrees(m.pi/2 + m.pi - THETA0)

        self.servo_angles = np.clip(self.servo_angles + self.physical_calibration_offsets, 0, 180)
        self.servo_angles = np.round(np.multiply(self.servo_angles, self.servo_multipliers) + self.complementary_angle, 1)


### SUPPORT FUNCTIONS ###

def calculate_4_bar(th2, a, b, c, d):
    x_b = a * m.cos(th2)
    y_b = a * m.sin(th2)
    f = np.sqrt((d - x_b)**2 + y_b**2)
    beta = np.arccos((f**2 + c**2 - b**2) / (2 * f * c))
    gamma = np.arctan2(y_b, d - x_b)
    th4 = np.pi - gamma - beta
    x_c = c * np.cos(th4) + d
    y_c = c * np.sin(th4)
    th3 = np.arctan2(y_c - y_b, x_c - x_b)
    ABC = np.pi - th2 + th3
    BCD = th4 - th3
    CDA = 2 * np.pi - th2 - ABC - BCD
    return ABC, BCD, CDA


def lower_leg_angle_to_servo_angle(link, THETA2, THETA3):
    GDE, DEF, EFG = calculate_4_bar(THETA3 + link.lower_leg_bend_angle, link.i, link.h, link.f, link.g)
    CDH = 1.5 * np.pi - THETA2 - GDE - link.EDC
    CDA = CDH + link.gamma
    DAB, ABC, BCD = calculate_4_bar(CDA, link.d, link.a, link.b, link.c)
    THETA0 = DAB + link.gamma
    return THETA0


def impose_physical_limits(joint_angles):
    possible_joint_angles = np.zeros((3, 4))

    for i in range(4):
        hip, upper, lower = np.degrees(joint_angles[:, i])
        hip = np.clip(hip, -20, 20)
        upper = np.clip(upper, 0, 120)

        if upper < 10: lower = np.clip(lower, -20, 40)
        elif upper < 20: lower = np.clip(lower, -40, 40)
        elif upper < 30: lower = np.clip(lower, -50, 40)
        elif upper < 40: lower = np.clip(lower, -60, 30)
        elif upper < 50: lower = np.clip(lower, -70, 25)
        elif upper < 60: lower = np.clip(lower, -70, 20)
        elif upper < 70: lower = np.clip(lower, -70, 0)
        elif upper < 80: lower = np.clip(lower, -70, -10)
        elif upper < 90: lower = np.clip(lower, -70, -20)
        elif upper < 100: lower = np.clip(lower, -70, -30)
        elif upper < 110: lower = np.clip(lower, -70, -40)
        else: lower = np.clip(lower, -70, -60)

        possible_joint_angles[:, i] = hip, upper, lower

    return np.radians(possible_joint_angles)
