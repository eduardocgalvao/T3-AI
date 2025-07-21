#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define random(n) (rand ()%(n))

//Monta o tabuleiro
Tabuleiro(char tab[9]);
// Verifica quais espaços estão vazios
void espacos_vazios(char tab[9], int indexes[9]);
// Pega apenas o primeiro caractere inserido
char caracter();
//Troca de jogador
char troca_jogador(char player);




#endif
