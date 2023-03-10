#include <iostream>
#include "Piece.h"
#include "Knight.h"

Knight::Knight() {
    p_row = 1;
    p_col = 'b';
    p_color = 'W';
}

Knight::Knight(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 1;
        p_col = 'b';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool Knight::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a Knight piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool Knight::valid_move(int row, char col) {
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

    if (is_lmove(row,col)) {
        check_row = true;
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}

bool Knight::is_lmove(int row, int col) {
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    int c_dif = abs(cur_col-new_col);
    int r_dif = abs(p_row - row);

    if( (c_dif == 2 && r_dif == 1) || (c_dif == 1 && r_dif == 2) ) {
        return true;
    } else {
        return false;
    }


}

