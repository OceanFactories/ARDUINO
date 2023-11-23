#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial sim800l(0, 1);
LiquidCrystal_I2C lcd(0x20,20,4);
#define echoPin 3 
#define trigPin 4

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int resval = 0;  // holds the value
int respin = A0; // sensor pin used
boolean kirim = false;

void setup() {
  for(int i=8;i<=13;i++){    
    pinMode(i, OUTPUT);    
  }
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
  attachInterrupt(digitalPinToInterrupt(2),rutinInterupsi0, FALLING);
  sim800l.begin(9600);  
  Serial.begin(9600);
  lcd.begin(20,4);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Muhamad Harrys Gumay");
  lcd.setCursor(0,1);
  lcd.print("21/478343/SV/19267");
  lcd.setCursor(0,2);
  lcd.print("Pendeteksi Jarak");
  lcd.setCursor(0,3);
  lcd.print("Aman dan Hujan");
  delay(500);
  lcd.clear();
}


void loop() {
  resval = analogRead(respin);
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.016 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance = ");
  lcd.setCursor(11,0);
  lcd.print(distance);
  lcd.setCursor(16,0);
  lcd.print("cm"); 
  
  if(distance<50)
    {
      digitalWrite(13,HIGH);
      tone(5,3000,500);
    }else
    {
      
        for(int i=8;i<=13;i++){    
          digitalWrite(i, LOW);    
        }
        tone(5,0,500);
          
      
    }
  
   if (distance<80){
      digitalWrite(12,HIGH);
     tone(5,2000,500);
   }
  
   if (distance<110){
      digitalWrite(11,HIGH);
     tone(5,1500,500);
   }
  
    if (distance<140){
        digitalWrite(10,HIGH);
      tone(5,900,500);
     }
  
    if (distance<170){
        digitalWrite(9,HIGH);
      tone(5,450,500);
     }
  
    if (distance<200){
        digitalWrite(8,HIGH);
      tone(5,100,500);
     }
  delay(500);
  air();
}

void rutinInterupsi0(){
  for(int i=8;i<=13;i++){    
      digitalWrite(i, LOW);    
        }
    tone(5,00,5000);
  delay(50000);
}

void SendSMS()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+6282176191109\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("Kendaraan Kehujanan");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  lcd.setCursor(0,3);
  lcd.println("Pesan Terkirim");
  delay(500);
}

void air(){
   if (resval > 500) {
    Serial.println("Very heavy Rain");
    if(!kirim){
    SendSMS();
    kirim =true;
    }
    }
  else if ((resval > 300) && (resval <= 500)) {
    Serial.println("light rain");
    lcd.setCursor(0,2);
    lcd.println("Hujan Rintik-Rintik");
    }
  else{
    Serial.println("Dry Weather");
  }
}
