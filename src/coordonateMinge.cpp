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

void coordonateMinge::SchimbaDir(Directie D)
{
    directie = D;
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
coordonateMinge::Directie coordonateMinge::getDirect()
{ return directie; }


coordonateMinge::~coordonateMinge()
{
    //dtor
}
