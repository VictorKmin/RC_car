#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servo_pot_oin = 0;  // analog pin used to connect the potentiometer
int servo_val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);
}

void loop() {
  servo_val = analogRead(servo_pot_oin);            // reads the value of the potentiometer (value between 0 and 1023)
  servo_val = map(servo_val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(servo_val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
 // PART 2

int motorLpin1=2;
int motorLpin2=3;
int motorRpin1=4;
int motorRpin2=5;
int motorLpwm=10;
int motorRpwm=11;

int motorSpeed=125;
int turn=50;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(motorLpin1,OUTPUT);
  pinMode(motorLpin2,OUTPUT);
  pinMode(motorRpin1,OUTPUT);
  pinMode(motorRpin2,OUTPUT);
  pinMode(motorLpwm,OUTPUT);
  pinMode(motorRpwm,OUTPUT);
}

void loop() {
  String input="";
  while(Serial.available()){
    input+=(char)Serial.read();
    delay(5);
  }

  if(input=="n"){
    stp();
  }
  else if(input=="F"){
    fwd();
  }
  else if(input=="R"){
    rev();
  }
  else if(input.indexOf("TL")>-1){
    lft();
  }
  else if(input.indexOf("TR")>-1){
    rght();
  }
  else if(input!=""){
    motorSpeed=input.toInt();
  }
}

void fwd(){
  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
}

void rev(){
  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void lft(){
  analogWrite(motorLpwm,motorSpeed-turn);
  analogWrite(motorRpwm,motorSpeed+turn);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
}

void rght(){
  analogWrite(motorLpwm,motorSpeed+turn);
  analogWrite(motorRpwm,motorSpeed-turn);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void stp(){
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,1);
}
