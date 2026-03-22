#include "contador.h"
#include <stdio.h>


int main() {
  Contador c;

  inicializar(&c);
  printf("Valor inicial: %d\n", obterValor(&c));

  incrementar(&c);
  incrementar(&c);
  incrementar(&c);
  printf("Apos 3 incrementos: %d\n", obterValor(&c));

  decrementar(&c);
  printf("Apos 1 decremento: %d\n", obterValor(&c));

  return 0;
}
