/*
WRITTEN BY THE TECHKHID
ASUSTEM ROBOTICS-LENOVO TRANSFORME
ARDUINO LESSON-(Introduction to the Light Dependent Resistor(LDR))
*/

//Assigning pin number to a variable
const int ldr = A0;

//declaring variable to store light data later 
int light; 


void setup() {
  // put your setup code here, to run once:

//setting up pin modes
pinMode(ldr, INPUT);
pinMode(led, OUTPUT);

//initializing serial communication
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//reading analog signals and assigning to previously declared variable
light = analogRead(ldr);

//print light intensity data in the serial monitor/terminal
Serial.print("light intensity: ");
Serial.println(light);
//delay(1000);

}
