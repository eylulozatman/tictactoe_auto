
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define DIMENSION 3
#define PLAYER1_MARKER 'X'
#define COMPUTER_MARKER 'O'
#define EMPTY_SPACE ' '
using namespace std;

char board[DIMENSION][DIMENSION];

void clearBoard()
{

    for (int i = 0; i < DIMENSION; ++i)
    {
        for (int j = 0; j < DIMENSION; ++j)
        {
            board[i][j] = EMPTY_SPACE;
        }
    }
}
// Print the board in the given format in std.txt file
void printBoard()
{
    for (int i = 0; i < DIMENSION; ++i)
    {
        for (int j = 0; j < DIMENSION; ++j)
        {
          
           cout << "[" << board[i][j] << "]";
        }
        cout << "\n";
    }
}
// Check that if the given coordinate is in the bound of board and suitable to place a marker

bool isAvailable(int row, int column)
{

   if (board[row][column] == EMPTY_SPACE )
   { 
   
       return true;
   }
   else
     
       return false;

}
// Place Marker. Place the corresponding marker to the board
void placeMarker(int row, int column, bool firstPlayerTurn)
{

    if (firstPlayerTurn)
    { 
        board[row][column] = PLAYER1_MARKER;

    } 
    else
    {
        

        board[row][column] = COMPUTER_MARKER;
    }

}
// Place your marker to any available corner.


void playerFirstMove()
{
    srand( time(NULL) );
   int random =  rand() % 4;

    switch (random)
    {
        case 0:
            placeMarker(0,0, true);
            break;
        case 1:
            placeMarker(0,2, true);
            break;
        case 2:
            placeMarker(2,0, true);
            break;
        case 3:
            placeMarker(2,2, true);
            break;
        default: break;
    }


}
// Place a second marker in an adjacent corner
void playerSecondMove()
{
    if (board[0][0] == PLAYER1_MARKER || board[2][2] == PLAYER1_MARKER)
    {
        int random =  rand() % 2;
        switch (random)
        {
            case 0:
                if (isAvailable(2,0))
                {
                    placeMarker(2,0, true);
                }
                break;

            case 1:
                if (isAvailable(0,2))
                {
                    placeMarker(0,2, true);
                }
                break;
            default:break;
        }
    }
    else (board[0][2] == PLAYER1_MARKER || board[2][0] == PLAYER1_MARKER);
    {
        int random =  rand() % 2;
        switch (random)
        {
            case 0:
                if (isAvailable(0,0))
                {
                    placeMarker(0,0, true);
                }
                break;

            case 1:
                if (isAvailable(2,2))
                {
                    placeMarker(2,2, true);
                }
                break;
            default:break;
        }
    }

}
// Checks that if the game over in any state
bool gameOver()
{


    if(board[0][0]==PLAYER1_MARKER && board[0][1]==PLAYER1_MARKER && board[0][2]==PLAYER1_MARKER)

        return true;

    else if(board[1][0]==PLAYER1_MARKER && board[1][1]==PLAYER1_MARKER && board[1][2]==PLAYER1_MARKER )
        return true;

    else if(board[2][0] == PLAYER1_MARKER && board[2][1] == PLAYER1_MARKER && board[2][2] == PLAYER1_MARKER )
        return true;

   else if(board[0][0]==PLAYER1_MARKER && board[1][0]==PLAYER1_MARKER && board[2][0]==PLAYER1_MARKER )
        return true;

    else if(board[0][1]==PLAYER1_MARKER && board[1][1]==PLAYER1_MARKER && board[2][1]==PLAYER1_MARKER )
        return true;

  else if(board[0][2]==PLAYER1_MARKER && board[1][2]==PLAYER1_MARKER && board[2][2]==PLAYER1_MARKER )
        return true;

    else if(board[0][0]==PLAYER1_MARKER && board[1][1]==PLAYER1_MARKER && board[2][2]==PLAYER1_MARKER )
        return true;

    else if(board[2][0]==PLAYER1_MARKER && board[1][1]==PLAYER1_MARKER && board[0][2]==PLAYER1_MARKER )
        return true;

   else if(board[0][0] == COMPUTER_MARKER && board[0][1] == COMPUTER_MARKER && board[0][2] == COMPUTER_MARKER )
        return true;

    else if(board[1][0]==COMPUTER_MARKER && board[1][1]==COMPUTER_MARKER && board[1][2]==COMPUTER_MARKER )
        return true;

   else if(board[2][0]==COMPUTER_MARKER && board[2][1]==COMPUTER_MARKER && board[2][2]==1 )
        return true;

    else if(board[0][0]==COMPUTER_MARKER && board[1][0]==COMPUTER_MARKER && board[2][0]==COMPUTER_MARKER  )
        return true;

    else if(board[0][1]==COMPUTER_MARKER  && board[1][1]==COMPUTER_MARKER  && board[2][1]==COMPUTER_MARKER )
        return true;

    else if(board[0][2]==COMPUTER_MARKER  && board[1][2]==COMPUTER_MARKER  && board[2][2]==COMPUTER_MARKER  )
        return true;

    else if(board[0][0]==COMPUTER_MARKER  && board[1][1]==COMPUTER_MARKER  && board[2][2]==COMPUTER_MARKER  )
        return true;

    else if(board[2][0]==COMPUTER_MARKER  && board[1][1]==COMPUTER_MARKER  && board[0][2]==COMPUTER_MARKER  )
        return true;
    else return false;


}
// Fill the function to apply correct strategy
void playerMove1()
{
    int chance = 0;
    for (int i = 0; i < 3; ++i)
    {

        if (board[0][i] == PLAYER1_MARKER )
        {
           chance++;
        }
        else break;
    }
    if (chance == 2)
    {
        int i = 0;
        while (!isAvailable(0, i))
        {
            placeMarker(0, i, true);
            i++;
        }

    }
    else
    {
        srand(time(NULL));
        int row, column;
        do {
            row = rand() % DIMENSION;
            column = rand() % DIMENSION;
        } while (!isAvailable(row, column));
        placeMarker(row, column, true);
    }



}
void computerMove1() {
    srand(time(NULL));
    int row, column;
    do {
        row = rand() % DIMENSION;
        column = rand() % DIMENSION;
    } while (!isAvailable(row, column));
    placeMarker(row, column, false);
}

void playerMove()
{

    int row, column;
    
    row = rand() % DIMENSION;
    column = rand() % DIMENSION;

    if(isAvailable(row, column) ){
        placeMarker(row, column, true);

    }
    else {
        
        playerMove();
    }

}
void computerMove() {
 
    int row, column;
    
    row = rand() % DIMENSION;
    column = rand() % DIMENSION;

    if(isAvailable(row, column)){
        placeMarker(row, column, false);
    }
    else {
      

        computerMove();
    }
}


void play()
{
    computerMove();
    printBoard();
    cout << "-----------------------" "\n";
    playerMove();
    printBoard();
    cout << "-----------------------" "\n";

}
int main()
{
    srand(time(NULL));
    printBoard();
    clearBoard();
    cout << "-----------------------" "\n";
    while (!gameOver())
    {
       play();

    }
     

}
