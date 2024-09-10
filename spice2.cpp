#include "Arduino.h"
#include "Spice.h"

spice::spice(int pulse[2], int dir[3])
{
    motor main(pulse, dir);
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