#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "const.h"

void motor_set(int side, int speed_);
void motor_init();

#define left_motor_pin1 6
#define left_motor_pin2 7
#define right_motor_pin1 9
#define right_motor_pin2 8

#endif
