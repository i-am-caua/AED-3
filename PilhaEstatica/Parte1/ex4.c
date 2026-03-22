#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vtr;
    int topo;
    int tam;
} Pilha;

void inicializarPilha(Pilha *p, int tam) {
    p->topo = -1;
    p->tam = tam;
    p->vtr = (int *) malloc(tam * sizeof(int));

    if (p->vtr == NULL) {
        printf("Erro\n");
        return;
    }
}

int isFull(Pilha *p) {
    return p->tam - 1 == p->topo;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int c) {
    if (isFull(p)) {
        printf("Erro, esta cheia\n");
        return;
    }

    p->topo++;
    p->vtr[p->topo] = c;
}

void pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha ja vazia\n");
        return;
    }
    p->topo--;
}

int verificaCrescente(Pilha *p) {
    if (isEmpty(p) || p->topo == 0) {
        return 1;
    }

    Pilha pAux;
    inicializarPilha(&pAux, p->tam);
    int ordem = 1;

    while (!isEmpty(p)) {
        int topoAtual = p->vtr[p->topo];
        push(&pAux, topoAtual);
        pop(p);

        if (!isEmpty(p)) {
            if (topoAtual < p->vtr[p->topo]) {
                ordem = 0;
                break;
            }
        }
    }

    while (!isEmpty(&pAux)) {
        push(p, pAux.vtr[pAux.topo]);
        pop(&pAux);
    }

    free(pAux.vtr);
    return ordem;
}

int main() {
    int tamPilha;
    int num;
    Pilha p;

    printf("Digite o tamanho da pilha:\n");
    scanf("%d", &tamPilha);

    inicializarPilha(&p, tamPilha);

    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o num %d da pilha:\n", i + 1);
        scanf("%d", &num);
        push(&p, num);
    }

    if (verificaCrescente(&p) == 1) {
        printf("Pilha esta em ordem crescente.\n");
    } else {
        printf("Pilha NAO esta em ordem crescente.\n");
    }

    while (!isEmpty(&p)) {
        printf("|%d|\n", p.vtr[p.topo]);
        pop(&p);
    }

    free(p.vtr);

    return 0;
}
