#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "const.h"
#include "IIC.h"

void motor_set(int side, int speed_);
void motor_init();
void motor_reset();

#endif
