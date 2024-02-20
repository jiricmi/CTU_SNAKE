//
// Created by jiricmi1 on 5/19/23.
//

#ifndef APO_PROJECT_DRAW_MODULE_H
#define APO_PROJECT_DRAW_MODULE_H

#include "snake.h"
#include "player.h"
#include <stddef.h>

void draw_score(struct player **players, size_t size);

void draw_snake(struct snake_t *snake);

void draw_board();

void draw_end_game(struct player **players, size_t size);

void background_init(int game_background);

void draw_background();

#endif //APO_PROJECT_DRAW_MODULE_H
