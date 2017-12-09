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

//Candy shooting global variables
Servo SpinMotor; //creates servo object for spinning broadcast spreader
Servo CandyMotor; //Creates servo object for roatating motor to dispense candy

int ch5; //input from channel 5 of RC reciever, which is controlled by SWC (Switch C), controls candy shooting

boolean Shoot = false; //boolean to record state of shooting
int RecordTime; //stores time. used for delays


int ShootDuration = 2000; //sets the duration the robot shoots candy if just switched on and off in milliseconds.


String State = "off"; // state in candy shooting sequence, starts in off and is in off whenever it isnt in the process of shooting

boolean SpinMotor1 = false; //records whether or not Broadcast spreader motor is spinning 
boolean CandyMotor1 = false; // records whether or not hopper/candy dispenser motor is rotating



void setup() {
  // put your setup code here, to run once:

  pinMode(4, INPUT); // Set pin 4 as input from RC reciever, controls 

  SpinMotor.attach(7); //tells arduino to control pin 7 as a servo, which can also control DC motors
  CandyMotor.attach(6);//tells arduino to control pin 6 as a servo, which can also control DC motors

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(ch5>1500){//switch is turned on
    Shoot = true;
  } 
  
  if(ch5<1500){//switch is turned off   
    Shoot = false; 
  }

  //if the switch (SWC) is turned on and off quickly, the robot will shoot candy for a set amount of time. 
  //Right now it is set for 2 seconds but it can be changed by modifying the value of the ShootDuration variable


  //Begin spining broadcast spreader, change state to startup
  if(Shoot == true && State == "off"){
    SpinMotor.write(115);//number controls motor speed and direction, begins spinng broadcast spreader motor
    RecordTime = millis(); //records time when actuated to be used for delay until desired time
    State = "start up"; //changes state 
  }
  
  //start shooting candy
  else if(State == "start up" && millis() >= RecordTime + 500 ){
    CandyMotor.write(110); //number controls motor speed and direction, turns on hopper motor, begins dispensing candy
    RecordTime = millis(); //resets recorded time
    State = "shooting sequence";
  }

   //continues shooting if switch is left on after shooting duration has passed
   else if(Shoot == true && State == "shooting sequence" && millis() >= (RecordTime + ShootDuration) ){
    RecordTime = millis();
    State = "continous shooting";
  }

  //shut down, stop shooting if switch was just turned on and off rapidly and robot is only meant to shoot for set duration
  else if(Shoot == false && State == "shooting sequence" && millis() >= RecordTime + ShootDuration){
    CandyMotor.write(90); //number controls motor speed and direction
    RecordTime = millis();
    State = "shut down";
  }
  
  //stops shooting (dispensing candy from hopper) if robot was in continous shooting state 
  else if(Shoot == false && State == "continous shooting" && millis() >= RecordTime){
    CandyMotor.write(90); //number controls motor speed and direction
    RecordTime = millis(); //reset timer
    State = "shut down"; //enters shutdown
  }

  //turns off broadcastspreader motor, changes state to shutdown
  else if(Shoot == false && State == "shut down" && millis() >= RecordTime + 500){
    SpinMotor.write(90); // turns off broadcast spreader
    State = "off"; //turns state to off
  }

}
