# velocity_cmd

[![Join the chat at https://gitter.im/velocity_cmd/Lobby](https://badges.gitter.im/velocity_cmd/Lobby.svg)](https://gitter.im/velocity_cmd/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

# Introduction
This project send topic to set velocity to ardupilot via mavros and displays actual (gps) velocity. 
Those information are useful for system identification for velocity model.
This project is originally made to work with the following tutorial for identification of the velocity model.
http://docs.erlerobotics.com/simulation/vehicles/erle_copter/tutorial_5

# System requirements
* Ubuntu 14.04.5
* ROS Indigo
* Configure the simulation environment following: http://docs.erlerobotics.com/simulation/configuring_your_environment

# Usages
Suppose the ROS catkin workspace is `~/simulation/ros_catkin_ws/`.

`cd ~/simulation/ros_catkin_ws/`

## Edit the source file
`gedit ~/simulation/ros_catkin_ws/src/velocity_cmd/velocity_cmd.cpp`

## Make
```
cd ~/simulation/ros_catkin_ws/
catkin_make --pkg velocity_cmd
```
## Run
```
roscore
cd ~/simulation/ros_catkin_ws/
source ./devel/setup.bash 
rosrun velocity_cmd velocity_cmd 
```

## Topic echo
`rostopic echo /mavros/setpoint_velocity/cmd_vel`
