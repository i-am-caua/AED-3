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
void localiza (Pilha *p, int num, Pilha *pAux) {
    while (!isEmpty(p)) {
        if (p->vtr[p->topo] != num) {
            push(pAux, p->vtr[p->topo] );
        }
        pop(p);
    }
}
int inverte (Pilha *p, Pilha *pAux) {
    int max = pAux->topo, cout = 0;
    for (int i = 0; i <= max; i++) {
        push(p, pAux->vtr[pAux->topo]);
        pop(pAux);
        cout++;
    }
    return cout;

}

int main () {
    int tamPilha;
    int num, numPop;
    Pilha p, pAux;
    printf("Digite o tamanho da pilha 1:\n");
    scanf("%d", &tamPilha);

    inicializarPilha(&p, tamPilha);
    inicializarPilha(&pAux, tamPilha);


    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o num %d da pilha 1:\n", i + 1);
        scanf("%d", &num);
        push(&p, num);
    }
    printf("Digite o num a remover:\n");
    scanf("%d", &numPop);

    localiza(&p, numPop, &pAux);

    printf("\nPilha com %d removido e o total removido eh %d:\n", numPop,inverte(&p, &pAux));

    while ( !isEmpty(&p)) {
        printf("|%d|\n", p.vtr[p.topo]);
        pop(&p);
    }
    free(p.vtr);
    free(pAux.vtr);



    return 0;
}
