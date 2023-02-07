#include "Ship.h"
#include <string>
#include <vector>

using namespace std;

Ship::Ship(int Id, int Len)
{
    id = Id;
    length = Len;
    isSunk = false;
}
