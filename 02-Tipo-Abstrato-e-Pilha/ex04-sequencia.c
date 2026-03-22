#include <stdio.h>

#define MAX 10

typedef struct {
  int dados[MAX];
  int topo;
} Pilha;

void inicializar(Pilha *p) { p->topo = -1; }

int estaVazia(Pilha *p) { return p->topo == -1; }

int estaCheia(Pilha *p) { return p->topo == MAX - 1; }

void empilhar(Pilha *p, int valor) {
  if (!estaCheia(p)) {
    p->topo++;
    p->dados[p->topo] = valor;
  }
}

int desempilhar(Pilha *p) {
  int valor = -1;
  if (!estaVazia(p)) {
    valor = p->dados[p->topo];
    p->topo--;
  }
  return valor;
}

void sequenciaA(Pilha *p) {
  int seq[] = {1, 2, 4, 5, 10};
  int i;

  inicializar(p);

  for (i = 0; i < 5; i++)
    empilhar(p, seq[i]);

  printf("Sequencia A desempilhada: ");
  while (!estaVazia(p))
    printf("%d ", desempilhar(p));
  printf("\n");
}

void sequenciaB(Pilha *p) {
  int seq[] = {7, 12, 15, 18, 22};
  int i;

  inicializar(p);

  for (i = 0; i < 5; i++)
    empilhar(p, seq[i]);

  printf("Sequencia B desempilhada: ");
  while (!estaVazia(p))
    printf("%d ", desempilhar(p));
  printf("\n");
}

int main() {
  Pilha p;

  sequenciaA(&p);
  sequenciaB(&p);

  return 0;
}
