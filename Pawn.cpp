//
//  Pawn.cpp
//  Chess
//
//  Created by ButterFly on 5/8/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#include "Pawn.h"
#include "Board.h"

#include "iostream"
using namespace std;

Pawn::Pawn(){};


Pawn::Pawn(int _x,int _y,Board *_plate,string _color,string _name)

{
    name = _name;
    flag = 1 ;
    color = _color;
    plate=_plate;
    x=_x;
    y=_y;
    plate->setIndexexistPlate(x,y);
    plate->setAddressPlate(x,y,this);
    plate->setCharPlate(x, y, "-Pawn--");
    plate->setColorPlate(x,y,_color);
}

Pawn::~Pawn()
{
    cout << "Destroying Object\n" << endl;
}



bool Pawn::isVaildMove(int _x,int _y)
{
    
 if( (_x==x+1 && y==_y) && color == "White" && !plate->isExist(_x,y) )
        return true;
 if( (_x==x-1 && y==_y) && color == "Black" && !plate->isExist(_x,y))
        return true;
    
 if( ((x==_x+1 && y==_y+1) || (x==_x+1 && y==_y-1)) && color == "Black"  )
        if(plate->isExist(_x,_y))
            return true;
 if( ((x==_x-1 && y==_y-1) ||  (x==_x-1 && y==_y+1)) && color == "White" )
        if(plate->isExist(_x,_y))
            return true;
    return false;
}



bool Pawn::isNoPieceThereInPath(int _x,int _y)
{
    return true;
}













