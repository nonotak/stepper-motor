#include "Arduino.h"
#include "StepperManage.h"
#include <Adafruit_MotorShield.h>

StepperManager::StepperManager(Adafruit_MotorShield card, int x, int y){
    _card = card; 
    _x = x;
    _y = y;
}

void StepperManager::move(int x, int y){

}

void StepperManager::reset(){

}