//
// Created by jiricmi1 on 5/19/23.
//

#ifndef APO_PROJECT_SETTINGS_H
#define APO_PROJECT_SETTINGS_H
#define GAMEMODES_COUNT 4 // + 1 for exit
#define DIFFICULTIES_COUNT 4
#define MAPS_COUNT 3

struct settings {
    short int gamemode;
    short int difficulty;
    short int map;
};

void free_settings(struct settings *settings);

struct settings *create_settings();

void print_settings(struct settings *settings);

#endif //APO_PROJECT_SETTINGS_H
