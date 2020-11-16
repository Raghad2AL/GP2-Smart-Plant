#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 5;
bool flag = true;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(flag){  forward();
flag=false;}
  delay(100);
  right();
    

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
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(3000);
    //forward();
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
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
}
