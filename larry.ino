#include "./motor_relay.h"
#include "./sonar.h"
int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
const int default_speed=400;//define the spead of motor
const int max_speed = 700;
const int pingPin = 38;

MotorRelay motor_relay (9, 10, 8, 11, 12, 13);
Sonar sonar (38);

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
    int forward_speed = 350;
    int reverse_speed = 100;
    int right_speed = 100;
    int minimum_distance_from_obstical = 5;
    int back_up_distance = 7;
    // As long as we're 5" away from an obstical move forward
    while(sonar.inches_from_obstical() > minimum_distance_from_obstical) {
        motor_relay.forward(forward_speed);
    }
    // As long as we're closer to 5" move backwards
    while(sonar.inches_from_obstical() < back_up_distance) {
        motor_relay.backward(reverse_speed);
    }
    // Turn Right
    for(int i = 0; i<=5; i++){
       motor_relay.right(right_speed);
    }
}