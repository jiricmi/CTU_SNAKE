//
// Created by jiricmi1 on 5/13/23.
//
#include "food.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// food coord for ai
int food[2] = {2, 4};

/* generates food on random tile but only on free ones */
void create_food() {
    unsigned int free_x[BOARD_WIDTH * BOARD_HEIGHT];
    unsigned int free_y[BOARD_HEIGHT * BOARD_WIDTH];
    size_t array_size = 0;
    // get free tiles
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board_values[i][j] == 0) {
                free_x[array_size] = j;
                free_y[array_size] = i;
                ++array_size;
            }
        }
    }
    // generate random number
    srand(time(NULL));
    int random_number = rand() % array_size;
    // select random free tile
    food[0] = free_x[random_number];
    food[1] = free_y[random_number];
    board_values[free_y[random_number]][free_x[random_number]] = 2;
}
