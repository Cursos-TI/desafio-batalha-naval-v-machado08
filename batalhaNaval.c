#include <stdio.h>

int main() {
    //array linhas (A a J)
    char linhas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];


    //tabuleiro inicial com 0s representando a agua
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }


    //POSICIONAMENTO DOS NAVIOS (Navio 1) 3 posiçoes na horizontal
    //Começa na Linha 'B', coluna 3
    int navio1_linha_inicio = 1; 
    int navio1_coluna_inicio = 3; 


    for (int k = 0; k < 3; k++) { //3 posições lado a lado com o número 3
        tabuleiro[navio1_linha_inicio][navio1_coluna_inicio + k] = 3;
    }
    
    // Navio 2: 3 posiçoes na vertical
    //Começa na Linha 'E', coluna 7
    int navio2_linha_inicio = 4; 
    int navio2_coluna_inicio = 7; 


    for (int k = 0; k < 3; k++) {//3 posições uma embaixo da outra com o número 3
        tabuleiro[navio2_linha_inicio + k][navio2_coluna_inicio] = 3;
    }



    // Navio 3: 3 posições na diagonal principal começando em A, 0
    for (int l = 0; l < 3; l++) {
        tabuleiro[l][l] = 3; 
    }

    // Navio 4: 3 posições na diagonal secundária começando em A, 9
    for (int m = 0; m < 3; m++) {
        tabuleiro[m][9 - m] = 3;
    }



    //imprime a coluna (0 a 9)
    printf("   "); //esse espaço eu utilizei para ficarem alinhadas as colunas
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n"); //pula para uma nova linha depois da sequencia 0 a 9



    //imprime A,B,C,D,E....
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linhas[i]); 

        
        // Imprime 10 zeros para alinha atual 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
