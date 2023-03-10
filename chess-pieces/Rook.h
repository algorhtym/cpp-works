#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class Rook : public Piece {
public:
    Rook();
    Rook(int,char,char);
    bool move(int,char);
    bool valid_move(int,char);
    //bool is_diagonal(int, int);
    bool is_vertical(int,int);
};