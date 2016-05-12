//
//  piece.h
//  proj6
//
//  Created by Yating Liu on 8/8/14.
//  Copyright (c) 2014 Yating Liu. All rights reserved.
//

#ifndef PIECE
#define PIECE

#include <iostream>
#include <string>


class piece
{
public:
    void flip();
    
    std::string get_status() const;
    
    void human_status();
    
    void computer_status();
    
    piece();
    
private:
    std::string status;
};




#endif















