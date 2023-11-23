//motor directory
#define CW 0
#define CCW 1
// motor control pin
#define motorDirPin 7
#define motorPWMPin 8
#define EnablePin 9
// encoder pin
#define encoderPinA 2
#define encoderPinB 4
//encoder var
int encoderPos = 0;
// PID control
float Kp = 1.5;
float Ki = 0;
float Kd = 0;
int targetPos = 100;
int error;
float dt = 0.01;
float integral;
float prevError;
float derivative;;
int control;
int velocity;
void doEncoderA()
{ 
 digitalRead(encoderPinB)?encoderPos--:encoderPos++;
}
void setup()
{ 
 //setup interrupt
 pinMode(encoderPinA, INPUT_PULLUP);
 pinMode(encoderPinB, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(encoderPinA), 
doEncoderA, RISING);
 
 //setup motor driver
 pinMode (motorDirPin, OUTPUT);
 pinMode (EnablePin, OUTPUT);
 digitalWrite (EnablePin, HIGH);
 
 Serial.begin(9600);
}
void loop()
{ 
 error = targetPos - encoderPos;
integral += error * dt;
derivative = (error - prevError)/dt;
control = 
(Kp*error)+(Ki*integral)+(Kd*derivative);
 
 velocity = min(max(control,-255), 255);
 if(velocity>=0)
 {
 digitalWrite(motorDirPin, CW);
 analogWrite(motorPWMPin, velocity);
 }
 else
 {
 digitalWrite(motorDirPin, CCW); 
 analogWrite(motorPWMPin,(255+velocity));
 } 
 Serial.println(encoderPos);
prevError = error;
delay(dt*1000);
}
