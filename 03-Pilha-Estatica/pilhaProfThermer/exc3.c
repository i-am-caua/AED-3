#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *vtr;
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
    p->vtr = (float *) malloc (tam * sizeof (float));

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

void push (Pilha *p, float c) {
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
Pilha *copiaPilha (Pilha *p) {
    Pilha *pilhaCopiada = criarPilha(p->tam); 
    Pilha *pilhaAux = criarPilha(p->tam); 
    while (!isEmpty(p)) {
        push (pilhaAux, p->vtr[p->topo]);
        pop (p);
    }
    while (!isEmpty(pilhaAux)) {
        push (p, pilhaAux->vtr[pilhaAux->topo]);
        push (pilhaCopiada, pilhaAux->vtr[pilhaAux->topo]);
        pop (pilhaAux);
    }
    
    return pilhaCopiada;
}

int main () {
    float a[] = {1.0, 2.0, 4.0, 5.5, 10.5};
    
    int sizeA = sizeof(a) / sizeof(float);
  

    Pilha *pilha1 = criarPilha(sizeA);
  

    for (int i = sizeA - 1; i >= 0; i--) {
        push (pilha1, a[i]);
    }
   
    printf ("Pilha A: ");
    Pilha *pilhaCopia = copiaPilha (pilha1);

    for (int i = 0; i < sizeA; i++) {
        printf ("%.2f", pilha1->vtr[pilha1->topo]);
        if (i < sizeA - 1) {
            printf(" ");
        }
        pop(pilha1);
    }

    printf ("\nPilha copia A: ");
    for (int i = 0; i < sizeA; i++) {
        printf ("%.2f", pilhaCopia->vtr[pilhaCopia->topo]);
        if (i < sizeA - 1) {
            printf(" ");
        }
        pop(pilhaCopia);
    }

  
    return 0;
}
