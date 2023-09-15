/*
  Flappable - a Modification of A Fabric that Remembers Version 2 Code
  Controls from https://flappable-rtd.web.app/ populate a real-time database read by an arduino that updates
  Electromagnets upon a fabric
  Modified from: Rui Santos
  Complete project details at our blog.
    - ESP32: https://RandomNerdTutorials.com/esp32-firebase-realtime-database/
    - ESP8266: https://RandomNerdTutorials.com/esp8266-nodemcu-firebase-realtime-database/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
  Based in the RTDB Basic Example by Firebase-ESP-Client library by mobizt
  https://github.com/mobizt/Firebase-ESP-Client/blob/main/examples/RTDB/Basic/Basic.ino
*/
#include <secrets.h>
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"



//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false; 

//pins for the first four flaps
//36 is top left
int flaps[16] = {13, 12, 14, 27, 26, 25, 33, 32, 21, 22, 19, 23, 18, 5, 15, 2};
int onboard_led = 4;

//the total number of flap values we are reading
int num_regs = 16;


const bool input_vals[16] = {false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false};



void setup(){

  digitalWrite(onboard_led, HIGH);


  for(int i = 0; i < num_regs; i++){
    pinMode(flaps[i], OUTPUT);
  }
  pinMode(onboard_led, OUTPUT);

   Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  Serial.println(WIFI_SSID);
  Serial.println(WIFI_PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;


  //set a connection delay here (or put sign up function in loop)
  delay(5000);
  Serial.println("attempting first signup");
  while(!signupOK){
    Serial.println("trying signup again");

    /* Sign up */
    if (Firebase.signUp(&config, &auth, "", "")){
      Serial.println("ok");
      signupOK = true;
    }
    else{
      Serial.printf("%s\n", config.signer.signupError.message.c_str());
    }
    delay(1000);
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

}

void loop() {

  
   if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 250 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();



    if (Firebase.RTDB.getInt(&fbdo, "bits")) {
        digitalWrite(onboard_led, LOW);

      if (fbdo.dataType() == "int") {
        int intValue = fbdo.intData();
        char binary[17] = {0};
        int expanded = intValue + 65536;
        itoa(expanded,binary,2);
        char* string = binary + 1;
        Serial.println(string); //print out our string.
        for(int i = 0; i < num_regs; i++){
            digitalWrite(flaps[i], string[i] - '0'); //write to the pin (the - '0' converts the bit of the string to HIGH or LOW)
        }
      }
    }
    else {
      digitalWrite(onboard_led, HIGH);

      Serial.println(fbdo.errorReason());
    }

  }

}










