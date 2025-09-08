#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "food.h"

void spawn_food(Food *food, char grid[20][20]) {
    int i;
    int j;
    int found;

    found = 0;
    while(found == 0)
    {
        i = rand() % 18 + 1; // entre 1 et 18
        j = rand() % 18 + 1; 
        if (grid[i][j] == ' ') // éviter murs/serpent
            found = 1;
    }
    food->i = i;
    food->j = j;
    grid[i][j] = '*';
}

int check_eat_food(int head_i, int head_j, Food *food) {
    return (head_i == food->i && head_j == food->j);
}

/*void print_grid(char grid[20][20])
{
    int i = 0;
    while (i < 20)
    {
        int j = 0;
        while (j < 20)
        {
            printf("%c ", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main()
{
    char grid[20][20];
    Food food;
    int i;
    int j;
    int count;

    srand(time(NULL));

    // Initialisation de la grille : murs = '.', intérieur = ' '
    i = 0;
    while (i < 20)
    {
        j = 0;
        while (j < 20)
        {
            if (i == 0 || i == 19 || j == 0 || j == 19)
                grid[i][j] = '.';
            else
                grid[i][j] = ' ';
            j++;
        }
        i++;
    }

    // Appeler spawn_food plusieurs fois pour tester
    count = 0;
    while (count < 5)
    {
        spawn_food(&food, grid);
        printf("Food #%d placed at (%d,%d)\n", count + 1, food.i, food.j);
        print_grid(grid);
        printf("\n");
        count++;
    }

    return 0;
}*/