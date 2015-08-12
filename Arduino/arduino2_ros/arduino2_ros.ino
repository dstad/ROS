#include <ros.h>
#include <std_msgs/Int64.h>

const int buttonPin = 4;
int count = 0;

ros::NodeHandle nh;


void messageCb(const std_msgs::Int64& btn_msg)
{
  if(digitalRead(buttonPin) == LOW)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}

ros::Subscriber<std_msgs::Int64> sub("Topic_2", messageCb);

std_msgs::Int64 btn_msg2;
ros::Publisher pub("Topic_4", &btn_msg2);

int A = 2;

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(buttonPin, HIGH);
  digitalWrite(13, LOW);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  if (count == 5000)
  {
    count = 0;
    btn_msg2.data= A;
    pub.publish(&btn_msg2);
    nh.spinOnce();
  }
  else
  {
    count++;
  }
   
}
  
