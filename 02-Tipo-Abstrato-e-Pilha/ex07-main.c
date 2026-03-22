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

int main() {
  Pilha p;
  int i, num;

  inicializar(&p);

  for (i = 0; i < 3; i++) {
    printf("Digite o %do numero: ", i + 1);
    scanf("%d", &num);
    empilhar(&p, num);
  }

  printf("Valor no topo da pilha: %d\n", p.dados[p.topo]);

  return 0;
}
