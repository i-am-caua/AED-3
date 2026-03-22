#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *vtr;
    int topo;
    int tam;

}Pilha;

void inicializarPilha (Pilha *p, int tam) {
    p->topo = -1; //vazia
    p->tam = tam;
    p->vtr = (char *) malloc (tam * sizeof (char));

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

void push (Pilha *p, char c) {
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
    int tamPilha, tamPilha2;
    char carac;
    Pilha p, p2;
    printf("Digite o tamanho da pilha 1:\n");
    scanf("%d", &tamPilha);
    printf("Digite o tamanho da pilha 2:\n");
    scanf("%d", &tamPilha2);

    if (tamPilha != tamPilha2) {
        printf("As pilhas tem valores diferentes por conta que o tamanho eh diferente\n");
        return 1;
    } else {
        inicializarPilha(&p, tamPilha);
        inicializarPilha(&p2, tamPilha2);
    }

    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o caractere %d da pilha 1:\n", i + 1);
        scanf(" %c", &carac);
        push(&p, carac);
    }
    for (int i = 0; i < tamPilha; i++) {
        printf("Digite o caractere %d da pilha 2:\n", i + 1);
        scanf(" %c", &carac);
        push(&p2, carac);
    }
    if (comparaPilha(&p, &p2)) {
        printf("Pilhas iguais\n");
    } else {
        printf("Pilhas diferentes\n");
    }

    return 0;
}
