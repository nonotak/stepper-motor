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
    Serial.println("move");
    Serial.println(x);
    Serial.println(y);

    if(x > _x){
        _card.getStepper(stepsPerRevolution, 1)->step(stepsPerRevolution, FORWARD, DOUBLE);
    }else{
        _card.getStepper(stepsPerRevolution, 1)->step(stepsPerRevolution, BACKWARD, DOUBLE);
    }
    _x = x;

    if(y > _y){
        _card.getStepper(stepsPerRevolution, 2)->step(stepsPerRevolution, FORWARD, DOUBLE);
    }else{
        _card.getStepper(stepsPerRevolution, 2)->step(stepsPerRevolution, BACKWARD, DOUBLE);
    }
    _y = y;
}

void StepperManager::reset(){

}

void StepperManager::setSpeed(int speed){
    
}