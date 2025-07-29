#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "header/funcoes.h"

// Prototipacao das funcoes auxiliares
char MostrarMenu();
char EscolherJogador();
int  QuerJogarNovamente();
void JogarPartida(char modo, char humano);

// Menu principal: exibe opcoes e retorna a escolha do jogador
char MostrarMenu() {
    char opcao;

    printf("X & O ~ C EDITION\n");
    printf("=================\n");

    while (1) {
        printf("\nSelecione o modo de jogo:\n");
        printf("  1. Um jogador - IA Normal\n");
        printf("  2. Um jogador - IA Impossível\n");
        printf("  3. Sair\n");
        printf("  0. Dois jogadores\n");
        printf("Digite 0, 1, 2 ou 3: ");

        opcao = lerCaractere();
        if (opcao == 0) exit(1); // Fim de entrada

        if (opcao == '0' || opcao == '1' || opcao == '2' || opcao == '3') {
            return opcao;
        }

        printf("Opção inválida. Tente novamente.\n");
    }
}

// Permite o jogador escolher quem joga primeiro
char EscolherJogador() {
    char option;

    printf("\nQuem jogará primeiro?\n");
    printf("  1. Jogador (X)\n");
    printf("  2. Jogador (O)\n");
    printf("  3. Aleatório\n");
    printf("Escolha 1, 2 ou 3: ");

    while (1) {
        option = lerCaractere();
        if (option == 0) exit(1);

        switch (option) {
            case '1': return 'X';
            case '2': return 'O';
            case '3': return (char[2]){'X', 'O'}[rand() % 2];
        }

        printf("Opção inválida. Escolha 1, 2 ou 3: ");
    }
}

// Pergunta se o jogador deseja jogar novamente
int QuerJogarNovamente() {
    char replay;

    while (1) {
        printf("Deseja jogar novamente? [Y/N]: ");
        replay = lerCaractere();
        if (replay == 0) exit(1);

        if (toupper(replay) == 'Y') return 1;
        if (toupper(replay) == 'N') return 0;

        printf("Entrada inválida. Digite Y ou N.\n");
    }
}

// Executa um turno para o jogador humano
int turnoJogadorHumano(char grade[9], char TurnoJogador) {
    char coordenadas[4];
    printf("Turno do jogador %c\n", TurnoJogador);
    printf("Digite uma coordenada (ex: 2B): ");
    if (lerEntrada(coordenadas, 4) == NULL) exit(1);
    return posicionarJogada(TurnoJogador, grade, coordenadas);
}

// Executa um turno para a IA
int turnoIA(char grade[9], char TurnoJogador, char modo, int EmBranco) {
    printf("IA está jogando...\n");
    if (modo == '1') {
        return normalAI(grade, TurnoJogador, EmBranco);
    } else {
        return impossivelAI(grade, TurnoJogador, EmBranco);
    }
}

// Verifica se houve vencedor ou empate
int verificarFimDeJogo(char grade[9], int EmBranco) {
    if (ChecarGanhador('X', grade)) {
        MostrarTabuleiro(grade);
        printf("Jogador X venceu!\n");
        return 1;
    } else if (ChecarGanhador('O', grade)) {
        MostrarTabuleiro(grade);
        printf("Jogador O venceu!\n");
        return 1;
    } else if (EmBranco == 0) {
        MostrarTabuleiro(grade);
        printf("Empate!\n");
        return 1;
    }
    return 0;
}

// Controla a execucao de uma partida
void JogarPartida(char modo, char humano) {
    char tabuleiro[9];
    LimparTabuleiro(tabuleiro); // Inicializa o tabuleiro com espacos vazios

    char TurnoJogador = 'X';
    int  EmBranco = 9; // Contador de espacos vazios
    int  FimDeJogo = 0;

    while (!FimDeJogo) {
        MostrarTabuleiro(tabuleiro);

        int error;
        if (modo == '0' || humano == TurnoJogador) {
            error = turnoJogadorHumano(tabuleiro, TurnoJogador);
        } else {
            error = turnoIA(tabuleiro, TurnoJogador, modo, EmBranco);
        }

        if (error != -1) {
            TurnoJogador = alternarJogador(TurnoJogador);
            EmBranco--;
            printf("\n");
        }

        FimDeJogo = verificarFimDeJogo(tabuleiro, EmBranco);
    }
}

int main(void) {
    srand(time(0));  // Inicializa o gerador de números aleatórios (para IA aleatória)

    while (1) {
        char modo = MostrarMenu();  // Menu principal
        if (modo == '3') {
            printf("Saindo...\n");
            break;
        }

        // Define quem é o jogador humano (se modo não for 2 jogadores)
        char humano = 'X';
        if (modo == '1' || modo == '2') {
            humano = EscolherJogador();
        }

        JogarPartida(modo, humano);  // Executa a partida

        if (!QuerJogarNovamente()) {
            printf("Saindo...\n");
            break;
        }
    }

    return 0;
}
