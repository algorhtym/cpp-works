#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class King : public Piece {
public:
    King();
    King(int,char,char);
    bool move(int,char);
    bool valid_move(int,char);
};