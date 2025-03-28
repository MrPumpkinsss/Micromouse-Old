#ifndef MOVEMENTCONTROL_CPP
#define MOVEMENTCONTROL_CPP

#include "movementcontrol.h"



void turn(int direction_){
  uint8_t i;
  switch(direction_){
  encoder_reset();
  case left: //左转
  while((encoder_read(left)>-920)||(encoder_read(right)<920)){
     Serial.println(encoder_read(left));
    motor_set(left,-slow_power);  //匀速
    motor_set(right,slow_power);
    Serial.print("lefting ");
  }
  break;
  case right:    //右转
  while((encoder_read(right)>-920)||(encoder_read(left)<920)){
    motor_set(left,slow_power);  //匀速
    motor_set(right,-slow_power);
    Serial.print("righting");
    Serial.println(encoder_read(left));
  }
  break;
  }
  motor_reset();
  delay(100);
}

void turn_around(void){
  turn(left);
  turn(left);  
}

void gofoward(void){  //前进一格
  uint8_t i;
  int ap = 0;
  ap = adjustpower();
  encoder_reset();
  while((encoder_read(right)<2400)||(encoder_read(right)>2400)){
//    while((encoder_read(right)<1000||(encoder_read(right)>1000))){
//      for(i=0;i<=base_power;i++){ //加速
//      motor_set(left,i+ap);
//      motor_set(right,i-ap);
//      delay(20);
//      Serial.println(ap);
//      }
      motor_set(0,(base_power-ap));  //匀速
      motor_set(1,(base_power+ap));
      Serial.print(base_power+ap);
      Serial.print("  ");
      Serial.println(base_power-ap);
      delay(100);
    }
//    for(i=base_power;i>=5;i-0-){  //减速
//      motor_set(left,i+ap);
//      motor_set(right,i-ap);
//      delay(20);
//    }
  
  motor_reset();
  encoder_reset();
}
int leftwallconst, rightwallconst;

void pid_init(void){
   sensor_cali(&leftwallconst,&rightwallconst);
   Serial.println("Pid Init Success");
}

int adjustpower(void){         //pd 电机转速修正值
  /*如果两边墙都没有 adjustpower = 0    0
   * 两面墙都有 跟右边                  1
   *  只有右墙 跟右边                   1
   * 只有左墙 跟左边                    2
  */
  int ap = 0;
  uint8_t temp = 0;
  int error = 0;
  if(sensor_read(right)<150){  //判断电机转速修正值的传感器数值应该以哪面墙为基准
     temp = 1;
  }
  else if(sensor_read(left)<150){
      temp = 2;
  }
  else temp = 0;
  Serial.print("wall status: ");
  Serial.println(temp);
  switch(temp){
    case 0:
    error = 0;
    break;
    case 1:
    error = rightwallconst - sensor_read(right);
    break;
    case 2:
    error = leftwallconst - sensor_read(left);
    break;
  }
  ap = P*error;
  Serial.print("error = ");
  Serial.print(error);
  Serial.print("ap = ");
  Serial.println(ap);

  return ap * 0.001;
}
#endif
