#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);

char c ;
void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
 //   Serial3.begin(38400);
  Serial.println("ENTER AT Commands:");
  //Serial3.write("hi to serial 0");
  Serial.write("hi to serial1");

  //Initialize Bluetooth Serial Port
  hc06.begin(38400);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available() > 0){
    c = hc06.read();
    Serial.write(c);
  }

  //Write from Serial Monitor to HC06
  if (Serial.available() > 0){
    c = Serial.read();
       Serial.println (c);
    hc06.write(c);
  }  

  delay(300);
}
