/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include "const.h"
#include "myencoder.h"

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

//   avoid using pins with LEDs attached


#define left_motor_pin1 7
#define left_motor_pin2 6
#define right_motor_pin1 8
#define right_motor_pin2 9
  
void setup() {

  Serial.begin(9600);
  encoder_init();
  Serial.println("Basic Encoder Test:");
  pinMode(left_motor_pin1,OUTPUT);
    pinMode(left_motor_pin2,OUTPUT);
    pinMode(right_motor_pin1,OUTPUT);
    pinMode(right_motor_pin2,OUTPUT);
}


void loop() {
  digitalWrite(left_motor_pin1,HIGH);
  digitalWrite(left_motor_pin2,LOW);
  digitalWrite(right_motor_pin1,HIGH);
  digitalWrite(right_motor_pin2,LOW);
  Serial.print(encoder_read(left));
  Serial.print(" ");
  Serial.println(encoder_read(right));
}
