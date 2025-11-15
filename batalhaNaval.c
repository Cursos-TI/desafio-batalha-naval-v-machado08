#include <stdio.h> 

//FUNÇÕES DE POSICIONAMENTO

// Função que gera o Cone no tabuleiro (número 2)
// Recebe a matriz do tabuleiro e a posição inicial (linha/coluna)
void cone(int tabuleiro[10][10], int inicioLargura, int inicioColuna) {
    // Percorre as 3 linhas de altura da figura
    for (int i = 0; i < 3; i++) {
        int largura = 2 * i + 1; // A largura da linha cresce: 1, 3, 5
        int col_inicio = inicioColuna + 2 - i; // Ajusta o início da coluna para centralizar a linha

        // Preenche a linha atual com o número 2
        for (int j = 0; j < largura; j++) {
            // Verifica se a posição está DENTRO dos limites 0 a 9 do tabuleiro
            if (inicioLargura + i >= 0 && inicioLargura + i < 10 && col_inicio + j >= 0 && col_inicio + j < 10) {
                tabuleiro[inicioLargura + i][col_inicio + j] = 2;
            }
        }
    }
}

// Função que gera a Cruz no tabuleiro (número 1)
void cruz(int tabuleiro[10][10], int inicioLargura, int inicioColuna) {
    // Desenha a linha horizontal do meio (5 posições)
    for (int j = 0; j < 5; j++) {
        if (inicioLargura + 1 >= 0 && inicioLargura + 1 < 10 && inicioColuna + j >= 0 && inicioColuna + j < 10) {
            tabuleiro[inicioLargura + 1][inicioColuna + j] = 1;
        }
    }

    
    //faz i ser 0 (topo) e depois 2 (base)
    for (int i = 0; i < 3; i += 2) {
        if (inicioLargura + i >= 0 && inicioLargura + i < 10 && inicioColuna + 2 >= 0 && inicioColuna + 2 < 10) {
            tabuleiro[inicioLargura + i][inicioColuna + 2] = 1;
        }
    }
}

// Função que gera o Octaedro no tabuleiro (número 3)
void octaedro(int tabuleiro[10][10], int inicioLargura, int inicioColuna) {
    // Percorre as 3 linhas de altura
    for (int i = 0; i < 3; i++) {
        int largura;
        int col_inicio;

        if (i == 0 || i == 2) {
            // Linhas superior e inferior têm 1 elemento, centralizado
            largura = 1;
            col_inicio = inicioColuna + 2;
        } else {
            // Linha do meio tem 3 elementos
            largura = 3;
            col_inicio = inicioColuna + 1;
        }

        // Preenche a linha atual com o número 3
        for (int j = 0; j < largura; j++) {
            if (inicioLargura + i >= 0 && inicioLargura + i < 10 && col_inicio + j >= 0 && col_inicio + j < 10) {
                tabuleiro[inicioLargura + i][col_inicio + j] = 3;
            }
        }
    }
}


int main() {
    char linhas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Cria o tabuleiro: uma matriz de 10 linhas por 10 colunas
    int tabuleiro[10][10];

    // Inicializa o tabuleiro: preenche tudo com 0 (zero), que representa a água
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //POSICIONAMENTO DAS FIGURAS NO TABULEIRO
    // Posiciona o Cone (2) começando na Linha B, Coluna 2
    cone(tabuleiro, 1, 2);

    // Posiciona a Cruz (1) começando na Linha F, Coluna 0
    cruz(tabuleiro, 5, 0);

    // Posiciona o Octaedro (3) começando na Linha H, Coluna 5
    octaedro(tabuleiro, 7, 5);


    //IMPRESSÃO DO TABULEIRO
    // Imprime os números das colunas (0 a 9) no topo
    printf("  "); // Espaço para alinhar com as letras das linhas
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Pula para a próxima linha


    for (int i = 0; i < 10; i++) {
        printf("%c ", linhas[i]); // Imprime a letra da linha atual (A, B, C...)
        
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime 0, 1, 2 ou 3
        }
        printf("\n"); // Pula para a próxima linha para começar a imprimir a próxima linha do tabuleiro
    }

    return 0; 
}
