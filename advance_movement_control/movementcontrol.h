#ifndef MOVEMENTCONTROL_H
#define MOVEMENTCONTROL_H

#include "myencoder.h"
#include "motor.h"
#include "sensor.h"

void turn(int direction_);
void turn_around(void);
void gofoward(void);
int adjustpower(void);
void pid_init(void);

#define P 1
#define D 5


#endif
