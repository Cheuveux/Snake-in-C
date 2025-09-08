#ifndef GRID_H
#define GRID_H

typedef struct {
    int i;
    int j;
} Segment;

extern Segment snake[100];
extern int snake_length;

void    clear_screen();
void    print_grid(char grid[20][20]);
void    move_snake(char move, int *game_over);


#endif