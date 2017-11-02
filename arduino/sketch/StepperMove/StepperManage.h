#ifndef StepperManage_h
#define StepperManage_h

#include "Arduino.h"
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

class StepperManager
{
  public:
    StepperManager(Adafruit_MotorShield, int x, int y,AccelStepper stepper1, AccelStepper stepper2);
    void init();
    void move(int x, int y);
    void setSpeed(int speed);
    void reset();
    void run();
    int getX();
    int getY();
    void getCard();
    void setX(int);
    void setY(int);

  private:
    int _x;
    int _y;
    Adafruit_MotorShield _card;
    AccelStepper _stepper1;
    AccelStepper _stepper2;

};

//utility
String getSplitValue(String data, char separator, int index);

#endif