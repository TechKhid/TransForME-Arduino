/*
WRITTEN BY THE TECHKHID
ASUSTEM ROBOTICS-LENOVO TRANSFORME
ARDUINO LESSON-(Introduction to the Light Dependent Resistor(LDR)---project)

*/

#include<Servo.h> // Import Servo library

Servo cover;// Create Servo objects
Servo lock;

int trig1 = 12; // assign pin numbers to variables
int trig2 = 4;

int echo1 = 11;
int echo2 = 2;

int buzz = 13;

float dist; // declaring variables for equation
float level;

float dura1;
float dura2;

const float sos = 0.0343;


void setup() {
  // put your setup code here, to run once:
cover.attach(9);// attach servo pin numbers
lock.attach(10);

pinMode(trig1, OUTPUT);//set pinmodes
pinMode(trig2, OUTPUT);

pinMode(echo1, INPUT);
pinMode(echo2, INPUT);

pinMode(buzz, OUTPUT);
Serial.begin(9600);// initialize serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig1, LOW);
delay(2);
digitalWrite(trig1, HIGH);
delay(10);
digitalWrite(trig1, LOW);

dura1 = pulseIn(echo1, HIGH);// calculating distance for front facing ultrasonic sensor
dist = (sos*dura1)/2;
dist = round(dist);// rounding to whole number for easy thresholding

Serial.print("ultrasonic sensor 1: ");
Serial.println(dist);

digitalWrite(trig2, LOW);
delay(2);
digitalWrite(trig2, HIGH);
delay(10);
digitalWrite(trig2, LOW);

dura2 = pulseIn(echo2, HIGH);
level = (sos*dura2)/2;// calculating distance for garbage level ultrasonic sensor
level = round(level);
Serial.print("Garbage level: ");
Serial.println(level);
//delay(1000);

if(dist < 10){ // if object dectected within 10cm open trashcan
  cover.write(0);
  }
else{
  cover.write(90);// else remain closed
  };

if (level < 5){// if trash level reaches within 5cm of the cover turn on and off the buzzer and lock trashcan
  digitalWrite(buzz, HIGH);
  delay(500);
  digitalWrite(buzz, LOW);
  lock.write(180);
  }
else{
  digitalWrite(buzz, LOW);
  lock.write(0);
  }
}
