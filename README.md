This is the final project of the Udacity Robotics Software Engineer Nanodegree

Your Home Service Robot
Now it’s time to simulate a full home service robot capable of navigating to pick up and deliver virtual objects. To do so, the add_markers and pick_objects node should be communicating. Or, more precisely, the add_markers node should subscribe to your odometry to keep track of your robot pose.

Modify the add_markers node as follows:

Initially show the marker at the pickup zone
Hide the marker once your robot reaches the pickup zone
Wait 5 seconds to simulate a pickup
Show the marker at the drop off zone once your robot reaches it

To run this program, run the following command in the terminal:

$ cd home/robond/catkin_ws/

$ source devel/setup.bash

$ catkin_make

$ cd home/robond/catkin_ws/src/scripts

$ ./home_service.sh

This project was completed by referencing the following sources:
1) https://github.com/huuanhhuynguyen/RoboND-Home-Service-Robot/tree/ec192e50c3646fef58dd62435fc8ea295b0141e1
2) https://github.com/anyuguo/Robotics-Software-Engineer-Udacity
3) https://github.com/AndreiMoiceanu29/Home-Service-Robot
4) https://github.com/andreapasetti/Robot---HomeServiceRobot