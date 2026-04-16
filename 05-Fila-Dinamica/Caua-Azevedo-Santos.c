#include <stdio.h>
#include <stdlib.h>
typedef struct NO {
    char caractere;
    struct NO proximoNo;
} NO;
typedef struct {
    NO *inicio, *fim;
    int qtd;
} Fila;
Fila *criarFila () {
    Fila *f = malloc (sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}




int main () {

    return 0;
}
