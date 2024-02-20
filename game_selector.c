//
// Created by jiricmi1 on 5/20/23.
//

#include "game_selector.h"
#include "settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "draw_module.h"
#include "player.h"
#include "board.h"
#include "periferial_module.h"
#include <time.h>
#include "graphics.h"
#include "window_module.h"

/* set delay of timer */
int get_delay(struct settings *settings) {
    switch (settings->difficulty) {
        case 0:
            return EASY_GAME;
        case 1:
            return MEDIUM_GAME;
        case 2:
            return HARD_GAME;
        case 3:
            return EXTREME_GAME;
        default:
            fprintf(stderr, "Error: Invalid difficulty\n");
            exit(1);
    }
}

/* core function of game running */
int game_run(uint32_t *knobs, struct settings *settings, struct player **players, size_t size, int ai) {
    // set speed of the game
    struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = get_delay(settings) * SECOND};
    // draw snake and score for each player
    draw_players(players, size);
    knob_bounce(knobs); // wait for knob to be released
    unsigned short int end = 0; // flag for end of game
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        // checks if any player changed direction
        check_directions(players, size, *knobs, ai);
        end = check_snakes(players, size);
        if (end > 0) { // if game ended
            break;
        }
        draw_players(players, size);
        display_refresh();
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL); // sleep for delay
        setLEDtoColor(NO_LED_COLOR); // turn off all leds
    }
    return end_game(knobs, players, size, end); // end game window
}

/* basic game for single player */
int setup_singleplayer(uint32_t *knobs, struct settings *settings) {
    const size_t players_size = 1; // create one player
    struct player *players[players_size];
    players[0] = create_player(knobs, LIGHT_BROWN, 8, 5, FIRST_PLAYER_OFFSET);
    int res = game_run(knobs, settings, players, players_size, 0); // run game
    remove_players(players, players_size); // free memory
    return res;
}

/* basic game for multiplayer */
int setup_multiplayer(uint32_t *knobs, struct settings *settings) {
    const size_t players_size = 2; // create two players
    struct player *players[players_size];
    players[0] = create_player(knobs, RED, 8, 5, FIRST_PLAYER_OFFSET);
    players[1] = create_player(knobs, BLUE, 8, 3, SECOND_PLAYER_OFFSET);
    int res = game_run(knobs, settings, players, players_size, 0);
    remove_players(players, players_size); // free memory
    return res;
}

/* basic game for ai */
int setup_ai(uint32_t *knobs, struct settings *settings) {
    const size_t players_size = 2; // create one player and one ai
    struct player *players[players_size];
    players[0] = create_player(knobs, RED, 8, 5, FIRST_PLAYER_OFFSET);
    players[1] = create_player(knobs, BLUE, 8, 3, SECOND_PLAYER_OFFSET);
    int res = game_run(knobs, settings, players, players_size, 1);
    remove_players(players, players_size); // free memory
    return res;
}

/* choose which function to run based on selected in menu */
void setup_game(uint32_t *knobs, struct settings *settings) {
    while (1) {
        background_init(1);
        init_board(settings->map);
        int res;
        switch (settings->gamemode) {
            case 0:
                res = setup_singleplayer(knobs, settings);
                break;
            case 1:
                res = setup_multiplayer(knobs, settings);
                break;
            case 2:
                res = setup_ai(knobs, settings);
                break;
            default:
                fprintf(stderr, "Error: Invalid gamemode\n");
                exit(1);
        }
        if (res == 0)
            break;
    }
}
