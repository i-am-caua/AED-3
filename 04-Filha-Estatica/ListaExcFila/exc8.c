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

void mesclaFilaDecrescente(Fila *f1, Fila *f2, Fila *f3) {
    int total = f1->qtd + f2->qtd;
    Fila *fAux = criarFila(total);
    Pilha *p = criarPilha(total);
    int valor;

    if (fAux == NULL || p == NULL) {
        if (fAux != NULL) {
            free(fAux->vet);
            free(fAux);
        }
        if (p != NULL) {
            free(p->vet);
            free(p);
        }
        return;
    }

    while (!isEmpty(f1) || !isEmpty(f2)) {
        if (!isEmpty(f1) && !isEmpty(f2)) {
            if (f1->vet[f1->inicio] <= f2->vet[f2->inicio]) {
                remover(f1, &valor);
                inserir(fAux, valor);
            } else {
                remover(f2, &valor);
                inserir(fAux, valor);
            }
        } else if (!isEmpty(f1)) {
            remover(f1, &valor);
            inserir(fAux, valor);
        } else {
            remover(f2, &valor);
            inserir(fAux, valor);
        }
    }

    while (!isEmpty(fAux)) {
        remover(fAux, &valor);
        push(p, valor);
    }

    while (!isEmptyPilha(p)) {
        pop(p, &valor);
        inserir(f3, valor);
    }

    free(fAux->vet);
    free(fAux);
    free(p->vet);
    free(p);
}

int main () {
    int valorF1[] = {0, 2, 6, 7, 11};
    int valorF2[] = {1, 2, 5, 9, 10, 12};
    int sizeF1 = sizeof(valorF1) / sizeof(int);
    int sizeF2 = sizeof(valorF2) / sizeof(int);

    Fila *f1 = criarFila(sizeF1);
    Fila *f2 = criarFila(sizeF2);
    Fila *f3 = criarFila(sizeF1 + sizeF2);

    if (f1 == NULL || f2 == NULL || f3 == NULL) return 1;

    for (int i = 0; i < sizeF1; i++) inserir(f1, valorF1[i]);
    for (int i = 0; i < sizeF2; i++) inserir(f2, valorF2[i]);

    mesclaFilaDecrescente(f1, f2, f3);

    printf("F3 decrescente: [");
    printFila(f3);
    printf("]\n");

    free(f1->vet);
    free(f1);
    free(f2->vet);
    free(f2);
    free(f3->vet);
    free(f3);

    return 0;
}
