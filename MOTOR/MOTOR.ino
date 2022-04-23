int MotorUnoA = 11;
int MotorUnoB = 10;
int MotorDosA = 6;
int MotorDosB = 5;

const int SENSOR = A0;
int sensorvalue = 0;

void setup() {
  pinMode(MotorUnoA, OUTPUT);
  pinMode(MotorUnoB, OUTPUT);
  pinMode(MotorDosA, OUTPUT);
  pinMode(MotorDosB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorvalue = analogRead(SENSOR);
  Serial.println(sensorvalue);
  
  if(sensorvalue > 0){
    digitalWrite(MotorUnoA, HIGH);
     digitalWrite(MotorUnoB, LOW);
      
  }else{
    digitalWrite(MotorUnoA, LOW);
     digitalWrite(MotorUnoB, LOW);
  }

}
