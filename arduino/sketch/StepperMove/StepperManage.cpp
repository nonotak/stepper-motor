#include "Arduino.h"
#include "StepperManage.h"
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

const int stepsPerRevolution = 200;
const int defaultSpeed = 255;

//#################### CLASS ####################

StepperManager::StepperManager(Adafruit_MotorShield card, int x, int y, AccelStepper stepper1, AccelStepper stepper2){
    _card = card; 
    _x = x;
    _y = y;
    _stepper1 = stepper1;
    _stepper2 = stepper2;
}

void StepperManager::init(){
    _card.begin();
    
    _stepper1.setMaxSpeed(300.0);
    _stepper1.setAcceleration(100.0);

    _stepper2.setMaxSpeed(300.0);
    _stepper2.setAcceleration(100.0);

}

int StepperManager::getX(){
    return _x;
}

void StepperManager::setX(int x){
    _x = x;
}

int StepperManager::getY(){
    return _y;
}

void StepperManager::setY(int y){
    _y = y;
}

void StepperManager::move(int x, int y){
    Serial.println("move");
    Serial.println(x);
    Serial.println(y);

    int currentX = -(_x - x);
    Serial.println("current X");
    Serial.println(currentX);

    int currentY = -(_y - y);
    Serial.println("current Y");
    Serial.println(currentY);

    _stepper1.moveTo(currentX * 1000);
    _stepper2.moveTo(currentY * 1000);

    _x = x;
    _y = y;
}

void StepperManager::reset(){
    
}

void StepperManager::run(){
    /*if(_stepper1.distanceToGo() == 0){
        _card.getStepper(stepsPerRevolution, 1)->release();
    }*/
    _stepper1.run();

    /*if(_stepper2.distanceToGo() == 0){
        _card.getStepper(stepsPerRevolution, 2)->release();
    }*/
    _stepper2.run();
}

void StepperManager::setSpeed(int speed){
    
}

//#################### UTILITY ####################
String getSplitValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length()-1;
  
    for(int i=0; i<=maxIndex && found<=index; i++){
      if(data.charAt(i)==separator || i==maxIndex){
          found++;
          strIndex[0] = strIndex[1]+1;
          strIndex[1] = (i == maxIndex) ? i+1 : i;
      }
    }
    return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
  }