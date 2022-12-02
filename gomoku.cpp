

#include "gomoku.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iostream>
#include <iomanip>


using namespace std;

gomoku::gomoku()
{

}

void gomoku::printBoard(int boardSize, char gameBoard[][15])
{
    for (int i =0 ; i<boardSize; i++)               //traverse through every array index for the given board size
    {
        for (int j =0 ; j<boardSize; j++)
        {
            gameBoard[i][j]=' ';                    // fill the array with empty spaces
        }
    }
}

bool gomoku::isMoveValid( char gameBoard[][15], int rowPosition, int columnPosition)
{
    if (gameBoard[rowPosition][columnPosition]==' ')
    {
        return true;                                    // If the array index consists of an empty space, the position can be played in and is thus a valid move
    }
    else if (gameBoard[rowPosition][columnPosition]=='X' || gameBoard[rowPosition][columnPosition]=='O')
    {
        return false;                                   // If the array index consists of an X or O, the position cannot be played in and is thus an invalid move
    }

}

int gomoku::checkForWinner(int boardSize, char gameBoard[][15])
{
    //Declare Variables for counters to determine if there 5 in a row
    int counterRows=1;
    int counterColumns=1;
    int counterDiagonals1 = 1;
    int counterDiagonals2 = 1;
    int counterDiagonals3 = 1;
    int counterDiagonals4 = 1;
    int counterDiagonals5 = 1;
    int counterDiagonals6 = 1;

    // Check for a winner in the rows
    for (int i= 0; i<boardSize; i++)
    {
        for (int j=0; j<boardSize; j++)             //Traverse through each of the array indexes
        {
                if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3]&&gameBoard[i][j+3]==gameBoard[i][j+4])
                {
                    counterRows++;      // If there are 5 indexes in a row that are not empty and are occupied by the same marker then increase the counter by 1
                }
                if (counterRows==2)     // When there are 5 in a line, check who is the winner
                {
                    if (gameBoard[i][j]=='X')       //If Player 1 has 5 in a line
                    {
                        return 1;                   //Return 1
                    }

                    else if  (gameBoard[i][j]=='O') //If Player 2 has 5 in a line
                    {
                         return -1;                 //Return -1
                    }
                }
        }
    }

    // Check for a winner in the columns
    for (int i= 0; i<boardSize; i++)
    {
        for (int j=0; j<boardSize; j++) //Traverse through each of the array indexes
        {
            if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j]&&gameBoard[i+1][j]==gameBoard[i+2][j]&&gameBoard[i+2][j]==gameBoard[i+3][j]&&gameBoard[i+3][j]==gameBoard[i+4][j])
            {
                counterColumns++;       // If there are 5 indexes in a column that are not empty and are occupied by the same marker then increase the counter by 1
            }

            if (counterColumns==2)      // When there are 5 in a line, check who is the winner
            {
                if (gameBoard[i][j]=='X')        //If Player 1 has 5 in a line
                {
                    return 1;                    //Return 1
                }

                else if  (gameBoard[i][j]=='O')  //If Player 2 has 5 in a line
                {
                        return -1;               //Return -1
                }
            }
        }
    }

    // Check for a winner in the leading diagonal
    for (int i =0 ; i<boardSize; i++)   //Traverse through each of the array indexes
    {
        if ((gameBoard[i][i]!=' ') && gameBoard[i][i]==gameBoard[i+1][i+1]&&gameBoard[i+1][i+1]==gameBoard[i+2][i+2]&&gameBoard[i+2][i+2]==gameBoard[i+3][i+3]&&gameBoard[i+3][i+3]==gameBoard[i+4][i+4])
        {
            counterDiagonals1++;              // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
        }

        if (counterDiagonals1==2)            // When there are 5 in a line, check who is the winner
        {

            if (gameBoard[i][i]=='X')        //If Player 1 has 5 in a line
            {
                return 1;                    //Return 1
            }

            else if(gameBoard[i][i]=='O')    //If Player 2 has 5 in a line
            {
                return -1;                   //Return -1
            }
        }
    }

    // Check for a winner in the diagonals above the leading diagonal
    for (int i = 0; i<boardSize;i++)
    {
        for (int j=1; j<boardSize;j++)          //Traverse through each of the array indexes
        {
            if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j+1]&&gameBoard[i+1][j+1]==gameBoard[i+2][j+2]&&gameBoard[i+2][j+2]==gameBoard[i+3][j+3]&&gameBoard[i+3][j+3]==gameBoard[i+4][j+4] )
            {
                counterDiagonals2++;            // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
            }

            if (counterDiagonals2==2)           // When there are 5 in a line, check who is the winner
            {

                if (gameBoard[i][j]=='X')       //If Player 1 has 5 in a line
                {
                return 1;                       //Return 1
                }

                else if  (gameBoard[i][j]=='O') //If Player 2 has 5 in a line
                {
                return -1;                      //Return -1
                }
            }
        }
    }


    // Check for a winner in the diagonals below the leading diagonal
    for (int i = 1; i<boardSize;i++)
    {
        for (int j=0; j<boardSize;j++)               //Traverse through each of the array indexes
        {
            if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j+1]&&gameBoard[i+1][j+1]==gameBoard[i+2][j+2]&&gameBoard[i+2][j+2]==gameBoard[i+3][j+3]&&gameBoard[i+3][j+3]==gameBoard[i+4][j+4] )
            {
                counterDiagonals3++;                // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
            }

            if (counterDiagonals3==2)               // When there are 5 in a line, check who is the winner
            {

                if (gameBoard[i][j]=='X')           //If Player 1 has 5 in a line
                {
                return 1;                           //Return 1
                }

                else if  (gameBoard[i][j]=='O')     //If Player 2 has 5 in a line
                {
                return -1;                          //Return -1
                }
            }
        }
    }


   // Check for a winner in the counter diagonal
    for (int i =0, j = boardSize-1 ; i<boardSize; i++, j--)         //Traverse through each of the array indexes
    {
       if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j-1]&&gameBoard[i+1][j-1]==gameBoard[i+2][j-2]&&gameBoard[i+2][j-2]==gameBoard[i+3][j-3]&&gameBoard[i+3][j-3]==gameBoard[i+4][j-4])
        {
            counterDiagonals4++;                                    // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
        }

        if (counterDiagonals4==2)                                   // When there are 5 in a line, check who is the winner
        {

            if (gameBoard[i][j]=='X')                               //If Player 1 has 5 in a line
            {
                return 1;                                           //Return 1
            }

            else if  (gameBoard[i][j]=='O')                         //If Player 2 has 5 in a line
            {
                return -1;                                          //Return -1
            }
        }
    }


    // Check for a winner in the diagonals above the counter diagonal
    for (int i =0 ; i<boardSize; i++)
    {
        for (int j=boardSize-2; j>=0;j--)                       //Traverse through each of the array indexes
        {
            if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j-1]&&gameBoard[i+1][j-1]==gameBoard[i+2][j-2]&&gameBoard[i+2][j-2]==gameBoard[i+3][j-3]&&gameBoard[i+3][j-3]==gameBoard[i+4][j-4])
            {
                counterDiagonals5++;                            // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
            }

            if (counterDiagonals5==2)                           // When there are 5 in a line, check who is the winner
            {

                if (gameBoard[i][j]=='X')                       //If Player 1 has 5 in a line
                {
                    return 1;                                   //Return 1
                }

                else if  (gameBoard[i][j]=='O')                 //If Player 2 has 5 in a line
                {
                    return -1;                                  //Return -1
                }
            }
        }
    }

    // Check for a winner in the diagonals below the counter diagonal
    for (int i =1 ; i<boardSize; i++)
    {
        for (int j=boardSize-1; j>=0;j--)                       //Traverse through each of the array indexes
        {
            if ((gameBoard[i][j]!=' ') && gameBoard[i][j]==gameBoard[i+1][j-1]&&gameBoard[i+1][j-1]==gameBoard[i+2][j-2]&&gameBoard[i+2][j-2]==gameBoard[i+3][j-3]&&gameBoard[i+3][j-3]==gameBoard[i+4][j-4])
            {
                counterDiagonals6++;                            // If there are 5 indexes in a diagonal that are not empty and are occupied by the same marker then increase the counter by 1
            }

            if (counterDiagonals6==2)                           // When there are 5 in a line, check who is the winner
            {

                if (gameBoard[i][j]=='X')                       //If Player 1 has 5 in a line
                {
                    return 1;                                   //Return 1
                }

                else if  (gameBoard[i][j]=='O')                 //If Player 2 has 5 in a line
                {
                    return -1;                                  //Return -1
                }
            }
        }
    }

    return 0;                                                   //Return 0 until a winner can be concluded or the game ends in a draw
}

void gomoku::alg1(int boardSize, char gameBoard[][15], char player1, ofstream& outputData)
{
    //Declare variables
    int column;         // Stores the random column position generated
    int row;            // Stores the random row position generated
    bool randomMove;

    srand(time(NULL));                      // Changes the seeding of the random number generator so that a different number is generated each time
    column=rand()%(boardSize);              // Generates a random number between 0 and (boardSize-1) and is then assigned to the column variable
    row=rand()%(boardSize);                 // Generates a random number between 0 and (boardSize-1) and is then assigned to the row variable

    randomMove=isMoveValid( gameBoard, row, column);                    //Checks if the random row and column generated is already occupied


    while ( randomMove!= true)                                          //Until the random move returns a valid move
    {                                                                   //a random number for the rows and column
        srand(time(NULL));                                              //will be generated and continuously checks
        column=rand()%(boardSize);                                      //if the move is valid
        row=rand()%(boardSize);
        randomMove =isMoveValid( gameBoard, row, column);
    }
        outputData<<"r"<<row<<"c"<<column<< " " <<setw(2)<<"alg1" <<endl;       //Output the rows and columns of the valid move
        gameBoard[row][column]=player1;                                         //Assign the valid move with player 1's marker (X)
}

int gomoku::alg2SmartMove(int boardSize, char gameBoard[][15], char player2, ofstream& outputData)
{

    for (int i=0; i <boardSize; i++)
    {
        for (int j=0; j<boardSize; j++)
        {
           for (int k=boardSize-1; k>=0;k-- )           //Traverse through
           {
                //Check for 4 in a line and  play the winning move horizontally on the right side
                if (i<(boardSize)&&j<(boardSize-4)&&gameBoard[i][j+4]!='X'&&gameBoard[i][j+4]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3])
                {
                    gameBoard[i][j+4]=player2;                                            //Assign the valid move with player 2's marker (O)
                    outputData<<"r"<<i<<"c"<<j+4<< " " <<setw(2)<<"alg2" <<endl;         //Output the rows and columns of the valid move
                    return 1;                                                            //Returns 1 when a valid move is made
                    break;                                                               //Breaks the loop so that only one move is made
                }
                //check for 4 in a line and play the winning move horizontally on the left side
                else if(i<(boardSize)&&j<(boardSize)&&gameBoard[i][j-1]!='X'&&gameBoard[i][j-1]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2]&&gameBoard[i][j+2]==gameBoard[i][j+3])
                {
                    gameBoard[i][j-1]=player2;
                    outputData<<"r"<<i<<"c"<<j-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 4 in a line and play the winning move vertically at the bottom
                else if (i<(boardSize)&&j<(boardSize-4)&&gameBoard[j+4][i]!='X'&&gameBoard[j+4][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i]&&gameBoard[j+1][i]==gameBoard[j+2][i]&&gameBoard[j+2][i]==gameBoard[j+3][i])
                {
                    gameBoard[j+4][i]=player2;
                    outputData<<"r"<<j+4<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 4 in a line and play the winning move vertically at the top
                else if (i<(boardSize)&&j<(boardSize)&&gameBoard[j-1][i]!='X'&&gameBoard[j-1][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i]&&gameBoard[j+1][i]==gameBoard[j+2][i]&&gameBoard[j+2][i]==gameBoard[j+3][i])
                {
                    gameBoard[j-1][i]=player2;
                    outputData<<"r"<<j-1<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }

                //check for 4 in a line and play the winning move at the bottom of the leading diagonal
                else if (i<(boardSize-4)&&gameBoard[i+4][i+4]!='X'&&gameBoard[i+4][i+4]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1]&&gameBoard[i+1][i+1]==gameBoard[i+2][i+2]&&gameBoard[i+2][i+2]==gameBoard[i+3][i+3])
                {
                    gameBoard[i+4][i+4]=player2;
                    outputData<<"r"<<i+4<<"c"<<i+4<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 4 in a line and play the winning move at the top of the leading diagonal
                else if (i<(boardSize)&&gameBoard[i-1][i-1]!='X'&&gameBoard[i-1][i-1]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1]&&gameBoard[i+1][i+1]==gameBoard[i+2][i+2]&&gameBoard[i+2][i+2]==gameBoard[i+3][i+3])
                {
                    gameBoard[i-1][i-1]=player2;
                    outputData<<"r"<<i-1<<"c"<<i-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 4 in a line and play the winning move at the bttom of the counter diagonal
                else if (i<(boardSize-4)&&k<(boardSize)&&gameBoard[i+4][k-4]!='X'&&gameBoard[i+4][k-4]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1]&&gameBoard[i+1][k-1]==gameBoard[i+2][k-2]&&gameBoard[i+2][k-2]==gameBoard[i+3][k-3])
                {
                    gameBoard[i+4][k-4]=player2;
                    outputData<<"r"<<i+4<<"c"<<k-4<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 4 in a line  and play the winning move at the top of the counter diagonal
                else if (i<(boardSize)&&k<(boardSize-1)&&gameBoard[i-1][k+1]!='X'&&gameBoard[i-1][k+1]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1]&&gameBoard[i+1][k-1]==gameBoard[i+2][k-2]&&gameBoard[i+2][k-2]==gameBoard[i+3][k-3])
                {
                    gameBoard[i-1][k+1]=player2;
                    outputData<<"r"<<i-1<<"c"<<k+1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }



                //check for 3 in a line and play move horizontally on the right side
                else if (i<(boardSize)&&j<(boardSize-3)&&gameBoard[i][j+3]!='X'&&gameBoard[i][j+3]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2])
                {
                    gameBoard[i][j+3]=player2;
                    outputData<<"r"<<i<<"c"<<j+3<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 3 in a line and play move horizontally on the left side
                else if(i<(boardSize)&&j<(boardSize)&&gameBoard[i][j-1]!='X'&&gameBoard[i][j-1]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1]&&gameBoard[i][j+1]==gameBoard[i][j+2])
                {
                    gameBoard[i][j-1]=player2;
                    outputData<<"r"<<i<<"c"<<j-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 3 in a line and play move  vertically at the bottom
                else if (i<(boardSize)&&j<(boardSize-3)&&gameBoard[j+3][i]!='X'&&gameBoard[j+3][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i]&&gameBoard[j+1][i]==gameBoard[j+2][i])
                {
                    gameBoard[j+3][i]=player2;
                    outputData<<"r"<<j+3<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 3 in a line and play move  vertically at the top
                else if (i<(boardSize)&&j<(boardSize)&&gameBoard[j-1][i]!='X'&&gameBoard[j-1][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i]&&gameBoard[j+1][i]==gameBoard[j+2][i])
                {
                    gameBoard[j-1][i]=player2;
                    outputData<<"r"<<j-1<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }

                 //check for 3 in a line and play move at the bottom of the leading diagonal
                else if (i<(boardSize-3)&&gameBoard[i+3][i+3]!='X'&&gameBoard[i+3][i+3]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1]&&gameBoard[i+1][i+1]==gameBoard[i+2][i+2])
                {
                    gameBoard[i+3][i+3]=player2;
                    outputData<<"r"<<i+3<<"c"<<i+3<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 3 in a line and play the move at the top of the leading diagonal
                else if (i<(boardSize)&&gameBoard[i-1][i-1]!='X'&&gameBoard[i-1][i-1]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1]&&gameBoard[i+1][i+1]==gameBoard[i+2][i+2])
                {
                    gameBoard[i-1][i-1]=player2;
                    outputData<<"r"<<i-1<<"c"<<i-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }

                //check for 3 in a lin3 and play the move at the bottom of the counter diagonal
                else if (i<(boardSize-3)&&k<(boardSize)&&gameBoard[i+3][k-3]!='X'&&gameBoard[i+3][k-3]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1]&&gameBoard[i+1][k-1]==gameBoard[i+2][k-2])
                {
                    gameBoard[i+3][k-3]=player2;
                    outputData<<"r"<<i+3<<"c"<<k-3<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 3 in a line and play the move at the top of the counter diagonal
                else if (i<(boardSize)&&k<(boardSize-1)&&gameBoard[i-1][k+1]!='X'&&gameBoard[i-1][k+1]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1]&&gameBoard[i+1][k-1]==gameBoard[i+2][k-2])
                {
                    gameBoard[i-1][k+1]=player2;
                    outputData<<"r"<<i-1<<"c"<<k+1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }


                 //check for 2 in a line and play move horizontally on the right side
                else if (i<(boardSize)&&j<(boardSize-2)&&gameBoard[i][j+2]!='X'&&gameBoard[i][j+2]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1])
                {
                    gameBoard[i][j+2]=player2;
                    outputData<<"r"<<i<<"c"<<j+2<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 2 in a line and play move horizontally on the left side
                else if(i<(boardSize)&&j<(boardSize)&&gameBoard[i][j-1]!='X'&&gameBoard[i][j-1]==' '&&gameBoard[i][j]==player2&&gameBoard[i][j]==gameBoard[i][j+1])
                {
                    gameBoard[i][j-1]=player2;
                    outputData<<"r"<<i<<"c"<<j-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 2 in a line and play move  vertically at the bottom
                else if (i<(boardSize)&&j<(boardSize-2)&&gameBoard[j+2][i]!='X'&&gameBoard[j+2][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i])
                {
                    gameBoard[j+2][i]=player2;
                    outputData<<"r"<<j+2<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 2 in a line and play move  vertically at the top
                else if (i<(boardSize)&&j<(boardSize)&&gameBoard[j-1][i]!='X'&&gameBoard[j-1][i]==' '&&gameBoard[j][i]==player2&&gameBoard[j][i]==gameBoard[j+1][i])
                {
                    gameBoard[j-1][i]=player2;
                    outputData<<"r"<<j-1<<"c"<<i<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }

                 //check for 2 in a line  and play the move at the bottom of the leading diagonal
                else if (i<(boardSize-2)&&gameBoard[i+2][i+2]!='X'&&gameBoard[i+2][i+2]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1])
                {
                    gameBoard[i+2][i+2]=player2;
                    outputData<<"r"<<i+2<<"c"<<i+2<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 2 in a line and play the move at the top of the leading diagonal
                else if (i<(boardSize)&&gameBoard[i-1][i-1]!='X'&&gameBoard[i-1][i-1]==' '&&gameBoard[i][i]==player2&&gameBoard[i][i]==gameBoard[i+1][i+1])
                {
                    gameBoard[i-1][i-1]=player2;
                    outputData<<"r"<<i-1<<"c"<<i-1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }


                //check for 2 in a line and play the move at the bottom of the counter diagonal
                else if (i<(boardSize-2)&&k<(boardSize)&&gameBoard[i+2][k-2]!='X'&&gameBoard[i+2][k-2]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1])
                {
                    gameBoard[i+2][k-2]=player2;
                    outputData<<"r"<<i+2<<"c"<<k-2<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
                //check for 2 in a line and play the move at the top of the counter diagonal
                else if (i<(boardSize)&&k<(boardSize-1)&&gameBoard[i-1][k+1]!='X'&&gameBoard[i-1][k+1]==' '&&gameBoard[i][k]==player2&&gameBoard[i][k]==gameBoard[i+1][k-1])
                {
                    gameBoard[i-1][k+1]=player2;
                    outputData<<"r"<<i-1<<"c"<<k+1<< " " <<setw(2)<<"alg2" <<endl;
                    return 1;
                    break;
                }
           }

        }

    }
    return 0;               //Return 0 if no valid move can be found
}

void gomoku::alg2(int boardSize, char gameBoard[][15],char player2, ofstream& outputData)
{
    //Declare Variables
    int row;            // Stores the random column position generated
    int column;         // Stores the random row position generated
    bool randomMove;
    int smartMove;

    srand(time(NULL));  // Changes the seeding of the random number generator so that a different number is generated each time

    smartMove = alg2SmartMove(boardSize,gameBoard, player2, outputData); //If the alg2SmartMove function returns a 1, there is a predefined move that is found and algorithm 2 will carry out that move

    if (smartMove!=1)                     //If no predefined move is found
    {
        column=rand()%(boardSize);       //algorithm 2 will generate a random row and column
        row=rand()%(boardSize);          //to play in

        randomMove =isMoveValid( gameBoard, row, column);  //Checks if the random row and column generated is already occupied

        while ( randomMove!= true)                                  //Until the random move returns a valid move
        {                                                           //a random number for the rows and column
            srand(time(NULL));                                      // will be generated and continuously checks
            column=rand()%(boardSize);                              //if the move is valid
            row=rand()%(boardSize);
            randomMove =isMoveValid( gameBoard, row, column);
        }

        outputData<<"r"<<row<<"c"<<column<< " " <<setw(2)<<"alg2" <<endl;           //Output the rows and columns of the valid move
        gameBoard[row][column]=player2;                                             //Assign the valid move with player 2's marker (O)
    }

}
