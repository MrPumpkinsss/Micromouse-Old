/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include "myencoder.h"
#include "motor.h"

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability


//   avoid using pins with LEDs attached

void setup() {

  Serial.begin(9600);
  encoder_init();
  motor_init();

}

void loop() {
     motor_set(left,70);
     motor_set(right,80);
     
//     Serial.print(" ");
//     Serial.print(encoder_read(left));
//     Serial.print(" ");
//     Serial.println(encoder_read(right));
// 
}
