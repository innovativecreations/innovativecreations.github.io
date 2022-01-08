#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char authcode[] = "5ogwvDTJ7HJqvASVSdmLxzgXXur4lc_o";     //Auth Code
char wifissid[] = "no device foud";                               //WiFi Name
char wifipassword[] = "nahipata";                         //WiFi Password

int vValue = 0;           //Store V1 parameters

int m1 = 16;        //pin 0
int m2 = 5;         //pin1
int m3 = 4;         //pin2
int m4 = 14;        //pin5
void setup() {
  Serial.begin(9600);
  Blynk.begin(authcode,wifissid,wifipassword);

  pinMode(m1,OUTPUT);     // pin define
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);

  digitalWrite(m1,LOW);   //stop 
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
BLYNK_WRITE(V1){
  vValue = param.asInt();
  Serial.println(vValue);  
}
void loop() {
  
  Blynk.run();
  
  if (vValue == 1){           //FORWARD
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
  }
  
  if (vValue == 2){           //LEFT
    digitalWrite(m1,HIGH);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
    
  if (vValue == 3){           //RIGHT
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,HIGH);
    digitalWrite(m4,LOW);
  }
    
  if (vValue == 4){            //BACKWARD
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  } 
  if (vValue == 0){            //STOP
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
  }
  
}
