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

boolean Shoot = false; //boolean to record state of shooting
boolean SpinMotor1 = false; //records whether or not motor is spinning 
boolean CandyMotor1 = false; // records whether or not motor is spinning
  
void setup() {
  
  pinMode(4, INPUT); // Set pi 4 as input from RC reciever
  SpinMotor.attach(7); //tells arduino to control pin 7 as a servo, which can also control DC motors
  CandyMotor.attach(6);//tells arduino to control pin 6 as a servo, which can also control DC motors

}


void loop() {
  
  ch5 = pulseIn(4, HIGH, 25000); // Read the pulse width of incoming signal

  // Value when switch on: 1960-1962
  // Value when switch off: 981-982

  
  if(ch5>1500){//switch is turned on
    Shoot = true;
  } 
  
  if(ch5<1500){//switch is turned off   
    Shoot = false; 
  }


  if(Shoot == true && SpinMotor1 == false && CandyMotor1 == false){ //starts candy shooting sequence
    SpinMotor1 = true;
    CandyMotor1 = true;

    SpinMotor.write(135); //Spins broadcast spreader
    delay(500); //waits .5 seconds for it to get to full speed
    
    CandyMotor.write(135); // begins to rotate dispensing candy
  }


  if(Shoot == true && SpinMotor1 == true && CandyMotor1 == true){
    //dont change anything, just keep shootin candy
  }


  if(Shoot == false && SpinMotor1 == true && CandyMotor1 == true){//ends candy shooting sequence
    
     CandyMotor.write(90); //stops dispensing candy 
     delay(500); //waits set amount of time for all candy to be dispensed and shot
     SpinMotor.write(90); //stops spinning broadcast spreader

     SpinMotor1 = false;
     CandyMotor1 = false;
     //stores that motors arent spinning
  }
  
 
}
