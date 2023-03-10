#include <iostream>
#include "Piece.h"

using namespace std;

const int row_space[CHESS_NUM] = {1, 2, 3, 4, 5, 6, 7, 8};
const char col_space[CHESS_NUM*2] = {'a','b','c','d','e','f','g','h',
                                   'A','B','C','D','E','F','G','H'};
const char color[4] = {'B','W','b','w'};

Piece::Piece() {
    p_row = 1;
    p_col = 'a';
    p_color = 'W';
}

Piece::Piece(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 1;
        p_col = 'a';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool Piece::valid_position(int row, char col) {
    int i,j;
    bool check_row = false;
    for (i = 0; i < 8; i++) {
        if (row == row_space[i]){
            check_row = true;
            break;
        }
    }

    bool check_col = false;
    for (j = 0; j < 16; i++) {
        if (col == col_space[j]){
            check_col = true;
            break;
        }
    }

    if (check_col && check_row) {
        return true;
    }
    return false;
}

bool Piece::valid_color(char clr) {
    int i;
    bool check_color = false;
    for (i = 0; i < 4; i++) {
        if (clr == color[i]){
            check_color = true;
            break;
        }
    }

    if (check_color){
        return true;
    } else {
        return false;
    }
}

bool Piece::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 

    p_row = row;
    p_col = col;
    return true;
}









