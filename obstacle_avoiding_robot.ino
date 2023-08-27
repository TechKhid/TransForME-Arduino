// WRITTEN BY THE TECHKHID

#include <Servo.h> // import Servo library

Servo servo;// create servo object

int trig = 3;// assigning pins to variables
int echo = 4;
float sos = 0.034;

int motorA_speed = 5;
int motorA1 = 12;
int motorA2 = 11;

int motorB_speed = 6;
int motorB1 = 7;
int motorB2 = 8;


int duration;// declaring variables for equation
int distance; 

int C_dist;
int R_dist;
int L_dist;



void setup() {
  // put your setup code here, to run once:

  servo.attach(10);// attach servo pin number
  
  
  pinMode(trig, OUTPUT);// Setting pinmodes
  pinMode(echo, INPUT);
  
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  
  pinMode(motorA_speed, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(motorB_speed, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  Serial.begin(9600);// initializing Serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  C_dist = look_forward(); // getting front distance
  delay(100);
  Serial.println(C_dist);
  if (C_dist < 30){ //if front distance is less than 30 
    Stop(); //stop ==> back ==> stop ==> get right and left distance
    delay(800);
    back();
    delay(500);
    Stop();
    delay(700);
    R_dist = look_right();
    delay(700);
//    servo.write(90);
    delay(200);
    Serial.print("Right_dist: ");
    Serial.println(R_dist);
    L_dist = look_left();
    delay(700);
    Serial.print("Left_dist: ");
    Serial.println(L_dist);

    int distDiff = L_dist - R_dist; //get left and right distance difference
  if (distDiff > 0) { // turn left if left distance is greater
    left();
  } 
  else {
    right();// turn right if right distance is greater
  }
    
//    if (R_dist > L_dist){
//      right();
//      Stop();
//      delay(400);
//      forward();
//      }
//    else if(L_dist > R_dist){
//      left();
//      Stop();
//      delay(500);
//      forward();
//      }
    }

    else{ // Keep moving forward
      forward();
      }
}


//int read_distance() {
//  int totalDistance = 0;
//  int numReadings = 5; // Number of readings for averaging
//  
//  for (int i = 0; i < numReadings; i++) {
//    digitalWrite(trig, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trig, LOW);
//    duration = pulseIn(echo, HIGH);
//    totalDistance += (duration * sos) / 2;
//  }
//  
//  return totalDistance / numReadings;
//}

int read_distance(){ // Function for reading distance
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration*sos)/2;
  return distance;
  }


int look_forward(){ // Function for turning neck forward and returning forward distance
  int dist;
  servo.write(90);
  delay(300);
  dist = read_distance();
  return dist;
  
  }
int look_right(){//Function for turning neck right and returning right distance
  int _dist;
  servo.write(0);
  _dist = read_distance();
  return _dist;
  
  }

int look_left(){ //Function for turning neck leftt and returning left distance
  int dist_;
  servo.write(180);
  dist_ = read_distance();
  return dist_;
  
  }



void back(){ // Function for back/reverse motion of robot
  analogWrite(motorA_speed, 200);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2,HIGH);

  analogWrite(motorB_speed, 200);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  }


void forward(){ // Function for forward/progressive motion of robot
  analogWrite(motorA_speed, 200);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2,LOW);

  analogWrite(motorB_speed, 200);
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  }


void right(){ // Function for right turn of robot
  analogWrite(motorA_speed, 150);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2,LOW);

  analogWrite(motorB_speed, 150);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  delay(525); //delay and speed determines how much the robot turns in this direction
  }



void left(){  // Function for right left of robot
  analogWrite(motorA_speed, 150);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  
  analogWrite(motorB_speed, 150);
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  delay(525);//delay and speed determines how much the robot turns in this direction
  }


void Stop(){ // Function to stop motion of robot
  analogWrite(motorA_speed, 0);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  
  analogWrite(motorB_speed, 0);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
}
