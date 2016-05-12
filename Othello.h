//
//  Othello.h
//  proj6
//
//  Created by Yating Liu on 8/8/14.
//  Copyright (c) 2014 Yating Liu. All rights reserved.
//

#ifndef OTHELLO_H
#define OTHELLO_H
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <queue>
#include "game.h"
#include "piece.h"
#include "colors.h"

class Othello:public main_savitch_14::game
{
public:
    
    game* clone() const;
    // Compute all the moves that the next player can make:
    
    void compute_moves(std::queue<std::string>& moves) const;
    // Display the status of the current game:
    
    void display_status( ) const;
       // Evaluate a board position:
    // NOTE: positive values are good for the computer.
    
    virtual int evaluate( ) const;  //stub
    // Return true if the current game is finished:
    
    virtual bool is_game_over( ) const;
        // Return true if the given move is legal for the next player:
    
    virtual bool is_legal(const std::string& move) const;
    
    void make_move(const std::string& move);
   
    void restart();
    
    bool check_available(int row_n, int col_n) const;
    
    bool check_around(int row_n, int col_n) const;
    
    void check_flip(int row_n, int col_n);
    
    bool pass() const; //if there's no legal move, pass
    
private:
    piece board[8][8];
    
};





#endif