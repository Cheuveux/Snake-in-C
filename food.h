#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int i;
    int j;
} Food;

void spawn_food(Food *food, char grid[20][20]);
int check_eat_food(int head_i, int head_j, Food *food);

#endif