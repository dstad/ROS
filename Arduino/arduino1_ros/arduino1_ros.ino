#include <ros.h>
#include <std_msgs/Int64.h>

const int buttonPin = 4;
int count = 0;

ros::NodeHandle nh;


void messageCb(const std_msgs::Int64& btn_msg2)
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

ros::Subscriber<std_msgs::Int64> sub("Topic_3", messageCb);

std_msgs::Int64 btn_msg;
ros::Publisher pub("Topic_1", &btn_msg);

int A = 1;

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
    btn_msg.data= A;
    pub.publish(&btn_msg);
    nh.spinOnce();
  }
  else
  {
    count++;
  }
   
}
  
