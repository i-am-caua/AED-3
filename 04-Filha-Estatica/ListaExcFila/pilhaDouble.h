#ifndef PILHA_H
#define PILHA_H
 typedef struct {
    int topo;
    int tam;
    double *vet;
 } Pilha;
 Pilha *criarPilha (int tam);
 int isFullPilha (Pilha *p);
 int isEmptyPilha (Pilha *p);
 int push (Pilha *p, double valor);
 double pop (Pilha *p);
#endif
