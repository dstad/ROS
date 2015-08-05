/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/

//#include <ProTrinketKeyboard.h>  // Ensure the library is installed

//#ifndef __AVR_ATmega328P__
//#define __AVR_ATmega328P__


#include <ArduinoHardware.h>
#include <ros.h>
//#include <std_msgs/String.h>
//#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>


// Switches are connected from ground to these defined pins
const int right = 17;
const int up = 16;
const int down = 15;
const int left = 14;
int count;
/*************************
 class TeleopTurtle
  {
  public:
    TeleopTurtle();
    void keyLoop();
    double linear_, angular_, l_scale_, a_scale_;
  private:
     };
***************************/

/********************
struct linear_ { 
     int x = 0; 
     int y = 0; 
     int z = 0;
   };
     
struct angular_ { 
     int x = 0; 
     int y = 0; 
     int z = 0;
   };
**********************/     
//void messageCb( const std_msgs::Empty& toggle_msg)
//{
  // blink the led
//}

ros::NodeHandle nh;
//std_msgs::String str_msg;
//ros::Publisher vel_pub_;
geometry_msgs::Twist twist;
ros::Publisher pub("/turtle1/cmd_vel", &twist);  
//ros::Subscriber<std_msgs::Empty> sub("/turtle1/cmd_vel", &messageCb);

/***********************************
TeleopTurtle::TeleopTurtle():
  linear_(0),
  angular_(0),
  l_scale_(2.0),
  a_scale_(2.0)
  {
    //nh.getParam("scale_angular", a_scale_, 1 );
    //nh.getParam("scale_linear", l_scale_, 1 );
  }

/**********************
{
  nh.param("scale_angular", a_scale_, a_scale_);
  nh.param("scale_linear", l_scale_, l_scale_);
}
******************/
void setup()
{
  //intialize the ros sub node
  nh.initNode();
  nh.advertise(pub);
  //nh.subscribe(sub);
  // Declare button pins as inputs
  //Serial.begin(57600);
  pinMode(right, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(right, HIGH);
  digitalWrite(up, HIGH);
  digitalWrite(down, HIGH);
  digitalWrite(left, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed
  
  //TeleopTurtle teleop_turtle;

  //teleop_turtle.keyLoop();

  // start USB stuff
  //TrinketKeyboard.begin();
}

void loop()
{
    //twist.angular.z = twist.linear.x = 0;
  //TeleopTurtle teleop_turtle;
  //TeleopTurtle::keyLoop();
   //nh("~");
  //struct angular_ angular;
  //struct linear_ linear;
  
  //teleop_turtle.linear_=teleop_turtle.angular_=0;
  
  //TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  

 //twist.linear.x = linear.x; twist.linear.y = 0; twist.linear.z = 0;
 //twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = angular.z;
 //twist.angular.z = teleop_turtle.a_scale_*teleop_turtle.angular_;
 //twist.linear.x = teleop_turtle.l_scale_*teleop_turtle.linear_;
 if (count == 7500)
 {
  if (digitalRead(right) == LOW)
  {
    //TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT);
    twist.angular.z =  -2.0;
    pub.publish(&twist);
    // this should move the keyboard to the right
    //TrinketKeyboard.pressKey(0, 0);
    // this releases the key
  }

  else if (digitalRead(up) == LOW)
  {
    // type out a string using the Print class
    //TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP);
    twist.linear.x = 2.0;
    pub.publish(&twist);
    //TrinketKeyboard.pressKey(0, 0);
  }
  
 else if  (digitalRead(down)== LOW)
 {
   //TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN);
   twist.linear.x = -2.0;
   pub.publish(&twist);
   //TrinketKeyboard.pressKey(0, 0);
 }
 
 else if (digitalRead(left)== LOW)
 {
   //TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT);
   twist.angular.z = 2.0;
   pub.publish(&twist);
   //TrinketKeyboard.pressKey(0, 0);
 }

 else
 {
  twist.angular.z = 0;
  twist.linear.x = 0;
 }
  
  count = 0;
 }

 else 
 {
  count++;
 }
 
 
 //Serial.print(right);
// Serial.print(right);
//pub.publish(&str_msg );
 nh.spinOnce(); 



}
 

 

 //#endif
