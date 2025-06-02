#include "player.h"
#include "board.h"

int ghostx[MAX_GHOSTS];
int ghosty[MAX_GHOSTS];
int score = 0;
int lives = 3;
int wherepacmanx = 1;
int wherepacmany = 1;


void playa(void) {
    score = 0;
    lives = 3;
    wherepacmanx = 1;
    wherepacmany = 1;

    // Place ghosts randomly
    for (int i = 0; i < MAX_GHOSTS; i++) {
        int x, y;
        do {
            x = rand() % (width - 2) + 1;
            y = rand() % (height - 2) + 1;

        } while (gameboard[y][x] != empty);  //funny bug where ghosts were placed on walls and each other

        ghostx[i] = x;
        ghosty[i] = y;
        gameboard[y][x] = ghost;
    }
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

void move_ghosts(void) {
    for (int i = 0; i < MAX_GHOSTS; i++) {
    //erase old ghost to avoid actual ghosts
        gameboard[ghosty[i]][ghostx[i]] = empty;

        // random movement
        int dx = 0, dy = 0;
        int dir = rand() % 4;
        if (dir == 0) dx = -1;      // left
        else if (dir == 1) dx = 1;  // right
        else if (dir == 2) dy = -1; // up
        else dy = 1;                // down

        int newx = ghostx[i] + dx;
        int newy = ghosty[i] + dy;

        
        if (gameboard[newy][newx] != wall && gameboard[newy][newx] != ghost) {
            ghostx[i] = newx;
            ghosty[i] = newy;
        }
       //move
        gameboard[ghosty[i]][ghostx[i]] = ghost;

        // Check for death
        if (ghostx[i] == wherepacmanx && ghosty[i] == wherepacmany) {
            lives--;
        }
    }
}
