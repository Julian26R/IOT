//#include <LiquidCrystal_I2C.h>
#include <ESP8266HTTPClient.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <Wire.h>



//-------------------VARIABLES GLOBALES--------------------------

//LiquidCrystal_I2C lcd(0x27,16,2); //reemplazar por (0x3f,16,2) si no funciona el LCD
int contconexion = 0;
const char *ssid = "CLARO-DDE0"; //nombre de la red wifi
const char *password = "Nikolas04"; //clave de la red wifi
unsigned long previousMillis = 0;
char host[48];
String strhost = "192.168.10.123"; //direccion ip del servidor
String strurl = "/esp/esp/esp/enviodatos.php"; //la ruta
String chipid = "";

int ledRe = 16;
int ledAe;
int ledVe ;
int ledRs;
int ledAs ;
int ledVs ;



int irPin1=14;
int irPin2=12;
int count=0;
boolean state1 = true;
boolean state2 = true;
boolean insideState = false;
boolean outsideIr=false;
boolean isPeopleExiting=false;
int i=1;

//-------Función para Enviar Datos a la Base de Datos SQL--------

String enviardatos(String datos) {
  String linea = "error";
  WiFiClient client;
  strhost.toCharArray(host, 49);
  if (!client.connect(host, 80)) {
    Serial.println("Fallo de conexion");
    return linea;
  }

  client.print(String("POST ") + strurl + " HTTP/1.1" + "\r\n" + 
               "Host: " + strhost + "\r\n" +
               "Accept: */*" + "*\r\n" +
               "Content-Length: " + datos.length() + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded" + "\r\n" +
               "\r\n" + datos);           
  //delay(10);             
  
  Serial.print("Enviando datos a SQL...");
  
  unsigned long timeout = millis();



  while (client.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println("Cliente fuera de tiempo!");
      client.stop();
      return linea;
    }
  }
  // Lee todas las lineas que recibe del servidor y las imprime por la terminal serial
  while(client.available()){
    linea = client.readStringUntil('\r');
  }  
  Serial.println(linea);
  return linea;
}

//-------------------------------------------------------------------------

void setup() {

Serial.begin(115200);

pinMode(ledRe, OUTPUT);
pinMode(ledAe, OUTPUT);
pinMode(ledVe, OUTPUT);
pinMode(ledRs, OUTPUT);
pinMode(ledAs, OUTPUT);
pinMode(ledVs, OUTPUT);

pinMode(irPin2, INPUT);
lcd.init();
lcd.backlight();
lcd.clear();
}lcd.setCursor(0,0);
lcd.print( " <= SISTEMA  =>"); 
lcd.setCursor(0,1);
  lcd.print("<== DE AFORO ==> "); 
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("");
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  Serial.print("chipId: "); 
  chipid = String(ESP.getChipId());
  Serial.println(chipid); 

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and contconexion <50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    delay(500);
    Serial.print(".");
  }
  if (contconexion <50) {
      //para usar con ip fija
      //hacer ipconfig en el cmd del equipo- servidor
      IPAddress ip(12,168,10,124); 
      IPAddress gateway(192,168,10,1); 
      IPAddress subnet(255,255,255,0); 
      WiFi.config(ip, gateway, subnet); 
      
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
     digitalWrite(ledRe,HIGH);
     digitalWrite(ledRs,HIGH);
      delay(500);
      digitalWrite(ledRs,LOW);
      digitalWrite(ledRs,LOW);
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");
  }
}

//--------------------------LOOP--------------------------------
void loop()

{

 if (!digitalRead(irPin1) && i==1 && state1){
     //outsideIr=true;
     delay(50);
     i++;
     state1 = false;
  }

   if (!digitalRead(irPin2) && i==1 &&   state2){
     Serial.println("Entrando");
     outsideIr=true;
     delay(50);
     i = 1 ;
     count++;
     Serial.print("Número de personas adentro: ");
     Serial.println(count);
     float door = 1;
     float contador = count;
//      lcd.setCursor(0,0);
  //   lcd.print( "==> ENTRADA ==>"); 
    // lcd.setCursor(0,1);
     //lcd.print("AFORO:          "); 
    // lcd.setCursor(7,1);
    // lcd.print(count); 
      digitalWrite(ledRe,HIGH);
      delay(200);
      digitalWrite(ledRe,LOW);
      Serial.print("Puerta ");
     Serial.println(door);
     state2 = false;
    unsigned long currentMillis = millis();
    enviardatos("chipid=" + chipid + "&aforo=" + String(contador) + "&door=" + String(door));
    
   }
 if (!digitalRead(irPin2) && i==1 && state2 ){
     outsideIr=true;
     //delay(100);
     i = 2 ;
     state2 = false;
  }

  if (!digitalRead(irPin1) && i==1 && state1 ){
     Serial.println("Saliendo");
     outsideIr=true;
     //delay(100);
     if (count <= 0)
     {
      Serial.println("Establecimiento vacío");
//      lcd.setCursor(0,0);
  //    lcd.print("  == NO HAY ==  "); 
    //  lcd.setCursor(0,1);
      //lcd.print(" == PERSONAS == ");
     }
     else{
      count--;
      Serial.print("Número de personas adentro: ");
      Serial.println(count);
      float door = 0;
      float contador = count;
      Serial.print("Puerta ");
      Serial.println(door);
      i = 1;
      state1 = false; 
     //lcd.setCursor(0,0);
     // lcd.print("<==  SALIDA  <=="); 
     // lcd.setCursor(0,1);
     // lcd.print("AFORO:          "); 
     // lcd.setCursor(7,1);
     // lcd.print(count);  
     digitalWrite(ledRs,HIGH);
      delay(500);
      digitalWrite(ledRs,LOW);
      //unsigned long currentMillis = millis();
       enviardatos("chipid=" + chipid  + "&aforo=" + String(contador) + "&door=" + String(door));
     }
   } 
}
