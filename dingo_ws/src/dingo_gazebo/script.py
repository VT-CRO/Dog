#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import JointState
from gazebo_msgs.srv import SetModelState
from gazebo_msgs.msg import ModelState


class JointStatesSubscriberPlugin(Node):
    def __init__(self):
        super().__init__('joint_states_subscriber_plugin')

        self.joint_positions = {}

        self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_states_callback,
            10
        )

        self.set_model_state_client = self.create_client(
            SetModelState,
            '/gazebo/set_model_state'
        )

        # Wait for service to be ready
        while not self.set_model_state_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for /gazebo/set_model_state service...')

    def joint_states_callback(self, msg):
        for joint_name, position in zip(msg.name, msg.position):
            self.joint_positions[joint_name] = position

        self.actuate_robot()

    def actuate_robot(self):
        model_state = ModelState()
        model_state.model_name = 'your_robot_model_name'  # <-- change this to your model name!

        # Here: example - only set Z based on first joint position
        if self.joint_positions:
            position = next(iter(self.joint_positions.values()))
            model_state.pose.position.z = position

        model_state.twist.linear.x = 0.0
        model_state.twist.linear.y = 0.0
        model_state.twist.linear.z = 0.0
        model_state.twist.angular.x = 0.0
        model_state.twist.angular.y = 0.0
        model_state.twist.angular.z = 0.0
        model_state.reference_frame = 'world'

        model_state.pose.orientation.x = 0.0
        model_state.pose.orientation.y = 0.0
        model_state.pose.orientation.z = 0.0
        model_state.pose.orientation.w = 1.0  # identity quaternion!

        req = SetModelState.Request()
        req.model_state = model_state

        self.set_model_state_client.call_async(req)


def main(args=None):
    rclpy.init(args=args)
    node = JointStatesSubscriberPlugin()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
