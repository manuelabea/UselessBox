#include "Arduino.h"
#include "Servo.h"
#include "UselessServo.h"

//Constructor definition. This Code will run every time an object is created
UselessServo::UselessServo(int pin) {
  _myServo = Servo();
  _myServo.attach(pin);
  _pin = pin;
}

void UselessServo::moveServoToPosition(int pos){
  _pos = pos ;
  _myServo.write(_pos) ;
}