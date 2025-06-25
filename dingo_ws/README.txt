run python3 src/dingo_input_interfacing/src/dingo_input_interfacing/Keyboard.py
in a separate terminal

run ros2 launch dingo dingo.launch.py use_keyboard:=0
(this is because keyboard listener doesn't work simulateneously with ros2 launch)

run ros2 launch dingo_gazebo simulation.launch.py to see the robot move

TODO:
add physics and gazebo behavior in urdf (collision)
integrate with hardwareInterface in real life with arduino
