//
//  Board.h
//  Chess
//
//  Created by ButterFly on 5/8/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//
#ifndef Board_h
#define Board_h

#include <string>
#include "Piece.h"



using namespace std;

class Board
{
private:
    int         existPlate[8][8];
    string      charPlate[8][8];
    Piece     * addressPlate[8][8];
    string      colorPlate[8][8];
    
    int num;
    
public:
    Board();
    Board(int _num);
    void display();
    int whichBoard();
    bool isIn(int _x,int _y);
    bool isExist(int _x,int _y);
    void isNotExist(int _x,int _y);
    void setIndexexistPlate(int _x,int _y);
    void setCharPlate(int _x,int _y, string type);
    string getCharPlate(int _x,int _y);
    void setAddressPlate(int _x, int _y,Piece *);
    void setColorPlate(int _x, int _y,string _color);
    string getColorPlate(int _x, int _y);
    
    Piece * getAddressPlate(int _x, int _y);
};

#endif /* Board_h */
