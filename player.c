#include "player.h"
#include "board.h"

int score = 0;
int lives = 3;
int wherepacmanx = 1;
int wherepacmany = 1;

void init_player(void) {
    score = 0;
    lives = 3;
    wherepacmanx = 1;
    wherepacmany = 1;
}

void move_pacman(char dir) {
    int newx = wherepacmanx;
    int newy = wherepacmany;

    if (dir == 'w') newy--;
    else if (dir == 's') newy++;
    else if (dir == 'a') newx--;
    else if (dir == 'd') newx++;

    if (gameboard[newy][newx] == wall)
        return;

    gameboard[wherepacmany][wherepacmanx] = empty;
    wherepacmanx = newx;
    wherepacmany = newy;
    gameboard[wherepacmany][wherepacmanx] = pacman;
}
