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

// number of step for one revolution
const int stepsPerRevolution = 200;
const int defaultSpeed = 255;

void forwardstep1() {  
  cards[0].getStepper(stepsPerRevolution, 1)->onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  cards[0].getStepper(stepsPerRevolution, 1)->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  cards[0].getStepper(stepsPerRevolution, 2)->onestep(FORWARD, DOUBLE);
}
void backwardstep2() {  
  cards[0].getStepper(stepsPerRevolution, 2)->onestep(BACKWARD, DOUBLE);
}

void forwardstep3() {  
  cards[1].getStepper(stepsPerRevolution, 1)->onestep(FORWARD, SINGLE);
}
void backwardstep3() {  
  cards[1].getStepper(stepsPerRevolution, 1)->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep4() {  
  cards[1].getStepper(stepsPerRevolution, 2)->onestep(FORWARD, DOUBLE);
}
void backwardstep4() {  
  cards[1].getStepper(stepsPerRevolution, 2)->onestep(BACKWARD, DOUBLE);
}

void forwardstep5() {  
  cards[2].getStepper(stepsPerRevolution, 1)->onestep(FORWARD, SINGLE);
}
void backwardstep5() {  
  cards[2].getStepper(stepsPerRevolution, 1)->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep6() {  
  cards[2].getStepper(stepsPerRevolution, 2)->onestep(FORWARD, DOUBLE);
}
void backwardstep6() {  
  cards[2].getStepper(stepsPerRevolution, 2)->onestep(BACKWARD, DOUBLE);
}

void forwardstep7() {  
  cards[3].getStepper(stepsPerRevolution, 1)->onestep(FORWARD, SINGLE);
}
void backwardstep7() {  
  cards[3].getStepper(stepsPerRevolution, 1)->onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep8() {  
  cards[3].getStepper(stepsPerRevolution, 2)->onestep(FORWARD, DOUBLE);
}
void backwardstep8() {  
  cards[3].getStepper(stepsPerRevolution, 2)->onestep(BACKWARD, DOUBLE);
}

AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

AccelStepper stepper3(forwardstep3, backwardstep3);
AccelStepper stepper4(forwardstep4, backwardstep4);

AccelStepper stepper5(forwardstep5, backwardstep5);
AccelStepper stepper6(forwardstep6, backwardstep6);

AccelStepper stepper7(forwardstep7, backwardstep7);
AccelStepper stepper8(forwardstep8, backwardstep8);

/*StepperManager steppers[4] = {
  StepperManager(cards[0],1,1,stepper1,stepper2),
  StepperManager(cards[1],1,1,stepper3,stepper4),
  StepperManager(cards[2],1,1,stepper5,stepper6),
  StepperManager(cards[3],1,1,stepper7,stepper8)
};*/

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper start...");

  //init all stacked card with default frequency
  /*for(int i = 0; i < 4; i++){
    steppers[i].init();
  }*/
}

void loop() {
  //Read the serial buffer as a string. data format as P
  /*String data = Serial.readString();

  if(data.length() > 0){

    if(data.startsWith("RESET")){
      for(int i = 0; i < 4; i++){
        steppers[i].reset();
      }
      //step backward all motor until end stop activated 
    }else{
        //move stepper position
        for(int i=0; i<4; i++){
          String position = getSplitValue(data,':',i);
          Serial.println(position);

          if(position.length() > 0){
            int x = getSplitValue(position,'&',0).toInt();
            int y = getSplitValue(position,'&',1).toInt();
            steppers[i].move(x,y);  
          }
        }  
    }
  }

  //move and run the motors
  for(int i=0; i<4; i++){
    steppers[i].run();

  }*/
}



