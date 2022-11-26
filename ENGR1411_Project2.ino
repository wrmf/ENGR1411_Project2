#include "pitches.h"

const double DELAY = 5.00; //Delay for when the sound activates after you put your head down

int speaker = 4; // the PWM pin the speaker is attached to
int tiltPin = 8; // tilt sensor pin is connected to pin 2
int ledPin = 13; //Pin the LED is attached to
double time = 0.00; //Time for when to start beeping
double time2 = 0.00; //Timer for when to restart time variable

// the setup routine runs once when you press reset:
void setup() {
  pinMode(tiltPin, INPUT); //Set tilt pin as input
  digitalWrite(tiltPin, HIGH); //Calibrate value to high
  pinMode(speaker, OUTPUT); //Set speaker to output
  pinMode(ledPin, OUTPUT); //Set led to output
  digitalWrite(ledPin, HIGH); //Turn LED on
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(tiltPin)) { //Check if the tilt sensor is tilted
      if(time < DELAY) { //Check if we have reached DELAY yet
        time = time+1; //Increment if not
        delay(1000); //Wait
      }

      else{
        tone(speaker, 5000, 4); //Play tone if we have
        time2 = 0.00; //Reset time2 timer
      }
  } else { //If the tilt sensor is not tilted
    noTone(speaker); //Turn speaker off
    if(time2 > 2) {
      time = 0.00; //Reset time after 2 seconds
    } else {
      time2 += 0.01; //Increment if it hasn't been tilted 2 seconds
      delay(10); //Delay
    }
    
  }
}