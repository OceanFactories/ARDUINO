#define CW 0
#define CCW 1
#define motorDirPin 7
#define motorPWMPin 9
#define enablePin 8
#define encoderPinA 2
#define encoderPinB 4
#define potPin A0 // Pin untuk input potensio
int encoderPos = 0;
int prevEncoderPos = 0;
float Kp = 1.5;
float Ki = 0;
float Kd = 0;
float error;
float integral = 0;
float derivative = 0;
float prevError = 0;
int targetPos = 0;
int control;
int velocity;

unsigned long currentTime = 0;
unsigned long prevTime = 0;
unsigned long deltaTime = 0;

void setup() {
pinMode(motorDirPin, OUTPUT);          
pinMode(enablePin, OUTPUT);
digitalWrite(enablePin, HIGH);
pinMode(encoderPinA, INPUT_PULLUP);
pinMode(encoderPinB, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(encoderPinA), 
doEncoder, RISING);
Serial.begin(9600);
}
void loop() {
currentTime = millis();
deltaTime = currentTime - prevTime;

// Baca input potensio
int potVal = analogRead(potPin);

// Konversi nilai potensio menjadi targetPos antara 0 dan 255
targetPos = map(potVal, 0, 1023, 0, 255);
if (deltaTime >= 10) {
prevTime = currentTime;
error = targetPos - encoderPos;
integral += error * deltaTime;
derivative = (error - prevError) / deltaTime;
control = (int) (Kp * error + Ki* integral + Kd * 
derivative);
velocity = constrain(control, -255, 255);
if (velocity >= 0) {
digitalWrite(motorDirPin, CW);
analogWrite(motorPWMPin, velocity);
} else {
digitalWrite(motorDirPin, CCW);
analogWrite(motorPWMPin, abs(velocity));
}
Serial.println(encoderPos);

prevError = error;
prevEncoderPos = encoderPos;
}
}

void doEncoder() {
int currEncoderPos = digitalRead(encoderPinB) == 
digitalRead(encoderPinA) ? encoderPos++ : encoderPos--;
prevEncoderPos = currEncoderPos;
}
