//
// Created by jiricmi1 on 5/19/23.
//

#include "periferial_module.h"
#include "mzapo_parlcd.h"
#include "mzapo_regs.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char *parlcd_mem_base, *mem_base;
unsigned short int *display_buffer;

/* effect for direction of led on mzapo */
void write_direction_to_led(unsigned int direction) {
    switch (direction) {
        case 0:
            *(volatile uint32_t *) (mem_base + SPILED_REG_LED_LINE_o) = 0xFF000000;
            break;
        case 1:
            *(volatile uint32_t *) (mem_base + SPILED_REG_LED_LINE_o) = 0x00FF0000;
            break;
        case 2:
            *(volatile uint32_t *) (mem_base + SPILED_REG_LED_LINE_o) = 0x0000FF00;
            break;
        case 3:
            *(volatile uint32_t *) (mem_base + SPILED_REG_LED_LINE_o) = 0x000000FF;
            break;
    }
}

/* effect for color of led on mzapo */
void setLEDtoColor(unsigned int color) {
    *(volatile uint32_t *) (mem_base + SPILED_REG_LED_RGB1_o) = color;
    *(volatile uint32_t *) (mem_base + SPILED_REG_LED_RGB2_o) = color;
}

/* copy buffer to register of the display */
void display_refresh() {
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (unsigned int y = 0; y < LCD_HEIGHT; ++y) {
        for (unsigned int x = 0; x < LCD_WIDTH; ++x) {
            parlcd_write_data(parlcd_mem_base, display_buffer[x + y * LCD_WIDTH]);
        }
    }
}

/* read registers and save the value */
uint32_t update_knobs() {
    return *(volatile uint32_t *) (mem_base + SPILED_REG_KNOBS_8BIT_o);
}

/* tries to secure of bouncing of the button */
void knob_bounce(uint32_t *knobs) {
    *knobs = update_knobs();
    while ((*knobs & 0x04000000) != 0) {
        *knobs = update_knobs();
    }
}

// Detects if knob is not pressed
// color is the color of the knob 0: red, 1: green, 2: blue
int knob_press(uint32_t *knobs, const unsigned int color) {
    switch (color) {
        case (0):
            return (*knobs & 0x04000000) == 0;
        case (1):
            return (*knobs & 0x02000000) == 0;
        case (2):
            return (*knobs & 0x01000000) == 0;
        default:
            fprintf(stderr, "Invalid knob color\n");
            exit(1);
    }
}
