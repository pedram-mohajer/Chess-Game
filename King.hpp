//
//  King.hpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef King_hpp
#define King_hpp

#include <stdio.h>
#include "Piece.h"
class Board;


class King : public Piece
{

public:
    ~King();
    King();
    King(int _x,int _y,Board *_plate,string _color,string _name);
    bool isVaildMove(int _x,int _y);
    bool isNoPieceThereInPath(int _x,int _y);
    
};
#endif /* King_hpp */
