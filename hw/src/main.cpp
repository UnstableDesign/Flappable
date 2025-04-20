#include <secrets.h>
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>


#include <Arduino.h>

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false; 

//pins for the first four flaps
//36 is top left
int flaps[8] = {32, 33, 25, 26, 27, 14, 12, 13};
int onboard_led = 21;

//the total number of flap values we are reading
int num_regs = 8;




void setup(){

  digitalWrite(onboard_led, HIGH);


  for(int i = 0; i < num_regs; i++){
    pinMode(flaps[i], OUTPUT);
  }
  pinMode(onboard_led, OUTPUT);

   Serial.begin(115200);
 

}

void loop() {


  //ALL ON/OFF for 3 SECONDS, 2 Times
  for(int j = 0; j < 2; j++){
    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],HIGH);
    }
    delay(3000);

    //ALL OFF FOR 3 SECONDS
    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],LOW);
    }
    delay(3000);
  }

  //ALL ON/OFF for 2 SECONDS,  3 Times
  for(int j = 0; j < 3; j++){
    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],HIGH);
    }
    delay(2000);

    //ALL OFF FOR 3 SECONDS

    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],LOW);
    }
    delay(2000);
  }

  //ALL ON/OFF for 1 SECONDS,  4 Times
  for(int j = 0; j < 4; j++){
    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],HIGH);
    }
    delay(1000);

    //ALL OFF FOR 3 SECONDS

    for(int i=0; i < num_regs; i++){
      digitalWrite(flaps[i],LOW);
    }
    delay(1000);
  }



   

  //ACTIVATING EACH FLAP LEFT TO RIGHT, RIGHT TO LEFT FOR 1 sec each, 3 times
  
    for(int j = 0; j < 3; j++){

      for(int i=0; i < num_regs; i+=2){
        digitalWrite(flaps[i],HIGH);
        if(i+1 < num_regs) (flaps[(i+1)],HIGH);

        delay(1000);
        digitalWrite(flaps[i],LOW);
        if(i+1 < num_regs) digitalWrite(flaps[i+1],LOW);

      }

        for(int i=num_regs-1; i >= 0; i-=2){
        digitalWrite(flaps[i],HIGH);
        if(i+1 >= 0) digitalWrite(flaps[i-1],HIGH);
        delay(1000);
        digitalWrite(flaps[i],LOW);
        if(i+1 >= 0) digitalWrite(flaps[i-1],LOW);

      }

  }

  //FLUTTER LEFT HALF, RIGHT HALF 4 TIMES
  for(int j = 0; j < 4; j++){
    for(int i=0; i < num_regs; i++){
      if(i < 4) digitalWrite(flaps[i],HIGH);
      if( i >= 4) digitalWrite(flaps[i], LOW);
    }
    delay(500);

    for(int i=0; i < num_regs; i++){
      if(i < 4) digitalWrite(flaps[i],LOW);
      if( i >= 4) digitalWrite(flaps[i], HIGH);
    }
    delay(500);

  }


  //REMOVE TOP HALFS
  for(int i=0; i < num_regs; i+=2){
    digitalWrite(flaps[i],LOW);
    delay(1000);
  }

  //ALL OFF 10 SECONDS
  for(int i=0; i < num_regs; i++){
    digitalWrite(flaps[i],LOW);
  }

  
  delay(10000);



}










