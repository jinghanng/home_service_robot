#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <complex>

// Positions, orientation and distance threshold of robot from goal in meter
float pickUpGoal[3] = { 0.0, 1.0, 1.0 };
float dropOffGoal[3] = { 0.0, 5.0, 1.0 };
float threshold = 0.2;

// Flags
bool pickUp = false;
bool dropOff = false;
bool haveObject = false;


// Callback function to check if robot has reached the location of pick up or drop off zone.
void callback(const nav_msgs::Odometry::ConstPtr& msg)
{
  if(std::abs(pickUpGoal[0] -msg->pose.pose.position.x) < threshold && std::abs(pickUpGoal[1] -msg->pose.pose.position.y) < threshold)
  {
    if(!pickUp)
    {
      pickUp = true;
    }
  }
  else
  {
    pickUp = false;
  }


  if (std::abs(dropOffGoal[0] -msg->pose.pose.position.x) < threshold && std::abs(dropOffGoal[1] -msg->pose.pose.position.y) < threshold)
  { 
    if(!dropOff)
    {
      dropOff = true;
    }
  }
  else
  { 
    dropOff = false;
  }
}

int main( int argc, char** argv )
{
  ROS_INFO("Main");
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("odom", 1000, callback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "odom";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one

    marker.ns = "goal";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickUpGoal[0];
    marker.pose.position.y = pickUpGoal[1];
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = pickUpGoal[2];

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    marker_pub.publish(marker);
    ROS_INFO("Showing marker at the pick-up location.");

    // Execute Pick-Up
    while(!pickUp)
    {
      ros::spinOnce();
    }

    if(pickUp & !haveObject)
    {
      ros::Duration(5.0).sleep();
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
      ROS_INFO("Removing marker at the pick-up location.");
      haveObject = true;
    }

    // Execute Drop-Off
    while(!dropOff)
    {
      ros::spinOnce();
    }

    if(dropOff & haveObject)
    {
      marker.pose.position.x = dropOffGoal[0];
      marker.pose.position.y = dropOffGoal[1];
      marker.pose.orientation.w = dropOffGoal[2];
      ros::Duration(5.0).sleep();
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
      ROS_INFO("Showing marker at the drop-off location.");
      haveObject = false;
      
      ros::Duration(5.0).sleep();
      return 0;
    }

  }

}