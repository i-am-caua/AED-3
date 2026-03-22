#include "data.h"
#include <stdio.h>


Data criarData(int d, int m, int a) {
  Data dt;
  dt.dia = d;
  dt.mes = m;
  dt.ano = a;
  return dt;
}

void imprimirData(Data *dt) {
  printf("%02d/%02d/%04d\n", dt->dia, dt->mes, dt->ano);
}

int compararDatas(Data *d1, Data *d2) {
  if (d1->ano != d2->ano)
    return d1->ano - d2->ano;
  if (d1->mes != d2->mes)
    return d1->mes - d2->mes;
  return d1->dia - d2->dia;
}

int validarData(Data *dt) {
  int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (dt->mes < 1 || dt->mes > 12)
    return 0;
  if (dt->ano < 1)
    return 0;

  if (dt->mes == 2) {
    if ((dt->ano % 4 == 0 && dt->ano % 100 != 0) || dt->ano % 400 == 0)
      diasPorMes[2] = 29;
  }

  if (dt->dia < 1 || dt->dia > diasPorMes[dt->mes])
    return 0;

  return 1;
}
