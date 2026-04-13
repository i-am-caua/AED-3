#include "pilhaDouble.h"
#include <stdio.h>
#include <stdlib.h>
#define ERRO -999999999.0
Pilha *criarPilha(int tam) {
    Pilha *p = malloc (sizeof(Pilha));
    p->topo = -1;
    p->tam = tam;
    p->vet = malloc (sizeof(double) * tam);
    return p;
}
int isFullPilha(Pilha *p) {
    return p->topo == p->tam - 1;
}
int isEmptyPilha(Pilha *p) {
    return p->topo == -1;
}
int push(Pilha *p, double valor) {
    if (isFullPilha(p)) return 0;
    p->vet[++p->topo] = valor;
    return 1;
}
double pop (Pilha *p) {
    if (isEmptyPilha(p)) return ERRO;
    return p->vet[p->topo--];
}


