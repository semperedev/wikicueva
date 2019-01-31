#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tda-5.h"

struct MonomioRep {
  double c;
  int e;
};

Monomio crea_monomio(double coef, int exp) {
  Monomio m = malloc(sizeof(struct MonomioRep));

  m->c = coef;
  m->e = exp;

  return m;
}

void libera_monomio(Monomio m) {
  free(m);
}

void muestra_monomio(Monomio m) {
  printf("%f * x^%d\n", m->c, m->e);
}

double recupera_coeficiente_monomio(Monomio m) {
  return m->c;
}

int recupera_exponente_monomio(Monomio m) {
  return m->e;
}

void modifica_coeficiente_monomio(Monomio m, double coef) {
  m->c = coef;
}

double evalua_monomio(Monomio m, double x) {
  return m->c * pow(x, m->e);
}
