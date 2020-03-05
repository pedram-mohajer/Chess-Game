#include "Board.h"
#include "iostream"
#include <iomanip>

using namespace std;

Board::Board(int _num)
{
    int i,j;
    
    for(i=0 ; i<8 ; i++)
        for(j=0 ; j<8 ; j++)
        {
                addressPlate[i][j] = NULL;
                existPlate[i][j] = 0;
                charPlate[i][j]  = "XXXXXX" ;
                colorPlate[i][j] = "XXXXXX" ;
        }
    num=_num;
}

Board::Board(){}

int Board::whichBoard()
{
    return num;
}

bool Board::isExist(int _x,int _y)
{

    if(existPlate[_x][_y]==1)
        return true;
    return false;
    
}

bool Board::isIn(int _x,int _y)
{
    return (_x>=0 && _x<=7) && (_y>=0 && _y<=7);
}

void Board::setIndexexistPlate(int _x,int _y)
{
    existPlate[_x][_y]=1;
}


void Board::setAddressPlate(int _x, int _y, Piece * piece)
{
    addressPlate[_x][_y] = piece;
}


Piece * Board::getAddressPlate(int _x, int _y)
{
    return addressPlate[_x][_y];
}



void Board::isNotExist(int _x,int _y)
{
    existPlate[_x][_y]=0;
}

void Board::display()
{
    
    int i,j;
    for(i=0 ; i<8 ; i++)
        cout << setw(13) << i ;
    cout << endl;
    for(i=0 ; i<8 ; i++)
    {
        cout << "----------------------------------------------------------------------------------------------------------------\n";
        
        for(j=0 ; j<8 ; j++)
                cout <<   charPlate[i][j] <<  colorPlate[i][j]   << setw(2) << "|" ;
        if(j==8)
        {
            cout << "  " << i ;
            cout << "\n";
        }
    }
     cout << "----------------------------------------------------------------------------------------------------------------\n";
}



void Board::setCharPlate(int _x,int _y,string type)
{
    charPlate[_x][_y] = type;
}


string Board::getCharPlate(int _x,int _y)
{
    return charPlate[_x][_y];
}

void Board::setColorPlate(int _x, int _y,string _color)
{
    colorPlate[_x][_y] = _color;
}

string Board::getColorPlate(int _x, int _y)
{
    return colorPlate[_x][_y];
}






