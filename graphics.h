//
// Created by bubenkry on 5/13/23.
//

#ifndef APO_PROJECT_GRAPHICS_H
#define APO_PROJECT_GRAPHICS_H

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x2728
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define BROWN 0x8AE3
#define DARK_BROWN 0x7A83
#define LIGHT_BROWN 0xCD06
#define ULTRA_LIGHT_BROWN 0xD5CD
#define DARK_RED 0xD000
#define DARK_GREEN 0x2648
#define X 'X'
#define Y 'Y'
#define A 'A'
#define B 'B'

// 1 - RED
// 2 - DARK RED
// 3 - BROWN
// 5 - DARK BROWN
// 4 - DARK GREEN
// 6 - LIGHT BROWN
// 7 - ULTRA LIGHT BROWN
// Y - WHITE
// X - BLACK

static const unsigned char appleGraphics[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 3, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 3, 3, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static const unsigned char holeGraphics[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0},
        {0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0},
        {0, 0, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 0, 0},
        {0, 0, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 0, 0},
        {0, 0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0, 0},
        {0, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0},
        {0, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 0},
        {0, 0, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 0, 0},
        {0, 0, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 0, 0},
        {0, 0, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 0, 0},
        {0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0},
        {0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static const unsigned char tallGrassGraphics[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 4, 0, 4, 0, 4, 4, 0, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 4, 0, 4, 4, 4, 0, 0, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 4, 4, 4, 0, 0, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 4, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 4, 0, 0, 0, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static const unsigned char shortGrassGraphics[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 4, 4, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 4, 4, 4, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 4, 0, 4, 0, 4, 4, 4, 4, 0, 4, 0, 4, 4, 0, 0, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 4, 4, 0, 4, 4, 4, 0, 4, 4, 0, 4, 0, 4, 4, 0, 0, 4, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 4, 0, 4, 4, 4, 0, 4, 4, 0, 4, 4, 4, 4, 0, 0, 4, 0, 0, 0},
        {0, 0, 4, 4, 0, 0, 4, 0, 0, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0},
        {0, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0},
        {0, 0, 4, 4, 0, 0, 4, 4, 0, 4, 4, 4, 0, 4, 4, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 4, 0, 4, 4, 4, 0, 0, 4, 0, 4, 4, 4, 0, 4, 4, 0, 0, 0},
        {0, 0, 0, 4, 4, 4, 0, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 0, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},
        {0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static const unsigned char snakeHeadNorth[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0},
        {0, 0, 0, 0, B, B, X, X, X, B, B, B, B, B, B, B, X, X, X, B, B, 0, 0, 0, 0},
        {0, 0, 0, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, 0, 0, 0},
        {0, 0, 0, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, B, 0, 0},
        {0, 0, B, X, X, Y, X, X, X, Y, X, X, B, X, X, Y, X, X, X, Y, X, X, B, 0, 0},
        {0, 0, B, X, X, Y, X, X, X, Y, X, X, B, X, X, Y, X, X, X, Y, X, X, B, 0, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, B, B, B, X, X, Y, Y, Y, X, X, B, B, B, X, X, Y, Y, Y, X, X, B, B, B, 0},
        {B, B, B, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, B, B, B},
        {B, B, B, B, B, B, X, X, X, B, B, B, B, B, B, B, X, X, X, B, B, B, B, B, B},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A}
};

static const unsigned char snakeHeadWest[25][25] = {
        {A, A, A, A, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, X, X, X, X, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, X, X, X, X, X, X, X, X, X, B, B, B, B, 0, 0, 0, 1, 1, 1, 0},
        {B, B, B, B, B, B, B, X, X, X, X, X, B, B, B, B, B, B, 1, 1, 1, 1, 1, 0, 0},
        {B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 1, 1, 1, 0, 0, 0, 0},
        {B, B, B, B, B, B, B, X, X, X, X, X, B, B, B, B, B, B, 1, 1, 1, 1, 1, 0, 0},
        {B, B, B, B, B, X, X, X, X, X, X, X, X, X, B, B, B, B, 0, 0, 0, 1, 1, 1, 1},
        {B, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, X, X, Y, Y, Y, Y, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, X, X, X, X, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, X, X, X, X, X, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static const unsigned char snakeHeadSouth[25][25] = {
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {B, B, B, B, B, B, X, X, X, B, B, B, B, B, B, B, X, X, X, B, B, B, B, B, B},
        {B, B, B, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, B, B, B},
        {0, B, B, B, X, X, Y, Y, Y, X, X, B, B, B, X, X, Y, Y, Y, X, X, B, B, B, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, 0},
        {0, 0, B, X, X, Y, X, X, X, Y, X, X, B, X, X, Y, X, X, X, Y, X, X, B, 0, 0},
        {0, 0, B, X, X, Y, X, X, X, Y, X, X, B, X, X, Y, X, X, X, Y, X, X, B, 0, 0},
        {0, 0, B, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, 0, 0, 0},
        {0, 0, 0, B, X, X, X, X, X, X, X, B, B, B, X, X, X, X, X, X, X, B, 0, 0, 0},
        {0, 0, 0, 0, B, B, X, X, X, B, B, B, B, B, B, B, X, X, X, B, B, 0, 0, 0, 0},
        {0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static const unsigned char snakeHeadEast[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, X, X, X, X, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, B},
        {1, 1, 1, 1, 0, 0, 0, B, B, B, B, X, X, X, X, X, X, X, X, X, B, B, B, B, B},
        {0, 0, 1, 1, 1, 1, 1, B, B, B, B, B, B, X, X, X, X, X, B, B, B, B, B, B, B},
        {0, 0, 0, 0, 1, 1, 1, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B},
        {0, 0, 1, 1, 1, 1, 1, B, B, B, B, B, B, X, X, X, X, X, B, B, B, B, B, B, B},
        {0, 1, 1, 1, 0, 0, 0, B, B, B, B, X, X, X, X, X, X, X, X, X, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, Y, Y, Y, Y, X, X, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, Y, Y, Y, Y, Y, X, X, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, X, X, X, X, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, X, X, X, X, X, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, A, A, A, A}
};

static const unsigned char snakeBody[25][25] = {
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
};

static const unsigned char snakeTailNorth[25][25] = {
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0},
        {0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0},
        {0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0},
        {0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0},
        {0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0},
        {0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0},
        {0, 0, 0, B, B, B, B, B, B, B, A, A, A, A, A, B, B, B, B, B, B, B, 0, 0, 0},
        {0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static const unsigned char snakeTailSouth[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0},
        {0, 0, 0, B, B, B, B, B, B, B, A, A, A, A, A, B, B, B, B, B, B, B, 0, 0, 0},
        {0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0},
        {0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0},
        {0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0},
        {0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0},
        {0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0},
        {0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A}
};

static const unsigned char snakeTailWest[25][25] = {
        {A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {B, B, B, B, B, A, A, A, A, A, A, A, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {A, A, A, A, A, B, B, B, B, B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

static const unsigned char snakeTailEast[25][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, A, A, A, A, A, A, A, B, B, B, B, B},
        {0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, B, B, B, A, A, A, A, A},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, B, B, B, B, B, A, A, A, A, A}
};

#endif //APO_PROJECT_GRAPHICS_H
