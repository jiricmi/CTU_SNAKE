//
// Created by jiricmi1 on 5/21/23.
//

#include "path_finding.h"
#include "board.h"
#include "player.h"
#include "snake.h"
#include <math.h>
#include "food.h"
#include <stdio.h>

/* checks if there is collision on tile */
int no_collision(int x_new, int y_new) {
    if (board_values[y_new][x_new] == EMPTY || board_values[y_new][x_new] == APPLE) {
        return 1;
    }
    return 0;
}

/* pathfinding based on finding shortest way */
void find_best_direction(struct player *player) {
    int dir = player->snake->direction;
    int dirs[3] = {dir, (dir + 1) % 4, (dir + 3) % 4}; // get directions only where to snake can go
    int best_dir = dir;
    float best_distance = 9999999;
    // find best direction
    for (int i = 0; i < 3; ++i) {
        unsigned int new_x = player->snake->head->x;
        unsigned int new_y = player->snake->head->y;
        direction_func(&new_x, &new_y, dirs[i]);
        // euclidean distance
        double distance = sqrt(pow((double) new_x - food[0], 2) + pow((double) new_y - food[1], 2));
        if (distance < best_distance && no_collision(new_x, new_y)) {
            best_distance = distance;
            best_dir = dirs[i];
        }
    }
    player->snake->direction = best_dir;
}
