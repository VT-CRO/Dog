#!/usr/bin/env python3

import serial
import numpy as np
import math as m
import rclpy
from rclpy.logging import get_logger
import platform

logger = get_logger('HardwareInterface')


class HardwareInterface:
    def __init__(self, link):
        self.link = link

        # FORMAT
        # [msg.fr_foot[0], msg.fl_foot[0], msg.rr_foot[0], msg.rl_foot[0]],
        # [msg.fr_foot[1], msg.fl_foot[1], msg.rr_foot[1], msg.rl_foot[1]],
        # [msg.fr_foot[2], msg.fl_foot[2], msg.rr_foot[2], msg.rl_foot[2]],
    
        # self.pins = np.array([[14, 10, 2, 6],
        #                       [13, 9, 1, 5],
        #                       [12, 8, 0, 4]])

        # self.servo_multipliers = np.array([[-1, 1, 1, -1],
        #                                    [1, -1, 1, -1],
        #                                    [1, -1, 1, -1]])

        self.servo_multipliers = np.ones((3, 4))

        # self.complementary_angle = np.array([[180, 0, 0, 180],
        #                                      [0, 180, 0, 180],
        #                                      [0, 180, 0, 180]])

        self.complementary_angle = np.zeros((3, 4))


        # self.physical_calibration_offsets = np.array(
        #     [[75, 130, 113, 73],
        #      [29, 13, 33, 15],
        #      [26, 12, 30, 4]]
        # )

        # self.physical_calibration_offsets = np.array(
        #     [[115, 90, 50, 80],
        #      [90, 30, 70, 180],
        #      [125, 90, 90, 82]]
        # )

        self.physical_calibration_offsets = np.array(
            [[125, 90, 90, 82,],
             [90, 30, 140, 50,],
             [115, 0, 140, 40]]
        )

        self.physical_calibration_offsets = np.array(
            [[125, 90, 106.6 , 98.6],
             [90, 30, 98, 8],
             [-45.1, -160, -65.2, -165.2]]
        )

        # raw_servo_angles_default = np.array(
        #     [[  0,    0,   -16.6, -16.6,],
        #      [  0,    0,    42,    42,],
        #      [160.1, 160.1, 205.2, 205.2]]
        # )

        # self.physical_calibration_offsets = np.array(
        #     [[115, 0, 140, 40,],
        #      [90, 30, 140, 50,],
        #      [125, 90, 90, 82]]
        # )

        self.servo_angles = np.zeros((3, 4))

        # Inside HardwareInterface.__init__
        self.first_command_sent = False

        # Set up serial only if on Pi
        try:
            self.serial = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)
            print("Serial connection established.")
        except Exception as e:
            print(f"[ERROR] Failed to connect to Arduino: {e}")
            self.serial = None


    def set_actuator_positions(self, joint_angles, active_legs):
        # Zero-out inactive legs
        for i, active in enumerate(active_legs):
            if not active:
                joint_angles[:, i] = 0.0
        
        possible_joint_angles = impose_physical_limits(joint_angles)
        self.joint_angles_to_servo_angles(possible_joint_angles)

        # Skip sending the first time unless explicitly allowed
        if not self.first_command_sent:
            self.first_command_sent = True
            print("[INFO] First joint command received. Skipping initial write to prevent jerk.")
            return

        if self.serial and self.serial.is_open:
            try:
                packet = bytearray([0xFF])
                for axis_index in range(3):
                    for leg_index in range(4):
                        angle = int(self.servo_angles[axis_index, leg_index])
                        angle = np.clip(angle, 0, 180)
                        packet.append(angle)
                self.serial.write(packet)
            except Exception as e:
                print(f"[WARN] Failed to send servo angles: {e}")

    def joint_angles_to_servo_angles(self, joint_angles):
        # self.servo_angles = np.zeros((3, 4))  # skip math
        
        for leg in range(4):
            THETA2, THETA3 = joint_angles[1:, leg]
            THETA0 = lower_leg_angle_to_servo_angle(self.link, m.pi / 2 - THETA2, THETA3 + np.pi / 2)

            self.servo_angles[0, leg] = m.degrees(joint_angles[0, leg])
            self.servo_angles[1, leg] = m.degrees(THETA2)
            self.servo_angles[2, leg] = m.degrees(m.pi / 2 + m.pi - THETA0)

        logger.info(f"[JOINTS] Raw servo_angles (before offset):\n{np.round(self.servo_angles, 1)}")

        self.servo_angles = np.clip(self.servo_angles + self.physical_calibration_offsets, 0, 180)

        logger.info(f"[JOINTS] After adding physical_calibration_offsets:\n{np.round(self.servo_angles, 1)}")

        self.servo_angles = np.round(np.multiply(self.servo_angles, self.servo_multipliers) + self.complementary_angle, 1)

        logger.info(f"[JOINTS] Final servo_angles to be sent (after multipliers + complementary):\n{self.servo_angles}")
            


    def relax_all_motors(self, servo_list=np.ones((3, 4))):
        if self.serial and self.serial.is_open:
            try:
                # Send relax signal: sync byte 0xFE + 12 servo enable/disable flags (0 or 1)
                packet = bytearray([0xFE])
                for axis_index in range(3):
                    for leg_index in range(4):
                        flag = 0 if servo_list[axis_index, leg_index] == 1 else 1
                        packet.append(flag)
                self.serial.write(packet)
            except Exception as e:
                print(f"[WARN] Failed to send relax command: {e}")

    def create(self):
        # No longer used — handled on Arduino side
        pass



### SUPPORT FUNCTIONS ###

def calculate_4_bar(th2, a, b, c, d):
    x_b = a * m.cos(th2)
    y_b = a * m.sin(th2)
    f = np.sqrt((d - x_b)**2 + y_b**2)
    # beta = np.arccos((f**2 + c**2 - b**2) / (2 * f * c))
    arg = (f**2 + c**2 - b**2) / (2 * f * c)
    arg = np.clip(arg, -1.0, 1.0)  # <-- This prevents NaN
    beta = np.arccos(arg)
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
