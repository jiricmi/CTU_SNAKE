//
// Created by jiricmi1 on 5/19/23.
//

#ifndef APO_PROJECT_DRAW_TOOLS_H
#define APO_PROJECT_DRAW_TOOLS_H
#define BLOCK_SIZE 25

unsigned short darken_color(unsigned short color, float factor);

unsigned int u16_to_rgb(unsigned short int color);

void draw_char(int x, int y, char ch, unsigned int scale, unsigned short color);

void draw_string(int x, int y, char *text, unsigned int size, unsigned int scale, unsigned short color,
                 unsigned short background_color);

void draw_pixel(int x, int y, const unsigned short int color);

void draw_rect(const unsigned int x, const unsigned int y, const unsigned int size_x, const unsigned int size_y,
               const unsigned short int color);

void
draw_graphics(const unsigned int x, const unsigned int y, const unsigned int size, const unsigned char graphics[25][25],
              const unsigned short int snake_color);

void draw_sign(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height,
               const unsigned char sign[height][width]);

void draw_pixel_big(int x, int y, unsigned int scale, unsigned short color);

int char_width(int ch);

#endif //APO_PROJECT_DRAW_TOOLS_H
