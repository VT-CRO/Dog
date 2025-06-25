#!/usr/bin/env python3

import numpy as np
from numpy.linalg import norm
from math import pi, sin, cos, asin, acos
from dingo_control.util import RotMatrix3D, point_to_rad
from transforms3d.euler import euler2mat
import rclpy
from rclpy.logging import get_logger

# Get a logger instance for safe logging if you use rclpy
_logger = get_logger('kinematics')

def leg_explicit_inverse_kinematics(r_body_foot, leg_index, config):
    """Inverse kinematics for a single leg."""
    # Determine if it's a right or left leg
    is_right = int(leg_index in [0, 2])  # index 0 & 2 are left, 1 & 3 are right

    x, y, z = r_body_foot
    if is_right:
        y = -y
    r_body_foot = np.array([x, y, z])

    # Rotate frame for theta_1 calculation
    R1 = pi / 2 - config.phi
    rot_mtx = RotMatrix3D([-R1, 0, 0], is_radians=True)
    r_body_foot_ = np.ravel(rot_mtx @ r_body_foot.reshape(3, 1))
    x, y, z = r_body_foot_

    len_A = norm([y, z])
    a_1 = point_to_rad(y, z)
    a_2 = asin(sin(config.phi) * config.L1 / len_A)
    a_3 = pi - a_2 - config.phi
    theta_1 = a_1 + a_3
    theta_1 %= 2 * pi

    offset = np.array([0.0, config.L1 * cos(theta_1), config.L1 * sin(theta_1)])
    translated = r_body_foot_ - offset

    R2 = theta_1 + config.phi - pi / 2
    rot_mtx = RotMatrix3D([-R2, 0, 0], is_radians=True)
    vec2D = np.ravel(rot_mtx @ translated.reshape(3, 1))
    x_, _, z_ = vec2D

    len_B = norm([x_, z_])
    if len_B >= (config.L2 + config.L3):
        len_B = (config.L2 + config.L3) * 0.8
        _logger.warning(f'Target too far: adjusted length to {len_B:.3f}')

    b_1 = point_to_rad(x_, z_)
    b_2 = acos((config.L2 ** 2 + len_B ** 2 - config.L3 ** 2) / (2 * config.L2 * len_B))
    b_3 = acos((config.L2 ** 2 + config.L3 ** 2 - len_B ** 2) / (2 * config.L2 * config.L3))

    theta_2 = b_1 - b_2
    theta_3 = pi - b_3

    return np.array(angle_corrector([theta_1, theta_2, theta_3]))


def four_legs_inverse_kinematics(r_body_foot, config):
    """Inverse kinematics for all four legs."""
    alpha = np.zeros((3, 4))
    for i in range(4):
        offset = config.LEG_ORIGINS[:, i]
        alpha[:, i] = leg_explicit_inverse_kinematics(r_body_foot[:, i] - offset, i, config)
    return alpha


def forward_kinematics(angles, config, is_right=False):
    """Forward kinematics for one leg."""
    x = config.L3 * sin(angles[1] + angles[2]) - config.L2 * cos(angles[1])
    y = (
        0.5 * config.L2 * cos(angles[0] + angles[1])
        - config.L1 * cos(angles[0] + (403 * pi) / 4500)
        - 0.5 * config.L2 * cos(angles[0] - angles[1])
        - config.L3 * cos(angles[1] + angles[2]) * sin(angles[0])
    )
    z = (
        0.5 * config.L2 * sin(angles[0] - angles[1])
        + config.L1 * sin(angles[0] + (403 * pi) / 4500)
        - 0.5 * config.L2 * sin(angles[0] + angles[1])
        - config.L3 * cos(angles[1] + angles[2]) * cos(angles[0])
    )
    if not is_right:
        y = -y
    return np.array([x, y, z])


def angle_corrector(angles):
    """Adjust theta offsets & wrap to (-pi, pi)."""
    angles[1] -= pi
    angles[2] -= pi / 2

    for idx, theta in enumerate(angles):
        theta %= 2 * pi
        if theta > pi:
            theta -= 2 * pi
        angles[idx] = theta

    return angles
