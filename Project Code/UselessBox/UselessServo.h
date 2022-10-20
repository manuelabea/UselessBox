#ifndef UselessServo_h
#define UselessServo_h
#include "Arduino.h"
#include "Servo.h"

class UselessServo {
  public:
    //Constructor declaration. What happens in the Constructor will be defined in the Source File
    UselessServo(int pin);

    //Functions for Servo
    //void setupServo(int pin); //Setup the servo on a certain input
    void moveServoToPosition(int servoPosition); // Turn the Servo to a certain position

  private:
    Servo _myServo;
    int _pin; // Input on which Servo is connected
    int _servoPosition; // To which Position the Servo must turn

};

#endif