#include "movementcontrol.h"
#include "motor.h"

void setup() {
  Serial.begin(9600);
  encoder_init();
  motor_init();
  pid_init();
  Serial.println("----------------------s");
  Serial.println("Test Begin");
}

void loop() {
  Serial.println("1");
  turn(left);
  Serial.println("2");
  delay(1000);
  turn(right);
  Serial.println("3");
  delay(1000);
  turn(left);
  turn(left);
  delay(1000);
  turn(right);
  turn(right);
  delay(1000);
//  uint8_t i;
//  delay(1000);
//  for(i=0;i<=10;i++){
//  gofoward();
//  delay(100);
//  }
//  delay(2000);

}
