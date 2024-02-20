//
// Created by jiricmi1 on 5/19/23.
//

#include "draw_tools.h"
#include "font_types.h"
#include "periferial_module.h"
#include "graphics.h"

font_descriptor_t *fdes = &font_rom8x16;

/* transform u16 to rgb code */
unsigned int u16_to_rgb(unsigned short int color) {
    int red = (color >> 10) & 0x1F;
    int green = (color >> 5) & 0x1F;
    int blue = color & 0x1F;
    red = (red * 255) / 31;
    green = (green * 255) / 31;
    blue = (blue * 255) / 31;
    return (red << 16) | (green << 8) | blue;
}

/* creates darken version of color */
unsigned short darken_color(unsigned short color, float factor) {
    unsigned short red = (color >> 10) & 0x1F;
    unsigned short green = (color >> 5) & 0x1F;
    unsigned short blue = color & 0x1F;

    red = (unsigned short) (red * factor);
    green = (unsigned short) (green * factor);
    blue = (unsigned short) (blue * factor);

    unsigned short darkenedColor = (red << 10) | (green << 5) | blue;
    return darkenedColor;
}

/* draws pixel to the buffer */
void draw_pixel(int x, int y, const unsigned short int color) {
    if (x >= 0 && x < 480 && y >= 0 && y < 320) {
        display_buffer[x + 480 * y] = color;
    }
}

/* draws rectangle pixel by pixel */
void draw_rect(const unsigned int x, const unsigned int y, const unsigned int size_x, const unsigned int size_y,
               const unsigned short int color) {
    for (unsigned int i = 0; i < size_x; ++i) {
        for (unsigned int j = 0; j < size_y; ++j) {
            draw_pixel(size_x * x + i, size_y * y + j, color);
        }
    }
}

/* draws graphic sprites */
void
draw_graphics(const unsigned int x, const unsigned int y, const unsigned int size, const unsigned char graphics[25][25],
              const unsigned short int snake_color) {
    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = 0; j < size; ++j) {
            switch (graphics[j][i]) {
                case 1:
                    draw_pixel(size * x + i, size * y + j, RED);
                    break;
                case 2:
                    draw_pixel(size * x + i, size * y + j, DARK_RED);
                    break;
                case 3:
                    draw_pixel(size * x + i, size * y + j, BROWN);
                    break;
                case 4:
                    draw_pixel(size * x + i, size * y + j, DARK_GREEN);
                    break;
                case 5:
                    draw_pixel(size * x + i, size * y + j, DARK_BROWN);
                    break;
                case 6:
                    draw_pixel(size * x + i, size * y + j, LIGHT_BROWN);
                    break;
                case 7:
                    draw_pixel(size * x + i, size * y + j, ULTRA_LIGHT_BROWN);
                    break;
                case X:
                    draw_pixel(size * x + i, size * y + j, BLACK);
                    break;
                case Y:
                    draw_pixel(size * x + i, size * y + j, WHITE);
                    break;
                case A:
                    draw_pixel(size * x + i, size * y + j, snake_color);
                    break;
                case B:
                    draw_pixel(size * x + i, size * y + j, darken_color(snake_color, 0.8));
                    break;
                default:
                    draw_pixel(size * x + i, size * y + j, GREEN);
            }
        }
    }
}

/* draws sign */
void draw_sign(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height,
               const unsigned char sign[height][width]) {
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            switch (sign[j][i]) {
                case 1:
                    draw_pixel(x + i, y + j, RED);
                    break;
                case 2:
                    draw_pixel(x + i, y + j, DARK_RED);
                    break;
                case 3:
                    draw_pixel(x + i, y + j, BROWN);
                    break;
                case 4:
                    draw_pixel(x + i, y + j, DARK_GREEN);
                    break;
                case 5:
                    draw_pixel(x + i, y + j, DARK_BROWN);
                    break;
                case 6:
                    draw_pixel(x + i, y + j, LIGHT_BROWN);
                    break;
                case 7:
                    draw_pixel(x + i, y + j, ULTRA_LIGHT_BROWN);
                    break;
                case X:
                    draw_pixel(x + i, y + j, BLACK);
                    break;
                case Y:
                    draw_pixel(x + i, y + j, WHITE);
                    break;
                default:
                    draw_pixel(x + i, y + j, BLACK);
            }
        }
    }
}

/* draws char */
void draw_char(int x, int y, char ch, unsigned int scale, unsigned short color) {
    int w = char_width(ch);
    const font_bits_t *ptr;
    if ((ch >= fdes->firstchar) && (ch - fdes->firstchar < fdes->size)) {
        if (fdes->offset) {
            ptr = &fdes->bits[fdes->offset[ch - fdes->firstchar]];
        } else {
            int bw = (fdes->maxwidth + 15) / 16;
            ptr = &fdes->bits[(ch - fdes->firstchar) * bw * fdes->height];
        }
        int i, j;
        for (i = 0; i < fdes->height; i++) {
            font_bits_t val = *ptr;
            for (j = 0; j < w; j++) {
                if ((val & 0x8000) != 0) {
                    draw_pixel_big(x + scale * j, y + scale * i, scale, color);
                }
                val <<= 1;
            }
            ptr++;
        }
    }
}

/* draws string */
void draw_string(int x, int y, char *text, unsigned int size, unsigned int scale, unsigned short color,
                 unsigned short background_color) {
    int width_sum = 0;
    for (int i = 0; i < size; i++) {
        width_sum += char_width(text[i - 1]) * scale;
    }
    for (unsigned int i = x - 10; i < (x + width_sum + 7); ++i) {
        for (unsigned int j = y - 3; j < (y + 16 * scale); ++j) {
            draw_pixel(i, j, background_color);
        }
    }

    int isFirst = 0;
    for (int i = 0; i < size; i++) {
        if (isFirst != 0) {
            draw_char(x + (char_width(text[i - 1]) * scale * i), y, text[i], scale, color);
        } else {
            draw_char(x, y, text[i], scale, color);
            isFirst = 1;
        }
    }
}

/* draws big pixel */
void draw_pixel_big(int x, int y, unsigned int scale, unsigned short color) {
    int i, j;
    for (i = 0; i < scale; i++) {
        for (j = 0; j < scale; j++) {
            draw_pixel(x + i, y + j, color);
        }
    }
}

/* gets char width */
int char_width(int ch) {
    int width;
    if (!fdes->width) {
        width = fdes->maxwidth;
    } else {
        width = fdes->width[ch - fdes->firstchar];
    }
    return width;
}
