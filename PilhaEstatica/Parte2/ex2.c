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

void copiaPilha (Pilha *p, Pilha *Copia, Pilha *PilhaInter) {
    
    for (int i = 0; i <= p->tam - 1; i++) {
        push(PilhaInter, p->vtr[p->topo] );
        push(PilhaInter, Copia->vtr[Copia->topo]);
        pop(p);
        pop(Copia);
    }
}

int main () {
    int tamPilha;
    int num;
    Pilha p,p2, PilhaInter;
    printf("Digite o tamanho da pilha 1:\n");
    scanf("%d", &tamPilha);

    inicializarPilha(&p, tamPilha);
    inicializarPilha(&p2, tamPilha);
    inicializarPilha(&PilhaInter, tamPilha * 2);
    
    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o num %d da pilha 1:\n", i + 1);
        scanf("%d", &num);
        push(&p, num);
    }
    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o num %d da pilha 2:\n", i + 1);
        scanf("%d", &num);
        push(&p2, num);
    }


    printf ("\nIntercalando...\n");

    copiaPilha(&p, &p2, &PilhaInter);
   

    printf("\nfeito:\n\n");
   
    while (!isEmpty(&PilhaInter)) {
        printf("|%d|\n", PilhaInter.vtr[PilhaInter.topo]);
        pop(&PilhaInter);
       
    }
    free(p.vtr);
    free(PilhaInter.vtr);
    free(p2.vtr);


    return 0;
}
