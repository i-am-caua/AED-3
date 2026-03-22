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

void limparPilha(Pilha *p) { p->topo = -1; }

int main() {
  Pilha p;

  inicializar(&p);

  empilhar(&p, 5);
  empilhar(&p, 15);
  empilhar(&p, 25);

  printf("Elementos antes de limpar: %d\n", quantidadeElementos(&p));

  limparPilha(&p);

  printf("Elementos depois de limpar: %d\n", quantidadeElementos(&p));

  return 0;
}
