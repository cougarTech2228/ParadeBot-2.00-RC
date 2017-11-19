
int ch5; // Here's where we'll keep our channel values
//channel 5 is SWC (Switch C)
void setup() {

  pinMode(5, INPUT); // Set our input pins as such

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch5 = pulseIn(5, HIGH, 25000); // Read the pulse width of 


 // Serial.print("Channel 5:"); // Print the value of 
 // Serial.println(ch5);        // each channel


  // Value when switch on: 1960-1962
  // Value when switch off: 981-982
  if(ch5>1500){
    Serial.println("Left Switch: Engaged");

    delay(1000); //run candy shooting sequence

    Serial.println("delivery complete");
  } 
  
  if(ch5<1500){
    //Serial.println("Left Switch: Disengaged");
  }
  
  delay(100); // I put this here just to make the terminal 
              // window happier
}
