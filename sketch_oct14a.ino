/*
 * LINKS
 * https://www.youtube.com/watch?v=JIfKOMAU224
 * https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm
 * https://maker.pro/arduino/projects/arduino-door-alarm-using-ultrasonic-sensor
 */

//pins for the ultrasonic, those are digtial, we can also use pin 3 and 2.
#define TRIGGER_PIN   7
#define ECHO_PIN      8
int echoTime;             //time in us
float distance;           //distance in 
//******************************************//

//pins for the car
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enA = 10;
int enB = 5;
//Those for the car

void setup() 
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIGGER_PIN, LOW);     //set trigger pin LOW - idle state
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(TRIGGER_PIN, HIGH);    //send trigger pulse
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  echoTime = pulseIn(ECHO_PIN, HIGH); //capture the echo signal and determine duration of pulse when HIGH
 // distance = (echoTime*0.034*10)/2;    //obtain distance (in mm), from time
 distance = (echoTime*0.034)/2;    //obtain distance (in cm), from time
 //car is moving
   digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    //Those speed I aint sure what we land on yet
    analogWrite(enA, 200);
    analogWrite(enB, 200);
 /*'
  * Here I am going to put an if statement but I aint sure how close we want the car to be to make it stop so it's commented till we test it
  * 
  * if(distance <= 10)
  * {
  *   //I am stopping the car here, but I think we should make it turn or maybe make it go back and then turn.
  *       digitalWrite(in1, LOW);
         digitalWrite(in2, LOW);  
         digitalWrite(in3, LOW);
         digitalWrite(in4, LOW);
  * 
  * }
  * else 
  * {
  *    //The car should keep moving
  *    continue;
  * }
  */

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm"); 

  delay(500);                         //wait for sometime to prevent flooding the terminal
}
