#include "coordonateMinge.h"
#include <iostream>

using namespace std;

coordonateMinge::coordonateMinge(int pozX, int pozY)
{
    originX = pozX;
    originY = pozY;
    x = pozX;
    y = pozY;
    directie = STOP;
}

void coordonateMinge::Reset()
{
    x = originX;
    y = originY;
    directie = STOP;
}

void coordonateMinge::SchimbaDir(int D)
{
    switch (D)
    {
    case 0:
        directie=STOP;
        break;
    case 1:
        directie=LEFT;
        break;
    case 2:
        directie=UPLEFT;
        break;
    case 3:
        directie=DOWNLEFT;
        break;
    case 4:
        directie=RIGHT;
        break;
    case 5:
        directie=UPRIGHT;
        break;
    case 6:
        directie=DOWNRIGHT;
        break;
    }
}

void coordonateMinge::randDirectii()
{
    directie = (Directie)((rand() % 6) + 1);
}

void coordonateMinge::Move()
{
    switch (directie)
    {
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        y--; x--;
        break;
    case DOWNLEFT:
        x--; y++;
        break;
    case UPRIGHT:
        x++; y--;
        break;
    case DOWNRIGHT:
        x++; y++;
        break;
    }
}
ostream & operator<<(ostream & o, coordonateMinge c)
{
    o << "Minge [" << c.getX() << "," << c.getY() << "][" << c.getDirect() << "]";
    return o;
}
int coordonateMinge::getX()
{ return x; }
int coordonateMinge::getY()
{ return y; }
int coordonateMinge::getDirect()
{
    switch (directie)
    {
    case STOP:
        return 0;
        break;
    case LEFT:
        return 1;
        break;
    case UPLEFT:
        return 2;
        break;
    case DOWNLEFT:
        return 3;
        break;
    case RIGHT:
        return 4;
        break;
    case UPRIGHT:
        return 5;
        break;
    case DOWNRIGHT:
        return 6;
        break;
    }
}


coordonateMinge::~coordonateMinge()
{
    //dtor
}
