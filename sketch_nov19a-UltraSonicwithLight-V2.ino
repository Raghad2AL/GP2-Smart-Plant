#include <Wire.h>
#include <BH1750.h>

//pins for the ultrasonic, those are digtial, we can also use pin 3 and 2. // trig = 2
#define TRIGGER_PIN_1   30
#define ECHO_PIN_1      31
int echoTimeOne;             //time in us
float distanceOne;           //distance in 
//***** First forward Ultrasonic**********

#define TRIGGER_PIN_2   11
#define ECHO_PIN_2      12
int echoTimeTwo;             //time in us
float distanceTwo;           //distance in 
//******Second back Ultrasonic*********

#define TRIGGER_PIN_3   2
#define ECHO_PIN_3      3
int echoTimeThree;             //time in us
float distanceThree;           //distance in 
//******Third right Ultrasonic*********


#define TRIGGER_PIN_4   22
#define ECHO_PIN_4      23
int echoTimeFour;             //time in us
float distanceFour;           //distance in 
//******Fourth left Ultrasonic*********

//pins for the car
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 5;
//Those for the car

//***Light Sensor***
BH1750 lightMeter;
BH1750 backLightMeter;

float LightValue;

int Value;
int newVal = 1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  backLightMeter.begin();
  //*****Ultrasonic*****
   pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  digitalWrite(TRIGGER_PIN_1, LOW); 
  
   pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  digitalWrite(TRIGGER_PIN_2, LOW); 

   pinMode(TRIGGER_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
  digitalWrite(TRIGGER_PIN_3, LOW); 

   pinMode(TRIGGER_PIN_4, OUTPUT);
  pinMode(ECHO_PIN_4, INPUT);
  digitalWrite(TRIGGER_PIN_4, LOW); 
  //*****Ultrasonic*****

 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

}
int val = 0;
void loop() {
  // put your main code here, to run repeatedly:
  LightValue =  ReadLightValue();
  distanceOne = Ultrasonic_One();
  distanceTwo = Ultrasonic_Two();
  distanceThree = Ultrasonic_Three();
  distanceFour = Ultrasonic_Four();
  delay(2000);
    Serial.println("dsds");
float sth =  ReadBackLightValue();
  //Check if we need light
  if( LightValue < 500 )
  {
      Movement(val);
      delay(2000);
      StopTheCar();
      newVal = ReadLightValue();
      if(newVal <= LightValue){
        if(val == 3){
          val = 0;
        }
        val = val +1;
      } 
        LightValue = newVal;
             Serial.println("sth");

     Serial.println(sth);
      
  }
    delay(200);
    //Found the Sun, stop
    if(LightValue>500)
    {
      StopTheCar();
    }
    
}//loop

float ReadLightValue(){
  float Value;
  Value = lightMeter.readLightLevel(true);
  return Value;  
}

float ReadBackLightValue(){
  float Value;
  Value = backLightMeter.readLightLevel(true);
  return Value;  
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

int Ultrasonic_Two(){
    int distance;
  digitalWrite(TRIGGER_PIN_2, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_2, LOW);
  echoTimeTwo = pulseIn(ECHO_PIN_2, HIGH); //capture the echo signal and determine duration of pulse when HIGH
 // distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time
 distance = (echoTimeTwo*0.034)/2;    //obtain distance (in cm), from time
 return distance;
}

int Ultrasonic_Three(){
  int distance;
  digitalWrite(TRIGGER_PIN_3, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_3, LOW);
  echoTimeThree = pulseIn(ECHO_PIN_3, HIGH); //capture the echo signal and determine duration of pulse when HIGH
 // distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time
 distance = (echoTimeThree*0.034)/2;    //obtain distance (in cm), from time
 return distance;
}

int Ultrasonic_Four(){
  int distance;
  digitalWrite(TRIGGER_PIN_4, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_4, LOW);
  echoTimeFour = pulseIn(ECHO_PIN_4, HIGH); //capture the echo signal and determine duration of pulse when HIGH
 // distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time
 distance = (echoTimeFour*0.034)/2;    //obtain distance (in cm), from time
 return distance;
}
void StopTheCar(){
    analogWrite(enA, 0);
     analogWrite(enB, 0);
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);  
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
}

int Movement(int value){
  int valuein = value;
  switch (valuein){
    case 0: //forward
    if(distanceOne>20)
    {
    forward();
    }
    break;

    case 1: //right
    if(distanceThree>20){
    right();
    }
     break;

     case 2://left
       if(distanceFour>20)
    {
      left();
    }
     break;

     case 3:
     if(distanceTwo>20)
    {
      backwards();
    }
    break;
    
  }
  return valuein;
}//function


void forward() {
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void right() {
      analogWrite(enA, 150);
    analogWrite(enB, 150);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(5000);
    forward();
}
void left() {
      analogWrite(enA, 150);
    analogWrite(enB, 150);
 digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(5000);
    forward();
}
void backwards() {
      analogWrite(enA, 190);
    analogWrite(enB, 190);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
