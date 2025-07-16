import numpy as np
import serial
import time


class motor_config():
    def __init__(self, port='/dev/ttyAMA0', baud=115200):
        self.serial = serial.Serial(port, baudrate=baud, timeout=1)
        time.sleep(2)  # Give Arduino time to boot

        # Mapping: joint type × leg index → servo ID on Arduino
        self.pins = np.array([[14, 10, 2, 6],
                              [13, 9, 1, 5],
                              [12, 8, 0, 4]])

        self.right_leg_servo_list = [14, 13, 12, 0]  # example
        self.left_leg_servos_list = [10, 9, 8, 4]    # example
        self.hip_opposite_list = [14, 6]             # example

    def send_angle(self, servo_id, angle):
        angle = int(np.clip(angle, 0, 180))
        packet = bytearray([0xFF, servo_id, angle])
        self.serial.write(packet)

    def moveAbsAngle(self, servo_number, angle):
        if servo_number in self.left_leg_servos_list or servo_number in self.hip_opposite_list:
            angle = 180 - angle
        self.send_angle(servo_number, angle)

    def calibrate_servo(self, servo_number):
        while True:
            angle = float(input("Input angle: "))
            self.moveAbsAngle(servo_number, angle)
            satisfied = input("Is it vertical? (y/n): ")
            if satisfied.lower() == 'y':
                print(f"Calibration angle for servo {servo_number}: {angle}")
                break

    def relax_all_motors(self):
        # Send a packet with header 0xFE and 16 zeros to signal relaxation
        try:
            self.serial.write(bytearray([0xFE] + [0] * 16))
        except Exception as e:
            print(f"[WARN] Failed to relax motors: {e}")
