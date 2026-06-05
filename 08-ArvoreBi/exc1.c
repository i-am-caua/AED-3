#include <stdio.h>
#include <stdlib.h>

typedef struct no{
   int chave;
   void *valor;
   No *esq, *dir, *pai;
}No;

typedef struct {
    No *raiz;
} ABB;

ABB *criarABB () {
    ABB *arvore = malloc (sizeof(ABB));
    return arvore;
}
No *criarNo (int chave, void *valor) {
    No *no = malloc (sizeof(No));
    no->chave = chave;
    no->valor = valor;
    no->dir = NULL;
    no->esq = NULL;
    no->pai = NULL;
    return no;
}

void inserir (ABB *arv, void *valor ) {
    
}
