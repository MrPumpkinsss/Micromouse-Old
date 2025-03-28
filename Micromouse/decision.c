#ifndef DECISION_C
#define DECISION_C

#include "decision.h"

uint8_t current_direction = North;
extern uint8_t wall[3];
uint8_t direction_[3];


void possible_direction(uint8_t *bArray){
  wall_detect(wall);
  switch(current_direction){
    case North:
    bArray[0] = !wall[1];
    bArray[1] = !wall[2];
    bArray[2] = 0;
    bArray[3] = !wall[0];
    break;
    case East:
    bArray[0] = !wall[0];
    bArray[1] = !wall[1];
    bArray[2] = !wall[2];
    bArray[3] = 0;
    break;
    case South:
    bArray[0] = 0;
    bArray[1] = !wall[0];
    bArray[2] = !wall[1];
    bArray[3] = !wall[2];
    break;
    case West:
    bArray[0] = !wall[2];
    bArray[1] = 0;
    bArray[2] = !wall[0];
    bArray[3] = !wall[1];
    break;
  }
  
}


#endif 
