//
//  Bishop.cpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#include "Bishop.hpp"
#include "Board.h"
#include "iostream"

using namespace std;


Bishop::Bishop(){};



Bishop::Bishop(int _x,int _y,Board *_plate,string _color,string _name)

{
    name = _name;
    flag = 1 ;
    color = _color;
    plate=_plate;
    x=_x;
    y=_y;
    plate->setIndexexistPlate(x,y);
    plate->setAddressPlate(x,y,this);
    plate->setCharPlate(x, y, "Bishop-");
    plate->setColorPlate(x,y,_color);
}


bool Bishop::isVaildMove(int _x,int _y)
{
    return ((y-_y)/(x-_x)==1)||((y-_y)/(x-_x)==-1);
}


Bishop::~Bishop()
{
    cout << "Destroying Object\n" << endl;
}

bool Bishop::isNoPieceThereInPath(int _x,int _y)
{
    int Y,_Y,X,_X;
    
    Y = y; _Y=_y; X = x; _X = _x;
    
    if(Y < _Y && X < _X)
    {
        Y = Y + 1;
        X = X + 1;
        while(Y != _Y   && X != _X )
        {
            
            if(plate->isExist(X, Y))
                return false;
            Y = Y + 1;
            X = X + 1;
        }
        return true;
        
    }
    else
        if(Y < _Y && X > _X)
        {
            Y = Y + 1;
            X = X - 1;
            while(Y != _Y   && X != _X )
            {

                if(plate->isExist(X, Y))
                    return false;
                Y = Y + 1;
                X = X - 1;
            }
            
            return true;
            
        }
        else
            if(Y > _Y && X < _X)
            {
                Y = Y - 1;
                X = X + 1;
                while(Y != _Y   && X != _X )
                {
                    
                    if(plate->isExist(X,Y))
                        return false;
                    Y = Y - 1;
                    X = X + 1;
                }
                
                return true;
            }
            else
            {
                Y = Y - 1;
                X = X - 1;
                while(Y != _Y   && X != _X )
                {
                    
                    if(plate->isExist(X,Y))
                        return false;
                    Y = Y - 1;
                    X = X - 1;
                }
                
                return true;
            }
    
}


