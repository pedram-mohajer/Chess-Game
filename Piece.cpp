//
//  Piece.cpp
//  Chess
//
//  Created by ButterFly on 5/8/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//
#include "iostream"
#include "Board.h"
#include "Piece.h"

void destructPiece(Piece *ptr )
{
    ptr->isSet(-1,-1);
    ptr->setZeroFlag();
    delete ptr;
}

string Piece::getColor()
{
    return color;
}
void Piece::whichPlace()
{
    cout << "(" << x << "," << y << ") in Board " << plate->whichBoard() << endl;
}


void Piece::isSet(int _x, int _y)
{
    x=_x; y=_y;
   
}

bool Piece::isVaildPlace(int _x,int _y)
{
    if(plate->isIn(_x,_y))
        return true;
    return false;
}

void Piece::moveTo(int _x,int _y)
{
    
    if(isVaildPlace(_x,_y))
    {
        if(plate->isExist(_x,_y))
        {
            if(isVaildMove(_x,_y))
            {
                
                if( isNoPieceThereInPath(_x,_y) )
                {
                    plate->setCharPlate(_x, _y, plate->getCharPlate(x,y));
                    plate->setCharPlate(x,y, "XXXXXX");
                
                    plate->setColorPlate(_x, _y, color);
                    plate->setColorPlate(x, y, "XXXXXX");
                
                    plate->setIndexexistPlate(_x, _y);
                    plate->isNotExist(x,y);
                
                
                
                
                    destructPiece(plate->getAddressPlate(_x,_y));
                    plate->setAddressPlate(x,y,NULL);
                    plate->setAddressPlate(_x,_y,this);
                
                    this->isSet(_x,_y);
                }
                else
                {
                    string error = "Path Is Not Empty For Moving";
                    throw error;
                }
                
            }
            else
            {
                string error = "Bad Moving";
                throw error;
            }
        }
        else
            if(isVaildMove(_x,_y))
            {
                if( isNoPieceThereInPath(_x,_y) )
                {
                    plate->setAddressPlate(_x,_y,this);
                    plate->setAddressPlate(x,y,NULL);
                
                    plate->setCharPlate(_x, _y, plate->getCharPlate(x,y));
                    plate->setCharPlate(x,y, "XXXXXX");
                
                    plate->setColorPlate(_x, _y, color);
                    plate->setColorPlate(x, y, "XXXXXX");
                
                    plate->setIndexexistPlate(_x, _y);
                    plate->isNotExist(x,y);
            
                    this->isSet(_x,_y);
                }
                else
                {
                    string error = "Path Is Not Empty For Moving";
                    throw error;
                }
            }
            else
            {
                string error = "Bad Moving";
                throw error;
            }
    }
        
};


int Piece::getFlag()
{
    return flag;
}
void Piece::setZeroFlag()
{
    flag = 0;
}

string Piece::getName()
{
    return name;
}


int Piece::getX()
{
    return x;
}
int Piece::getY()
{
    return y;
}







