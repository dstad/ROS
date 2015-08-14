/*
 * rosserial Service Client
 */

#include <ros.h>
//#include <ros/time.h>
//#include <std_msgs/Empty.h>
#include <beginner_tutorials/srvtest.h>
//#include <stdlib.h>

int count = 0;
const int buttonPin = 14; 
ros::NodeHandle  nh;
using beginner_tutorials::srvtest;
ros::ServiceClient<srvtest::Request, srvtest::Response> client("service_client");

void setup()
{
  nh.initNode();
  nh.serviceClient(client);
  //nh.advertise(chatter);
  while(!nh.connected()) nh.spinOnce();
  nh.loginfo("Startup complete");
  //ros::Rate loop_rate(10);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(buttonPin, HIGH);
  digitalWrite(13, LOW);
}

void loop()
{
  //bool val = true;
  srvtest::Request req;
  srvtest::Response res;
  //req.A = 1;
  //printf("%d", res.B);
  //beginner_tutorials::srvtest srv;
  req.A = 1;
  
  if (count == 20)
  {
      count = 0;
      if (digitalRead(buttonPin) == LOW)
      {
        client.call(req,res);
        if(res.B == 2)
        {
        nh.loginfo("recieved response");
        digitalWrite(13, HIGH);
        }
        else
        {
        digitalWrite(13, LOW);
        //req.A = 0;
        }
      }
      else 
      {
        digitalWrite(13, LOW);
      }
      //req.A = 1;
  }
    
    
  
  //str_msg.data = res.output;
  //chatter.publish( &str_msg );
  nh.spinOnce();
  //loop_rate.sleep();
  count++;
  //delay(100);
}
