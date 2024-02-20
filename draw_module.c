#include "draw_module.h"
#include "graphics.h"
#include <stdio.h>
#include <string.h>
#include "draw_tools.h"
#include "board.h"
#include "snake.h"
#include "periferial_module.h"
#include "signs.h"
#include "player.h"

/* draws score on bottom side of the display */
void draw_score(struct player **players, size_t size) {
    // draw bottom bar black
    for (unsigned int i = 0; i < LCD_WIDTH; ++i) {
        for (unsigned int j = BEGIN_BOTTOM_BAR; j < LCD_HEIGHT; ++j) {
            draw_pixel(i, j, BLACK);
        }
    }
    // declare buffers for score
    char player_one_buffer[5];
    char player_two_buffer[5];
    // create string from score
    snprintf(player_one_buffer, 5, "%ld", players[0]->score);
    draw_string(25, 265, "SCORE", 5, 4, WHITE, 0);
    draw_string(250, 265, player_one_buffer, strlen(player_one_buffer), 4, players[0]->snake->color, 0);
    // if there are two players, draw second score
    if (size > 1) {
        draw_string(300, 265, ":", 1, 4, WHITE, 0);
        snprintf(player_two_buffer, 5, "%ld", players[1]->score);
        draw_string(350, 265, player_two_buffer, strlen(player_two_buffer), 4, players[1]->snake->color, 0);
    }
}

/* draws board on the display */
void draw_board() {
    // paste background
    paste_graphics();
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            switch (board_values[y][x]) {
                case SNAKE:
                    break;
                case APPLE:
                    draw_graphics(x, y, BLOCK_SIZE, appleGraphics, BLACK);
                    break;
                case TALL_GRASS:
                    draw_graphics(x, y, BLOCK_SIZE, tallGrassGraphics, BLACK);
                    break;
                case SHORT_GRASS:
                    draw_graphics(x, y, BLOCK_SIZE, shortGrassGraphics, BLACK);
                    break;
                case OBSTACLE:
                    draw_graphics(x, y, BLOCK_SIZE, holeGraphics, BLACK);
                    break;
                default:
                    draw_rect(x, y, BLOCK_SIZE, BLOCK_SIZE, GREEN);
            }
        }
    }
}

/* draw snake which is represented as linked list*/
void draw_snake(struct snake_t *snake) {
    struct body_part_t *part = snake->head;
    unsigned int direction = snake->direction;
    board_values[part->y][part->x] = 1;
    // draw head in correct direction
    switch (direction) {
        case 0:
            draw_graphics(part->x, part->y, BLOCK_SIZE, snakeHeadWest, snake->color);
            break;
        case 1:
            draw_graphics(part->x, part->y, BLOCK_SIZE, snakeHeadSouth, snake->color);
            break;
        case 2:
            draw_graphics(part->x, part->y, BLOCK_SIZE, snakeHeadEast, snake->color);
            break;
        case 3:
            draw_graphics(part->x, part->y, BLOCK_SIZE, snakeHeadNorth, snake->color);
            break;
    }
    // find tail of the linked list and draw tail in correct direction
    part = part->next;
    while (part != NULL) {
        board_values[part->y][part->x] = 1;
        if (part->next == NULL) {
            if (part->previous->x > part->x) {
                draw_graphics(part->x, part->y, BLOCK_SIZE, snakeTailEast, snake->color);
            } else if (part->previous->x < part->x) {
                draw_graphics(part->x, part->y, BLOCK_SIZE, snakeTailWest, snake->color);
            } else if (part->previous->y > part->y) {
                draw_graphics(part->x, part->y, BLOCK_SIZE, snakeTailSouth, snake->color);
            } else if (part->previous->y < part->y) {
                draw_graphics(part->x, part->y, BLOCK_SIZE, snakeTailNorth, snake->color);
            }
            break;
        } else {
            // draw middle part of the snake
            draw_graphics(part->x, part->y, BLOCK_SIZE, snakeBody, snake->color);
            part = part->next;
        }
    }
}

/* draw eng game score */
void draw_end_game(struct player **players, size_t size) {
    //
    draw_rect(0, 0, LCD_WIDTH, LCD_HEIGHT, BLACK);
    draw_sign(39, 50, 402, 32, gameOverSign);
    char player_one_buffer[5];
    char player_two_buffer[5];
    if (size < 2) {
        snprintf(player_one_buffer, 5, "%ld", players[0]->score);
        draw_string(220, 100, player_one_buffer, strlen(player_one_buffer), 4, WHITE, 0);
    } else {
        draw_string(225, 100, ":", 1, 4, WHITE, 0);
        snprintf(player_one_buffer, 5, "%ld", players[0]->score);
        draw_string(175, 100, player_one_buffer, strlen(player_one_buffer), 4, players[0]->snake->color, 0);
        snprintf(player_two_buffer, 5, "%ld", players[1]->score);
        draw_string(275, 100, player_two_buffer, strlen(player_two_buffer), 4, players[1]->snake->color, 0);
    }
    draw_string(50, 270, "MENU", 4, 3, 0, RED);
    draw_string(280, 270, "RESTART", 7, 3, 0, BLUE);
}

/* draw background */
void background_init(int game_background) {
    int ptr = 0;
    for (int i = 0; i < LCD_HEIGHT; i++) {
        for (int j = 0; j < LCD_WIDTH; j++) {
            if (game_background == 1) {
                if (i < BEGIN_BOTTOM_BAR) {
                    display_buffer[ptr] = GREEN;
                } else {
                    display_buffer[ptr] = BLACK;
                }
            } else {
                display_buffer[ptr] = BLACK;
            }
            ptr++;
        }
    }
}

void draw_background() {
    draw_rect(0, 0, LCD_WIDTH, LCD_HEIGHT, BLACK);
}
