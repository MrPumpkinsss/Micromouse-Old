#include "sensor.h"

int sensor_standard[2] = {0,0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor_cali(sensor_standard);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("L / C / R ");
  Serial.print(sensor_read(left));
  Serial.print(" ");
  Serial.print(sensor_read(center));
  Serial.print(" ");
  Serial.println(sensor_read(right));
}
