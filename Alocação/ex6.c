
#include <stdio.h>
#include <stdlib.h>


int main() {
    int linha, coluna;
    
    int **matriz;

    printf ("Digite o nums de linhas: ");
    scanf ("%d", &linha);
    printf ("Digite o total de colunas: ");
    scanf ("%d", &coluna);

    matriz = (int **) malloc (linha * sizeof(int *));

    for (int i = 0; i < linha; i++) {
        matriz[i] = (int *) malloc (coluna * sizeof (int));

    }
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf ("Digite[%d] [%d]: ", i, j);
            scanf ("%d", &matriz[i][j] );
        }
    }
    printf("\n");

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf ("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
