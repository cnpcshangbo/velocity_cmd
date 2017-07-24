#include <ros/ros.h>
#include <std_msgs/String.h> 
#include <stdio.h>
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/Vector3Stamped.h"

void gps_vel_cb(const geometry_msgs::TwistStamped &msg)
{
   ROS_INFO("gps_vel: [%f]", msg.twist.linear.x);

}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "comun");
   ros::NodeHandle n;
   
   // Subscriber to gps velocity
   ros::Subscriber gps_vel;

   // Subscriber to velocity_setter
   //ros::Subscriber velociy_setter

   gps_vel = n.subscribe("/mavros/global_position/raw/gps_vel", 1, gps_vel_cb);

   ros::Publisher chatter_pub = n.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",100);
   ros::Rate loop_rate(10);

   geometry_msgs::TwistStamped msg;

   while(ros::ok()){
       msg.header.stamp = ros::Time::now();
       msg.header.seq=1;
       msg.twist.linear.x = -0.05;
       msg.twist.angular.x = 1;
       ROS_INFO("velocity_setpoint: [%f]", msg.twist.linear.x);
       //ROS_INFO("msg.header.stamp: [%s]", msg.header.stamp.secs);
       chatter_pub.publish(msg);
       ros::spinOnce();
       loop_rate.sleep();
   }    
   return 0;
}
