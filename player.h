#ifndef PLAYER_H
#define PLAYER_H
#define MAX_GHOSTS 4

extern int ghostx[MAX_GHOSTS];
extern int ghosty[MAX_GHOSTS];
extern int score; 
extern int lives; 
extern int wherepacmanx; 
extern int wherepacmany; 

void init_player(void);

void move_pacman(char dir);
void move_ghosts(void);

#endif