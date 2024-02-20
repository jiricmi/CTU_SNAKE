//
// Created by bubenkry on 5/14/23.
//

#ifndef APO_PROJECT_BOARD_H
#define APO_PROJECT_BOARD_H

#define BOARD_HEIGHT 10
#define BOARD_WIDTH 19

#define EMPTY 0
#define SNAKE 1
#define APPLE 2
#define TALL_GRASS 3
#define SHORT_GRASS 4
#define OBSTACLE 5


extern unsigned char board_values[BOARD_HEIGHT][BOARD_WIDTH];

extern unsigned char background_board[BOARD_HEIGHT][BOARD_WIDTH];

void init_board(int map);

void paste_graphics();

#endif //APO_PROJECT_BOARD_H
