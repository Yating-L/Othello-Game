//
//  piece.cc
//  proj6
//
//  Created by Yating Liu on 8/11/14.
//  Copyright (c) 2014 Yating Liu. All rights reserved.
//

#include <iostream>
#include "piece.h"

void piece::flip()
{
    if (status == "_O_")  //O represent human move
        status = "_X_";
    else if (status == "_X_")//X represent computer move
        status = "_O_";
}

std::string piece::get_status() const
    {return status;}
    
void piece::human_status()
{
    status = "_O_";
}

void piece::computer_status()
{
    status = "_X_";
}


piece::piece()
{status = "___";}
    


