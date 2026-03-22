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

void copiaPilha (Pilha *p, Pilha *Copia, Pilha *pAux) {
    for (int i = 0; i <=p->tam - 1; i++) {
        push(pAux, p->vtr[p->topo]);
        pop(p);
    }
  
    for (int i = 0; i <= p->tam - 1; i++) {
        push(p, pAux->vtr[pAux->topo]);
        push(Copia, pAux->vtr[pAux->topo]);
        pop(pAux);
    }
}

int main () {
    int tamPilha;
    int num;
    Pilha p,pCopia, pAux;
    printf("Digite o tamanho da pilha 1:\n");
    scanf("%d", &tamPilha);

    inicializarPilha(&p, tamPilha);
    inicializarPilha(&pCopia, tamPilha);
    inicializarPilha(&pAux, tamPilha);
    
    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o num %d da pilha 1:\n", i + 1);
        scanf("%d", &num);
        push(&p, num);
    }
    printf ("\nFazendo copia...\n");

    copiaPilha(&p, &pCopia, &pAux);
   

    printf("\nCopia feita:\n");
   
    while (!isEmpty(&p)) {
        printf("|%d|\t|%d|\n", p.vtr[p.topo], pCopia.vtr[pCopia.topo]);
        pop(&p);
        pop (&pCopia);
    }
    free(p.vtr);
    free(pAux.vtr);
    free(pCopia.vtr);


    return 0;
}
