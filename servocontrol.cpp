#include <ESP32Servo.h>

#define trigPin 33
#define echoPin 25
#define servoPin 18

Servo servoMotor;
long duration;
int distance;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  servoMotor.attach(servoPin); 
  
  servoMotor.write(0); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 10) {
    int angle = (distance - 10) / 2 * 10;
    
    if (angle > 180) {
      angle = 180;
    }
    
    servoMotor.write(angle);
    
    Serial.print("Servo Angle: ");
    Serial.println(angle);
  } else {
    servoMotor.write(0);
  }

  delay(500);  
}