int led_amarillo = 13;
int led_verde = 12;
int led_rojo = 11;
int led_naranja = 10;

int sound = A0;
int datasound;

void setup() {
  Serial.begin(9600);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_naranja, OUTPUT);
  pinMode(sound, INPUT);
  
}

void loop() {
  datasound = analogRead(sound);
  Serial.println(datasound);
  delay(100);

  if(datasound > 56 && datasound <= 65){
    digitalWrite(led_amarillo,HIGH);
  }else if(datasound > 65 && datasound <= 75){
    digitalWrite(led_verde,HIGH);
  }else if(datasound > 75 && datasound <= 85){
    digitalWrite(led_rojo,HIGH);
  }else if(datasound > 85 && datasound <= 95){
    digitalWrite(led_naranja,HIGH);
  }else{
    digitalWrite(led_amarillo,LOW);
    digitalWrite(led_verde,LOW);
    digitalWrite(led_rojo,LOW);
    digitalWrite(led_naranja,LOW);
  }
}
