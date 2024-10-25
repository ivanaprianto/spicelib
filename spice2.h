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
int stdpulse[2] = {3, 4};
int stddir[3] = {24, 26, 28};
#include <Arduino.h>
#include <Wire.h>

class spice
{
    public:
        spice(int pulse[2] = stdpulse, int dir[3] = stddir);
        int coords();
        void autoMode();
        void readCommand();
        bool isRunning();

    private:
        uint8_t _rec[3];
        bool _isRunning;
        bool _isWatering;
}

class motor
{
    public:
        motor(int pulse[2], int dir[3]);
        void drive()
        void moveX(int steps);
        void moveY(int steps);
        int locX();
        int locY();

    private:
        int _posX;
        int _posY;
        uint8_t _pulse[2];
        uint8_t _dir[3];

}

class sensor
{
    public:
        npk();
        o2();
        co2();
        readAll();

    private:

}
#endif