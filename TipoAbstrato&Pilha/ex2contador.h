#ifndef EX2CONTADOR_H
#define EX2CONTADOR_H

typedef struct {
  int valor;
} Contador;

void inicializar(Contador *c);
void incrementar(Contador *c);
void decrementar(Contador *c);
int obterValor(Contador *c);

#endif
