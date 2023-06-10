#include <iostream>
#include "coordonateMinge.h"
#include "Palete.h"

using namespace std;
class GameMgm
{
	private:
		int width, height;
		int score1, score2;
		char up1, down1, up2, down2;
		bool quit;
		coordonateMinge* minge;
		Palete* paleta1;
		Palete* paleta2;
	public:
		GameMgm(int w, int h);
		~GameMgm();
		void Scor(Palete* p);
		void Draw();
        void Input();
        void Logic();
        void Run();
};
