#include <stdio.h>

void printchar(char c) {
    printf("%c", c);
}

void printgrid(int head_i, int head_j) {
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 19)
                printchar('.');
            else if (i == head_i && j == head_j)
                printchar('O'); // tête du serpent
            else
                printchar(' ');
            printchar(' ');
        }
        printchar('\n');
    }
}

int main() {
    int head_i = 10;
    int head_j = 10;
    char move;

    while (1) {
        printgrid(head_i, head_j);

        printf("Déplace le serpent (z=haut, s=bas, q=gauche, d=droite) : ");
        scanf(" %c", &move);

        if (move == 'z' && head_i > 1) head_i--;
        else if (move == 's' && head_i < 18) head_i++;
        else if (move == 'q' && head_j > 1) head_j--;
        else if (move == 'd' && head_j < 18) head_j++;

        printf("\n\n"); // espace pour "effacer" l'écran
    }

    return 0;
}