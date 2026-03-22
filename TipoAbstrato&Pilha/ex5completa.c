#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *dados;
  int topo;
  int capacidade;
} Pilha;

Pilha *criarPilha(int tamanho) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->dados = (int *)malloc(tamanho * sizeof(int));
  p->topo = -1;
  p->capacidade = tamanho;
  return p;
}

void empilhar(Pilha *p, int valor) {
  if (p->topo < p->capacidade - 1) {
    p->topo++;
    p->dados[p->topo] = valor;
    printf("Valor %d empilhado\n", valor);
  } else {
    printf("Pilha cheia\n");
  }
}

int desempilhar(Pilha *p) {
  if (p->topo >= 0) {
    int valor = p->dados[p->topo];
    p->topo--;
    printf("Valor %d desempilhado\n", valor);
    return valor;
  }
  printf("Pilha vazia\n");
  return -1;
}

void destruirPilha(Pilha *p) {
  free(p->dados);
  free(p);
}

int main() {
  int tamanho, valor, opcao;

  printf("Digite o tamanho da pilha: ");
  scanf("%d", &tamanho);

  Pilha *p = criarPilha(tamanho);

  do {
    printf("\n1 - Empilhar\n2 - Desempilhar\n0 - Sair\nOpcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o valor: ");
      scanf("%d", &valor);
      empilhar(p, valor);
      break;
    case 2:
      desempilhar(p);
      break;
    }
  } while (opcao != 0);

  destruirPilha(p);
  return 0;
}
