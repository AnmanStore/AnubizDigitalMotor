#ifndef _DigitalMotor_H_
#define _DigitalMotor_H_

#include <Arduino.h>


class DigitalMotor
{
private:
    unsigned char DirPin;
public:
    DigitalMotor();
    void begin(long baud);
    void end(void);
    void setSpeed(unsigned char ID, int Speed);
};

extern DigitalMotor DM;


#endif