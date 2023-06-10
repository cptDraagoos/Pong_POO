#include <iostream>
#include "coordonateMinge.h"
#include "Palete.h"

using namespace std;


int main()
{
    coordonateMinge c(0, 0);
    cout << c << "\n";
    c.randDirectii();
    cout << c << "\n";
    c.Move();
    cout << c << "\n";
    c.randDirectii();
    c.Move();
    cout << c << "\n";
    cout << "ciau";
    return 0;
}
