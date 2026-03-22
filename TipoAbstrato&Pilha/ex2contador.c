#include "ex2contador.h"

void inicializar(Contador *c) { c->valor = 0; }

void incrementar(Contador *c) { c->valor++; }

void decrementar(Contador *c) {
  if (c->valor > 0)
    c->valor--;
}

int obterValor(Contador *c) { return c->valor; }
