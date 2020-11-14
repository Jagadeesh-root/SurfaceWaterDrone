#include <Servo.h>                   // To control 2 servo motors for camera angle and ESC for bldc motors
#define leftMotorPin 2                  // pin assignment
#define conveyorPin 3
#define cameraRLPin 4
#define rightMotorPin 5
#define conveyorMotor 6


Servo cameraRL,bldcLeft,bldcRight;   // Creating servo objects 
int countRL = 0;                       // counters and checkers for sweep control of camera angle motors
int check2=0;
int speed1,speed2 = 0;                               // Speed for bldc motor

void setup() {                                          //Setting up the pins to get a desired op
  cameraRL.attach(8);
  bldcLeft.attach(9);
  bldcRight.attach(10);
  cameraRL.write(0);
  bldcLeft.write(0);
  bldcRight.write(0);
  pinMode(conveyorMotor,OUTPUT);   
}

void loop() {
  
if(digitalRead(conveyorPin) == HIGH)  // The conveyor motor turns on only if either of the BLDC motor is ON (or) else we have to assign a seperate button for it which is not possible as we have only 4 channels in RF transmission (or) keep it always ON
  digitalWrite(conveyorMotor,HIGH);  
else 
  digitalWrite(conveyorMotor,LOW);  


if(digitalRead(cameraRLPin) == HIGH)        // As the camera's Horizontal angle control buttons are pressed the camera's angle sweeps left and right
  {
    if(countRL == 0)
      check2 = 1;
    
    if(countRL == 180)
     check2 = 0;
    
    if(check2 == 1)
    cameraRL.write(++countRL);
    
    if(check2 == 0)
     cameraRL.write(--countRL);
     delay(15);
  }

    if(digitalRead(leftMotorPin) == HIGH)              
    { 
      if(speed1 != 180){
         for (speed1 = 0;speed1<180 ; speed1++)  {       // for loop ensures that the BLDC motors speed up smoothly
           bldcLeft.write(speed1);
            delay(15);
         }
        }
       else
      bldcLeft.write(speed1);
      
    }
    else
    {
      speed1 = 0;
      bldcLeft.write(speed1);
    }
    
    
    if(digitalRead(rightMotorPin) == HIGH)
    {
      if(speed2 != 180){
      for (speed2 = 0;speed2<180 ; speed2++){          // for loop ensures that the BLDC motors speed up smoothly
         bldcRight.write(speed2);
         delay(15);
            }
        }
      else
       bldcRight.write(speed2);
    }
    else
    {
      speed2 = 0;
      bldcRight.write(speed2);
    }
}
