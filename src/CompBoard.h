#include "Board.h"

class CompBoard : public Board {
public:
    CompBoard();
    pair<int, int> getMove() override;
};