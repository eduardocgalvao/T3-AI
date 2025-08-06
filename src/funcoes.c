#include "../header/funcoes.h"

// Monta o tabuleiro do jogo da velha
Tabuleiro(char tab[9])
{
     printf("   A   B   C\n");
    printf("1  %c | %c | %c  \n", tab[0], tab[1], tab[2]);
    printf("  ------------\n");
    printf("2  %c | %c | %c \n", tab[3], tab[4], tab[5]);
    printf("  ------------\n");
    printf("3  %c | %c | %c \n", tab[6], tab[7], tab[8]);
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
void calcular_espacos_vazios(char tab[9], int indexes[9])
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
//Troca o jogador oponenete de acordo com a escolha do "player"
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
// Verifica se a coordenada é válida e se espaço já está preenchido (modo 1v1)
int VerificarCoord(char tab[9], char* coordenada, char player)
{
    int x, y;
    y--;
    x = toupper(x) - 65;

    sscanf(coordenada, " %c%d", &x, &y);

    if((x < 0 || x > 2) || (y < 0 || y > 2))
    {
        printf("Essa coordenada não é valida\n");
    }
    else 
    {
        if(tab[x * 3 + y] != ' ')
        {
            printf("Esse espaço já está preenchido no tabuleiro\n");
        }
        else
        {
            tab[x * 3 + y] = player;
        }
    }
    return 0;

}
// Checa quem ganhou o jogo da velha
int ChecarGanhador(char tab[9], char player)
{
    if((tab[0] == player && tab[4] == player && tab[8] == player)  || 
       (tab[2] == player && tab[4] == player && tab[6] == player ) ||
       (tab[0] == player && tab[1] == player && tab[2] == player ) ||
       (tab[3] == player && tab[4] == player && tab[5] == player ) ||
       (tab[6] == player && tab[7] == player && tab[8] == player)  ||
       (tab[0] == player && tab[3] == player && tab[6] == player)  ||
       (tab[1] == player && tab[4] == player && tab[7] == player)  ||
       (tab[2] == player && tab[5] == player && tab[8] == player)   )
    {
        return 1;
    }
    return 0;
}
// IA de modo "normal". Apenas escolhe um espaço aleatório vazio 
int IA_normal(char tab[9], char player, int espacos_vazios )
{
    int indexes[9];
    calcular_espacos_vazios(tab, indexes);
    tab[indexes[random(espacos_vazios)]] == player;

    return 0;
}
// Função que monta a lógica do minimax: Simula as jogadas e avalia a melhor jogada
int IA_minimax(char tab[9], int espacos_vazios, char player, compare cmp )
{
    int indexes[9];
    calcular_espacos_vazios(tab, indexes);

    if(cmp == min)
    {
        int score = 1000;
        int thisScore;

        for(int i = 0; i < espacos_vazios; i++)
        {
            tab[indexes[i]] = player;

            if(ChecarGanhador(player, tab) == 1)
            {
                thisScore = espacos_vazios * cmp;
            }
            else if(espacos_vazios-1 == 0)
            {
                thisScore = 0;
            }
            else
            {
                thisScore = IA_minimax(tab, espacos_vazios-1, troca_jogador(player), -cmp);
            }

            if (thisScore < score)
            {
                score = thisScore;
            }

            tab[indexes[i]] = ' ';
        }
        return score;
    }
    else
    {
        int score = -1000;
        int thisScore;

        for(int i = 0; i < espacos_vazios; i++)
        {
            if(ChecarGanhador(player, tab) == 1)
            {
                thisScore = espacos_vazios * cmp;
            }
            else if(espacos_vazios-1 == 0)
            {
                thisScore = 0;
            }
            else
            {
                IA_minimax(tab[9], espacos_vazios-1, troca_jogador(player), -cmp);
            }
            
            if(thisScore > score)
            {
                score = thisScore;
            }

            tab[indexes[i]] = ' ';
        }
        return score;
    }
}
// Função onde a IA é aplicada no jogo
int IA_minimax_dificil(char tab[9], char player, int espacos_vazios)
{
    int score = -1000;
    int thisScore;

    int indexes[9];
    calcular_espacos_vazios(tab, indexes);
    int move = -1;

    for(int i = 0; i < espacos_vazios; i++)
    {
        if(ChecarGanhador(tab, player) == 1)
        {
            thisScore = espacos_vazios;
        }
        else if(espacos_vazios-1 == 0)
        {
            thisScore = 0;
        }
        else
        {
            thisScore = IA_minimax(tab, troca_jogador(player),  espacos_vazios, min);
        }

        if(thisScore > score)
        {
            score = thisScore;
            move = i;
        }

        tab[indexes[i]] = ' ';
    }

    tab[indexes[move]] = player;
    return 0;


}





