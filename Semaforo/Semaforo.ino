int led_rojo = 13;
int led_amarillo = 12;
int led_verde = 11;
void setup() {
  // put your setup code here, to run once:
 pinMode(led_rojo,OUTPUT);
 pinMode(led_amarillo,OUTPUT);
 pinMode(led_verde,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_rojo,HIGH);
  delay(10000);
  digitalWrite(led_rojo,LOW);
  digitalWrite(led_amarillo,HIGH);
  delay(500);
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_verde,HIGH); 
  delay(10000);
  digitalWrite(led_verde,LOW);
  delay(500);
  digitalWrite(led_amarillo,HIGH);
  delay(500);
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_rojo,HIGH);
}
