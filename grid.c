#include<unistd.h>
void    printchar (char c)
{
    write(1, &c, 1);
}
void    printgrid (char grid[20][20])
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
            else 
                printchar (' ');
            printchar(' ');    
            j++;
        }    
        printchar('\n');
        i++;
    }
}

int main()
{
    char grid[20][20];
    printgrid(grid);

    return (0);
}



