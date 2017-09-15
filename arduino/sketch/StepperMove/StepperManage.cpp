#include "Arduino.h"
#include "StepperManage.h"
#include <Adafruit_MotorShield.h>

const int stepsPerRevolution = 200;
const int defaultSpeed = 255;

StepperManager::StepperManager(Adafruit_MotorShield card, int x, int y){
    _card = card; 
    _x = x;
    _y = y;
}

void StepperManager::init(){
    _card.begin();
    _card.getStepper(stepsPerRevolution, 1)->setSpeed(defaultSpeed);
    _card.getStepper(stepsPerRevolution, 2)->setSpeed(defaultSpeed);
}

void StepperManager::move(int x, int y){

}

void StepperManager::reset(){

}

void StepperManager::setSpeed(int speed){
    
}