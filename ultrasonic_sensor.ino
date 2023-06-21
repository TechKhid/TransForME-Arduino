/*
WRITTEN BY THE TECHKHID
ASUSTEM ROBOTICS-LENOVO TRANSFORME
ARDUINO LESSON-(Introduction to the Ultrasonic Sensor)
*/


//assigning variables to trig and echo pins
int trig = 12;
int echo = 13;

//Assigning and declaring variables for Calculation
const float sos = 0.034;
int distance;
float duration;


void setup() {
  // put your setup code here, to run once:
//Setting Up pin modes
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
//initializing Serial communication
Serial.begin(9600);

//testing trigger pin of Ultrasonic sensor
digitalWrite(trig, HIGH);
delay(2);
digitalWrite(trig, LOW);
delay(2);
}

void loop() {
  // put your main code here, to run repeatedly:
//trigerring ultrasonic waves for 30 milliseconds(0.03 sec)
digitalWrite(trig, HIGH);
delay(30);

//turning of off and waiting for 2 milliseconds(0.002 sec)
digitalWrite(trig, LOW);
delay(2);

//Assigning travel time for ultrasound waves to a variable
duration = pulseIn(echo, HIGH);

//Calculating for distance
distance = (sos*duration)/2;

//printing distance to the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.println("-cm");

}
