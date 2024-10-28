#include "Arduino.h"
#include "Spice.h"

spice::spice(int pulse[2], int dir[3])
{
    motor main(pulse, dir);
}

void spice::autoMode()
{
    if (Serial.available() > 0 && !isRunning) {
        Serial.readBytes(_rec, 3);
        Serial.write(b'\xA0');
        readCommand();
    }

}

void spice::readCommand()
{
    switch (_rec[2])
    {
    case 0x01:
        _isWatering = true;
        break;
    case 0x02:
        break;
    case 0x03:
        break;
    default:
        readAll();
        _isRunning = true;
        break;
    }
    if(_isRunning)
    {
        int targetX = _rec[0]*796;
        int targetY = _rec[1]*796;
        main.drive(targetX, targetY);
    }
    
}

bool spice::isRunning()
{
    return _isRunning;
}

int spice::coords()
{
    _posX = main.locX();
    _posY = main.locY();
    Serial.println(String(_posX) + " " + String(_posY));
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

void motor::drive(int x, int y)
{
    bool isRunning = spice.isRunning();
    if(isRunning)
    {
        bool dirX = _posX > x ? false : true;
        digitalWrite(_dir[0],  dirX);
        digitalWrite(_dir[1], !dirX);
        moveX(x);
        bool dirY = _posY > y ? false : true;
        digitalWrite(dor[2],  dirY);
        moveY(y);
        Serial.write(b'\xAA')
    }
    
}

void motor::moveX(int steps)
{
    while(spice.isRunning() && (_posX != steps))
    {
        digitalWrite(_pulse[0], HIGH);
        delayMicroseconds(400);
        digitalWrite(_pulse[0], LOW);
        delayMicroseconds(200);
    }
}

void motor::moveY(int steps)
{
    while(spice.isRunning() && (_posY != steps))
    {
        digitalWrite(_pulse[1], HIGH);
        delayMicroseconds(400);
        digitalWrite(_pulse[1], LOW);
        delayMicroseconds(200);
    }
}

int motor::locX()
{
    return _posX/796;
}

int motor::locY()
{
    return _posY/796;
}

sensor::sensor(int npk[4], int analog)
{
    _di = npk[0];
    _de = npk[1];
    _re = npk[2];
    _ro = npk[3];
    _co2 = analog;
}

float sensor::co2()
{
    analogRead(_co2);
}