#ifndef PLAYER_H
#define PLAYER_H

extern int score; 
extern int lives; 
extern int wherepacmanx; 
extern int wherepacmany; 

void init_player(void);

void move_pacman(char dir);


#endif