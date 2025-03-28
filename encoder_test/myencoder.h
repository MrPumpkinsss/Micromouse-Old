#ifndef MYENCODER_H
#define MYENCODER_H

#include "Arduino.h"
#include "const.h"
#include <Encoder.h>

#define left 0
#define right 1

#define left_encoder_pin1 10
#define left_encoder_pin2 11

#define right_encoder_pin1 12
#define right_encoder_pin2 13

void encoder_init(void);
int encoder_read(int encoder_side);
int encoder_write(int encoder_side, int data);


#endif
