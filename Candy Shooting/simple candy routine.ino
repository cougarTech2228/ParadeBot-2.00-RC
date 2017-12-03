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


Servo SpinMotor; //creates servo object for spinning broadcast spreader
Servo CandyMotor; //Creates servo object for roatating motor to dispense candy
int ch5; //input from channel 5 of RC reciever, which is controlled by SWC (Switch C), controls candy shooting



void setup() {
  
  pinMode(4, INPUT); // Set pi 4 as input from RC reciever
  SpinMotor.attach(7); //tells arduino to control pin 7 as a servo, which can also control DC motors
  CandyMotor.attach(6);//tells arduino to control pin 6 as a servo, which can also control DC motors
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
    
    
      SpinMotor.write(135); //Spins broadcast spreader
      delay(500); //waits .5 seconds for it to get to full speed
    
      CandyMotor.write(135); // begins to rotate dispensing candy
      delay(2000); //dispense candy for this amount of time
    
      CandyMotor.write(90); //stops dispensing candy 
      delay(500); //waits set amount of time for all candy to be dispensed and shot
      SpinMotor.write(90); //stops spinning broadcast spreader
    
      delay(500); //just to wait a bit in between shots. 

  } 
  
  if(ch5<1500){//switch is turned off   
    //do nothing
  }
  
 
}
