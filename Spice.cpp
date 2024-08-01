#include "Arduino.h"
#include "Spice.h"

motor::motor(int pulse, int dir)
{
    _pulse = pulse;
    _dir = dir;
    _dual = false;
}

motor::motor(int pulse, int dir[2])
{
    _pulse = pulse;
    _dir1 = dir[0];
    _dir2 = dir[1];
    dual = true
}

void motor::receiveCommand()
{
    Serial.readBytes(_rec, 3)
    _total = (_rec[1]*400) + _rec[2];
    switch(_rec[0]){
        case 0x01:
            _direction = true;
            _targetStep = _total;
            break;
        case 0x02:
            _direction = false;
            _targetStep = _total;
            break;
        case 0x03:
            _targetStep = _total - _currStep;
            if(_targetStep > 0){
            _direction = true;
            } else {
            _direction = false;
            }
            break;
        case 0x04:
            
        default:
            break;
    }
    if(!dual) {
        digitalWrite(_dir, _direction);
    } else {
        digitalWrite(_dir1, _direction);
        digitalWrite(_dir2, !_direction);
    }
}

void motor::runMotor()
{
    _currMicros = micros();
    if(_currMicros - _prevMicros >= 50)
    {
        digitalWrite(_pulse, HIGH);
        delayMicroseconds(450);
        digitalWrite(_pulse, LOW);
        if(_direction)
        {
            _currStep++;
            if(_currStep % 400 == 0)
            {
                _revs++;
            }
        } else {
            _currStep--;
            if(_currStep % 400 == 0)
            {
                _revs--;
            }
        }
    }
}

bool motor::isRunning()
{
    if(_currStep != _targetStep){
        return true;
    } else {
        return false;
    }
}

void motor::sendLocation()
{
    _loc[0] = _revs;
    _loc[1] = _currStep - _revs;
    Serial.write(_loc, 2);
}

npk::npk(Serial *serial, int de, int re)
{
    _serial = serial;
    _de = de;
    _re = re;
}

void npk::grabData()
{

}

byte npk::n()
{

}

byte npk::p()
{

}

byte npk::k()
{

}

oxygen::oxygen()
{
    
}