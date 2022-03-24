#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DigitalMotor.h"

extern SoftwareSerial ser(8,9);

#define sendData(args) (ser.write(args))
#define availableData() (ser.available())
#define readData() (ser.read())
#define beginCom(args) (ser.begin(args))
#define endCom() (ser.end())

// #define setRXPin(args) (ser.setRX(args))
// #define setTXPin(args) (ser.setTX(args))

#define delayUs(args) (delayMicroseconds(args))

#define setDPin(DirPin,Mode)   (pinMode(DirPin,Mode))
#define switchCom(DirPin,Mode) (digitalWrite(DirPin,Mode))

DigitalMotor::DigitalMotor(/* args */)
{
    DirPin = 7;
}

void DigitalMotor::begin(long baud)
{
    beginCom(baud);
    pinMode(DirPin,OUTPUT);
}

void DigitalMotor::end()
{
    endCom();
}

void DigitalMotor::setSpeed(unsigned char ID, int Speed)
{
    // sendData('#1P1500T100')
    ser.print('#');
    ser.print(ID);
    ser.print('P');
    ser.print(Speed);
    ser.println("T0");
    // Serial.println("#1P1500T0");
    delay(1);
}


DigitalMotor DM;