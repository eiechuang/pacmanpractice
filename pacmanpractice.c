#include "stdio.h"
#include "stdlib.h" 

#define height 30
#define width 40 
#define pacman 'C'
#define wall 'X' 
#define empty ' '
#define chaser 'P'

//first we define the board.>?

char gameboard [height][width];
int score; //how much food is eaten
int lives = 3; //3 total, game ends when zero

int wherepacmanx; //location of pacman in x, y coords on multidimensional array
int wherepacmany; 




void board () {
//currently seeds everything as X.
    for ( int i = 0; i < height; i ++) {
        for (int n = 0; i < width; n ++ ) {
            gameboard [i][n] = wall;
        }
    }


}