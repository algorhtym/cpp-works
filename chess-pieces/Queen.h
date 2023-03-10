#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class Queen : public Piece {
public:
    Queen();
    Queen(int,char,char);
    bool move(int,char);
    bool valid_move(int,char);
    bool is_diagonal(int, int);
    bool is_vertical(int,int);
};