#include <iostream>
#include "Piece.h"
#include "King.h"

King::King() {
    p_row = 1;
    p_col = 'e';
    p_color = 'W';
}

King::King(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 1;
        p_col = 'e';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool King::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a King piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool King::valid_move(int row, char col) {
    bool check_row = false;
    if(row == p_row || row == p_row + 1 || row == p_row - 1) {
        check_row = true;
    }
    bool check_col = false;
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    if(cur_col == new_col || cur_col == new_col + 1 || cur_col == new_col - 1) {
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}