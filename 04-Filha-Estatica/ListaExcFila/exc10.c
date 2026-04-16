#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vet;
    int inicio, fim, qtd, tamanho;
} Fila;

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
    if (f->fim == f->tamanho - 1) f->fim = -1;
    f->vet[++f->fim] = valor;
    f->qtd++;
    return 1;
}

int remover (Fila *f, int *valorRemovido) {
    if (isEmpty(f)) return 0;
    *valorRemovido = f->vet[f->inicio];
    if (f->inicio == f->tamanho - 1) f->inicio = -1;
    f->inicio++;
    f->qtd--;
    return 1;
}

void mostrarFila(Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    int valor;

    while (!isEmpty(f)) {
        printf("%d%s", f->vet[f->inicio], f->qtd > 1 ? ", " : "");
        remover(f, &valor);
        inserir(filaAux, valor);
    }

    while (!isEmpty(filaAux)) {
        remover(filaAux, &valor);
        inserir(f, valor);
    }

    free(filaAux->vet);
    free(filaAux);
}

int main () {
    int valores[] = {7, 14, 21, 28, 35};
    int n = sizeof(valores) / sizeof(int);

    Fila *f = criarFila(n);
    if (f == NULL) return 1;

    for (int i = 0; i < n; i++) inserir(f, valores[i]);

    printf("Valores da fila: [");
    mostrarFila(f);
    printf("]\n");

    free(f->vet);
    free(f);
    return 0;
}
