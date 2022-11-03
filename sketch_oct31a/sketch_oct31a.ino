int led = 26;         // the PWM pin the LED is attached to
int tiltPin = 30;	  // tilt sensor pin is connected to pin 2
bool flag = false;
double time = 0.00;
double time2 = 0.00;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello World");
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(tiltPin)) {
      if(time < 5.00) {
        time = time+1;
        delay(1000);
      }
      else if(flag) {
        time2 = 0.00;
        digitalWrite(led, HIGH);
        flag = false;
      } else {
        time2 = 0.00;
        digitalWrite(led, LOW);
        flag = true;
      }
      
  } else {
    Serial.print("off");
    digitalWrite(led, LOW);
    if(time2 > 2) {
      time = 0.00;
    } else {
      time2 += 0.01;
      delay(10);
    }
    
  }
}