#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define random(n) (rand ()%(n))

//Monta o tabuleiro
int Tabuleiro(char tab[9]);
// Verifica quais espaços estão vazios
void calcular_espacos_vazios(char tab[9], int indexes[9]);
// Pega apenas o primeiro caractere inserido
char caracter();
//Troca de jogador
char troca_jogador(char player);
// Verificação espaços preenchidos e coordenada dentro do tabuleiro (Modo 1v1)
int VerificarCoord(char tab[9], char* coordenada, char player);
int ChecarGanhador(char tab[9], char player);
typedef enum _compare
{
    max = 1,
    min = -1,
} compare;
int IA_normal(char tab[9], char player, int espacos_vazios );
// IA minimax que simula e analisa jogadas para a IA
int IA_minimax(char tab[9], int espacos_vazios, char player, compare cmp );
// Essa função ira agir dentro do tabuleiro de acordo com a função minimax
int IA_minimax_dificil(char tab[9], int espacos_vazios, char player);






#endif
