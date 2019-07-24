#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tf2PosePublisher");

  ros::NodeHandle node;

  //ros::Publisher posePublisher = node.advertise<geometry_msgs::PoseStamped>("mavros/vision_pose/pose", 100);
  ros::Publisher posePublisher = node.advertise<geometry_msgs::PoseStamped>("orb/pose", 100);

  tf2_ros::Buffer tfBuffer;
  tf2_ros::TransformListener tfListener(tfBuffer);

  ros::Rate rate(30);

  bool gotFirst = false;
  
  while (ros::ok()) {
    ros::spinOnce();

    geometry_msgs::TransformStamped transformStamped;

    try {
      transformStamped = tfBuffer.lookupTransform("world", "IMU", ros::Time(0));

      gotFirst = true;
    }
    catch (tf2::TransformException &ex) {

      if (gotFirst) {
      	ROS_WARN("%s",ex.what());
      }

      ros::Duration(1.0).sleep();

      continue;
    }
	
    geometry_msgs::PoseStamped pose;

    pose.pose.position.x = transformStamped.transform.translation.x;
    pose.pose.position.y = transformStamped.transform.translation.y;
    pose.pose.position.z = transformStamped.transform.translation.z;
    
    pose.pose.orientation.x = transformStamped.transform.rotation.x;
    pose.pose.orientation.y = transformStamped.transform.rotation.y;
    pose.pose.orientation.z = transformStamped.transform.rotation.z;
    pose.pose.orientation.w = transformStamped.transform.rotation.w;

    pose.header.stamp = ros::Time::now();
    
    posePublisher.publish(pose);
    rate.sleep();
  }

  return 0;
};

