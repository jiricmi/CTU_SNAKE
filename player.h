//
// Created by jiricmi1 on 5/13/23.
//

#ifndef APO_PROJECT_PLAYER_H
#define APO_PROJECT_PLAYER_H

#include "snake.h"
#include <stdint.h>

#define FIRST_PLAYER_OFFSET 16
#define SECOND_PLAYER_OFFSET 0

struct player {
    struct snake_t *snake;
    long int score;
    int knob_offset;
    unsigned int prev_knob;
};

struct player *malloc_player();

struct player *create_player(uint32_t *knobs, unsigned short int color, unsigned int x, unsigned int y, int offset);

void add_score(struct player *player);

void check_direction(struct player *player, const unsigned int knobs);

void check_directions(struct player **players, size_t size, const unsigned int knobs, int ai);

unsigned short int check_snake(struct player *player);

void remove_tail(int sum);

void draw_player(struct player *player);

void draw_players(struct player **players, size_t size);

unsigned short int check_snakes(struct player **players, size_t size);

void remove_players(struct player **player, size_t size);

#endif //APO_PROJECT_PLAYER_H

