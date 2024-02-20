//
// Created by jiricmi1 on 5/19/23.
//

#ifndef APO_PROJECT_PERIFERIAL_MODULE_H
#define APO_PROJECT_PERIFERIAL_MODULE_H

#define LCD_WIDTH 480
#define LCD_HEIGHT 320
#define BEGIN_BOTTOM_BAR 250


#define RED_KNOB 0
#define GREEN_KNOB 1
#define BLUE_KNOB 2
#define NO_LED_COLOR 0x00000000

#include "stdint.h"

extern unsigned char *parlcd_mem_base;
extern unsigned char *mem_base;
extern unsigned short int *display_buffer;

void write_direction_to_led(unsigned int direction);

void setLEDtoColor(unsigned int color);

void display_refresh();

uint32_t update_knobs();

void knob_bounce(uint32_t *knobs);

int knob_press(uint32_t *knobs, const unsigned int color);

#endif //APO_PROJECT_PERIFERIAL_MODULE_H
