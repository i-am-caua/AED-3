#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vtr;
    int topo;
    int tam;

}Pilha;

Pilha *criarPilha (int tam) {
    Pilha *p = (Pilha *) malloc (sizeof(Pilha));
    if (p == NULL) {
        printf("Erro\n");
        free(p);
        return NULL;
    }
    p->topo = -1; //vazia
    p->tam = tam;
    p->vtr = (int *) malloc (tam * sizeof (int));

    if (p->vtr == NULL) {
        printf("Erro\n");
        free(p);
        return NULL;
    }
    return p;
}
int isFull (Pilha *p) {
    return p->tam-1 == p->topo;
}
int isEmpty (Pilha *p) {
    return p->topo == -1;
}

void push (Pilha *p, int c) {
    if (isFull(p)){
        printf("Erro, esta cheia");
        return;
    }

    p->topo++;
    p->vtr[p->topo] = c;
}
void pop (Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha ja vazia");
        return;
    }
    p->topo--;
}

int main () {
    int a[] = {1, 2, 4, 5, 10};
    int b[] = {7, 12, 15, 18, 22};
    int sizeA = sizeof(a) / sizeof(int);
    int sizeB = sizeof(b) / sizeof(int);

    Pilha *pilha1 = criarPilha(sizeA);
    Pilha *pilha2 = criarPilha(sizeB); 

    for (int i = sizeA - 1; i >= 0; i--) {
        push (pilha1, a[i]);
    }
    for (int i = sizeB - 1; i >= 0; i--) {
        push (pilha2, b[i]);
    }

    printf ("Pilha A: ");

    for (int i = 0; i < sizeA; i++) {
        printf ("%d", pilha1->vtr[pilha1->topo]);
        if (i < sizeA - 1) {
            printf(" ");
        }
        pop(pilha1);
    }
    printf ("\nPilha B: ");
    for (int i = 0; i < sizeB; i++) {
        printf ("%d", pilha2->vtr[pilha2->topo]);
        if (i < sizeB - 1) {
            printf(" ");
        }
        pop(pilha2);
    }
   
    return 0;
}
