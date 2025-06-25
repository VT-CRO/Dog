#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
import math

class LegMover(Node):
    def __init__(self):
        super().__init__('leg_mover')
        self.pub_fl = self.create_publisher(Float64MultiArray, '/fl_leg_group/commands', 10)
        self.pub_fr = self.create_publisher(Float64MultiArray, '/fr_leg_group/commands', 10)
        self.pub_rl = self.create_publisher(Float64MultiArray, '/rl_leg_group/commands', 10)
        self.pub_rr = self.create_publisher(Float64MultiArray, '/rr_leg_group/commands', 10)
        self.timer = self.create_timer(0.1, self.timer_cb)
        self.t = 0.0

    def timer_cb(self):
        msg = Float64MultiArray()
        angle = 0.5 * math.sin(self.t)
        msg.data = [angle, -angle, angle]
        self.pub_fl.publish(msg)
        self.pub_fr.publish(msg)
        self.pub_rl.publish(msg)
        self.pub_rr.publish(msg)
        self.t += 0.1

def main():
    rclpy.init()
    node = LegMover()
    rclpy.spin(node)

if __name__ == '__main__':
    main()
