#include <ESP32Servo.h> //import servo library for esp32

//set pin 33 for trigger pin, pin 25 for echo pin, pin 18 for servo pin
#define trigPin 33 
#define echoPin 25
#define servoPin 18

Servo servoMotor; //variable for servo
long duration; //variable to store the time it takes for an ultrasonic wave to travel from when it is emitted to when it is reflected back.
int distance; //variable to store the distance between sensor and object

void setup() {
  Serial.begin(115200); //set baut rate at 115200
  pinMode(trigPin, OUTPUT); //set trigger pin as output pin
  pinMode(echoPin, INPUT);  //set echo pin as input pin
  servoMotor.attach(servoPin); //set the servo at pin 32
  
  servoMotor.write(0); //ensure that servo at 0 degree angle
}

void loop() {
  digitalWrite(trigPin, LOW); //set the trigger pin low
  delayMicroseconds(2); //delay
  digitalWrite(trigPin, HIGH); //set trigger pin high to emit ultrasonic waves
  delayMicroseconds(10); //delay
  digitalWrite(trigPin, LOW); //set the trigger pin low
  
  duration = pulseIn(echoPin, HIGH); //stores the time it takes for an ultrasonic wave to travel from when it is emitted to when it is reflected back.

  distance = duration * 0.034 / 2; //that time multiplied by the speed of sound and divide with 2 to find the distance between the sensor and the object
  
  Serial.print("Distance: "); //display distance on the serial monitor
  Serial.print(distance); //display distance on the serial monitor
  Serial.println(" cm"); //display distance on the serial monitor
  
  if (distance > 10) { //if the distance is greater than 10 cm...
    int angle = (distance - 10) / 2 * 10; //set the servo angle in increments of 10 every time the object distance is even
    
    if (angle > 180) { //if the angle is greater than 180...
      angle = 180; //set the servo angle to 180
    }
    
    servoMotor.write(angle); //set the servo angle according to the algorithm
    
    Serial.print("Servo Angle: "); //display the servo angle on the serial monitor
    Serial.println(angle); //display the servo angle on the serial monitor
  } else {
    servoMotor.write(0); //if the distance is below 10, set the servo at 0 angle
  }

  delay(500); //delay for good sensor reading
}
