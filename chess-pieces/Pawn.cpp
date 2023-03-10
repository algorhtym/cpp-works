#include <iostream>
#include "Piece.h"
#include "Pawn.h"

Pawn::Pawn() {
    p_row = 2;
    p_col = 'b';
    p_color = 'W';
}

Pawn::Pawn(int row, char col, char clr) {
    if(!valid_position(row, col) || !valid_color(clr)) {
        cout << "Not valid position!\nSetting default values...\n";
        p_row = 2;
        p_col = 'b';
        p_color = 'W';
    } else {
        p_row = row;
        p_col = col;
        p_color = clr;
    }
}

bool Pawn::move(int row, char col) {
    if(!valid_position(row, col)) {
        cout << "Invalid position given!\n";
        return false;
    } 
    if(!valid_move(row,col)){
        cout << "Invalid move for a Pawn piece!]n";
        return false; 
    }

    p_row = row;
    p_col = col;
    return true;
}

bool Pawn::valid_move(int row, char col) {
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

    if (is_pawn_move(row,col)) {
        check_row = true;
        check_col = true;
    }

    if(check_row && check_col) {
        return true;
    } else {
        return false;
    }

}

bool Pawn::is_pawn_move(int row, int col) {
    int i,cur_col,new_col;
    for (i = 0; i < 16; i++) {
        if(p_col == col_space[i]){
            cur_col = (i % 8) + 1;
        }
        if(col == col_space[i]){
            new_col = (i % 8) + 1;
        }
    }

    if(new_col != cur_col) {
        return false;
    }


    bool row_check = false;
    if(p_color == 'w' || p_color == 'W') {
        if(row == 2) {
            if(row == p_row + 1 || row == p_row + 2) {
                row_check = true;
            }
        } else {
            if(row == p_row + 1) {
                row_check = true;
            }
        }
    } else if(p_color == 'b' || p_color == 'B') {
        if(row == 7) {
            if(row == p_row - 1 || row == p_row - 2) {
                row_check = true;
            }
        } else {
            if(row == p_row - 1) {
                row_check = true;
            }
        }
    }

    return row_check;
}



