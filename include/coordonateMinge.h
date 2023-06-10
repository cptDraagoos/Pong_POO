#ifndef COORDONATEMINGE_H
#define COORDONATEMINGE_H

#include <iostream>
using namespace std;

class coordonateMinge
{

public:
    enum Directie { STOP = 0 , LEFT = 1, UPLEFT = 2 , DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
    coordonateMinge(int PozX, int PozY);
    void Reset();
    void SchimbaDir(Directie D);
    int getX();
    int getY();
    Directie getDirect();
    void randDirectii();
    void Move();
    virtual ~coordonateMinge();
    friend ostream& operator<<(ostream& o, coordonateMinge c);

protected:
    int x, y;
    int originX, originY;
    Directie directie;
private:

};

#endif // COORDONATEMINGE_H
