/*
  Sets all flaps to high, then low in 5 second intervals
*/
#include <Arduino.h>


//pins for the first four flaps
//36 is top left
int flaps[8] = {32, 33, 25, 26, 27, 14, 12, 13};
int onboard_led = 21;

//the total number of flap values we are reading
int num_regs = 8;


const bool input_vals[8] = {false, false, false, false, false, false, false, false};



void setup(){

  Serial.begin(115200);
  digitalWrite(onboard_led, HIGH);


  for(int i = 0; i < num_regs; i++){
    pinMode(flaps[i], OUTPUT);
  }
  
  pinMode(onboard_led, OUTPUT);
  pinMode(36, OUTPUT);

  


  //set a connection delay here (or put sign up function in loop)
  delay(5000);


}

void loop() {

  digitalWrite(onboard_led, HIGH);
  for(int i = 0; i < num_regs; i++){
    digitalWrite(flaps[i], HIGH); 
  }
  delay(5000);


  digitalWrite(onboard_led, LOW);
  for(int i = 0; i < num_regs; i++){
    digitalWrite(flaps[i], LOW); 
  }
  delay(5000);

}











