#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 5;
float lux;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test"));
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
   lux = lightMeter.readLightLevel(true);
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  //move()
      delay(2000);

  if (lux > 1000)
  {
     digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);

    Serial.print(lux);
    Serial.println(" inside lx");
  }
  else 
  {
    forward();
    delay(5000);
    right();
    delay(5000);
    left();
    delay(5000);
    backwards();
    delay(5000);


  }
  
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
}
void left() {
      analogWrite(enA, 200);
    analogWrite(enB, 200);
 digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void backwards() {
      analogWrite(enA, 130);
    analogWrite(enB, 130);
 digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
}
