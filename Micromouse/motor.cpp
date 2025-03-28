#ifndef MOTOR_CPP
#define MOTOR_CPP


#include "motor.h"


int8_t p1[4]={0,0,0,0};

void motor_set(int side, int speed_){
  p1[side] = -speed_;
  WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR,p1,2);
  delay(1);
}

uint8_t MotorType = MOTOR_TYPE_TT; //设定电机类型
uint8_t MotorEncoderPolarity = 1;
uint8_t p0[4] = {0,0,0,0};

void motor_init(){
  Wire.begin();
  printf_begin();
  delay(200);
  WireWriteDataArray(MOTOR_TYPE_ADDR,&MotorType,1);//在电机类型地址中写入电机类型编号
  delay(5);
  WireWriteDataArray(MOTOR_ENCODER_POLARITY_ADDR,&MotorEncoderPolarity,1);
  motor_set(left,0);
  motor_set(right,0);
  WireWriteDataArray(MOTOR_FIXED_PWM_ADDR,p0,4);
  Serial.println("Motor Init Success");
}

void motor_reset(){
  WireWriteDataArray(MOTOR_ENCODER_POLARITY_ADDR,&MotorEncoderPolarity,1);
  motor_set(left,0);
  motor_set(right,0);
  WireWriteDataArray(MOTOR_FIXED_PWM_ADDR,p0,4);
  Serial.println("Motor Reset Success");
}

#endif
