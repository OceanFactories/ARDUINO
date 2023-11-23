
const int SensorProximty = 8;
const int SensorProximty2 = 9;
void setup()
{
  Serial.begin(9600);
  pinMode(SensorProximty, INPUT);
  pinMode(SensorProximty2, INPUT);
}

void loop()
{
  int hasilkiri = digitalRead(SensorProximty);
  int hasilkanan = digitalRead(SensorProximty2);
  if(hasilkiri == LOW)
  {
    Serial.println("Ada Halangan dikiri");
  }
  if(hasilkanan == LOW)
  {
    Serial.println("Ada Halangan dikanan");
  }
  if(hasilkiri == HIGH)
  {
    Serial.println("Aman, dikiri Tidak Ada Halangan");
  }if(hasilkanan == HIGH)
  {
    Serial.println("Aman, dikanan Tidak Ada Halangan");
  }
  delay(250);
}
