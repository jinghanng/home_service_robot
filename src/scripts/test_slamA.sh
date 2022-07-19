#!/bin/sh
xterm -e "roslaunch my_robot world.launch world_file:=/home/robond/catkin_ws/src/map/sampleworld.world" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"