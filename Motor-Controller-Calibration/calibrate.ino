#include <Servo.h>
/* The 'Servo.h' library allows you to control motors and servos by passing any value between
0 and 180 into the "write" method (talon.write() in this program).
For a motor:   0 is full power in one direction,
             180 is full direction in the opposite direction,
              90 is stop.
For a servo:   0 is all the way one direction,
             180 is all the way in the opposite direction,
              90 is the middle.
*/


Servo motor; //creates servo object named motor
int ch5; //channel 5 is SWC (Switch C), controls motors



void setup() {
  
  pinMode(4, INPUT); // Set pi 4 as input from RC reciever
  motor.attach(7); //tells arduino to control pin 7 as a servo
  
}


void loop() {
  
  ch5 = pulseIn(4, HIGH, 25000); // Read the pulse width of incoming signal


  // Value when switch on: 1960-1962
  // Value when switch off: 981-982

  /*When switched on, will run through calibration sequence. 
    When calibrating, turn switch on, then immediately turn it off so it only runs through program once. Count to 10, and then release calibration button. 
    The light will blink green if properly calibrated. 
  */
  
  if(ch5>1500){//switch is turned on
    
    
      motor.write(90); // no motion, nuetrual/midle position
      delay(2000); // remain in this state for given duration
    
      motor.write(180); // full speed oppisite direction
      delay(2000); //maintains state for given duration
    
      motor.write(90); //no motion, nuetrual/midle position
      delay(500); //maintains state for given duration
    
      motor.write(0); // full speed oppisite direction
      delay(2000); //maintains state for given duration

      motor.write(90); // no motion, nuetrual/midle position

  } 
  
  if(ch5<1500){//switch is turned off   
    //do nothing
  }
  
 
}
