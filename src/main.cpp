#include "MPU6050.h"
 
#include <Arduino.h>

MPU6050 mpu;
 
void setup() {
    Serial.begin(230400);

    Serial.println("MPU6050 initialize");
 
    mpu.initialize();
    Serial.println("MPU6050 testConnection");
 
    while(mpu.testConnection() == false) {
        Serial.println("MPU6050 test failed");
        delay(1000);
    }
    Serial.println("MPU6050 test passed");   
}

void loop() {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;    
    int16_t mx, my, mz;    

    mpu.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);

    Serial.print("A:\t");
    Serial.print(ax);Serial.print("\t");
    Serial.print(ay);Serial.print("\t");
    Serial.print(az);Serial.print("\t");

    Serial.print("G:\t");
    Serial.print(gx);Serial.print("\t");
    Serial.print(gy);Serial.print("\t");
    Serial.print(gz);Serial.print("\t");
    
    Serial.print("M:\t");
    Serial.print(mx);Serial.print("\t");
    Serial.print(my);Serial.print("\t");
    Serial.println(mz);
    delay(500);
}
 