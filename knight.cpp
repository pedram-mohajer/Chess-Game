//
//  knight.cpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#include "knight.hpp"
#include "Board.h"
#include "iostream"

using namespace std;


knight::knight(){};


knight::knight(int _x,int _y,Board *_plate,string _color,string _name)

{
    name = _name;
    flag = 1 ;
    color = _color;
    plate=_plate;
    x=_x;
    y=_y;
    plate->setIndexexistPlate(x,y);
    plate->setAddressPlate(x,y,this);
    plate->setCharPlate(x, y, "knight-");
    plate->setColorPlate(x,y,_color);
}


bool knight::isVaildMove(int _x,int _y)
{
    bool value;
    int temp,xChange=0,yChange=0;
    if(x>_x){ temp = _x; _x = x; x = temp;xChange=1;}
    if(y>_y){ temp = _y; _y = y; y = temp;yChange=1;}
    value = (x == _x-2 && y==_y-1) || (x == _x-2 && y==_y+1) || (x == _x+2 && y==_y-1) ||         (x == _x+2 && y==_y-1) || (x == _x+2 && y==_y-1) || (x == _x-1 && y==_y-2) ||           (x == _x+1 && y==_y-2) || (x == _x+1 && y==_y+2) || (x == _x-1 && y==_y+2);
    if(xChange)
        { temp = _x; _x = x; x = temp;}
    if(yChange)
        { temp = _y; _y = y; y = temp;}
    return value;
}


knight::~knight()
{
    cout << "Destroying Object\n" << endl;
}



bool knight::isNoPieceThereInPath(int _x,int _y)
{
    return true;
}





