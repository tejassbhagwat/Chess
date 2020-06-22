#include <iostream>
#include "chess.h"
using namespace std;

// Constructors for spot

spot :: spot(int x, int y)   {
    this->x = x;
    this->y = y;
    annotation = 'o';
}

spot :: spot()  {
    annotation = 'o';
}
