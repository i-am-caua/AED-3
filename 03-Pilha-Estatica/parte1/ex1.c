#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vtr;
    int topo;
    int tam;

}Pilha;

void inicializarPilha (Pilha *p, int tam) {
    p->topo = -1; //vazia
    p->tam = tam;
    p->vtr = (int *) malloc (tam * sizeof (int));

    if (p->vtr == NULL) {
        printf("Erro\n");
        return;
    }
}
int isFull (Pilha *p) {
    return p->tam-1 == p->topo;
}
int isEmpty (Pilha *p) {
    return p->topo == -1;
}
void push (Pilha *p, int num) {
    if (isFull(p)){
        printf("Erro, esta cheia");
        return;
    }

    p->topo++;
    p->vtr[p->topo] = num;
}
void pop (Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha ja vazia");
        return;
    }
    p->topo--;
}

int main () {
    int num, valor, tamPilha;
    Pilha p;
    printf("Digite o tamanho da pilha:\n");
    scanf("%d", &tamPilha);
    inicializarPilha(&p, tamPilha);

    while (1) {
        printf("Qnts valores quer empilhar?\n");
        scanf("%d", &valor);
        if (valor > tamPilha) {
            printf("Erro, valor maior que o tamanho da pilha\n");
            continue;
        }
        break;

    }

    for (int i = 0; i < valor; i++) {
        printf("Dgite o num a empilhar:\n");
        scanf("%d", &num);
        push(&p, num);
    }
    for (; !isEmpty(&p);) {
        printf("|%d|\n", p.vtr[p.topo]);
        pop(&p);
    }

    return 0;
}
