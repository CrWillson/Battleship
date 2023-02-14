#include "Board.h"

class PlayerBoard : public Board {
public:
    PlayerBoard();
    pair<int, int> getMove() override;
};