//
//  Bishop.hpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef Bishop_hpp
#define Bishop_hpp

#include <stdio.h>
#include "Piece.h"
class Board;


class Bishop : public Piece
{
    
public:
    ~Bishop();
    Bishop();
    Bishop(int _x,int _y,Board *_plate,string _color,string _name);
    bool isVaildMove(int _x,int _y);
    bool isNoPieceThereInPath(int _x,int _y);
};

#endif /* Bishop_hpp */
