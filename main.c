#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"

int main(void) {

    init_player();
    board();

    while (lives > 0) {
        system("clear");
        print_board();

        printf("Use WASD in order to move. Lives: %d, Score: %d\n", lives, score);
        char move = getchar();
        getchar(); // flush newline

        move_pacman(move);
        move_ghosts();
    }

    fprintf("Game Over! Final Score: %d\n", score, stdout);
    return 0;
}
