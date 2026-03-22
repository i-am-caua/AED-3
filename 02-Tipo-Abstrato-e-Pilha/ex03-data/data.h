#ifndef EX3DATA_H
#define EX3DATA_H

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

Data criarData(int d, int m, int a);
void imprimirData(Data *dt);
int compararDatas(Data *d1, Data *d2);
int validarData(Data *dt);

#endif
