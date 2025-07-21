#include "../header/funcoes.h"

// Monta o tabuleiro do jogo da velha
Tabuleiro(char tab[9])
{
    printf("    A | B | C\n");
    printf("  ---------\n");
    printf("1  %c | %c  | %c  \n", tab[0], tab[1], tab[2]);
    printf("  ---------\n");
    printf("2  %c | %c  | %c \n", tab[3], tab[4], tab[5]);
    printf("  ---------\n");
    printf("3  %c | %c  | %c \n", tab[6], tab[7], tab[8]);

    return 0;
}
// Considera somente o primeiro caracter inserido 
char caracter()
{
    char ch = getchar();
    if (feof(stdin) != 0)
    {
        return 0;
    }
    if(ch != '\n')
    {
        while(1)
        {
            char c;
            c == getchar();
            if(c == '\n')
            {
                break;
            }
        }
    }

    return ch;


}
//Calcula os espaços vazios (Serve para verificação da IA para previsão de jogadas)
void espacos_vazios(char tab[9], int indexes[9])
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if(tab[i] = ' ')
        {
            indexes[count] = i;
            count++;
        }
    }
}

char troca_jogador(char player)
{
    if(player == 'X')
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}





