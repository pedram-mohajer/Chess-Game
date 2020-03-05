//
//  Person.hpp
//  Cheeses
//
//  Created by ButterFly on 5/20/19.
//  Copyright © 2019 ButterFly. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>

#include "Board.h"

using namespace std;

class Person
{
    private :
        string name;
        string family;
        string id;
        string color;
        int score;
    
    public :
        Person(string _name,string _family, string _id, int _score,string _color);
        void showPersonInfo();
        void move(Board *board);
        void moveKing(Board *board,int X,int Y);
        bool checKish(Board *board);
        bool checKishMat(Board *board);
        bool checKishXY(Board *board,int xKing,int yKing);
};

#endif /* Person_hpp */
