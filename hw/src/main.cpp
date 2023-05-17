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

// Insert your network credentials - must be 2.4 Ghz
#define WIFI_SSID "UnstableWifi"
#define WIFI_PASSWORD "fluxusmuxus"

// #define WIFI_SSID "wiremore"
// #define WIFI_PASSWORD "falovespa"

// Insert Firebase project API Key
#define API_KEY "AIzaSyBnoUNIicXo_56Omv7o7_YKI7O01oMYwTQ"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://flappable-rtd-default-rtdb.firebaseio.com" 

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

const char* db_location[16] = {"f1_a", "f1_b", "f2_a", "f2_b","f3_a", "f3_b", "f4_a", "f4_b", "f5_a", "f5_b", "f6_a", "f6_b", "f7_a", "f7_b", "f8_a", "f8_b"};


//the total number of flap values we are reading
int num_regs = 16;


const bool input_vals[16] = {false, false, false, false, false, false, false, false,false, false, false, false, false, false, false, false};



void setup(){

  for(int i = 0; i < num_regs; i++){
    pinMode(flaps[i], OUTPUT);
  }

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

//digitalWrite(13, HIGH);


   if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 100 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();




   
  //  Serial.printf("Get bool ref... %s\n", Firebase.RTDB.getBool(&fbdo, F("f1_a"), &bVal) ? bVal ? "true" : "false" : fbdo.errorReason().c_str());

    //for(int i = 0; i < num_regs; i++){
          bool bVal;
          Serial.printf("Count... %i\n", count);

          Serial.printf("Get bool ref... %s\n", Firebase.RTDB.getBool(&fbdo, F(db_location[count]), &bVal) ? bVal ? "true" : "false" : fbdo.errorReason().c_str());


            if(bVal == true){
              digitalWrite(flaps[count], HIGH);
            }else{
              digitalWrite(flaps[count], LOW);
            }
   
     count = (count + 1) % num_regs;

  }

}

void printValues(){

    for(int i = 0; i < num_regs; i++){
      Serial.print(input_vals[i]+" ");
      Serial.println("********");
    }


}









