#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"

#define left 0
#define center 1
#define right 2

#define left_ir A1
#define center_ir A2
#define right_ir A3


int sensor_read(int side); //中值滤波
void sensor_cali(int *bArray);

#endif
