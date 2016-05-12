//
//  Othello.cc
//  proj6
//
//  Created by Yating Liu on 8/11/14.
//  Copyright (c) 2014 Yating Liu. All rights reserved.
//

#include <iostream>
#include "Othello.h"



main_savitch_14::game* Othello::clone() const
{
    return new Othello (*this);
}

void Othello::compute_moves(std::queue<std::string>& moves) const
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            char temp[2];
            
            temp[0] = 'A'+i;
            temp[1]='1'+j;
            string move(temp);
           if (is_legal(move))
           {
               
               moves.push(move);
           }
        }
    }
}


void Othello::display_status( ) const
{
    char letter;
    cout<<"   |_1_|_2_|_3_|_4_|_5_|_6_|_7_|_8_|"<<endl;
    for (int i =0; i<8; i++)
    {
        letter='A'+i;
        cout<<" "<<letter<<" ";
        for (int j=0; j<8; j++)
        {
            
            cout<<"|"<<board[i][j].get_status();
            
        }
        std::cout<<"|"<<endl;
    }
    std::cout<<endl;
    std::cout<<"*************************************************************";
    std::cout<<endl;
}

int Othello::evaluate( ) const
{
    int num1=0, num2=0,num=0;
    std::string sign, opposite;
    if (last_mover()==HUMAN)
    {
        sign="_O_";
        opposite = "_X_";
    }
    else
    {
        sign="_X_";
        opposite = "_O_";
    }
    
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (board[i][j].get_status()==sign)
                num1++;
            if (board[i][j].get_status()==opposite)
                num2++;
        }
    }
    
    num=num1-num2;
    return num;
    
}

     bool Othello::is_game_over( ) const
{
    bool over = true;
    for (int i =0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (board[i][j].get_status() == "___")
            {
                over = false;
                break;
            }
        }
    }
    
    return over;
    
}

    bool Othello::is_legal(const std::string& move) const
{
    int row, col;
    row = int(toupper(move[0]) - 'A');
    col = int (move[1] - '1');
    
    if (pass()==true)
    {
        return true;
    }
    
    if (check_available(row, col))
    {
        if (check_around(row, col))
        {
            return true;
         }
        else
            return false;
    }
    
    else
        return false;
    
}
    
    
    void Othello::make_move(const std::string& move) {
        
        int row_num, col_num;
        row_num = int(toupper(move[0]) - 'A');
        col_num = int (move[1] - '1');
        
        if (pass() == false)
        {
        
            if (next_mover()==COMPUTER)
                board[row_num][col_num].computer_status();
            else
                board[row_num][col_num].human_status();
            check_flip(row_num, col_num);
        }
        game::make_move(move);
    }
    
    
    void Othello::restart() {
        cout<<B_CYAN;
        board[4][3].human_status();
        board[3][3].computer_status();
        board[3][4].human_status();
        board[4][4].computer_status();
        
        game::restart();
        
    }
    
    bool Othello::check_available(int row_n, int col_n) const
    {
        if (row_n>=0 && row_n<8)
        {
            if (col_n>=0 && col_n<8)
            {
                if (board[row_n][col_n].get_status() == "___")
                    return true;
                else
                    return false;
                
            }
            else
                return false;
        }
        else
            return false;
        
    }
                              

bool Othello::check_around(int row_n, int col_n) const
{
    bool right_place=false;
    int row_up, row_down, col_left, col_right;
    row_up = row_n-1;
    row_down = row_n +1;
    col_left=col_n-1;
    col_right=col_n+1;
    string opposite, self;
    
    if (next_mover()==HUMAN)
    {
        opposite="_X_";
        self="_O_";
    }
    else
    {
        opposite="_O_";
        self="_X_";
    }
    
    if (row_up >=0)
    {
        
        if (board[row_up][col_n].get_status() == opposite)
        {
            int row = row_up-1;
            if (row>=0) {
            while (row>=0 && board[row][col_n].get_status()!= "___")
            {
                
                if (board[row][col_n].get_status()==self)
                {
                    right_place=true;
                    return right_place;
                }
                row--;
            }
            }
        }
        if (col_left>=0)
        {
            if (board[row_up][col_left].get_status() == opposite)
            {
                int row= row_up-1;
                int col=col_left-1;
                if (row>=0 && col>=0) {
                while (row>=0 && col>=0 && board[row][col].get_status()!="___")
                {
                    
                    if (board[row][col].get_status()==self)
                    {
                        right_place=true;
                        return right_place;
                    }
                    row--; col--;
                }
                }
            }
                
        }
        if (col_right<8)
        {
            if (board[row_up][col_right].get_status() == opposite)
            {
                int row=row_up-1;
                int col=col_right+1;
                if (row>=0 && col<8) {
                while (row>=0 && col<8 && board[row][col].get_status()!="___")
                {
                    
                    if (board[row][col].get_status()==self)
                    {
                        right_place = true;
                        return right_place;
                    }
                    row--; col++;
                }
                }
            }
        }
    }
    
    if (col_left>=0)
    {
        if (board[row_n][col_left].get_status() == opposite)
        {
            int col=col_left-1;
            if (col>=0) {
            while (col>=0 && board[row_n][col].get_status() != "___")
            {
               if (board[row_n][col].get_status()==self)
                   {
                       right_place=true;
                       return right_place;
                   }
                col--;
            }
            }
        }
    }
    
    if (col_right<8)
    {
        if (board[row_n][col_right].get_status()==opposite)
        {
            int col=col_right+1;
            if (col<8) {
            while (col<8 && board[row_n][col].get_status()!="___")
            {
                if (board[row_n][col].get_status()==self)
                    {
                    right_place=true;
                        return right_place;
                    }
                    col++;
            }
            }
        }
    }
    
    if (row_down<8)
    {
        if (board[row_down][col_n].get_status() == opposite)
        {
            int row=row_down+1;
            if (row<8) {
            while (row<8 && board[row][col_n].get_status()!="___")
            {
                if (board[row][col_n].get_status()==self)
                {
                    right_place = true;
                    return right_place;
                }
                row++;
            }
            }
        }
        if (col_left>=0)
        {
            if (board[row_down][col_left].get_status() == opposite)
            {
                int row=row_down+1;
                int col=col_left-1;
                if (row<8 && col>=0) {
            while (row<8 && col>=0 && board[row][col].get_status()!="___")
                {
                    if (board[row][col].get_status()==self)
                        {
                            right_place = true;
                            return right_place;
                        }
                        row++;
                        col--;
                }
                }
            }
            
        }
        if (col_right<8)
        {
            if (board[row_down][col_right].get_status() == opposite)
            {
                int row=row_down+1;
                int col=col_right+1;
                if (row<8 && col<8) {
            while (row<8 && col<8 && board[row][col].get_status()!="___")
                {
                    if (board[row][col].get_status()==self)
                    {
                        right_place = true;
                        return right_place;
                    }
                    row++;
                    col++;
                
                }
                }
            }
        }

    }
    
    return right_place;
        
}
    

void Othello::check_flip(int row_n, int col_n)
{
    int row_up, row_down, col_left, col_right;
    row_up = row_n-1;
    row_down = row_n +1;
    col_left=col_n-1;
    col_right=col_n+1;
    string opposite, self;
    
    if (next_mover()==HUMAN)
    {
        opposite="_X_";
        self="_O_";
    }
    if (next_mover()==COMPUTER)
    {
        opposite="_O_";
        self="_X_";
    }

    if (row_up >0)
    {
        if (board[row_up][col_n].get_status() == opposite)
        {
            int row = row_up-1;
            if (row>=0) {
            while (row>=0 && board[row][col_n].get_status()!="___")
            {
                if (board[row][col_n].get_status()==self)
                    {
                        for (int i=row_up; i>row; i--)
                        {
                            board[i][col_n].flip();
                        }
                        break;
                    }
                    row--;
            }
            }
            
        }
        if (col_left>=0)
        {
            if (board[row_up][col_left].get_status() == opposite)
            {
                int row = row_up-1;
                int col = col_left-1;
                if (row>=0 && col>=0) {
                while (row>=0 && col>=0 && board[row][col].get_status()!="___")
                {
                   if (board[row][col].get_status()==self)
                   {
                       int j=col_left;
                       for (int i=row_up; i>row; i--)
                       {
                           board[i][j].flip();
                           j--;
                       }
                       break;
                   }
                    row--; col--;
                }
                }
            }
            
        }
        if (col_right<8)
        {
            if (board[row_up][col_right].get_status() == opposite)
            {
                int row = row_up-1;
                int col = col_right+1;
                if (row>=0 && col<8) {
                while (row>=0 && col<8 && board[row][col].get_status()!="___")
                {
                    if (row>=0 && col<8 && board[row][col].get_status()==self)
                    {
                        int j=col_right;
                        for (int i=row_up; i>row; i--)
                        {
                            board[i][j].flip();
                            j++;
                        }
                        break;
                    }

                    row--; col++;
                }
                }
                
            }
        }
    }
    
    if (col_left>=0)
    {
        if (board[row_n][col_left].get_status() == opposite)
        {
            int col=col_left-1;
            if (col>=0) {
            while (col>=0 && board[row_n][col].get_status() != "___")
            {
               if (col>=0 && board[row_n][col].get_status()==self)
               {
                
                   for (int j=col_left; j>col; j--)
                   {
                       board[row_n][j].flip();

                   }
                   break;
               }
                col--;
            }
            }
        }
    }
    
    if (col_right<8)
    {
       
        if (board[row_n][col_right].get_status()==opposite)
        {
            int col;
            col= col_right+1;
            if (col<8) {
            while (col<8 && board[row_n][col].get_status()!="___")
            {
                if (col<8 && board[row_n][col].get_status()==self)
                {
                    for (int j=col_right; j<col; j++)
                    {
                        board[row_n][j].flip();
                    }
                    break;
                }
                col++;
            }
            }
        }
     
    }
    
    if (row_down<8)
    {
        if (board[row_down][col_n].get_status() == opposite)
        {
            int row;
            row=row_down+1;
            if (row<8) {
            while (row<8 && board[row][col_n].get_status()!="___")
            {
                if (board[row][col_n].get_status()==self)
                    {
                        for (int i=row_down; i<row; i++)
                        {
                            board[i][col_n].flip();
                        }
                        break;
                    }
                    row++;
            }
            }
        }
        if (col_left>=0)
        {
            if (board[row_down][col_left].get_status() == opposite)
            {
                int row=row_down+1;
                int col=col_left-1;
                if (row<8 && col>=0) {
                while (row<8 && col>=0 && board[row][col].get_status()!="___")
                {
                   if (board[row][col].get_status()==self)
                       {
                           int j=col_left;
                           for (int i=row_down; i<row; i++)
                           {
                               board[i][j].flip();
                               j--;
                           }
                           break;
                       }
                       row++;
                       col--;
                }
                }
            }
            
        }
        if (col_right<8)
        {
            if (board[row_down][col_right].get_status() == opposite)
            {
                int row=row_down+1;
                int col=col_right+1;
                if (row<8 && col<8) {
                while (row<8 && col<8 && board[row][col].get_status()!="___")
                {
                    if (board[row][col].get_status()==self)
                        {
                            int j=col_right;
                            for (int i=row_down; i<row; i++)
                            {
                                board[i][j].flip();
                                j++;
                                
                            }
                            break;
                        }
                        row++;
                        col++;
                    
                }
                }
            }
        }
        
    }
    
    
    
}

    
bool Othello::pass() const
{
    string move;
    bool pass=true;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (check_available(i,j))
            {
                if (check_around(i,j))
                    pass=false;
            }
        }
    }
    return pass;

  }

    
    
    
