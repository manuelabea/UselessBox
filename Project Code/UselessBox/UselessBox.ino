#include <UselessServo.h>

UselessServo myServo(15);

void setup() {
}

void loop() {
    myServo.moveServoToPosition(10);
    delay(3000);
    myServo.moveServoToPosition(70);
    delay(3000);
}
