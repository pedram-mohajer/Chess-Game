//
//  Person.cpp
//  Cheeses
//
//  Created by ButterFly on 5/20/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#include "Person.hpp"
#include "Piece.h"

#include <string>
#include <iostream>
using namespace std;


Person::Person(string _name,string _family, string _id, int _score, string _color)
{
     name    = _name;
     family  = _family;
     id      = _id;
     score   = _score;
     color   = _color;
}
void Person::showPersonInfo()
{
    cout << "name    : "   << name    << endl;
    cout << "family  : "   << family  << endl;
    cout << "id      : "   << id      << endl;
    cout << "score   : "   << score   << endl;
}

void Person::move(Board *board)
{
    int x,y,_x,_y;
    string error;
    
    cout << name <<" Pick up " << color << " Piece in (x,y) : " ;
    cin >> x >> y;
    if( !board->isExist(x,y) )
    {
        error = "No picec in (x,y)";
        throw error;
    }
    if( color.compare(board->getColorPlate(x,y) ) )
    {
        error = "Choose Wrong Color";
        throw error;
    }
    if(!board->isIn(x, y))
    {
        error= "Source (x,y) is not in board";
        throw error;
    }
    
    cout << name << " Place Piece in (_x,_y) : " ;
    cin >> _x >> _y;
    
    if(!board->isIn(_x,_y))
    {
        error= "Destination (x,y) is not in board";
        throw error;
    }
    if( !color.compare(board->getColorPlate(_x,_y)) )
    {
        error= "Destination (x,y) is Your Color";
        throw error;
    }
    try {
        board->getAddressPlate(x,y)->moveTo(_x,_y);
    } catch (string error) {
        throw error;
    }
    
}


bool Person::checKish(Board *board)
{
    string error;
    int i,j,xKing=-1,yKing=-1 ,found=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if(board->isExist(i,j))
                if( !(board->getAddressPlate(i,j)->getName()).compare("King") )
                  if(  !(board->getAddressPlate(i,j)->getColor()).compare(color))
                  {
                      xKing = board->getAddressPlate(i,j)->getX();
                      yKing = board->getAddressPlate(i,j)->getY();
                      found = 1 ; break;
                  }
        if(found)
            break;
    }
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board->isExist(i,j))
                if(  (board->getAddressPlate(i,j)->getColor()).compare(color) )
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing,yKing))
                        if(board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing,yKing))
                            
                        {
                            cout << " Kish --> you Must move your king";
                            try
                            {
                                moveKing(board,xKing,yKing);
                                return true;
                            }
                            catch(string error)
                            {
                                throw error;
                            }
                    }
    return false;
}


void Person::moveKing(Board *board,int X,int Y)
{
    int x,y,_x,_y;
    string error;
    x = X; y = Y;
    
    cout << name << " Place King in (_x,_y) : " ;
    cin >> _x >> _y;
    

    if(!checKishXY(board,_x,_y))
        {
            if(!board->isIn(_x,_y))
            {
                error= "Destination (x,y) for KING is not in board";
                throw error;
            }
            if( !color.compare(board->getColorPlate(_x,_y)) )
            {
                error= "Destination (x,y) for KING is Your Color";
                throw error;
            }
            try
            {
                board->getAddressPlate(x,y)->moveTo(_x,_y);
            }
            catch (string error)
            {
                throw error;
            }
        }
    else
        {
            error= "Your King (_x,_y) is KISH yet";
            throw error;
        }
    
}



bool Person::checKishXY(Board *board,int xKing,int yKing)
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board->isExist(i,j))
                if(  (board->getAddressPlate(i,j)->getColor()).compare(color) )
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing,yKing))
                        if(board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing,yKing))
                            return true;
    return false;
}




bool Person::checKishMat(Board *board)
{
    int p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
    
    string error;
    int i,j,xKing=-1,yKing=-1 ,found=0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board->isExist(i,j) && !found)
                if( !(board->getAddressPlate(i,j)->getName()).compare("King")   &&
                   !(board->getAddressPlate(i,j)->getName()).compare(color))
                {
                    xKing = board->getAddressPlate(i,j)->getX();
                    yKing = board->getAddressPlate(i,j)->getY();
                    found = 1 ; break;
                }
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board->isExist(i,j))
                if((board->getAddressPlate(i,j)->getColor()).compare(color))
                {
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing,yKing)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing,yKing) )
                        p1 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing+1,yKing+1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing+1,yKing+1) )
                        p2 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing-1,yKing-1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing-1,yKing-1) )
                        p3 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing+1,yKing-1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing+1,yKing-1) )
                        p4 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing-1,yKing+1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing-1,yKing+1) )
                        p5 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing+1,yKing)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing+1,yKing) )
                        p6 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing-1,yKing)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing-1,yKing) )
                        p7 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing,yKing+1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing,yKing+1) )
                        p8 = 1;
                    if(board->getAddressPlate(i,j)->isVaildMove(xKing,yKing-1)  &&
                       board->getAddressPlate(i,j)->isNoPieceThereInPath(xKing,yKing-1) )
                        p9 = 1;
                }
    if( p1 && p2 && p3 && p4 && p5 && p6 && p7 && p8 && p9)
        return  true;
    else
        return false;
    
}
