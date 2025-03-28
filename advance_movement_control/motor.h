#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "const.h"
#include "IIC.h"

#define left 0
#define right 1

void motor_set(int side, int speed_);
void motor_init(void);
void motor_reset(void);

#endif
