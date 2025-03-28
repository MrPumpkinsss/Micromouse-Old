#ifndef MOVEMENTCONTROL_CPP
#define MOVEMENTCONTROL_CPP

#include "movementcontrol.h"

extern uint8_t current_direction;

void turn(int direction_){
  uint8_t i;
  switch(direction_){
  encoder_reset();
  case left:
  while(!(encoder_read(right)<-970||(encoder_read(right)>970))){
    while(!(encoder_read(right)<-770||(encoder_read(right)>770))){
      for(i=0;i<=base_power;i++){ //加速
      motor_set(left,-i);
      motor_set(right,i);
      delay(20);
      }
      motor_set(left,-base_power);  //匀速
      motor_set(right,base_power);
    }
    for(i=base_power;i>=5;i--){  //减速
      motor_set(left,-i);
      motor_set(right,i);
      delay(20);
    }
  }
  if(current_direction != 0){
    current_direction = current_direction - 1;
  }
  else{ 
    current_direction = current_direction + 3;
  }
  motor_reset();
  encoder_reset();
  break;
  case right:   
  while(!(encoder_read(right)<-970||(encoder_read(left)>970))){
    while(!(encoder_read(right)<-770||(encoder_read(right)>770))){
      for(i=0;i<=base_power;i++){ //加速
      motor_set(left,i);
      motor_set(right,-i);
      delay(20);
      }
      motor_set(left,base_power);  //匀速
      motor_set(right,-base_power);
    }
    for(i=base_power;i>=5;i--){  //减速
      motor_set(left,i);
      motor_set(right,-i);
      delay(20);
    }
  }
  if(current_direction != 3){
    current_direction = current_direction + 1;
  }
  else{ 
    current_direction = current_direction - 3;
  }
  motor_reset();
  encoder_reset();
  break;
  }
  delay(100);
}

void turn_around(void){
  turn(left);
  turn(left);  
}

void gofoward(void){
  uint8_t i;
  int ap = 0;
  ap = adjustpower();
  encoder_reset();
  while(!(encoder_read(right)<1400||(encoder_read(right)>1400))){
    while(!(encoder_read(right)<1000||(encoder_read(right)>1000))){
      for(i=0;i<=base_power;i++){ //加速
      motor_set(left,i+ap);
      motor_set(right,i-ap);
      delay(20);
      }
      motor_set(left,base_power+ap);  //匀速
      motor_set(right,base_power-ap);
    }
    for(i=base_power;i>=5;i--){  //减速
      motor_set(left,i+ap);
      motor_set(right,i-ap);
      delay(20);
    }
  }
  motor_reset();
  encoder_reset();
  delay(100);
}

extern int sensor_standard[2];

//void adjustpower(int side){  //pd 电机转速修正值
//  int ap;
//  switch(side){
//    case left:
//    
//    break;
//    case right:
//    
//    break;
//  }
//  return ap;
//}

int adjustpower(void){         //pd 电机转速修正值
  /*如果两边墙都没有 adjustpower = 0    0
   * 两面墙都有 跟右边                  1
   *  只有右墙 跟右边                   1
   * 只有左墙 跟左边                    2
  */
  int ap;
  uint8_t temp = 0;
  int error;
  if(sensor_read(right)<200){  //判断电机转速修正值的传感器数值应该以哪面墙为基准
     temp = 1;
  }
  else if(sensor_read(left)<200){
      temp = 2;
  }
  else temp = 0;
  switch(temp){
    case 0:
    error = 0;
    break;
    case 1:
    error = sensor_standard[1] - sensor_read(right);
    break;
    case 2:
    error = sensor_standard[0] - sensor_read(left);
    break;
    ap = P*error;
  }
  return ap;
}
#endif
