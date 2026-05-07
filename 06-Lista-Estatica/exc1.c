#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int fim, tam;
    char *vtr;
} Lista;

Lista *criarLista (int tam) {
    Lista *l = malloc (sizeof(Lista));

    l->fim = -1;
    l->tam = tam;
    l->vtr = malloc (sizeof (char) * tam);

    return l;
}
int isFull (Lista *l) {return l->fim == l->tam - 1;}
int isEmpty (Lista *l) {return l->fim == -1;}
void inserir (Lista *l, char valor) {
    if (isFull (l)) return;
    l->vtr[++l->fim] = valor;
}
void inserirPosicao (Lista *l, int index, char valor) {
    if (isFull (l)|| index < 0 || index > l->fim + 1) return;
    l->fim++;
    for (int i = l->fim; i >= index + 1; i-- ) {
        l->vtr[i] = l->vtr[i - 1];
    }
    l->vtr[index] = valor;
}
char remover (Lista *l, int index) {
    if (isEmpty(l) || index < 0 || index > l->fim) return '\0';
    l->fim--;
    char aux = l->vtr[index];
    for (int i = index; i <= l->fim; i++) {
        l->vtr[i] = l->vtr[i + 1];
    }
    return aux;
}
char consultar (Lista *l, int index) {
    if (isEmpty(l) || index < 0 || index > l->fim) return '\0';
    return l->vtr[index];
}
void printLista (Lista *l) {
    for (int i = 0; i <= l->fim; i++) {
        printf ("%c ", l->vtr[i]);
    }
}
int main () {
    Lista *l = criarLista(10);
    inserir(l, 'a');
    inserir(l, 'b');
    inserir(l, 'c');
    inserirPosicao(l, 2,'b');
    printLista (l);
    remover(l, 2);
    printf("\n");
    printLista(l);
}

