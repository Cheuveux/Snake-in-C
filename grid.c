#include<unistd.h> //pour fonction write
#include<stdio.h> //pour scnaf, permet de recuperer les inputs claviers de la fonction move
#include "grid.h" //structure concernant la grille et le serpent


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
void    print_grid (char grid[20][20])
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
            else if (grid[i][j] == '*')
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
                    else if ( k >= 2 && k == snake_length - 1)
                        c = '$';
                    else
                        c = 'o'; //corps
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

/*int main()
{
    char move;
    int game_over = 0;

    // Position initiale du serpent au centre
    snake[0].i = 10;
    snake[0].j = 10;
    snake_length = 1;

    clear_screen();
    print_grid();

    while (!game_over)
    {
        printf("Déplace le serpent (z=haut, s=bas, q=gauche, d=droite) : ");
        scanf(" %c", &move);

        move_snake(move, &game_over);
        clear_screen();
        print_grid();
    }

    return 0;
}*/