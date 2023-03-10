#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class Knight : public Piece {
public:
    Knight();
    Knight(int,char,char);
    bool move(int,char);
    bool valid_move(int,char);
    bool is_lmove(int, int);
    //bool is_diagonal(int, int);
    //bool is_vertical(int,int);
};