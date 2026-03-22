
#include <stdio.h>
#include <stdlib.h>

int verificaDuplicado (int num[]) {
    
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (num[j] == num[i]) return 1; //num duplicado  
        }
    }
    return 0;
}
int totalAcertos (int numLot[], int numUsa[]) {
    int total = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (numLot[j] == numUsa[i]) total++;  
        }
    }
    return total;
}
void numsAcertos (int vtr[], int numLot[], int numUsa[]) {
   
        int k = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (numLot[j] == numUsa[i]) {
                    vtr[k] = numLot[j];  
                    k++;
                }
            }
        }
    }


int main()
{
    int numLot[6];
    int numUsa[6];
    
    int *acertos;
    while (1) {
        
        printf ("Digite os 6 nums da loteria:\n");

        for (int i = 0; i < 6; i++) {
            scanf ("%d", &numLot[i]); 
        }
        if (verificaDuplicado(numLot)) {
            printf ("\nErro, num duplicado!\n");
            continue;
        }
        break;
        
    }
    while (1) {
        
        printf ("Digite os 6 nums que vc jogou loteria:\n");

        for (int i = 0; i < 6; i++) {
            scanf ("%d", &numUsa[i]);
        }
        if (verificaDuplicado(numUsa)) {
            printf ("\nErro, num duplicado!\n");
            continue;
        }
        break;  
    }
    int tamV = totalAcertos(numLot, numUsa) * sizeof(int);

    if (tamV != 0) {
        
        acertos = (int *) malloc(tamV);

        printf ("Nums da loteria:\n");
        for (int i = 0; i < 6; i++) {
            printf ("%d ", numLot[i]);
        }
        printf ("\nSeus nums:\n");
        for (int i = 0; i < 6; i++) {
            printf ("%d ", numUsa[i]);
        }
        printf ("\nNums acertados:\n");
        numsAcertos (acertos, numLot, numUsa);
        for (int i = 0; i < tamV / 4; i++) {
            printf ("%d ", acertos[i]);
        }

    } else {

        printf ("Nums da loteria:\n");
        for (int i = 0; i < 6; i++) {
            printf ("%d ", numLot[i]);
        }
        printf ("\n Seus nums:\n");
        for (int i = 0; i < 6; i++) {
            printf ("%d ", numUsa[i]);
        }
        printf ("\nNao teve nenhum acerto\n");
    }
    free (acertos);

    return 0;
}
