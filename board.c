#include "board.h"
#include "player.h"
#include <stdlib.h>

char gameboard[height][width];

void board(void) {
    for (int i = 0; i < height; i++) {
        for (int n = 0; n < width; n++) {
            if (i == 0 || n == 0 || i == height - 1 || n == width - 1)
                gameboard[i][n] = wall;
            else
                gameboard[i][n] = empty;
        }
    }

    //now need to create a bunch of random walls for pacman to run into


    for (int i = 0; i < 50; i++) {
        int x = rand() % (width - 2) + 1;
        int y = rand() % (height - 2) + 1;

        if (x == wherepacmanx && y == wherepacmany)
            continue;

        gameboard[y][x] = wall;
    }
 
    // Place pacman down in default
    gameboard[wherepacmany][wherepacmanx] = pacman;
}


void print_board(void) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(gameboard[i][j]);
        }
        putchar('\n');
    }
}
