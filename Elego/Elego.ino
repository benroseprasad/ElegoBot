#include "SR04.h"


// HC04 Ultrasonic Sensor pins
#define TRIG_PIN A5
#define ECHO_PIN A4
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

#define ENA 5 //Left wheel speed
#define ENB 6 //Right wheel speed

#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 150


void forward(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

void loop() {
  a = sr04.Distance();
    while (a>20){
      forward();
      a = sr04.Distance();
    }

   stop();

}
