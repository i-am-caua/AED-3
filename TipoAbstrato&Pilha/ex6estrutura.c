#include <stdio.h>

#define MAX 20

typedef struct {
  int dados[MAX];
  int topo;
} Pilha;

int main() {
  Pilha p;
  p.topo = -1;

  printf("Estrutura Pilha declarada com capacidade para %d elementos\n", MAX);
  printf("Topo inicializado em: %d\n", p.topo);

  return 0;
}
