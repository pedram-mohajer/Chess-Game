//
//  Piece.h
//  Chess
//
//  Created by ButterFly on 5/8/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

class Board;
#include <string>
using namespace std;



class Piece
{
protected:
    int x,y;
    int flag;
    Board *plate;
    string color;
    string name;
public:
    int getFlag();
    void setZeroFlag();
    string getColor();
    void isSet(int _x, int _y);
    bool isVaildPlace(int,int);
    void moveTo	(int,int);
    void whichPlace();
    string getName();
    int getX();
    int getY();
    friend void  destructPiece(Piece *);
    virtual bool isVaildMove(int,int)=0;
    virtual bool isNoPieceThereInPath(int _x,int _y)=0;
};

#endif /* Piece_h */
