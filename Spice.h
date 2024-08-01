#ifndef Spice_H
#define Spice_H
#define ADDRESS_0   0x70
#define ADDRESS_1   0x71
#define ADDRESS_2   0x72
#define ADDRESS_3   0x73  
#define OCOUNT      100   
#define OXYGEN_DATA_REGISTER 0x03   
#define USER_SET_REGISTER    0x08   
#define AUTUAL_SET_REGISTER  0x09   
#define GET_KEY_REGISTER     0x0A   
#include <Arduino.h>
#include <Wire.h>

class motor
{
    public:
        motor(int pulse, int dir);
        motor(int pulse, int dir[2]);

    private:
        bool _dual;
        int _mDelay;
        int _pulse;
        int _dir;
        int _dir1;
        int _dir2;
        int _total;
        int _revs;
        uint8_t _rec[3];
        uint8_t _coord[2];
        uint8_t _loc[2];
        long _currStep;
        long _targetStep;
        long _currMicros;
        long _prevMicros;
        bool _direction;
}

class npk
{
    public:
        npk(Serial *serial, int de, int re);
        void grabData();

    private:
        Serial _serial;
        int _de;
        int _re;
        const byte _nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
        const byte _phos[]  = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
        const byte _pota[]  = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
}

class oxygen
{
    public:
        oxygen();

    private:

}
#endif