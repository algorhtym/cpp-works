#pragma once

#include <iostream>
#include <stdlib.h>

#define CHESS_NUM 8

using namespace std;

extern const int row_space[];
extern const char col_space[];
extern const char color[];

class Piece {
protected:
    int p_row;
    char p_col;
    char p_color;
public:
    Piece();
    Piece(int, char, char);
    bool valid_position(int, char);
    bool valid_color(char);
    bool move(int, char);
    virtual bool valid_move(int, char);
};