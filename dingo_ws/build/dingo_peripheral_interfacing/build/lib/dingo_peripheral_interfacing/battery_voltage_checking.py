#!/usr/bin/env python3

import sys
import time
import signal
import subprocess

import RPi.GPIO as GPIO

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64, Bool


class BatteryMonitor(Node):
    def __init__(self):
        super().__init__('battery_monitor')

        # GPIO setup
        GPIO.setmode(GPIO.BCM)

        self.estop_pin_number = 5
        self.battery_pin1_number = 6
        self.battery_pin2_number = 13
        self.battery_pin3_number = 19

        GPIO.setup(self.estop_pin_number, GPIO.IN)
        GPIO.setup(self.battery_pin1_number, GPIO.IN)
        GPIO.setup(self.battery_pin2_number, GPIO.IN)
        GPIO.setup(self.battery_pin3_number, GPIO.IN)

        self.battery_percentage_publisher = self.create_publisher(Float64, '/battery_percentage', 10)
        self.estop_publisher = self.create_publisher(Bool, '/emergency_stop_status', 10)

        self.current_estop_bit = 0
        self.number_of_low_battery_detections = 0

        self.timer = self.create_timer(1.0 / 50.0, self.loop)

        # Publish initial E-Stop
        estop_bit = GPIO.input(self.estop_pin_number)
        self.estop_publisher.publish(Bool(data=bool(estop_bit)))
        self.current_estop_bit = estop_bit

        self.get_logger().info('Battery Monitor Node Started.')

    def loop(self):
        estop_bit = GPIO.input(self.estop_pin_number)
        battery_bits = [
            GPIO.input(self.battery_pin1_number),
            GPIO.input(self.battery_pin2_number),
            GPIO.input(self.battery_pin3_number)
        ]

        self.get_logger().debug(f"Battery bits: {battery_bits}, Estop: {estop_bit}")

        # Handle E-Stop changes
        if estop_bit != self.current_estop_bit:
            self.current_estop_bit = estop_bit
            self.estop_publisher.publish(Bool(data=bool(estop_bit)))

        # Convert battery bits to value
        num = int("".join([str(b) for b in battery_bits]), 2)

        level = {
            0: 0.0,
            1: 0.125,
            2: 0.25,
            3: 0.375,
            4: 0.5,
            5: 0.625,
            6: 0.75,
            7: 1.0
        }.get(num, 0.0)

        self.battery_percentage_publisher.publish(Float64(data=level))

        if level == 0.0:
            self.number_of_low_battery_detections += 1
            if self.number_of_low_battery_detections > 30:
                self.get_logger().warn("BATTERY VOLTAGE TOO LOW. Would shut down if enabled.")
                # self.shutdown()
        else:
            self.number_of_low_battery_detections = max(0, self.number_of_low_battery_detections - 1)

    def shutdown(self):
        GPIO.cleanup()
        self.get_logger().warn("BATTERY VOLTAGE TOO LOW. COMMENCING SHUTDOWN PROCESS")
        time.sleep(5)
        subprocess.run(["sudo", "shutdown", "-h", "now"])


def main(args=None):
    rclpy.init(args=args)
    monitor = BatteryMonitor()

    def handle_sigint(sig, frame):
        GPIO.cleanup()
        monitor.get_logger().info("Battery Monitor shutting down.")
        sys.exit(0)

    signal.signal(signal.SIGINT, handle_sigint)

    try:
        rclpy.spin(monitor)
    except KeyboardInterrupt:
        pass
    finally:
        GPIO.cleanup()
        monitor.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

# import RPi.GPIO as GPIO
# import sys, rospy, signal, subprocess, time
# from std_msgs.msg import Float64, Bool

# def signal_handler(sig, frame):
#     GPIO.cleanup()
#     sys.exit(0)

# def shutdown():
#     GPIO.cleanup()
#     rospy.logwarn("BATTERY VOLTAGE TOO LOW. COMMENCING SHUTDOWN PROCESS")
#     time.sleep(5)
#     subprocess.run(["sudo", "shutdown", "-h", "now"])

# def main():
#     # Set the mode of the GPIO library
#     rospy.init_node("battery_monitor") 
#     message_rate = 50
#     rate = rospy.Rate(message_rate)

#     signal.signal(signal.SIGINT, signal_handler)

#     GPIO.setmode(GPIO.BCM)

#     estop_pin_number = 5
#     battery_pin1_number = 6
#     battery_pin2_number = 13
#     battery_pin3_number = 19

#     # Set pin 5 as an input pin
#     GPIO.setup(estop_pin_number, GPIO.IN)
#     GPIO.setup(battery_pin1_number, GPIO.IN)
#     GPIO.setup(battery_pin2_number, GPIO.IN)
#     GPIO.setup(battery_pin3_number, GPIO.IN)

#     battery_percentage_publisher = rospy.Publisher("/battery_percentage", Float64, queue_size = 10)
#     estop_publisher = rospy.Publisher("/emergency_stop_status", Bool, queue_size = 10)
#     current_estop_bit = 0

#     number_of_low_battery_detections = 0

#     estop_bit = GPIO.input(estop_pin_number)
#     battery_bit1 = GPIO.input(battery_pin1_number)
#     battery_bit2 = GPIO.input(battery_pin2_number)
#     battery_bit3 = GPIO.input(battery_pin3_number)

#     #Grab initial value and publish that immediately
#     if estop_bit == 0:
#         estop_publisher.publish(0)
#     elif estop_bit == 1:
#         estop_publisher.publish(1)
#         current_estop_bit = 1
    
#     while not rospy.is_shutdown(): 
#         # Read the digital values from the pins
#         estop_bit = GPIO.input(estop_pin_number)
#         battery_bit1 = GPIO.input(battery_pin1_number)
#         battery_bit2 = GPIO.input(battery_pin2_number)
#         battery_bit3 = GPIO.input(battery_pin3_number)
#         print("estop: ", battery_bit1)
#         print("bit1: ", battery_bit1)
#         print("bit2: ", battery_bit2)
#         print("bit3: ", battery_bit3)

#         battery_bits = [battery_bit1, battery_bit2, battery_bit3]

#         if estop_bit == 1 and current_estop_bit == 0:
#             current_estop_bit = 1
#             estop_publisher.publish(1)

#         if estop_bit == 0 and current_estop_bit == 1:
#             current_estop_bit = 0
#             estop_publisher.publish(0)

#         # Convert the bits to a decimal number
#         num = int("".join([str(b) for b in battery_bits]), 2)

#         value = 0.0

#         # Check which scenario has occurred
#         if num == 0:
#             value = 0.0
#         elif num == 1:
#             value = 0.125
#         elif num == 2:
#             value = 0.25
#         elif num == 3:
#             value = 0.375
#         elif num == 4:
#             value = 0.5
#         elif num == 5:
#             value = 0.625
#         elif num == 6:
#             value = 0.75
#         elif num == 7:
#             value = 1

#         battery_percentage_publisher.publish(value)

#         if value == 0.0:
#             number_of_low_battery_detections = number_of_low_battery_detections+1
#             if (number_of_low_battery_detections > 30):
#                 #shutdown()
#                 print("Would shut down if activated")
#         else:
#             if (number_of_low_battery_detections > 0):
#                 number_of_low_battery_detections = number_of_low_battery_detections-1


#         rate.sleep()

# main()