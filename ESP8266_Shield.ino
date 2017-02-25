#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

int cds = 1;
int led1 = 2;
int led2 = 3;
int led3 = 4;

char auth[] = "ca9e5ac677444263a1993ee5273dd9c8";

char ssid[] = "cchamchi1";
char pass[] = "1234asdf";

#define EspSerial Serial1
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(8, 9); // RX, TX
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);

void setup() {
Serial.begin(115200);
delay(10);
EspSerial.begin(ESP8266_BAUD);
delay(10);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
Blynk.begin(auth, wifi, ssid, pass);
}

void loop() {
  int cdsValue = analogRead(cds);
    Serial.println(cdsValue);
    if (cdsValue >900 ) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      Serial.println("LED1 ON");
    }
    else if ((720 < cdsValue) && (cdsValue < 900)) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      Serial.println("LED12 ON");
     }
     else if( cdsValue < 720) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      Serial.println("LED123 ON");
     }
    delay(2000);  
Blynk.run();
Blynk.virtualWrite(V0, (int)led1, led2, led3);
}
