#!/bin/sh
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=\"$(rospack find map)/testworld.world\"" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=\"$(rospack find map)/map.yaml\"" &
sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "rosrun pick_objects pick_objects" &
sleep 5
xterm -e "rosrun home_service home_service"