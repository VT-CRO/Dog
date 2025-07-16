#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class StatusPublisher(Node):

    def __init__(self):
        super().__init__('status_publisher')
        self.status_publisher = self.create_publisher(String, "/robot_status_messages", 10)
        self.get_logger().info("StatusPublisher node started.")

    def publish_message(self, message):
        msg = String()
        msg.data = message
        self.status_publisher.publish(msg)
        self.get_logger().info(f"Published: {message}")

def main(args=None):
    rclpy.init(args=args)
    node = StatusPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
