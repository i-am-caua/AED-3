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

void copiaPilha (Pilha *p, Pilha *Copia, Pilha *PilhaAux) {
    
    for (int i = 0; i < p->tam; i++) {
        push(PilhaAux, p->vtr[p->topo] );
        push(Copia, p->vtr[p->topo]);
        pop(p);
        
    }
    for (int i = 0; i < p->tam; i++) {
        push(p, PilhaAux->vtr[PilhaAux->topo] );
        pop(PilhaAux); 
    }
    
}
int verificaPalindromo(Pilha *p1, Pilha *p2) {
    for (int i = 0; i < p1->tam; i++) {
        if (p1->vtr[p1->topo] != p2->vtr[p2->topo]) {
            return 0;
        }
        pop(p1);
        pop (p2);
    }
    return 1;
    
}

int main () {
    int tamPilha;
    char carac;
    Pilha p,p2, PilhaAux;
    printf("Digite o tamanho da pilha 1:\n");
    scanf("%d", &tamPilha);

    inicializarPilha(&p, tamPilha);
    inicializarPilha(&p2, tamPilha);
    inicializarPilha(&PilhaAux, tamPilha);
    printf("Digite a palavra(do tamanho da pilha):\n");
    
    for (int i = 0; i < tamPilha; i++) {
        scanf(" %c", &carac);
        push(&p, carac);
    }
   
    copiaPilha(&p, &p2, &PilhaAux);
   
    if (verificaPalindromo(&p, &p2)) {
        printf("Eh Palindromo");
    } else {
        printf ("Nao eh Palindromo");
    }
    free(p.vtr);
    free(PilhaAux.vtr);
    free(p2.vtr);


    return 0;
}
