/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */


#include "movementcontrol.h"
#include "decision.h"

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability


//   avoid using pins with LEDs attached

int sensor_standard[2];

void setup() {
  Serial.begin(9600);
  encoder_init();
  motor_init();
  sensor_cali(sensor_standard[2]);

  delay(1000);
}
uint8_t possible[4];

void loop() {
  //possible_direction(possible);
  Serial.print(possible[0]);
  Serial.print(possible[1]);
  Serial.print(possible[2]);
  Serial.println(possible[3]);
}
