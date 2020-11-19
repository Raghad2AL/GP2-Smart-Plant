#include <Wire.h>
#include <BH1750.h>

//pins for the ultrasonic, those are digtial, we can also use pin 3 and 2. // trig = 2
#define TRIGGER_PIN_1   2
#define ECHO_PIN_1      3
int echoTimeOne;             //time in us
float distanceOne;           //distance in 
//***** First Ultrasonic**********

#define TRIGGER_PIN_2   11
#define ECHO_PIN_2      12
int echoTimeTwo;             //time in us
float distanceTwo;           //distance in 
//******Second Ultrasonic*********

#define TRIGGER_PIN_3   4
#define ECHO_PIN_3      13
int echoTimeThree;             //time in us
float distanceThree;           //distance in 
//******Third Ultrasonic*********


#define TRIGGER_PIN_4   22
#define ECHO_PIN_4      23
int echoTimeFour;             //time in us
float distanceFour;           //distance in 
//******Fourth Ultrasonic*********

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
float LightValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();

  
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

void loop() {
  // put your main code here, to run repeatedly:
  LightValue =  ReadLightValue();
  distanceOne = Ultrasonic_One();
  distanceTwo = Ultrasonic_Two();
  distanceThree = Ultrasonic_Three();
  distanceFour = Ultrasonic_Four();
  delay(2000);
  
  //Check if we need light
  if(LightValue >= 200 && LightValue < 1000 )
  {
    if(distanceOne>10)
    {
      forward();
       if(distanceThree<10)
        {
           left();
        }
         if(distanceFour<10)
         {
            right();
         }
    }//inner if
   else if(distanceTwo>10)
    {
      backwards();
       if(distanceThree<10)
        {
           left();
        }
         if(distanceFour<10)
         {
            right();
         }
    }//else
   
  }//light if
    delay(2000);
    //Found the Sun, stop
    if(LightValue>1000)
    {
      StopTheCar();
    }
    
}//loop

int ReadLightValue(){
  float Value;
  Value = lightMeter.readLightLevel(true);
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

void forward() {
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void right() {
      analogWrite(enA, 130);
    analogWrite(enB, 130);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(3000);
    forward();
}
void left() {
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(3000);
    forward();
}
void backwards() {
      analogWrite(enA, 130);
    analogWrite(enB, 130);
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
}

void StopTheCar(){
    analogWrite(enA, 0);
     analogWrite(enB, 0);
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);  
     digitalWrite(in3, LOW);
     digitalWrite(in4, LOW);
}
