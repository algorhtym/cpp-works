#include <iostream>
#include "Piece.h"
#include "Bishop.h"

Bishop::Bishop() {
    p_row = 1;
    p_col = 'c';
    p_color = 'W';
}

Bishop::Bishop(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 1;
        p_col = 'c';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool Bishop::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a Bishop piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool Bishop::valid_move(int row, char col) {
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

    if (is_diagonal(row,col)) {
        check_row = true;
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}

bool Bishop::is_diagonal(int row, int col) {
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    int j, tmp;
    bool result = false;
    for (j = 1; j <= 8; j++) {
        tmp = abs(cur_col - j);
        if((row == p_row + tmp || row == p_row - tmp) && (new_col == cur_col + tmp || new_col == cur_col - tmp)) {
            result = true;
            break;
        }
    }
    return result;
}