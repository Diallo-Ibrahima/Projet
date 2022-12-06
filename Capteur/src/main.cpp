#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

int sound = A6;
int led = 4;
//const char analogPin = A4 ;
//const char digitalPin = 16;
//const char ledPin = 10;
bool flag = false;

void setup() {
  pinMode(sound, INPUT);
 // pinMode(digitalPin, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  wifiConnect();
  MQTTConnect();

  flag = false;
}

void loop() {
  
  /*Serial.print("Analog: ");
  Serial.println(analogRead(sound));
  Serial.print("Digital: ");
  Serial.println(analogRead(digitalPin));

  // delay (500);*/
int SensorData = analogRead(sound);
Serial.println(SensorData);
  if(SensorData > 10 ){
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
    appendPayload("Le son", SensorData);
    sendPayload();

  delay(1000);
}