//
//  Queen.hpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef Queen_hpp
#define Queen_hpp

#include <stdio.h>
#include "Piece.h"
class Board;


class Queen : public Piece
{

public:
    ~Queen();
    Queen();
    Queen(int _x,int _y,Board *_plate,string _color,string _name);
    bool isVaildMove(int _x,int _y);
    bool isNoPieceThereInPath(int _x,int _y);
    
};

#endif /* Queen_hpp */
