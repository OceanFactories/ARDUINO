#define in1 9
#define in2 10

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255

  if (pwmOutput<127 & pwmOutput>0) {
    int forward = map(pwmOutput, 0, 127, 0 , 255);
   digitalWrite(in2,LOW);  
   digitalWrite(in1,forward);
  }
  if (pwmOutput>127 & pwmOutput<255) {
    int reverse = map(pwmOutput, 128, 255, 0 , 255);
    digitalWrite(in2,reverse);
    digitalWrite(in1,LOW);  
  }
}
