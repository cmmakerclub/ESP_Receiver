// Chiang Mai Maker Club Receiver

#include "CMMC_Receiver.h"
#include <Servo.h>

#define Motor_pin 14
#define Rudder_pin 12


//#define Receiver_Debug

Servo Motor;
Servo Rudder;


void setup() {
  receriver_init();
  pinMode(15, OUTPUT);

  Motor.attach(Motor_pin);
  Motor.write(90);

  Rudder.attach(Rudder_pin);
  Rudder.write(90);
}

uint32_t time_now, time_prev1;

void loop() {

  digitalWrite(15, 1);
  time_now = millis();
  if (time_now - time_prev1 >= 20) {
    time_prev1 += 20;

#ifdef Receiver_Debug
    Serial.print(Get_ChannelValue(1)); Serial.print("\t");
    Serial.print(Get_ChannelValue(2)); Serial.print("\t");
    Serial.print(Get_ChannelValue(3)); Serial.print("\t");
    Serial.print(Get_ChannelValue(4)); Serial.println("\t");
#endif

    Motor.write(30 + Get_ChannelValue(3) * 1.2f);
    Rudder.write(90 + Get_ChannelValue(1) * 0.6f);
  }
  digitalWrite(15, 0);

  receriver_loop();
}
