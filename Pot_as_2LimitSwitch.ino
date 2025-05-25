// PotToLimitSwitch.ino
// Converts a potentiometer into two logical limit-switch-like triggers
// Author: Jaison
// Date: 2025-05-25

#define potPin A0
#define readPin 2
#define midThreshold 300    // Adjust based on your potentiometer range\

bool reached_higherthreshold,reached_lowerthreshold = false;
void setup() {
  pinMode(potPin, INPUT); 
  pinMode(readPin, INPUT);
 Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  
  if (potValue < midThreshold && !reached_lowerthreshold ) {
    digitalWrite(readPin, HIGH); // Low limit reached
    delay(10);
    digitalWrite(readPin, LOW);
    reached_lowerthreshold = true;
    reached_higherthreshold = false;
  }
  if (potValue > midThreshold && !reached_higherthreshold) {
    digitalWrite(readPin, HIGH);  // High limit reached
    delay(10);
    digitalWrite(readPin, LOW);
    reached_higherthreshold = true;
    reached_lowerthreshold = false;
  }
}
