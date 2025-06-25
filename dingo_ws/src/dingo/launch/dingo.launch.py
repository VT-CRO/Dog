import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch_ros.actions import Node

def generate_launch_description():

    # Declare arguments
    is_sim = DeclareLaunchArgument('is_sim', default_value='1')
    is_physical = DeclareLaunchArgument('is_physical', default_value='0')
    use_joystick = DeclareLaunchArgument('use_joystick', default_value='0')
    use_keyboard = DeclareLaunchArgument('use_keyboard', default_value='1')
    serial_port = DeclareLaunchArgument('serial_port', default_value='/dev/ttyS0')
    use_imu = DeclareLaunchArgument('use_imu', default_value='0')

    # ABSOLUTE correct paths!
    workspace_dir = os.getenv('PWD')  # or hardcode to your workspace root

    lcd_script = os.path.join(
        workspace_dir,
        'src', 
        'dingo_peripheral_interfacing',
        'src', 'dingo_peripheral_interfacing',
        'dingo_lcd_interfacing.py'
    )

    keyboard_script = os.path.join(
        workspace_dir,
        'src', 'dingo_input_interfacing', 'src', 'dingo_input_interfacing',
        'Keyboard.py'
    )

    driver_script = os.path.join(
        workspace_dir,
        'src', 'dingo',
        'src', 'dingo',
        'dingo_driver.py'
    )

    # LCD Node
    lcd_node = ExecuteProcess(
        cmd=['python3', lcd_script],
        output='screen',
        condition=IfCondition(LaunchConfiguration('is_physical'))
    )

    # Joystick Node (unchanged)
    joystick_node = Node(
        package='joy',
        executable='joy_node',
        name='JOYSTICK',
        parameters=[{'autorepeat_rate': 30.0}],
        condition=IfCondition(LaunchConfiguration('use_joystick'))
    )

    # Keyboard Node
    keyboard_node = ExecuteProcess(
        cmd=['python3', keyboard_script],
        output='screen',
        condition=IfCondition(LaunchConfiguration('use_keyboard'))
    )

    # Dingo Driver Node
    dingo_driver_node = ExecuteProcess(
        cmd=[
            'python3',
            driver_script,
            LaunchConfiguration('is_sim'),
            LaunchConfiguration('is_physical'),
            LaunchConfiguration('use_imu')
        ],
        output='screen'
    )

    return LaunchDescription([
        is_sim,
        is_physical,
        use_joystick,
        use_keyboard,
        serial_port,
        use_imu,
        lcd_node,
        joystick_node,
        keyboard_node,
        dingo_driver_node
    ])
