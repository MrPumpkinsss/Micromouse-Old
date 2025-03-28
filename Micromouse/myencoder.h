#ifndef MYENCODER_H
#define MYENCODER_H

#include "Arduino.h"
#include "const.h"
#include <Encoder.h>



#define left_encoder_pin1 3
#define left_encoder_pin2 11

#define right_encoder_pin1 2
#define right_encoder_pin2 10

void encoder_init(void);
int encoder_read(int encoder_side);
int encoder_write(int encoder_side, int data);
void encoder_reset(void);

#endif
