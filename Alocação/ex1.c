
#include <stdio.h>
#include <stdlib.h>
void inserir (int *ptr, int tamanhoV) {
    int valor, index;
    printf ("Digite a posicao (0 - %d):\n", tamanhoV - 1);
    scanf ("%d", &index);
    if (index >= tamanhoV) {
        printf ("Erro, vetor menor");
        return;
    }
    printf ("\nDigite o valor:\n");
    scanf ("%d", &valor);
    ptr[index] = valor;
    
}
void consulta (int *ptr, int tamV) {
    int index;
    
    printf ("Digite a posicao (0 - %d):\n", tamV - 1);
    scanf ("%d", &index);
    if (index >= tamV) {
        printf ("Erro, vetor menor");
        return;
    }
    printf ("\nValor da posicao %d eh: %d\n", index, ptr[index]);
}

int main()
{
    int Byte;
    int *Memory;
    int Option;
    
    printf ("Digite o total de bytes:\n");
    while (1) {
        scanf ("%d", &Byte);
        if (Byte % 4 != 0) {
            printf ("\nErro! Tem que ser multiplo de 4\n");
            continue;
        }
        break;
    }
     Memory = (int *) calloc (Byte, 1);
     
     if (Memory == NULL) {
         printf ("Erro");
         return 1;
     }
     do {
         printf ("Qual opcao, voce quer\n");
         printf ("1. Inserir um valor em uma determinada posicao\n");
         printf ("2. Consultar o valor armazenado em uma posicoo especifica\n");
         printf ("3. Sair\n");
         scanf ("%d", &Option);
         if (Option == 1) {
             inserir(Memory, Byte / 4);
         }
         if (Option == 2) {
             consulta(Memory, Byte / 4);
         }
         
     } while (Option != 3);
    
    free (Memory);
    return 0;
}
