#include "pitches.h"

const double DELAY = 5.00;

int speaker = 4;         // the PWM pin the LED is attached to
int tiltPin = 8;	  // tilt sensor pin is connected to pin 2
int ledPin = 13;
bool flag = false;
double time = 0.00;
double time2 = 0.00;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(speaker, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(tiltPin)) {
      if(time < DELAY) {
        time = time+1;
        delay(1000);
      }

      else{
        tone(speaker, 5000, 4);
        time2 = 0.00;
        /*delay(4);
        noTone(speaker);
        delay(8);*/
      }
  } else {
    noTone(speaker);
    if(time2 > 2) {
      time = 0.00;
    } else {
      time2 += 0.01;
      delay(10);
    }
    
  }
}