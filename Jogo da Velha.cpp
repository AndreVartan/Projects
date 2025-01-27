#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
/*
	0	1	2
0	_ | _ | _
1	_ | _ | _
2	_ | _ | _

*/

// Funcao para inicializar o tabuleiro com espacos vazios
void Matriz() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Funcao para validar se o caractere eh valido (x ou 0)
int validador(char letra) {
    if (letra == 'x' || letra == '0')
        return 1; 
    return 0;
}

// Funcao para verificar se a coordenadaa eh valida
int coordenadaValida(int x, int y) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3)
        return 1;
    return 0;
}

// Funcao para verificar se uma posicao do tabuleiro esta vazia
int posicaoVazia(int x, int y) {
    if (tabuleiro[x][y] == ' ')
        return 1;
    return 0;
}

// Funcao para verificar as linhas
int GanhouLinha() {
    for (int i = 0; i < 3; i++) { // percorre pelas linhas
        if (validador(tabuleiro[i][0]) && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1;
    }
    return 0;
}

// Funcao para verificar as colunas
int GanhouColuna() {
    for (int i = 0; i < 3; i++) { // percorre pelas colunas
        if (validador(tabuleiro[0][i]) && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }
    return 0;
}

// Função para verificar a diagonal
int GanhouDiagonal() {
    if (validador(tabuleiro[0][0]) && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1;
    return 0;
}

// Função para verificar a diagonal secundaria
int GanhouDiagonalSec() {
    if (validador(tabuleiro[0][2]) && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1;
    return 0;
}

// Função para imprimir o tabuleiro
void imprimir() {
    printf("\n\t    0   1   2\n");
    for (int lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin); // Imprime o indice da linha
        for (int col = 0; col < 3; col++) {
            printf(" %c ", tabuleiro[lin][col]); // Imprime o valor do campo
            if (col < 2)
                printf("|");
        }
        if (lin < 2)
            printf("\n\t   ---------\n");
    }
    printf("\n");
}

// Função principal do jogo, mostra o estado atual do tabuleiro, verifica se a posição é valida, ordena a vez de cada um e imprime o resultado
void jogar() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do {
        do {
            imprimir(); // Mostra o estado atual do tabuleiro
            printf("\nDigite a coordenada que deseja jogar (linha coluna): ");
            scanf("%d %d", &x, &y);

            valida = coordenadaValida(x, y) && posicaoVazia(x, y); // Verifica se a jogada é válida
            if (!valida)
                printf("\nPosicao invalida! Tente novamente.\n");
        } while (!valida);

        // Define o símbolo baseado no jogador (1 = 'x', 2 = '0')
        if (ordem == 1)
            tabuleiro[x][y] = 'x';
        else
            tabuleiro[x][y] = '0';

        jogadas++;
        ganhou = GanhouLinha() || GanhouColuna() || GanhouDiagonal() || GanhouDiagonalSec(); // Verifica vitória
        ordem = 3 - ordem; // Alterna entre os jogadores (1 e 2)
    } while (!ganhou && jogadas < 9);

    imprimir();
    if (ganhou) {
        printf("\nParabens! Jogador %d venceu!\n", 3 - ordem);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    int opcao;

    do {
        Matriz();
        jogar();
        printf("\nDeseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &opcao);
    } while (opcao == 1);
    return 0;
}
