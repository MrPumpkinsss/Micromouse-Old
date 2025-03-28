#ifndef MOVEMENTCONTROL_H
#define MOVEMENTCONTROL_H

#include "myencoder.h"
#include "motor.h"
#include "sensor.h"
#include "decision.h"

void turn(int direction_);
void turn_around(void);
void gofoward(void);
int adjustpower(void);


extern int sensor_standard[2];

#define P 0.05
#define D 5


#endif
