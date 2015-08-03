/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/

#include <ProTrinketKeyboard.h>  // Ensure the library is installed
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>


// Switches are connected from ground to these defined pins
const int right = 12 ;
const int up = 11;
const int down = 10;
const int left = 9;
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
     
void messageCb( const std_msgs::Empty& toggle_msg){
  // blink the led
}
ros::NodeHandle  nh;
std_msgs::String str_msg;
//ros::Publisher vel_pub_;
  geometry_msgs::Twist twist;
  
ros::Publisher pub("/turtle1/cmd_vel", &twist);
//ros::Subscriber<std_msgs::Empty> sub("/turtle1/cmd_vel", &messageCb);

void setup()
{
  //intialize the ros sub node
  nh.initNode();
 // nh.advertise(pub);
  //nh.subscribe(sub);
  // Declare button pins as inputs
  Serial.begin(9600);
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

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
 //nh("~");
  struct angular_ angular;
  struct linear_ linear;

  
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  if (digitalRead(right) == LOW)
  {
    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT);
    // this should move the keyboard to the right
    TrinketKeyboard.pressKey(0, 0);
    angular.x = 2;
    // this releases the key
  }

  if (digitalRead(up) == LOW)
  {
    // type out a string using the Print class
    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP);
    TrinketKeyboard.pressKey(0, 0);
    linear.x = 2;
  }
 if  (digitalRead(down)== LOW)
 {
   TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN);
   TrinketKeyboard.pressKey(0, 0);
    linear.x = -2;
 }
 
 if (digitalRead(left)== LOW)
 {
   TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT);
   TrinketKeyboard.pressKey(0, 0);
   angular.x = -2;
 }
 

 twist.linear.x = linear.x; twist.linear.y = 0; twist.linear.z = 0;
 twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = angular.z;
 pub.publish(&twist);
 
 Serial.print(right);
// Serial.print(right);
//pub.publish(&str_msg );
 nh.spinOnce();

 
 }
