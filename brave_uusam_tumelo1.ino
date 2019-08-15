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