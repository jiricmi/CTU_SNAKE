//
// Created by jiricmi1 on 5/19/23.
//

#include "settings.h"
#include <stdlib.h>
#include <stdio.h>

/* frees memory of settings */
void free_settings(struct settings *settings) {
    free(settings);
}

/* mallocs settings and set basic values */
struct settings *create_settings() {
    struct settings *settings = malloc(sizeof(struct settings));
    if (settings == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    settings->difficulty = 0;
    settings->gamemode = 0;
    settings->map = 0;
    return settings;
}

/* debug print */
void print_settings(struct settings *settings) {
    printf("Settings:\n");
    printf("Difficulty: %d\n", settings->difficulty);
    printf("Gamemode: %d\n", settings->gamemode);
    printf("Map: %d\n", settings->map);
}
