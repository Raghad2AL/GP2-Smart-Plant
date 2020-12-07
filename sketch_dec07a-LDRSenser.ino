
#include <SoftwareSerial.h>
#include <Wire.h>
#include <BH1750.h>

/*
 * Connects for thr relay and the pump:
 * 
 * for Relay, connect it with arduino
 * VCC - VCC
 * GND - GND
 * IN - A0
 * 
 * for pump with the relay:
 * 
 * red wire on the pump - COM pin on the relay
 * black wire - black wire to the battery
 * 
 * red wire of the battery - NO in the relay
 * 
 */
SoftwareSerial hc06(2,3);
//int sensorValue = 0; // variable to store the value coming from the sensor
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;
int sensorValue7 = 0;
int sensorValue8 = 0;

//int sensorPin = A0; // select the input pin for LDR
int sensorPin1 = A1; 
int sensorPin2 = A2; 
int sensorPin3 = A3; 
int sensorPin4 = A4; 
int sensorPin5 = A5; 
int sensorPin6 = A6; 
int sensorPin7 = A7; 


bool flag = true;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 5;
char c ;
const int sensor_pin = A0;
void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
    Wire.begin();
 //   Serial3.begin(38400);
  Serial.println("ENTER AT Commands:");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  hc06.begin(38400);
}//set up

void loop(){
  //Write data from HC06 to Serial Monitor

 // sensorValue = analogRead(sensorPin); // read the value from the sensor
//Serial.println(sensorValue); //prints the values coming from the sensor on the screen
sensorValue2 = analogRead(sensorPin1); // read the value from the sensor
sensorValue2 = analogRead(sensorPin2); // read the value from the sensor
sensorValue3 = analogRead(sensorPin3); // read the value from the sensor
sensorValue4 = analogRead(sensorPin4); // read the value from the sensor
sensorValue5 = analogRead(sensorPin5); // read the value from the sensor
sensorValue6 = analogRead(sensorPin6); // read the value from the sensor
sensorValue7 = analogRead(sensorPin7); // read the value from the sensor


Serial.println(sensorValue3);

  if(hc06.available() > 0) {
    char t = hc06.read();
     digitalWrite(RELAY_PIN, HIGH);
  }
  
  if(hc06.available() > 1) {
    char t = hc06.read();
     digitalWrite(RELAY_PIN, LOW);
  }

/*if(sensorValue > 300 ){
  hc06.write("t");
}*/

if(sensorValue1 > 300 ){
  hc06.write("t");
}
if(sensorValue6 > 300 ){
  hc06.write("t");
}
if(sensorValue2 > 300 ){
  hc06.write("t");
}

if(sensorValue3 > 300 ){
  hc06.write("t");
}

if(sensorValue4 > 300 ){
  hc06.write("t");
}

if(sensorValue5 > 300 ){
  hc06.write("t");
}
if(sensorValue7 > 300 ){
  hc06.write("t");
}


  //Write from Serial Monitor to HC06
//   



  delay(200);
}
