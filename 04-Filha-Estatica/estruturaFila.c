#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int inicio;
    int fim;
    int *vet;
    int tam;
} Fila;
Fila *criarFila (int tamanho) {
    Fila *f = (Fila *) malloc (sizeof(Fila));
    f->tam = tamanho;
    f->fim = -1;
    f->inicio = 0;
    f->vet = (int *) malloc (sizeof(int) * tamanho);

    return f;
}
int inserir (Fila *f, int valor) {
    if (isFull(f)) return 0;
    f->fim++;
    f->vet[f->fim] = valor;
    return 1;
}
int remover (Fila *f) {
    if (isEmpty(f)) return 0;
    return f->vet[f->inicio++];
}
int isEmpty (Fila *f) {
    return f->fim == -1;
}
int isFull (Fila *f) {
    return f->fim == f->tam - 1;
}
void imprimirFila (Fila *f) {
    for (int i = f->inicio; i <= f->fim; i++) {
        printf ("%d", f->vet[i]);
        if (i < f->fim) {
            printf (", ");
        }
    }
    printf ("\n");
}


int main () {
    Fila *fila;
    int tamanho;
    int opcao;
    int valor;

    printf("Digite o tamanho da fila: ");
    scanf("%d", &tamanho);
    fila = criarFila(tamanho);
    printf("-----------------\n");
    do {
        printf("1. Inserir\n2. Remover\n3. Ver fila\n0. Sair\n\nDigite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf ("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir(fila, valor);
                break;
            case 2:
                printf("Valor removido: %d\n", remover(fila));
                break;
            case 3:
                printf ("Fila: ");
                imprimirFila(fila);
                printf ("\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
