#! /bin/bash

rm ./src/dingo_description/dingo_description/urdf/dingo_description.urdf
rm ./src/dingo_description/dingo_description/urdf/dingo_description.sdf
bash & source /opt/ros/jazzy/setup.bash
source install/setup.bash
xacro ./src/dingo_description/dingo_description/urdf/dingo_description.xacro > ./src/dingo_description/dingo_description/urdf/dingo_description.urdf
gz sdf -p ./src/dingo_description/dingo_description/urdf/dingo_description.urdf > ./src/dingo_description/dingo_description/urdf/dingo_description.sdf
exit

