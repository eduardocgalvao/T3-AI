#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(void)
{
    char tab[9];
    
    for(int i = 0; i < 9; i++)
    {
        scanf(" %c", &tab[i]);
    }

    printf("   A   B   C\n");
    printf("1  %c | %c | %c  \n", tab[0], tab[1], tab[2]);
    printf("  ------------\n");
    printf("2  %c | %c | %c \n", tab[3], tab[4], tab[5]);
    printf("  ------------\n");
    printf("3  %c | %c | %c \n", tab[6], tab[7], tab[8]);

}