#pragma once

#include <vector>
#include <string>

using namespace std;

class Ship {
public:
    Ship(int Id, int Len);

private:
    int id;
    int length;
    bool isSunk;
    vector<vector<int>> knownCoords;

};