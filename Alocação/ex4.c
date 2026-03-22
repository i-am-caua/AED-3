
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    double *vtr;
    int tamV;
    while (1) {
        printf ("DIgite o tamanho do vtr (>= 10):\n");
        fflush(stdout);
        scanf ("%d", &tamV);
        if (tamV >= 10) {
            vtr =  (double *) malloc (tamV * sizeof(double));
            if (vtr == NULL) {
                printf ("Erro, memoria insuficiente!\n");
                return 1;
            }
            break;
        }
        printf ("Erro, tamanho do vtr deve ser >= 10!\n");
        fflush(stdout);
        
    }
    printf ("\nNums sorteados:\n");
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        vtr[i] = rand () % 101;
    }
    for (int i = 0; i < 10; i++) {
        printf ("%.1f ", vtr[i]);
    }
    free (vtr);

    
    

    return 0;
}
