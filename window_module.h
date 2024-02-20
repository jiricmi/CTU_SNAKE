//
// Created by jiricmi1 on 5/19/23.
//

#ifndef APO_PROJECT_WINDOW_MODULE_H
#define APO_PROJECT_WINDOW_MODULE_H

#include <stdint.h>
#include <stddef.h>
#include "settings.h"
#include "player.h"

typedef struct MenuItem {
    int x;
    int y;
    char *text;
    int textLength;
} MenuItem;

int end_game(uint32_t *knobs, struct player **players, size_t size, unsigned short int loser);

int main_menu_control(uint32_t *knobs);

void gamemode_control(uint32_t *knobs, struct settings *settings);

void map_control(uint32_t *knobs, struct settings *settings);

void difficulty_control(uint32_t *knobs, struct settings *settings);

void basic_window_draw();

void draw_menu_list(MenuItem *menu_items, int active_menu_item, int menu_items_count);

#endif //APO_PROJECT_WINDOW_MODULE_H
