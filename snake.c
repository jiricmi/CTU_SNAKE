//
// Created by jiricmi1 on 5/10/23.
//
#include "snake.h"
#include <stdlib.h>
#include <stdio.h>

/* mallocs body part and set basic values */
struct body_part_t *malloc_body() {
    struct body_part_t *body = (struct body_part_t *) malloc(sizeof(struct body_part_t));
    if (body == NULL) {
        fprintf(stderr, "Cannot malloc body\n");
        exit(1);
    }
    body->next = NULL;
    body->previous = NULL;
    return body;
}

/* mallocs snake struct and set basic values */
struct snake_t *malloc_snake() {
    struct snake_t *snake = (struct snake_t *) malloc(sizeof(struct snake_t));
    if (snake == NULL) {
        fprintf(stderr, "Cannot malloc snake\n");
        exit(1);
    }
    snake->tail = NULL;
    snake->head = NULL;
    snake->size = 0;
    snake->direction = 0;
    snake->color = 0;

    return snake;
}

/* move snake by one to new coords */
int move_snake(struct snake_t *snake, unsigned int x, unsigned int y) {
    add_body_part(snake, x, y);
    return remove_body_part(snake);
}

/* add new node to linked list */
void add_body_part(struct snake_t *snake, unsigned int x, unsigned int y) {
    struct body_part_t *new_head = malloc_body();
    new_head->x = x;
    new_head->y = y;
    if (snake->head == NULL) {
        snake->head = new_head;
        snake->tail = new_head;
    } else {
        struct body_part_t *head = snake->head;
        new_head->next = head;
        head->previous = new_head;
        snake->head = new_head;
    }
    snake->size += 1;
}

/* removes body part from part */
int remove_body_part(struct snake_t *snake) {
    int x, y;
    if (snake->tail != NULL) {
        struct body_part_t *tail = snake->tail;
        x = tail->x;
        y = tail->y;
        if (snake->tail == snake->head) {
            snake->head = NULL;
            snake->tail = NULL;
            free(tail);
        } else {
            struct body_part_t *new_tail = snake->tail->previous;
            new_tail->next = NULL;
            snake->tail = new_tail;
            free(tail);
        }
        snake->size -= 1;
        return x + 19 * y;
    } else {
        fprintf(stderr, "Warning: empty snake\n");
        return -1;
    }
}

/* create snake on possition on game start */
struct snake_t *create_snake(const unsigned short int color, unsigned int x, unsigned int y) {
    struct snake_t *snake = malloc_snake();
    snake->color = color;
    for (unsigned int i = 0; i < 3; ++i) {
        add_body_part(snake, x + i, y);
    }
    return snake;
}

/* empty linked list andd remove snake */
void remove_snake(struct snake_t *snake) {
    struct body_part_t *head = snake->head;
    struct body_part_t *next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
    free(snake);
}

/* add direction to coords */
void direction_func(unsigned int *x, unsigned int *y, int direction) {
    switch (direction) {
        case 0:
            *x += 1;
            break;
        case 1:
            *y += 1;
            break;
        case 2:
            *x -= 1;
            break;
        case 3:
            *y -= 1;
            break;
        default:
            fprintf(stderr, "Error: wrong direction\n");
            exit(1);
    }
    if (*x == -1) {
        *x = 18;
    }
    if (*y == -1) {
        *y = 9;
    }
    *x = (*x) % 19;
    *y = (*y) % 10;
}
