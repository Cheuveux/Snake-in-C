#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "food.h"


Segment snake[100];
int snake_length = 1;


void    printchar (char c)
{
    write(1, &c, 1);
}

void    printstr(char *str)
{
    int i;

    i = 0;
    while(str[i]!='\0')
    {
        printchar(str[i]);
        i++;
    }
}

void    clear_screen()
{
    write(1,"\033[2J\033[H", 7);
}
void    print_grid ()
{
    int i;
    int j;
    int k;
    char c;

    i = 0;
    while (i <20)
    {
        j = 0;
        while (j < 20)
        {
            
            if (i == 0 || i == 19 || j == 0 || j == 19 ) 
            {   
                c = '.';
                
            }
            else if (i == '*' || j == '*')
            {
                c = '*';
            }
            else 
                c = ' ';
            k = 0;
            while (k < snake_length)
            {
                if(snake[k].i == i && snake[k].j == j)
                {
                    if (k == 0)
                        c = 'O';    //tete
                    else
                        c = '$';
                    break;
                }
                k++;
            }   
            printchar(c);
            printchar(' ');
            j++;
        }    
        printchar('\n');
        i++;
    }
}

void    move_snake(char move, int *game_over)
{
    int k;
    int m;

    k = snake_length - 1;
    while (k > 0)
    {
        snake[k] = snake[k - 1];
        k--;
    }
    if(move == 'z')
        snake[0].i--;
    else if(move == 's')
        snake[0].i++;
    else if(move == 'q')
        snake[0].j--;
    else if(move == 'd')
        snake[0].j++;

    //collisions murs
    if(snake[0].i <= 0 || snake[0].i >= 19 || snake[0].j <= 0 || snake[0].j >= 19)
    {
        printstr("YOU LOSE");
        *game_over = 1;
    }
       


    //collisions avec le corps
    m = 1;
    while (m < snake_length)
    {
        if (snake[0].i == snake[m].i && snake[0].j == snake[m].j)
        {
            printstr("YOU LOSE");
            *game_over = 1;
        }
        
        m++;
    }
}


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


int main() {
    char grid[20][20];
    Food food;
    int game_over = 0;
    char move;

    srand(time(NULL));

    // Initialisation
    snake[0].i = 10;
    snake[0].j = 10;
    snake_length = 1;

    spawn_food(&food, grid);

        clear_screen();
        print_grid();

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
        print_grid();
    }

    printf("Game Over! Score = %d\n", snake_length - 1);
    return 0;
}