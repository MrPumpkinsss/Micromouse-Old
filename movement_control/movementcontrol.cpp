#ifndef MOVEMENTCONTROL_CPP
#define MOVEMENTCONTROL_CPP

#include "movementcontrol.h"



void turn(int direction_){
  switch(direction_){
  encoder_reset();
  case left:
  while(!(encoder_read(right)<-920)||(encoder_read(right)>920)){
      motor_set(left,-base_power);  //匀速
      motor_set(right,base_power);
  }
  break;
  case right:   
  while(!(encoder_read(right)<-920)||(encoder_read(left)>920)){
      motor_set(left,base_power);  //匀速
      motor_set(right,-base_power);
  }
  break;
  }
  delay(5);
  motor_reset();
  encoder_reset();
  delay(200);
}


#endif
