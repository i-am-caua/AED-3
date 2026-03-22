
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *vtr;
    int tamV;
    
    printf ("DIgite o tamanho do vtr:\n");
    fflush(stdout);
    scanf ("%d", &tamV);
    vtr = (int *) malloc (tamV * sizeof(int));

    for (int i = 0; i < tamV; i++) {
        printf ("Digite o valor[%d]: ", i);
        scanf ("%d", &vtr[i]);
    }
    for (int i = 0; i < tamV; i++) {
        printf ("%d ", vtr[i]);
    }
    free (vtr);

    return 0;
}
