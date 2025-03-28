#ifndef SENSOR_CPP
#define SENSOR_CPP

#include "sensor.h"


int sensor_read(int side){
  int bArray[5] = {0,0,0,0,0};
  int i,j;// 循环变量
  int bTemp;
  uint8_t iFilterLen = 5;
  for(i=0;i<=5;i++){
    switch(side){
      case left:
      bArray[i] = analogRead(left_ir);
      break;
      case center:
      bArray[i] = analogRead(center_ir);
      break;
      case right:
      bArray[i] = analogRead(right_ir);
      break;
    }
  }
  // 用冒泡法对数组进行排序
  for (j = 0; j < iFilterLen - 1; j ++)
  {
    for (i = 0; i < iFilterLen - j - 1; i ++)
    {
      if (bArray[i] > bArray[i + 1])
      {
        // 互换
        bTemp = bArray[i];
        bArray[i] = bArray[i + 1];
        bArray[i + 1] = bTemp;
      }
    }
  }
  // 计算中值
  if ((iFilterLen & 1) > 0)
  {
    // 数组有奇数个元素，返回中间一个元素
    bTemp = bArray[(iFilterLen + 1) / 2];
  }
  else
  {
    // 数组有偶数个元素，返回中间两个元素平均值
    bTemp = (bArray[iFilterLen / 2] + bArray[iFilterLen / 2 + 1]) / 2;
  }  
  return bTemp;
}

void sensor_cali(int *leftwall, int *rightwall){
  *leftwall = sensor_read(left);
  *rightwall = sensor_read(right);
  Serial.print("Sensor Calibration Success L/R");
  Serial.print(*leftwall);
  Serial.print("  ");
  Serial.println(*rightwall);
  //获取基准传感器读数
    delay(10);
}


#endif
