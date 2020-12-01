/*
 * Connects for thr sensor with arduino:
 * VCC - VCC
 * GND - GND
 * A0 (analog output) - A0 (analog pin on the arduino or any other analog pin)
 * NOTE: for the sensore, we can connect it to digtial pins using the D0 pin on the sensor and use digitalRead(DigitalPinNO) insted analogRead()
 */

/*
 * Connects for thr relay and the pump:
 * 
 * for Relay, connect it with arduino
 * VCC - VCC
 * GND - GND
 * IN - A5
 * 
 * for pump with the relay:
 * 
 * red wire on the pump - COM pin on the relay
 * black wire - black wire to the battery
 * 
 * red wire of the battery - NO in the relay
 * 
 */
const int RELAY_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay
const int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    output_value= analogRead(sensor_pin);
    output_value = map(output_value,550,10,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");

   //if we need water then < 0 is the condition
   //we need to change the code to make the car move and find the laser first then when it reaches the master should like true
   if(output_value<0){
      digitalWrite(RELAY_PIN, HIGH);
     }
     else{
       digitalWrite(RELAY_PIN, LOW);  // turn off pump 5 seconds
     }
   delay(1000);


}
