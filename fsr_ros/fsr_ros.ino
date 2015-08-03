/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

int FsrPin = 0;
int FsrReading;
char val[5];

void messageCb( const std_msgs::Empty& toggle_msg){
  // blink the led
}

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher pub("chatter", &str_msg);
ros::Subscriber<std_msgs::Empty> sub("response", &messageCb );

//char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
  pinMode(13, OUTPUT);
}



void loop()
{
  if(  FsrReading = analogRead(FsrPin)){
       digitalWrite(13, HIGH-digitalRead(13)); 
  }
  

 itoa(FsrReading, val, 10);
 str_msg.data = val;
        
 
  pub.publish(&str_msg );
  nh.spinOnce();
  delay(500);
}














