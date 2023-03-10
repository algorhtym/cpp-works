#include <iostream>
#include "Piece.h"
#include "Queen.h"

Queen::Queen() {
    p_row = 1;
    p_col = 'd';
    p_color = 'W';
}

Queen::Queen(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 1;
        p_col = 'd';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool Queen::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a Queen piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool Queen::valid_move(int row, char col) {
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

    if (is_diagonal(row,col) || is_vertical(row,col) ) {
        check_row = true;
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}

bool Queen::is_diagonal(int row, int col) {
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


bool Queen::is_vertical(int row, int col) {
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