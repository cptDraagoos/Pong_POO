#include "GameMgm.h"
#include <iostream>
#include "coordonateMinge.h"
#include "Palete.h"
#include <time.h>
#include "conio.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;


GameMgm::GameMgm(int w, int h)
{
	srand(time(NULL));
	quit = false;
	up1 = 'w'; up2 = 'i',
	down1 = 's'; down2 = 'k';
	score1 = score2 = 0;
	width = w;
	height = h;
	minge = new coordonateMinge(w / 2, h / 2);
	paleta1 = new Palete(1, h / 2 - 3);
	paleta2 = new Palete(w - 2, h / 2 - 3);
}

void GameMgm::Scor(Palete* p)
{
	if (p == paleta1)
		score1++;
	else if (p == paleta2)
		score2++;
    minge->Reset();
	paleta1->Reset();
	paleta2->Reset();
}

void GameMgm::Draw()
{
	system("clear");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int minx = minge->getX();
			int miny = minge->getY();
			int pal1x = paleta1->getX();
			int pal2x = paleta2->getX();
			int pal1y = paleta1->getY();
			int pal2y = paleta2->getY();
			if (j == 0)
			{
				cout << "#";
			}
			if (minx == j && miny == i)
			{
				cout << "0";
			}
			else if (pal1x == j && pal1y == i)
			{
				cout << "|";
			}
			else if (pal2x == j && pal2y == i)
			{
				cout << "|";
			}

			else if (pal1x == j && pal1y + 1 == i)
			{
				cout << "|";
			}
			else if (pal1x == j && pal1y + 2 == i)
			{
				cout << "|";
			}
			else if (pal1x == j && pal1y + 3 == i)
			{
				cout << "|";
			}

			else if (pal2x == j && pal2y + 1 == i)
			{
				cout << "|";
			}
			else if (pal2x == j && pal2y + 2 == i)
			{
				cout << "|";
			}
			else if (pal2x == j && pal2y + 3 == i)
			{
				cout << "|";
			}

			else
			{
				cout << " ";
			}
			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout<<"\nScore1:"<<score1;
	cout<<"\nScore2:"<<score2;
	cout << endl;
	usleep(100000);
}

void GameMgm::Input()
{
    minge->Move();

    int minx = minge->getX();
    int miny = minge->getY();
    int pal1x = paleta1->getX();
    int pal2x = paleta2->getX();
    int pal1y = paleta1->getY();
    int pal2y = paleta2->getY();

    if(_kbhit())
    {
        char ch = _getche();
        if(ch == up1)
            if(pal1y > 0)
                paleta1->MoveUp();
        if(ch == up2)
            if(pal2y > 0)
                paleta2->MoveUp();
        if(ch == down1)
            if(pal1y + 4 < height)
                paleta1->MoveDown();
        if(ch == down2)
            if(pal2y + 4 < height)
                paleta2->MoveDown();
        if(minge->getDirect() == minge->STOP)
            minge->randDirectii();
        if(ch == 'q')
            quit = true;
    }
}

void GameMgm::Logic()
{
    int minx = minge->getX();
    int miny = minge->getY();
    int pal1x = paleta1->getX();
    int pal2x = paleta2->getX();
    int pal1y = paleta1->getY();
    int pal2y = paleta2->getY();

    for(int i = 0 ; i < 4 ;i++)
    {
        if(minx == pal1x + 1)
            if(miny == pal1y + i)
                minge->SchimbaDir(minge->getDirect()*(rand() % 3 ) + 5);
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        if(minx == pal2x - 1)
            if(miny == pal2y + i)
                minge->SchimbaDir(minge->getDirect()*(rand() % 3 ) + 1);
    }
    if(miny == height - 1)
        minge->SchimbaDir(minge->getDirect() == minge->DOWNRIGHT ? minge->UPRIGHT : minge->UPLEFT);
    if(miny == 0)
        minge->SchimbaDir(minge->getDirect() == minge->UPRIGHT ? minge->DOWNRIGHT : minge->DOWNLEFT);

    if(minx == width - 1)
        Scor(paleta1);
    if(minx == 0)
        Scor(paleta2);
}

void GameMgm::Run()
{
    while(!quit)
    {
        Draw();
        Input();
        Logic();
    }
}

GameMgm::~GameMgm()
{
	delete minge, paleta1, paleta2;
}
