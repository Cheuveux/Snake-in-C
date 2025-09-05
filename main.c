void printgrid(char grid[20][20]);
void place_snake(char grid[20][20]);

int main()
{
    char grid[20][20];

    place_snake(grid);  // mettre le O au centre
    printgrid(grid);    // afficher la grille avec le serpent

    return 0;
}