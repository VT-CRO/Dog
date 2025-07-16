#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import sys
import os
import signal
from pynput import keyboard
from sensor_msgs.msg import Joy

class Keyboard(Node):
    def __init__(self):
        super().__init__('keyboard_input_listener')

        self.used_keys = [
            'w', 'a', 's', 'd', '1', '2', '7', '8', '9', '0',
            keyboard.Key.shift, keyboard.Key.backspace,
            keyboard.Key.up, keyboard.Key.down, keyboard.Key.left, keyboard.Key.right
        ]
        self.speed_multiplier = 1

        self.joystick_message_pub = self.create_publisher(Joy, "joy", 10)

        self.current_joy_message = Joy()
        self.current_joy_message.axes = [0.0] * 8
        self.current_joy_message.buttons = [0] * 11

        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_press,
            on_release=self.on_release
        )
        self.keyboard_listener.start()

        # Publish timer at 30Hz
        self.timer = self.create_timer(1.0 / 30.0, self.publish_current_command)

        self.get_logger().info("Keyboard node initialized and listening for key events.")

    def on_press(self, key):
        if hasattr(key, 'char'):
            key = key.char

        msg = self.current_joy_message

        if key == keyboard.Key.shift:
            self.speed_multiplier = 2
        elif key in ['w', 'W']:
            msg.axes[1] = 0.5 * self.speed_multiplier
        elif key in ['s', 'S']:
            msg.axes[1] = -0.5 * self.speed_multiplier
        elif key in ['a', 'A']:
            msg.axes[0] = 0.5 * self.speed_multiplier
        elif key in ['d', 'D']:
            msg.axes[0] = -0.5 * self.speed_multiplier
        elif key == '1':
            msg.buttons[5] = 1
        elif key == '2':
            msg.buttons[0] = 1
        elif key == keyboard.Key.backspace:
            msg.buttons[4] = 1
        elif key == keyboard.Key.up:
            msg.axes[4] = 0.5 * self.speed_multiplier
        elif key == keyboard.Key.down:
            msg.axes[4] = -0.5 * self.speed_multiplier
        elif key == keyboard.Key.left:
            msg.axes[3] = 0.5 * self.speed_multiplier
        elif key == keyboard.Key.right:
            msg.axes[3] = -0.5 * self.speed_multiplier
        elif key == '0':
            msg.axes[7] = 1
        elif key == '9':
            msg.axes[7] = -1
        elif key == '8':
            msg.axes[6] = 1
        elif key == '7':
            msg.axes[6] = -1

        print(f"[DEBUG] Key pressed: {key}")


        self.get_logger().debug(f"Keyboard key {key} pressed")


    def on_release(self, key):
        if hasattr(key, 'char'):
            key = key.char

        msg = self.current_joy_message

        if key == keyboard.Key.shift:
            self.speed_multiplier = 1
        elif key in ['w', 'W', 's', 'S']:
            msg.axes[1] = 0.0
        elif key in ['a', 'A', 'd', 'D']:
            msg.axes[0] = 0.0
        elif key == '1':
            msg.buttons[5] = 0
        elif key == '2':
            msg.buttons[0] = 0
        elif key == keyboard.Key.backspace:
            msg.buttons[4] = 0
        elif key in [keyboard.Key.up, keyboard.Key.down]:
            msg.axes[4] = 0.0
        elif key in [keyboard.Key.left, keyboard.Key.right]:
            msg.axes[3] = 0.0
        elif key in ['0', '9']:
            msg.axes[7] = 0
        elif key in ['8', '7']:
            msg.axes[6] = 0

        self.get_logger().debug(f"Keyboard key {key} released")


    def publish_current_command(self):
        # ROS 2 Joy doesn't have a header but it's okay
        self.joystick_message_pub.publish(self.current_joy_message)

def main(args=None):
    rclpy.init(args=args)

    if os.getenv("DISPLAY", "-") == "-":
        print("FATAL: No display found! The keyboard node requires a connected display due to pynput dependency.")
        sys.exit(1)

    node = Keyboard()

    signal.signal(signal.SIGINT, lambda sig, frame: sys.exit(0))

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
