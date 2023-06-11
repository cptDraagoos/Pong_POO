#include <iostream>
#include "coordonateMinge.h"
#include "Palete.h"
#include "GameMgm.h"

using namespace std;


int main()
{
    int ch;
    GameMgm c(40,20);
    cout<<"While playing the game you can press 'q' to close the game";
    cout<<"\nPress 1 to start playing PONG or press 2 to close the program:";
    cin>>ch;
    switch (ch)
    {
    case 1:
        c.Run();
        break;
    case 2:
        break;
    }
    return 0;
}
