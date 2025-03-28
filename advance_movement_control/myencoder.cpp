#ifndef MYENCODER_CPP
#define MYENCODER_CPP

#include "myencoder.h"

Encoder encoderl(3, 11);
Encoder encoderr(2, 10);

//  encoder_init();



int encoder_read(int encoder_side)
{
  delay(10);
  int temp;
  switch(encoder_side)
  {
    case(0):
    temp = encoderl.read();
    break;
    case(1):
    temp = encoderr.read();
    break;
  }
  return temp;
  delay(10);
}

int encoder_write(int encoder_side, int data)
{
  delay(10);
  switch(encoder_side)
  {
    case(0):
    encoderl.write(data);
    break;
    case(1):
    encoderr.write(data);
    break;
  }
  delay(10);
}

void encoder_init(void)
{
  delay(10);
  encoder_write(left, 0);
  encoder_write(right,0);
  delay(10);
}

void encoder_reset(void){
  delay(10);
  encoder_write(left, 0);
  encoder_write(right, 0);
  delay(10);
}


#endif
