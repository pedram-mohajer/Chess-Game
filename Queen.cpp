//
//  Queen.cpp
//  Cheeses
//
//  Created by ButterFly on 5/15/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#include "Queen.hpp"
#include "Board.h"
#include "iostream"

using namespace std;


Queen::Queen(){};




Queen::Queen(int _x,int _y,Board *_plate,string _color,string _name)

{
    name = _name;
    flag = 1 ;
    color = _color;
    plate=_plate;
    x=_x;
    y=_y;
    plate->setIndexexistPlate(x,y);
    plate->setAddressPlate(x,y,this);
    plate->setCharPlate(x, y, "+Queen+");
    plate->setColorPlate(x,y,_color);
}


bool Queen::isVaildMove(int _x,int _y)
{
    
    return (x==_x) || (y==_y) || ((y-_y)/(x-_x)==1) || ((y-_y)/(x-_x)==-1);
}


Queen::~Queen()
{
    cout << "Destroying Object\n" << endl;
}





bool Queen::isNoPieceThereInPath(int _x,int _y)
{
    int Y,_Y,X,_X;
    
    Y = y; _Y=_y; X = x; _X = _x;
    
    if(x==_x)
    {
        Y = y; _Y=_y;
        if(Y < _Y)
        {
            Y = Y + 1;
            while(Y != _Y)
            {
                
                if(plate->isExist(x, Y))
                    return false;
                Y = Y + 1;
            }
            return true;
        }
        else
        {
            Y = Y - 1;
            while(Y != _Y)
            {
                
                if(plate->isExist(x, Y))
                    return false;
                Y = Y - 1;
            }
            return true;
        }
        
    }
    
    else
    if(y==_y)
    {
        X = x; _X = _x;
        if(X < _X)
        {
            X = X + 1;
            while(X != _X)
            {
                
                if(plate->isExist(X, y))
                    return false;
                X = X + 1;
            }
            return true;
        }
        else
        {
            X = X - 1;
            while(X != _X)
            {
                
                if(plate->isExist(X, y))
                    return false;
                X = X - 1;
            }
            return true;
        }
    }
    
    
    
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
            
            
            if(plate->isExist(X, Y))
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
            
            
            if(plate->isExist(X, Y))
                return false;
            Y = Y - 1;
            X = X - 1;
        }
        
        return true;
    }
    
}







