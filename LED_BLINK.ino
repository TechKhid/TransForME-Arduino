//Assigning Pin numbers to variables
int led = 7;

void setup() {
  // put your setup code here, to run once:

// setting pin as output
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// turn LED on
digitalWrite(led, HIGH);
//keep LED on for 1000 milliseconds(1 sec)
delay(1000);

//turn LED off
digitalWrite(led, LOW);
//keep LED off for 1000 milliseconds(1 sec)
delay(1000);

}
