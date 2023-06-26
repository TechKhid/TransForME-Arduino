/*
WRITTEN BY THE TECHKHID
ASUSTEM ROBOTICS-LENOVO TRANSFORME
ARDUINO LESSON-(Introduction to the Bluetooth Module)
*/

//Include SoftwareSerial library
#include <SoftwareSerial.h>

//variable to store bluetooth commands
char data;

//Create a SoftwareSerial Object
SoftwareSerial bt(3, 2);// Rx, Tx

void setup() {
// put your setup code here, to run once:
    //Initialize bluetooth Serial communication
    bt.begin(9600);

    //Initialize Serial communication
    Serial.begin(9600);

}

void loop() {
// put your main code here, to run repeatedly:

    //check if there's any command
    if(bt.available() > 0){

    // read any bluetooth command and assign to data variable 
    data = bt.read();

    //print to serial monitor
    Serial.println(data);

    }

  }
