#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class Bishop : public Piece {
public:
    Bishop();
    Bishop(int,char,char);
    bool move(int,char);
    bool valid_move(int,char);
    bool is_diagonal(int, int);
    //bool is_vertical(int,int);
};