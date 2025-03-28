#ifndef MOTOR_CPP
#define MOTOR_CPP


#include "motor.h"

// 引脚命名

void motor_set(int side, int speed_){
  switch(side){
    case left:
    if(speed_ >= 0){
      //analogWrite(left_motor_pin1,speed_*2.55);
      analogWrite(left_motor_pin1,speed_*2.55);
      digitalWrite(left_motor_pin2,LOW);
    }
//    else{
//      analogWrite(left_motor_pin1,0);
//      digitalWrite(left_motor_pin1,LOW);
//      analogWrite(left_motor_pin2,speed_*2.55);
//    }
    break;
    case right:
    if(speed_ >= 0){
      analogWrite(right_motor_pin1,speed_*2.55);
      digitalWrite(right_motor_pin2,LOW);
    }
//    else{
//      analogWrite(right_motor_pin1,0);
//      analogWrite(right_motor_pin2,speed_*2.55);
//    }
    break;
  }
}

void motor_init(){
    pinMode(left_motor_pin1,OUTPUT);
    pinMode(left_motor_pin2,OUTPUT);
    pinMode(right_motor_pin1,OUTPUT);
    pinMode(right_motor_pin2,OUTPUT);
}

#endif
