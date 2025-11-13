#include <stdio.h>

int main() {
    //array linhas (A a J)
    char linhas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];


    //tabuleiro inicial com 0s
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
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
