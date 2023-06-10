#ifndef PALETE_H
#define PALETE_H

#include <iostream>

using namespace std;
class Palete
{
	public:
		Palete();
		Palete(int pozX, int pozY);
		void Reset();
		int getX();
		int getY();
		void MoveUp();
		void MoveDown();
		friend ostream& operator<<(ostream& o, Palete p);
	private:
		int x, y;
		int originX, originY;
};

#endif
