//
// Created by jiricmi1 on 5/10/23.
//
#ifndef APO_PROJECT_SNAKE_H
#define APO_PROJECT_SNAKE_H

#include <stdlib.h>

// struct of body part of snake (node of linked list)
struct body_part_t {
    struct body_part_t *next;
    struct body_part_t *previous;
    unsigned int x;
    unsigned int y;
};
// struct of snake (linked list)
struct snake_t {
    unsigned short int color;
    size_t size;
    int direction;
    struct body_part_t *head;
    struct body_part_t *tail;
};

struct body_part_t *malloc_body();

struct snake_t *malloc_snake();

int move_snake(struct snake_t *snake, unsigned int x, unsigned int y);

void add_body_part(struct snake_t *snake, unsigned int x, unsigned int y);

int remove_body_part(struct snake_t *snake);

struct snake_t *create_snake(const unsigned short int color, unsigned int x, unsigned int y);

void remove_snake(struct snake_t *snake);

void direction_func(unsigned int *x, unsigned int *y, int direction);

#endif //APO_PROJECT_SNAKE_H