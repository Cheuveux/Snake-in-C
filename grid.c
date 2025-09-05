#include<unistd.h> //pour fonction write
#include<stdio.h> //pour scnaf, permet de recuperer les inputs claviers de la fonction move
void    printchar (char c)
{
    write(1, &c, 1);
}
void    printgrid (int head_i, int head_j)
{
    int i;
    int j;
    i = 0;
    while (i <20)
    {
        j = 0;
        while (j < 20)
        {
            if (i == 0 || i == 19 || j == 0 || j == 19 ) 
            {   
                printchar('.');
                
            }
            else if (i == head_i && j == head_j)
            {
                printchar('O'); //tete du serpent
            }
            else 
                printchar (' ');
            printchar(' ');    
            j++;
        }    
        printchar('\n');
        i++;
    }
}

void    move_head(int *head_i, int *head_j, char move)
{
    if(move == 'z' && *head_i > 1)
        (*head_i)--;
    else if(move == 's' && *head_i < 18)
        (*head_i)++;
    else if(move == 'q' && *head_j > 1)
        (*head_j)--;
    else if(move == 'd' && *head_j < 18)
        (*head_j)++;

    int i;
    i = 0;
    while(i < 10)
    {
        printf("\n");
        i++;
    }
    printgrid(*head_i, *head_j);
}

int main()
{
    int head_i = 10;
    int head_j = 10;
    char move;

    printgrid(head_i, head_j);

    while (1)
    {
        printf("Déplace le serpent (z=haut, s=bas, q=gauche, d=droite) : ");
        scanf(" %c", &move);

        move_head(&head_i, &head_j, move);
    }

    return 0;
}


