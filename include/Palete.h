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

	private:
		int x, y;
		int originX, originY;
};
