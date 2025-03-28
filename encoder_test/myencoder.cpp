#ifndef MYENCODER_C
#define MYENCODER_C

#include "myencoder.h"

Encoder encoderl(3, 11);
Encoder encoderr(4, 13);

//  encoder_init();


int encoder_read(int encoder_side)
{
  int templ;
  int tempr;
  switch(encoder_side)
  {
    case(0):
    templ = encoderl.read();
    return templ;
    break;
    case(1):
    tempr = encoderr.read();
    return tempr;
    break;
    
  }

}

int encoder_write(int encoder_side, int data)
{
  switch(encoder_side)
  {
    case(0):
    encoderl.write(data);
    break;
    case(1):
    encoderr.write(data);
    break;
  }
}

void encoder_init(void)
{
  encoder_write(left, 0);
  encoder_write(right,0);
}
#endif
