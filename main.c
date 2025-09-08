#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "food.h"

int main() {
    char grid[20][20];
    Food food;
    int game_over = 0;
    char move;
    int i;
    int j;

    srand(time(NULL));

    // Initialize grid
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


    // Initialisation
    snake[0].i = 10;
    snake[0].j = 10;
    snake_length = 1;

    spawn_food(&food, grid);
    clear_screen();
    print_grid(grid);

    // Boucle principale du jeu
    while (!game_over) {
      

        printf("Déplace le serpent (z=haut, s=bas, q=gauche, d=droite) : ");
        scanf(" %c", &move);

        move_snake(move, &game_over);

        if (check_eat_food(snake[0].i, snake[0].j, &food)) {
            snake_length++;
            spawn_food(&food, grid);
        }

        clear_screen();
        print_grid(grid);
    }

    printf("Game Over! Score = %d\n", snake_length - 1);
    return 0;
}