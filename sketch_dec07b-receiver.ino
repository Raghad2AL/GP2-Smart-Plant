#include <Wire.h>

#include <SoftwareSerial.h>
/*
 * Connects for thr sensor with arduino:
 * VCC - VCC
 * GND - GND
 * A0 (analog output) - A0 (analog pin on the arduino or any other analog pin)
 * NOTE: for the sensore, we can connect it to digtial pins using the D0 pin on the sensor and use digitalRead(DigitalPinNO) insted analogRead()
 */

//SoftwareSerial hc06(19,18);
char c ;
int enA = 10;
int enB = 5;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
bool flag = true;
bool once = true;
const int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
bool FindLaser = false;
//************
#define TRIGGER_PIN_1   30
#define ECHO_PIN_1      31
int echoTimeOne;             //time in us
float distanceOne;           //distance in 
//***** First backward Ultrasonic**********

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
   Serial2.begin(38400);
 // Serial.println("ENTER AT Commands:");
    Wire.begin();
   pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  digitalWrite(TRIGGER_PIN_1, LOW); 
 // Serial3.write("hi to serial 0");
 // Serial.write("hi to serial1");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

}

void loop(){
  //Write data from HC06 to Serial Monitor
  output_value= analogRead(sensor_pin);
    output_value = map(output_value,550,10,0,100);
  // Serial.print("Mositure : ");
  // Serial.print(output_value);
   
  distanceOne = Ultrasonic_One();//approx 29
  Serial.print("dis : ");
   Serial.print(distanceOne);
  if(output_value<0){
    FindLaser = true;
  }
  if (Serial2.available() > 0){
          c = Serial2.read();
            Serial.println("vv");
             FindLaser = false;
            once = false;
        Serial.println(c);
        backwards();
        if(distanceOne < 30)
        {
          stopp();
          Serial2.write("t");
          if(output_value>0){
             Serial2.write("t");
          }
        }

  }//if
  if(FindLaser){
    if(flag){  forward(); 
     flag=false;
    }// if flag
    delay(100);
    if(once == true){
      right();
      delay(150);  
      stopp();

  }//if once
  delay(200);
}//if for the hum sensor
}//loop



void right() {
  analogWrite(enA, 150);
  //analogWrite(enB, 160);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
   // forward();
}

void forward() {
      analogWrite(enA, 190);
    analogWrite(enB, 190);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void left() {
      analogWrite(enA, 100);
    analogWrite(enB, 100);
 digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(3000);
    //forward();
}
void backwards() {
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void stopp() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
 digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(300);
    //forward();
}
int Ultrasonic_One(){
  int distance;
  digitalWrite(TRIGGER_PIN_1, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_1, LOW);
  echoTimeOne = pulseIn(ECHO_PIN_1, HIGH); //capture the echo signal and determine duration of pulse when HIGH
 // distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time
 distance = (echoTimeOne*0.034)/2;    //obtain distance (in cm), from time
 return distance;
}
