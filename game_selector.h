//
// Created by jiricmi1 on 5/20/23.
//

#ifndef APO_PROJECT__GAME_SELECTOR_H
#define APO_PROJECT__GAME_SELECTOR_H

#include "settings.h"
#include <stdint.h>

#define EASY_GAME 500
#define MEDIUM_GAME 200
#define HARD_GAME 100
#define EXTREME_GAME 50
#define SECOND 1000000

void setup_game(uint32_t *knobs, struct settings *settings);

#endif //APO_PROJECT__GAME_SELECTOR_H
