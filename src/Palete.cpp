#include "Palete.h"
#include <iostream>

using namespace std;

Palete::Palete()
{
	x = y = 0;
}

Palete::Palete(int pozX, int pozY) :	Palete()
{
	originX = pozX;
	originY = pozY;
	x = pozX;
	y = pozY;
}

void Palete::Reset()
{
	x = originX;
	y = originY;
}

int Palete::getX()
{ return x; }

int Palete::getY()
{ return y; }

void Palete::MoveUp()
{ y--; }

void Palete::MoveDown()
{ y++; }
