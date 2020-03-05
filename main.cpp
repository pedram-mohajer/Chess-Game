
#include "Pawn.h"
#include "Bishop.hpp"
#include "Board.h"
#include "knight.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Piece.h"
#include "Person.hpp"
#include <iostream>
#include <string>

using namespace std;




int main()
{
    
    Board board(1);
    Pawn   *pw1  = new Pawn(1,0,&board,"White","Pawn");
    Pawn   *pw2  = new Pawn(1,1,&board,"White","Pawn");
    Pawn   *pw3  = new Pawn(1,2,&board,"White","Pawn");
    Pawn   *pw4  = new Pawn(1,3,&board,"White","Pawn");
    Pawn   *pw5  = new Pawn(1,4,&board,"White","Pawn");
    Pawn   *pw6  = new Pawn(1,5,&board,"White","Pawn");
    Pawn   *pw7  = new Pawn(1,6,&board,"White","Pawn");
    Pawn   *pw8  = new Pawn(1,7,&board,"White","Pawn");
    
    Rook   *rw1   = new Rook(0,0,&board,"White","Rook");
    knight *knw1  = new knight(0,1,&board,"White","knight");
    Bishop *bw1   = new Bishop(0,2,&board,"White","Bishop");
    Queen  *qw    = new Queen(0,3,&board,"White","Queen");
    King   *kw    = new King(0,4,&board,"White","King");
    Bishop *bw2   = new Bishop(0,5,&board,"White","Bishop");
    knight *knw2  = new knight(0,6,&board,"White","knight");
    Rook   *rw2   = new Rook(0,7,&board,"White","Rook");
    
    
    Pawn   *pb1  = new Pawn(6,0,&board,"Black","Pawn");
    Pawn   *pb2  = new Pawn(6,1,&board,"Black","Pawn");
    Pawn   *pb3  = new Pawn(6,2,&board,"Black","Pawn");
    Pawn   *pb4  = new Pawn(6,3,&board,"Black","Pawn");
    Pawn   *pb5  = new Pawn(6,4,&board,"Black","Pawn");
    Pawn   *pb6  = new Pawn(6,5,&board,"Black","Pawn");
    Pawn   *pb7  = new Pawn(6,6,&board,"Black","Pawn");
    Pawn   *pb8  = new Pawn(6,7,&board,"Black","Pawn");
    
    Rook   *rb1   = new Rook(7,0,&board,"Black","Rook");
    knight *knb1  = new knight(7,1,&board,"Black","knight");
    Bishop *bb1   = new Bishop(7,2,&board,"Black","Bishop");
    Queen  *qb    = new Queen(7,3,&board,"Black","Queen");
    King   *kb    = new King(7,4,&board,"Black","King");
    Bishop *bb2   = new Bishop(7,5,&board,"Black","Bishop");
    knight *knb2  = new knight(7,6,&board,"Black","knight");
    Rook   *rb2   = new Rook(7,7,&board,"Black","Rook");
    
    
    Person p1("Pedram","Mohajer","94033",5000,"Black");
    Person p2("Farhad","Ansary","94048",5000,"White");
    
    int turn1=0,turn2=1;
    
    board.display();
    while(1)
    {
        if(turn1==1 && turn2==0 )
            try
            {
                if(!p1.checKish(&board))
                    p1.move(&board);
                
                turn1 = 0;
                turn2 = 1;
                board.display();
                if(p1.checKishMat(&board))
                {
                    cout << "winner : \n";
                    p2.showPersonInfo();
                    
                }
            }
            catch (string error)
            {
                cout << error << endl;
            }
        if(turn1==0 && turn2==1 )
            try
            {
                if(!p2.checKish(&board))
                    p2.move(&board);
                turn1 = 1;
                turn2 = 0;
                board.display();
                if(p2.checKishMat(&board))
                {
                    cout << "winner : \n";
                    p1.showPersonInfo();
                    
                }
            }
        catch (string error)
            {
                cout << error << endl;
            }
        
    }

    return 0;
}







