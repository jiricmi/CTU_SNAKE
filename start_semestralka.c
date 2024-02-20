#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "player.h"
#include "periferial_module.h"
#include "window_module.h"
#include "settings.h"

/* init on start */
void init() {
    // init display
    display_buffer = (unsigned short int *) malloc(LCD_HEIGHT * LCD_WIDTH * 2);
    parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
    if (parlcd_mem_base == NULL) {
        fprintf(stderr, "Cannot map phys lcd\n");
        exit(1);
    }
    // init knobs
    mem_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
    if (mem_base == NULL) {
        fprintf(stderr, "Cannot map phys");
        exit(1);
    }
    parlcd_hx8357_init(parlcd_mem_base);
    display_refresh();
}

/* main menu control */
int main(int argc, char *argv[]) {
    init();
    struct settings *settings = create_settings();
    uint32_t knobs = update_knobs();
    // main menu loop
    while (1) {
        int selected = main_menu_control(&knobs);
        knob_bounce(&knobs);
        switch (selected) {
            case 0: // start game
                gamemode_control(&knobs, settings);
                break;
            case 1: // select map
                map_control(&knobs, settings);
                break;
            case 2: // select difficulty
                difficulty_control(&knobs, settings);
                break;
            case 3: // leave game
                free_settings(settings);
                return 0;
        }
        print_settings(settings);
    }
    return 0;
}
