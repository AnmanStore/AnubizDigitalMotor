#include <Arduino.h>
#include <DigitalMotor.h>


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    DM.begin(115200);
    Serial.println("Hello World");
}

void loop() {
    // put your main code here, to run repeatedly:
    DM.setSpeed(1,1000);
    delay(1000);
}