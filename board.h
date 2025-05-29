#ifndef BOARD_H
#define BOARD_H

#define height 20
#define width 30

#define pacman 'C'
#define wall 'X'
#define empty ' '

extern char gameboard[height][width];

void board(void);
void print_board(void);

#endif
