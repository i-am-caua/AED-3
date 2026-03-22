
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *vtr;
    int tamV, par = 0, impar = 0;
    
    printf ("DIgite o tamanho do vtr:\n");
    fflush(stdout);
    scanf ("%d", &tamV);
    vtr = (int *) malloc (tamV * sizeof(int));

    for (int i = 0; i < tamV; i++) {
        printf ("Digite o valor[%d]: ", i);
        scanf ("%d", &vtr[i]);
    }
    for (int i = 0; i < tamV; i++) {
        if (vtr[i] % 2 == 0) {
            par++;
        } else {
            impar++;
        }   
    }
    printf ("O total de par eh: %d\nO total de impar eh: %d", par, impar);
    free (vtr);

    return 0;
}

