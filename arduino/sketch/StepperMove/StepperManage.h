#ifndef StepperManage_h
#define StepperManage_h

#include "Arduino.h"
#include <Adafruit_MotorShield.h>

class StepperManager
{
  public:
    StepperManager(Adafruit_MotorShield, int x, int y);
    void init();
    void move(int x, int y);
    void setSpeed(int speed);
    void reset();
  private:
    int _x;
    int _y;
    Adafruit_MotorShield _card;
};

#endif