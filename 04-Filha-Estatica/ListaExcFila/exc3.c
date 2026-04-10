#include <stdio.h>
#include <stdlib.h>
#define intMin -2147483648
typedef struct {
    int fim, inicio, tamanho;
    double *vet;
} Fila;
Fila *criarFila (int tamanho) {
    Fila *f = malloc (sizeof(Fila));
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = tamanho;
    f->vet = malloc (tamanho * sizeof(double));
    return f;
}
int inserir (Fila *f, double valor) {
    if (isFull(f)) return 0;

    f->fim++;
    f->vet[f->fim] = valor;
    return 1;
}
int remover (Fila *f) {
    if (isEmpty(f)) return intMin;
    return f->vet[f->inicio++];
}
int isEmpty (Fila *f) {
    return f->fim == -1;
}
int isFull (Fila *f) {
    return f->fim == f->tamanho - 1;
}
int size (Fila *f) {
    return (f->fim - f->inicio) + 1;
}
void clear (Fila *f) {
    if (isEmpty(f)) return;
    f->fim = -1;
    f->inicio = 0;
}


int main () {

    return 0;
}
