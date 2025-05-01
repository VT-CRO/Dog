#! /bin/bash

rm ./src/leg1_description/leg1_description/urdf/leg1_description.urdf
rm ./src/leg1_description/leg1_description/urdf/leg1_description.sdf
bash & source /opt/ros/jazzy/setup.bash
source install/setup.bash
xacro ./src/leg1_description/leg1_description/urdf/leg1_description.xacro > ./src/leg1_description/leg1_description/urdf/leg1_description.urdf
gz sdf -p ./src/leg1_description/leg1_description/urdf/leg1_description.urdf > ./src/leg1_description/leg1_description/urdf/leg1_description.sdf
exit

