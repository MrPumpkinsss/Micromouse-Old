/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */


#include "movementcontrol.h"

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability


//   avoid using pins with LEDs attached

void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(200);
  Serial.println("begin");
  motor_init();
  encoder_init();

  Serial.println("----------------------s");
}

void loop() {
  uint8_t i;
  for(i = 0;i<=20;i++){
    motor_set(left,i);
    motor_set(right,i);
    delay(150);
  }
//  turn(left);
//  delay(1000);
//  turn(right);
//  delay(1000);
//  turn(left);
//  turn(left);
//  delay(1000);
//  turn(right);
//  turn(right);
//  delay(1000);
}
