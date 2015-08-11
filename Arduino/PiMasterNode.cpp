#include "ros/ros.h"
#include "std_msgs/Int64.h"

int count = 0;

//ros::init(argc, argv, "listener_and_talker_node");

//ros::NodeHandle nh;

//ros::Publisher pub = nh.advertise<std_msgs::Int64>("Topic_2", 1000); 
	
//ros::Publisher pub2 = nh.advertise<std_msgs::Int64>("Topic_3", 1000); 

ros::Publisher pub;

ros::Publisher pub2; 

void messageCb(const std_msgs::Int64::ConstPtr& btn_msg)
	{
		pub.publish(btn_msg);
	}

void messageCb2(const std_msgs::Int64::ConstPtr& btn_msg2)
	{
		pub2.publish(btn_msg2);
	}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener_and_talker_node");
	
	ros::NodeHandle nh;
	
	pub = nh.advertise<std_msgs::Int64>("Topic_2", 1000);
	
	pub2 = nh.advertise<std_msgs::Int64>("Topic_3", 1000);
	
	ros::Subscriber sub = nh.subscribe("Topic_1", 1000, messageCb);
	
	ros::Subscriber sub2 = nh.subscribe("Topic_4", 1000, messageCb2);
	
	ROS_INFO("Ready");
	
	ros::spin();
	
	ros::Rate loop_rate(10);
	
	while (ros::ok())
	{
		ros::spinOnce();
		
		loop_rate.sleep();
		++count;
	}
	
	return 0;
}


	
	
