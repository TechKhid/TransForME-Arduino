/*
WRITTEN BY THE TECHKHID
ASUSTEM ROBOTICS-LENOVO TRANSFORME
ARDUINO LESSON-(Introduction to the Light Dependent Resistor(LDR)---project)

*/

//Assigning pin number to a variable
int ldr = A0;
int led = 8;

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

void loop( ) {
  // put your main code here, to run repeatedly:
//reading analog signals and assigning to previously declared variable
light = analogRead(ldr);

//print light intensity data in the serial monitor/terminal
Serial.println(light);

//Setting a threshold to detect darkness and turn on light
if(light < 10){
  digitalWrite(led, HIGH);
}

//keeping light off for if condition is False
else{
  digitalWrite(led, LOW);
}
}
