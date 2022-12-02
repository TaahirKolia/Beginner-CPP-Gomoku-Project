#ifndef GOMOKU_H
#define GOMOKU_H
#include <fstream>

using namespace std;

class gomoku
{
    public:
        gomoku();
        void printBoard(int boardSize, char gameBoard[][15]);
        bool isMoveValid( char gameBoard[][15], int positionX, int positionY);
        int checkForWinner(int boardSize, char gameBoard [][15]);
        void alg1(int boardSize, char gameBoard[][15], char player1, ofstream& outputData);
        int alg2SmartMove(int boardSize, char gameboard[][15], char player2, ofstream& outputData);
        void alg2(int boardSize, char gameBoard[][15], char player2, ofstream& outputData);



    private:

};

#endif // GOMOKU_H