//
//  main.cpp
//  proj6
//
//  Created by Yating Liu on 8/8/14.
//  Copyright (c) 2014 Yating Liu. All rights reserved.
//

#include <iostream>
#include "Othello.h"

int main() {
    
    Othello mygame;
    
    if (mygame.play()==Othello::HUMAN)
        cout<<RED<<"The human won!"<<endl;
    else
        cout<<RED<<"The computer won!"<<endl;
    
    
    
    return 0;
}
