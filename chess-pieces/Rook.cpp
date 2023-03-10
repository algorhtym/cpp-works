#include <iostream>
#include "Piece.h"
#include "Rook.h"

Rook::Rook() {
    p_row = 1;
    p_col = 'a';
    p_color = 'W';
}

Rook::Rook(int row, char col, char clr) {
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

bool Rook::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a Rook piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool Rook::valid_move(int row, char col) {
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    bool check_row = false;
    bool check_col = false;

    if (is_vertical(row,col)) {
        check_row = true;
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}

bool Rook::is_vertical(int row, int col) {
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    if(cur_col == new_col || p_row == row) {
        return true;
    } else {
        return false;
    }


}




