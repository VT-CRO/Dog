import os

from ament_index_python.packages import get_package_share_directory
from launch.actions import TimerAction
from launch.substitutions import TextSubstitution
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess, RegisterEventHandler
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.event_handlers import OnProcessExit
from launch.substitutions import Command, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

from launch_ros.actions import Node

def generate_launch_description():

    # Use your package name
    package_name = 'dingo_gazebo'

    robot_description_content = Command([
        'xacro ',
        PathJoinSubstitution([
            FindPackageShare('dingo_description'),
            'urdf',
            'dingo.urdf.xacro'
        ])
    ])

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description_content, 'use_sim_time': True}],
        output='screen'
    )

    # World file path
    default_world = os.path.join(
        get_package_share_directory(package_name),
        'worlds',
        'empty.world'
    )
    world = LaunchConfiguration('world')

    world_arg = DeclareLaunchArgument(
        'world',
        default_value=default_world,
        description="World to load"
    )

    gz_args = LaunchConfiguration('gz_args')

    gz_args_arg = DeclareLaunchArgument(
        'gz_args',
        default_value=['-r -v4 ', world],
        description='Arguments for Gazebo'
    )

    # Launch Gazebo Harmonic via ros_gz_sim
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(
                get_package_share_directory('ros_gz_sim'),
                'launch',
                'gz_sim.launch.py'
            )
        ]),
        launch_arguments={        
            'gz_args': gz_args,
            'on_exit_shutdown': 'true'
        }.items()
    )

    # Spawn robot in Gazebo Harmonic
    
    spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-topic', 'robot_description',
            '-entity', 'dingo',
            '-z', '0.3'
        ],
        output='screen'
    )

    # Joint State Broadcaster
    joint_state_broadcaster = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active',
             'joint_state_broadcaster'],
        output='screen'
    )

    # ros2_control controller spawners — minimal version
    controllers = [
        # 'joint_states_controller',
        'fl_leg_group',
        'fr_leg_group',
        'rl_leg_group',
        'rr_leg_group',
    ]

    controller_spawners = [
        TimerAction(
            period=5.0,   # wait 5 seconds
            actions=[
                Node(
                    package="controller_manager",
                    executable="spawner",
                    arguments=[ctrl],
                    output="screen"
                )
            ]
        )
        for ctrl in controllers
    ]

    bridge_params = os.path.join(get_package_share_directory(package_name),'config','gz_bridge.yaml')
    
    ros_gz_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            '--ros-args',
            '-p',
            f'config_file:={bridge_params}'
        ],
    )

    return LaunchDescription([
        world_arg,
        gz_args_arg,
        gazebo,
        robot_state_publisher,
        spawn_entity,
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[joint_state_broadcaster], 
            ) # joint_state_broadcaster starts after entity is spawned
        ),
        ros_gz_bridge
    ] + controller_spawners )
