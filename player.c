//
// Created by jiricmi1 on 5/13/23.
//

#include "player.h"
#include <stdio.h>
#include "snake.h"
#include "board.h"
#include "food.h"
#include "periferial_module.h"
#include "draw_module.h"
#include "draw_tools.h"
#include <stdlib.h>
#include <stdint.h>
#include "path_finding.h"

#define FIRST_PLAYER 16
#define SECOND_PLAYER 0


/* mallocs memory and set basic values */
struct player *malloc_player() {
    struct player *player = (struct player *) malloc(sizeof(struct player));
    if (player == NULL) {
        fprintf(stderr, "Cannot create Player");
        exit(1);
    }
    return player;
}

/* creates player with snake and set basic values */
struct player *create_player(uint32_t *knobs, unsigned short int color, unsigned int x, unsigned int y, int offset) {
    struct player *player = malloc_player();
    player->snake = create_snake(color, x, y);
    player->score = 0;
    player->knob_offset = offset;
    player->prev_knob = (*knobs >> player->knob_offset) & 0xff;
    return player;
}

/* increase score by one */
void add_score(struct player *player) {
    player->score++;
}

/* free memory of snake and then whole player */
void remove_player(struct player *player) {
    if (player->snake != NULL) {
        remove_snake(player->snake);
    }
    free(player);
}

/* remove player one by one */
void remove_players(struct player **player, size_t size) {
    for (int i = 0; i < size; i++) {
        remove_player(player[i]);
    }
}

/* modulo for negative numbers */
int normalize_direction(int direction) {
    if (direction < 0) {
        return 3;
    } else {
        return direction % 4;
    }
}

/* emulates knobs to go around without issue */
void check_direction(struct player *player, const unsigned int knobs) {
    unsigned int my_knob = (knobs >> player->knob_offset) & 0xff;
    // if knob is in the middle of the knob range, it is probably a mistake
    if (my_knob - player->prev_knob < 4) {
        my_knob = (knobs >> player->knob_offset) & 0xff;
    }
    int new_dir = player->snake->direction;
    // if knob is on end of the knob range, we have to check if its overflows
    if (player->prev_knob <= 255 && player->prev_knob >= 230
        && my_knob >= 0 && my_knob <= 25) {
        new_dir += 1;
    } else if (player->prev_knob >= 0 && player->prev_knob <= 25
               && my_knob <= 255 && my_knob >= 230) {
        new_dir -= 1;
    } else if ((int) (my_knob - player->prev_knob) >= 3) {
        new_dir += 1;
    } else if ((int) (player->prev_knob - my_knob) >= 3) {
        new_dir -= 1;
    }
    player->snake->direction = normalize_direction(new_dir);
    player->prev_knob = (unsigned int) my_knob;
}

/* checks direction for all players */
void check_directions(struct player **players, size_t size, const unsigned int knobs, int ai) {
    // if ai plays, enable path finding
    if (ai == 0) {
        for (int i = 0; i < size; i++) {
            check_direction(players[i], knobs);
        }
    } else {
        check_direction(players[0], knobs);
        find_best_direction(players[1]);
    }
}

/* check snake if it eats apple or hit the obstacle */
unsigned short int check_snake(struct player *player) {
    struct body_part_t *part = player->snake->head;
    unsigned int x = part->x;
    unsigned int y = part->y;
    // add direction to coordinates
    direction_func(&x, &y, player->snake->direction);
    // if snake eats apple, add score and body part
    if (board_values[y][x] == APPLE) {
        add_score(player);
        add_body_part(player->snake, x, y);
        create_food();
        setLEDtoColor(u16_to_rgb(player->snake->color));
        printf("#%x\n", u16_to_rgb(player->snake->color));
        // if snake hits obstacle, return 1
    } else if (board_values[y][x] == SNAKE || board_values[y][x] == OBSTACLE) {
        return 1;
    } else {
        // else move snake by add new head and remove tail
        int sum = move_snake(player->snake, x, y);
        remove_tail(sum);
    }
    return 0;
}

/* if snakes get heads on same tile in next round, end the game */
unsigned short int check_heads(struct player **players, size_t size) {
    if (players[0]->snake->head->x == players[1]->snake->head->x
        && players[0]->snake->head->y == players[1]->snake->head->y) {
        if (players[0]->snake->size > players[1]->snake->size) {
            return 2;
        } else if (players[0]->snake->size < players[1]->snake->size) {
            return 1;
        } else {
            return 1;
        }
    }
    return 0;
}

/* check all snakes */
unsigned short int check_snakes(struct player **players, size_t size) {
    // if there are two players, check if they hit each other in next round with heads
    if (size > 1) {
        int ret = check_heads(players, size);
        if (ret != 0) {
            return ret;
        }
    }

    for (int i = 0; i < size; i++) {
        if (check_snake(players[i])) {
            return i + 1;
        }
    }
    return 0;
}

/* remove tail from board */
void remove_tail(int sum) {
    if (sum == -1) {
        fprintf(stderr, "nebyl vyhozen zadny prvek");
    } else {
        int y = sum / BOARD_WIDTH; // get coords from single number
        int x = sum - (y * BOARD_WIDTH);
        board_values[y][x] = 0;
    }
}

/* draw all components of the snake */
void draw_player(struct player *player) {
    draw_snake(player->snake);
    if (player->knob_offset == FIRST_PLAYER) {
        // changes to make once in loop
        write_direction_to_led(player->snake->direction);
        draw_board();
    }
}

/* draw all players */
void draw_players(struct player **players, size_t size) {
    for (int i = 0; i < size; i++) {
        draw_player(players[i]);
    }
    draw_score(players, size);
}
