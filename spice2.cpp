#include "Arduino.h"
#include "Spice.h"

spice::spice(int pulse[2], int dir[3])
{
    motor main(pulse, dir);
}

void spice::readCommand(uint8_t, rec)
{
    switch (rec[2])
    {
    case 0x01:
        _isWatering = true;
        break;
    case 0x02:
        break;
    case 0x03:
        break;
    default:
        _isRunning = true;
        break;
    }
    
}

motor::motor(int pulse[2], int dir[3])
{
    for(int i = 0; i < 2; i++)
    {
        _pulse[i] = pulse[i];
        _dir[i] = dir[i];
    }
    _dir[3] = dir[3];
}

void motor::moveX(int steps)
{

}

void motor::moveY(int steps)
{
    
}