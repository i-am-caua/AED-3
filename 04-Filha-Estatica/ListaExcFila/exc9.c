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

void printFila (Fila *f) {
    Fila *filaAux = criarFila(f->tamanho);
    int valorRemovido;
    while (!isEmpty(f)) {
        printf("%d%s", f->vet[f->inicio], f->qtd > 1 ? ", " : "");
        remover(f, &valorRemovido);
        inserir(filaAux, valorRemovido);
    }
    while (!isEmpty(filaAux)) {
        remover(filaAux, &valorRemovido);
        inserir(f, valorRemovido);
    }
    free(filaAux->vet);
    free(filaAux);
}

Pilha *criarPilha(int tam) {
    Pilha *p = malloc(sizeof(Pilha));
    if (p == NULL) return NULL;
    p->vet = malloc(sizeof(int) * tam);
    if (p->vet == NULL) {
        free(p);
        return NULL;
    }
    p->topo = -1;
    p->tam = tam;
    return p;
}

int isFullPilha(Pilha *p) {
    return p->topo == p->tam - 1;
}

int isEmptyPilha(Pilha *p) {
    return p->topo == -1;
}

int push(Pilha *p, int valor) {
    if (isFullPilha(p)) return 0;
    p->vet[++p->topo] = valor;
    return 1;
}

int pop(Pilha *p, int *valor) {
    if (isEmptyPilha(p)) return 0;
    *valor = p->vet[p->topo--];
    return 1;
}

void inverterFila(Fila *f) {
    Pilha *p = criarPilha(f->tamanho);
    int valor;
    if (p == NULL) return;

    while (!isEmpty(f)) {
        remover(f, &valor);
        push(p, valor);
    }

    while (!isEmptyPilha(p)) {
        pop(p, &valor);
        inserir(f, valor);
    }

    free(p->vet);
    free(p);
}

int main () {
    int valores[] = {3, 8, 1, 9, 4};
    int n = sizeof(valores) / sizeof(int);

    Fila *f = criarFila(n);
    if (f == NULL) return 1;

    for (int i = 0; i < n; i++) inserir(f, valores[i]);

    printf("Original: [");
    printFila(f);
    printf("]\n");

    inverterFila(f);

    printf("Invertida: [");
    printFila(f);
    printf("]\n");

    free(f->vet);
    free(f);
    return 0;
}
