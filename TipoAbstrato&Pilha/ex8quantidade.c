#include <stdio.h>

#define MAX 20

typedef struct {
  int dados[MAX];
  int topo;
} Pilha;

void inicializar(Pilha *p) { p->topo = -1; }

void empilhar(Pilha *p, int valor) {
  if (p->topo < MAX - 1) {
    p->topo++;
    p->dados[p->topo] = valor;
  }
}

int quantidadeElementos(Pilha *p) { return p->topo + 1; }

int main() {
  Pilha p;

  inicializar(&p);

  empilhar(&p, 10);
  empilhar(&p, 20);
  empilhar(&p, 30);
  empilhar(&p, 40);

  printf("Quantidade de elementos na pilha: %d\n", quantidadeElementos(&p));

  return 0;
}
