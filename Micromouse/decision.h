#ifndef DECISION_H
#define DECISION_H

#include "Arduino.h"
#include "maze.h"
#include "sensor.h"

#define North 0
#define East 1
#define South 2
#define West 3

void possible_direction(uint8_t *bArray);
  

#endif 
