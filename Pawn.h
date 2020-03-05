//
//  Pawn.h
//  Chess
//
//  Created by ButterFly on 5/8/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef Pawn_h
#define Pawn_h

#include "Piece.h"
class Board;

class Pawn : public Piece
{


public:
    ~Pawn();
    Pawn();
    Pawn(int _x,int _y,Board *_plate,string _color,string _name);
    bool isVaildMove(int _x,int _y);
    bool isNoPieceThereInPath(int _x,int _y);

};


#endif /* Pawn_h */
