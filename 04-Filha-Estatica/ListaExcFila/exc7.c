#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vet;
    int inicio, fim, qtd, tamanho;
} Fila;
typedef struct {
    int topo;
    int tam;
    int *vet;
} Pilha;

Pilha *criarPilha(int tam);
int isFullPilha(Pilha *p);
int isEmptyPilha(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p, int *valor);

Fila *criarFila (int tam) {
    Fila *f = malloc (sizeof(Fila));
    if (f == NULL) return NULL;
    f->vet = malloc (sizeof(int) * tam);
    if (f->vet == NULL) {
        free(f);
        return NULL;
    }
    f->fim = -1;
    f->inicio = 0;
    f->qtd = 0;
    f->tamanho = tam;
    return f;
}
int isFull (Fila *f) {
    return f->qtd == f->tamanho;
}
int isEmpty (Fila *f) {
    return f->qtd == 0;
}
int inserir (Fila *f, int valor) {
    if (isFull(f)) return 0;
    if (f->fim == f->tamanho-1) f->fim = -1;
    f->vet[++f->fim] = valor;
    f->qtd++;
    return 1;
}
int remover (Fila *f, int *valorRemovido) {
    if (isEmpty(f)) return 0;
    *valorRemovido = f->vet[f->inicio];
    if (f->inicio == f->tamanho-1) f->inicio = -1;
    f->inicio++;
    f->qtd--;
    return 1;
    
}
int size (Fila *f) {
    return f->qtd;
}
void clear (Fila *f) {
    f->fim = -1;
    f->inicio = 0;
    f->qtd = 0;
}

void printFila (Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    int valorRemovido;
    while (!isEmpty(f)) {
        printf("%d%s", f->vet[f->inicio], f->qtd > 1 ? ", ": "");
        remover(f, &valorRemovido);
        inserir(filaAux, valorRemovido);
    }
    while (!isEmpty(filaAux)) {
        remover(filaAux, &valorRemovido);
        inserir (f, valorRemovido);
    }
    free (filaAux->vet);
    free (filaAux);
    
}
void mesclaFila (Fila *f1, Fila *f2, Fila *f3) {
    int valor;
    while (!isEmpty(f1) || !isEmpty(f2)) {
        if (!isEmpty(f1) && !isEmpty(f2)) {
            if (f1->vet[f1->inicio] <= f2->vet[f2->inicio]) {
                remover (f1, &valor);
                inserir (f3, valor);
            } 
            else {
                remover (f2, &valor);
                inserir (f3, valor);
            }

        } 
        else if (!isEmpty(f1)) {
            remover (f1, &valor);
            inserir (f3, valor);
        } 
        else {
            remover (f2, &valor);
            inserir (f3, valor);
        }
    }
    
}
int main () {
    int valorF1[] = {0, 2, 6, 7, 11};
    int valorF2[] = {1, 2, 5, 9, 10, 12};
    int sizeF1 = sizeof (valorF1) / sizeof (int);
    int sizeF2 = sizeof (valorF2) / sizeof (int);
    
    
    Fila *f1 = criarFila(sizeF1);
    Fila *f2 = criarFila(sizeF2);
    Fila *f3 = criarFila(sizeF1 + sizeF2);
    if (f1 == NULL || f2 == NULL || f3 == NULL) return 1;
    
    for (int i = 0; i < sizeF1; i++) {
        inserir (f1,valorF1[i]);
    }
    for (int i = 0; i < sizeF2; i++) {
        inserir (f2,valorF2[i]);
    }
    printf ("Filas originais:\n");
    printf("F1: [");
    printFila(f1);
    printf("]\n");
    printf("F2: [");
    printFila(f2);
    printf("]\n");
    mesclaFila (f1, f2, f3);

    printf ("\nFila mesclada e ordenada:\n");
    printf("[");
    printFila(f3);
    printf("]\n\n");

    free(f1->vet);
    free(f1);
    free(f2->vet);
    free(f2);
    free(f3->vet);
    free(f3);
        
    return 0;

}
   