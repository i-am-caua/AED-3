
#include <stdio.h>
#include <stdlib.h>
int **AlocaMatriz (int linha, int coluna) {
    int **matriz = (int **) malloc (linha * sizeof (int *));
    for (int i = 0; i < linha; i++) {
        matriz[i] = (int *) malloc (coluna * sizeof(int));
    }
    return matriz;
}
void lerMatriz (int **matriz, int linha, int coluna) {
    
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf ("Digite num[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        
    }
}
void printMatriz (int **matriz, int linha, int coluna) {
    printf ("\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf ("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}
void freeMatriz (int **matriz, int linha) {
    for (int i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}


int main() {
    int a, b, c, d;

    printf ("Digite a linha e colonua (A x B)\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    printf ("Digite a linha e colonua (C x D)\n");
    fflush(stdout);
    scanf("%d %d", &c, &d);
    

    int **AxB = AlocaMatriz(a, b);
    int **CxD = AlocaMatriz(c, d);

    lerMatriz(AxB, a, b);
    lerMatriz(CxD, c, d);
    printf ("\nMatriz (AxB):\n\n");
    printMatriz(AxB, a, b);
    printf ("\nMatriz (CxD):\n\n");
    printMatriz(CxD, c, d);

    if (b == c) {
        int **matrizP = AlocaMatriz (a, d);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                matrizP[i][j] = 0; 
                for (int k = 0; k < b; k++) { 
                    matrizP[i][j] += AxB[i][k] * CxD[k][j];
                }
            }
        }
        printf ("\nMatriz Produto:\n\n");
        printMatriz(matrizP, a, d);
        freeMatriz(matrizP, a);
    }
    freeMatriz(AxB, a);
    freeMatriz(CxD, c);
    

    return 0;
}
