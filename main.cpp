

#include <iostream>
#include <fstream>
#include<cstdlib>
#include "gomoku.h"
#include <iomanip>

using namespace std;

int main()
{

    //Declare input and output variables
   	ifstream inputData;
   	ofstream outputData;

    //Open input and output files
	inputData.open("input.txt");
	outputData.open("gomokuResults.txt");

	//Declare required varaibles
	int boardSize;
    char gameBoard[15][15];                // Set the array of the game board to the maximum size
    char player1 = 'X';                    // Player 1's marker is represented by a X
    char player2 = 'O';                    // Player 2's marker is represented by an O
    int alg1Wins=0,alg2Wins=0, drawCount=0;             // Wins of each player are set to zero
    gomoku play;
    int numberOfMoves=0;



while(!inputData.eof())                 //Loop until the the last entry of the file is reached
{

    inputData>>boardSize;               //Store the board size read from the file in a variable


    if (boardSize>=6&&boardSize<=15)    //If the board size is not within this range do not carry out the following code for that board size
    {
        outputData<<"size="<<boardSize<<endl;

        beginPlay:                                                          //Where the program is directed to if there is a draw

        play.printBoard(boardSize,gameBoard);
        int outcome=play.checkForWinner(boardSize, gameBoard);

        while (outcome==0 && numberOfMoves!=(boardSize*boardSize))       //while there is no winner, let the algorithms play
        {

            play.alg1(boardSize, gameBoard, player1,outputData);            //Algorithm 1 plays a single move in a valid position
            numberOfMoves++;
            play.alg2(boardSize, gameBoard, player2,outputData);            //Algorithm 2 plays a single move in a valid position
            numberOfMoves++;
            outcome=play.checkForWinner(boardSize, gameBoard);                   //Check if one of the algorithms made a game winning move
                                                                           //If there is no winner, play until there is one

            if(outcome==1)                                                 //If algorithm 1 wins, output that algorithm 1 wins
            {                                                              //Add a win to algorithm 1's win tally
                outputData<<"win=alg1"<<endl;                              //Thereafter break the loop for the next game to be played
                outputData<<endl;
                numberOfMoves=0;                                           //Reset the number of moves
                alg1Wins++;                                                //Increment algorithm 1's wins
                break;

            }
            else if (outcome==-1)                                            //If algorithm 1 wins, output that algorithm 2 wins
            {                                                               //Add a win to algorithm 2's win tally
                outputData<<"win=alg2"<<endl;                               //Thereafter break the loop for the next game to be played
                outputData<<endl;
                numberOfMoves=0;                                            //Reset the number of moves
                alg2Wins++;                                                 //increment algorithm 2's wins
                break;
            }
            else if(outcome==0&&numberOfMoves==boardSize*boardSize)          //If it is a draw
            {
                outputData<<"draw"<<endl;
                numberOfMoves=0;
                drawCount++;
                goto   beginPlay;                                              //clear the board and play again
            }
        }
    }



}
    outputData<<"wins alg1=" <<alg1Wins<<endl;                             //Output the total wins of algorithm 1
    outputData<<"wins alg2=" <<alg2Wins<<endl;                             //Output the total wins of algorithm 2
    outputData<<"draws=" <<drawCount<<endl ;                                //Output the total draws

    inputData.close();
    outputData.close();

    return 0;
}











