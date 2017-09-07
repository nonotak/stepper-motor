#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

//connect stepper to M1 M2
Adafruit_StepperMotor *myMotor1 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *myMotor2 = AFMS.getStepper(200, 2);



void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor1->setSpeed(255);  //  rpm  
  myMotor2->setSpeed(255);  //  rpm   
}

void loop() {
  //myMotor1->step(100, FORWARD, DOUBLE);
  //myMotor2->step(100, FORWARD, DOUBLE);


  /*
  //Serial.println("Single coil steps");
  //myMotor1->step(1, FORWARD, INTERLEAVE); 
  myMotor2->step(1, FORWARD, INTERLEAVE); 
  //myMotor->step(100, BACKWARD, SINGLE); 

  
  Serial.println("Double coil steps");
  myMotor->step(100, FORWARD, DOUBLE); 
  myMotor->step(100, BACKWARD, DOUBLE);
  
  Serial.println("Interleave coil steps");
  myMotor->step(100, FORWARD, INTERLEAVE); 
  myMotor->step(100, BACKWARD, INTERLEAVE); 
  
  Serial.println("Microstep steps");
  myMotor->step(50, FORWARD, MICROSTEP); 
  myMotor->step(50, BACKWARD, MICROSTEP);
  */
}
