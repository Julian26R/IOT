// C++ code
//
#include <Servo.h>

int distancia = 0;

Servo servo_9;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  servo_9.write(0);
  distancia = 0.01723 * readUltrasonicDistance(11, 10);
  if (distancia <= 100) {
    servo_9.write(90);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_9.write(0);
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}          
