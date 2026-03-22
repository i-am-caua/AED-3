#include "ex3data.h"
#include <stdio.h>


int main() {
  Data d1 = criarData(25, 2, 2026);
  Data d2 = criarData(31, 12, 2025);
  Data d3 = criarData(30, 2, 2026);

  printf("Data 1: ");
  imprimirData(&d1);
  printf("Valida: %s\n", validarData(&d1) ? "Sim" : "Nao");

  printf("Data 2: ");
  imprimirData(&d2);
  printf("Valida: %s\n", validarData(&d2) ? "Sim" : "Nao");

  printf("Data 3: ");
  imprimirData(&d3);
  printf("Valida: %s\n", validarData(&d3) ? "Sim" : "Nao");

  int cmp = compararDatas(&d1, &d2);
  if (cmp > 0)
    printf("Data 1 e posterior a Data 2\n");
  else if (cmp < 0)
    printf("Data 1 e anterior a Data 2\n");
  else
    printf("As datas sao iguais\n");

  return 0;
}
