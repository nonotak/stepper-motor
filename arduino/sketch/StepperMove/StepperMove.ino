//#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "StepperManage.h"

// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// create 4 stcking card in a table.
Adafruit_MotorShield cards[4] = {
  Adafruit_MotorShield(0x60),
  Adafruit_MotorShield(0x61),
  Adafruit_MotorShield(0x62),
  Adafruit_MotorShield(0x63) 
};

StepperManager steppers[4] = {
  StepperManager(Adafruit_MotorShield(0x60),1,1),
  StepperManager(Adafruit_MotorShield(0x61),1,1),
  StepperManager(Adafruit_MotorShield(0x62),1,1),
  StepperManager(Adafruit_MotorShield(0x63),1,1)
};

// number of step for one revolution
const int stepsPerRevolution = 200;
const int defaultSpeed = 255;

//connect stepper to M1 M2
Adafruit_StepperMotor *myMotor1 = cards[0].getStepper(stepsPerRevolution, 1);
Adafruit_StepperMotor *myMotor2 = cards[0].getStepper(stepsPerRevolution, 2);


void setup() {
  Serial.begin(9600);
  Serial.println("Stepper start...");

  //init all stacked card with default frequency
  for(int i = 0; i < 4; i++){
    // create with the default frequency 1.6KHz
    //cards[i].begin();
    //cards[i].getStepper(stepsPerRevolution, 1)->setSpeed(defaultSpeed);
    //cards[i].getStepper(stepsPerRevolution, 2)->setSpeed(defaultSpeed);
    steppers[i].init();
  }
}

void loop() {
  //Read the serial buffer as a string. data format as P
  String data = Serial.readString();

  if(data.length() > 0){

    if(data.startsWith("RESET")){
      for(int i = 0; i < 4; i++){
        steppers[i].reset();
      }
      //step backward all motor until end stop activated 
    }

    if(data.startsWith("P")){
      //move stepper position
      data
      myMotor1->step(stepsPerRevolution, FORWARD, DOUBLE);
      myMotor2->step(stepsPerRevolution, FORWARD, DOUBLE);
    }
  }
}
