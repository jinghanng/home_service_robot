This is the final project of the Udacity Robotics Software Engineer Nanodegree

#Home Service Robot
The project simulates a full home service robot capable of navigating to pick up and deliver virtual objects. To do so, the add_markers and pick_objects node should be communicating. Or, more precisely, the add_markers node should subscribe to your odometry to keep track of your robot pose.

##Installation

$ sudo apt-get update && apt-get upgrade

$ sudo apt-get install xterm

To turn the shell scripts in the scripts folder into an executable and then launch it, run the following:

$ chmod +x launch.sh

$ ./launch.sh

To run this program, run the following command in the terminal:

$ cd home/robond/catkin_ws/

$ source devel/setup.bash

$ catkin_make

$ cd home/robond/catkin_ws/src/scripts

$ ./home_service.sh

##Packages

The gmapping package provides laser-based SLAM (Simultaneous Localization and Mapping), as a ROS node called slam_gmapping. With slam_gmapping, one can create a 2-D occupancy grid map (like a building floorplan) from laser and pose data collected by a mobile robot.
```
https://github.com/ros-perception/slam_gmapping
```

The turtlebot_teleop package provides teleoperation using joysticks or keyboard.
```
https://github.com/turtlebot/turtlebot
```

The turtlebot_rviz_launchers package supports user side interactions with the turtlebot. It allows for the visualization of the entire robot model, laser data, particle cloud and a map.
```
https://github.com/turtlebot/turtlebot_interactions
```

The turtlebot_gazebo package was used to launch the gazebo simulation of the turtlebot.
```
https://github.com/turtlebot/turtlebot_simulator
```

This project was completed by referencing the following sources:
1) https://github.com/huuanhhuynguyen/RoboND-Home-Service-Robot/tree/ec192e50c3646fef58dd62435fc8ea295b0141e1
2) https://github.com/anyuguo/Robotics-Software-Engineer-Udacity
3) https://github.com/AndreiMoiceanu29/Home-Service-Robot
4) https://github.com/andreapasetti/Robot---HomeServiceRobot