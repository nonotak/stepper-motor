#ifndef StepperManage_h
#define StepperManage_h

#include "Arduino.h"
#include <Adafruit_MotorShield.h>

class StepperManager
{
  public:
    StepperManager(Adafruit_MotorShield, int x, int y);
    void move(int x, int y);
    void reset();
  private:
    int _x;
    int _y;
    Adafruit_MotorShield _card;
};

#endif