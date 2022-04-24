int MotorUnoA = 11;
int MotorUnoB = 10;
//LEDS
int led_amarillo = 13;
int led_verde = 12;
int led_rojo = 9;
int led_naranja = 8;

//SENSOR NIVEL DE AGUA
const int SENSOR1 = A0;
int sensorvalue1 = 0;

//SENSOR HIDROMETRO 
const int SENSOR2 = A1;
int sensorvalue2 = 0;

void setup() {
  pinMode(MotorUnoA, OUTPUT);
  pinMode(MotorUnoB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //ENCENDER MOTOR
  sensorvalue1 = analogRead(SENSOR1);
  if(sensorvalue1 = 0 && sensorvalue1 < 60 ){
    digitalWrite(MotorUnoA, HIGH);
     digitalWrite(MotorUnoB, LOW);
      
  }else{
    digitalWrite(MotorUnoA, LOW);
     digitalWrite(MotorUnoB, LOW);
  }

  //ENCENDER LEDS
  sensorvalue2 = analogRead(SENSOR2);
   if(sensorvalue2> 56 && sensorvalue2 <= 100){
    digitalWrite(led_amarillo,HIGH);
  }else if(sensorvalue2 > 100 && sensorvalue2 <= 150){
    digitalWrite(led_verde,HIGH);
  }else if(sensorvalue2 > 150 && sensorvalue2 <= 200){
    digitalWrite(led_rojo,HIGH);
  }else if(sensorvalue2 > 200 && sensorvalue2 <= 250){
    digitalWrite(led_naranja,HIGH);
  }else{
    digitalWrite(led_amarillo,LOW);
    digitalWrite(led_verde,LOW);
    digitalWrite(led_rojo,LOW);
    digitalWrite(led_naranja,LOW);
  }
}
