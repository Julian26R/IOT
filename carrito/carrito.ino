int distancia = 0;
int MotorUnoA = 13;
int MotorUnoB = 12;
int MotorDosA = 11;
int MotorDosB = 10;

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
  pinMode(MotorUnoA, OUTPUT);
  pinMode(MotorUnoB, OUTPUT);
  pinMode(MotorDosA, OUTPUT);
  pinMode(MotorDosB, OUTPUT);
}

void loop(){
  //Motores apagados
  digitalWrite(MotorUnoA, LOW);
  digitalWrite(MotorUnoB, LOW);
  digitalWrite(MotorDosA, LOW);
  digitalWrite(MotorDosB, LOW);
  distancia = 0.01723 * readUltrasonicDistance(11, 10); //determinar distancia
  delay(10000); //esperar 10sg
  if(distancia <= 10){ //si la distancia es menor o igual a 10 frena los motores
    digitalWrite(MotorUnoA, LOW);
    digitalWrite(MotorUnoB, LOW);
    digitalWrite(MotorDosA, LOW);
    digitalWrite(MotorDosB, LOW);
    delay(5000);//esperar 5sg
    //girar a la derecha
    digitalWrite(MotorUnoA, HIGH);
    digitalWrite(MotorUnoB, LOW);
    digitalWrite(MotorDosA, LOW);
    digitalWrite(MotorDosB, LOW);
    if(distancia <= 10){ //si la distancia es menor o igual a 10 frena los motores
      digitalWrite(MotorUnoA, LOW);
      digitalWrite(MotorUnoB, LOW);
      digitalWrite(MotorDosA, LOW);
      digitalWrite(MotorDosB, LOW);
      delay(5000);//esperar 5sg
      //girar a la izquierda
      digitalWrite(MotorUnoA, LOW);
      digitalWrite(MotorUnoB, LOW);
      digitalWrite(MotorDosA, HIGH);
      digitalWrite(MotorDosB, LOW);
      delay(5000);//esperar 5sg
      if(distancia > 10){ //si la distancia es mayor a 10 avanza
        digitalWrite(MotorUnoA, HIGH);
        digitalWrite(MotorUnoB, LOW);
        digitalWrite(MotorDosA, HIGH);
        digitalWrite(MotorDosB, LOW);
      }else{ // si no apaga los morotes
        digitalWrite(MotorUnoA, LOW);
        digitalWrite(MotorUnoB, LOW);
        digitalWrite(MotorDosA, LOW);
        digitalWrite(MotorDosB, LOW);  
      }
    }else{// si no apaga los avanza
      digitalWrite(MotorUnoA, HIGH);
      digitalWrite(MotorUnoB, LOW);
      digitalWrite(MotorDosA, HIGH);
      digitalWrite(MotorDosB, LOW);
    }
  }else{// si no apaga los avanza
      digitalWrite(MotorUnoA, HIGH);
      digitalWrite(MotorUnoB, LOW);
      digitalWrite(MotorDosA, HIGH);
      digitalWrite(MotorDosB, LOW);
  }
 
}
