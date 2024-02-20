//
// Created by jiricmi1 on 5/19/23.
//

#include "window_module.h"
#include "graphics.h"
#include "draw_module.h"
#include "draw_tools.h"
#include "signs.h"
#include "periferial_module.h"
#include "settings.h"
#include "game_selector.h"
#include <stdint.h>


/* window of the end game */
int end_game(uint32_t *knobs, struct player **players, size_t size, unsigned short int loser) {
    draw_end_game(players, size);
    display_refresh();
    knob_bounce(knobs);
    while (knob_press(knobs, RED_KNOB) && knob_press(knobs, BLUE_KNOB)) {
        *knobs = update_knobs();
    };
    if (knob_press(knobs, BLUE_KNOB)) {
        return 0;
    }
    return 1;
}

/* show menu of difficulty */
void show_difficulty(int active_menu_item) {
    basic_window_draw();
    MenuItem menu_items[] = {
            {171, 100, "EASY",    4},
            {171, 150, "MEDIUM",  6},
            {171, 200, "HARD",    4},
            {171, 250, "EXTREME", 7}};
    draw_menu_list(menu_items, active_menu_item, DIFFICULTIES_COUNT);
}

/* main function of menu difficulty */
void difficulty_control(uint32_t *knobs, struct settings *settings) {
    int active_menu_item = 0;
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        active_menu_item = ((*knobs >> 16) & 0xff >> 4) / DIFFICULTIES_COUNT;
        show_difficulty(active_menu_item);
    }
    settings->difficulty = active_menu_item;
}

/* draws menu list and highlight selected item */
void draw_menu_list(MenuItem *menu_items, int active_menu_item, int menu_items_count) {
    for (int i = 0; i < menu_items_count; i++) {
        unsigned short int fc = (i == active_menu_item) ? BLACK : WHITE;
        unsigned short int bc = (i == active_menu_item) ? WHITE : BLACK;
        MenuItem m = menu_items[i];
        draw_string(m.x, m.y, m.text, m.textLength, 2, fc, bc);
    }
    display_refresh();
}

/* show gamemode menu */
void show_gamemode(int active_menu_item) {
    basic_window_draw();
    MenuItem menu_items[] = {
            {171, 100, "SINGLE", 6},
            {171, 150, "MULTI",  5},
            {171, 200, "AI",     2},
            {171, 250, "<-BACK", 6}};
    draw_menu_list(menu_items, active_menu_item, GAMEMODES_COUNT);
}


/* main function of gammode menu */
void gamemode_control(uint32_t *knobs, struct settings *settings) {
    int active_menu_item = 0;
    knob_bounce(knobs);
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        active_menu_item = ((*knobs >> 16) & 0xff >> 4) / GAMEMODES_COUNT;
        show_gamemode(active_menu_item);
    }
    if (active_menu_item == 3) {
        return;
    }
    settings->gamemode = active_menu_item;
    knob_bounce(knobs);
    setup_game(knobs, settings);
}

/* show map menu */
void show_map(int active_menu_item) {
    basic_window_draw();
    MenuItem menu_items[] = {
            {171, 100, "EMPTY",  5},
            {171, 150, "BORDER", 6},
            {171, 200, "MAZE",   4}};
    draw_menu_list(menu_items, active_menu_item, MAPS_COUNT);
}

/* main function of map menu */
void map_control(uint32_t *knobs, struct settings *settings) {
    int active_menu_item = 0;
    knob_bounce(knobs);
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        active_menu_item = ((*knobs >> 16) & 0xff >> 4) / MAPS_COUNT;
        if (active_menu_item == 4)
            active_menu_item = 0;
        show_map(active_menu_item);
    }
    settings->map = active_menu_item;
}

/* show main menu */
void show_main_menu(int active_menu_item) {
    basic_window_draw();
    MenuItem menu_items[] = {
            {171, 100, "PLAY",       4},
            {171, 150, "MAP",        3},
            {171, 200, "DIFFICULTY", 10},
            {171, 250, "EXIT",       4}};
    draw_menu_list(menu_items, active_menu_item, GAMEMODES_COUNT);
}

/* main function of main menu */
int main_menu_control(uint32_t *knobs) {
    int active_menu_item = 0;
    *knobs = update_knobs();
    knob_bounce(knobs);
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        active_menu_item = ((*knobs >> 16) & 0xff >> 4) / GAMEMODES_COUNT; // dodelat konstatu
        show_main_menu(active_menu_item);
    }
    return active_menu_item;
}

/* basic logo draw */
void basic_window_draw() {
    draw_background();
    draw_sign(121, 50, 238, 32, snakeSign);
}
