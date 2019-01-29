#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tda-3.h"

struct ComplejoRep {
  double r, i;
};

Complejo crea_complejo(double r, double i) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  c->r = r;
  c->i = i;

  return c;
}

Complejo crea_polares_complejo(double r, double o) {
  return crea_complejo(r * cos(o), r * sin(o));
}

void libera_complejo(Complejo c) {
  free(c);
}

void muestra_complejo(Complejo c) {
  printf("r: %f, i: %f\n", c->r, c->i);
}

double recupera_parte_real_complejo(Complejo c) {
  return c->r;
}

double recupera_parte_imaginaria_complejo(Complejo c) {
  return c->i;
}

double modulo_complejo(Complejo c) {
  return sqrt(pow(c->r, 2) + pow(c->i, 2));
}

Complejo suma_complejo(Complejo c, Complejo d) {
  return crea_complejo(c->r + d->r, c->i + d->i);
}

Complejo resta_complejo(Complejo c, Complejo d) {
  return crea_complejo(c->r - d->r, c->i - d->i);
}

Complejo multiplica_complejo(Complejo c, Complejo d) {
  return crea_complejo(
    c->r * d->r - c->i * d->i,
    c->r * d->i + c->i * d->r
  );
}

Complejo divide_complejo(Complejo c, Complejo d) {
  return crea_complejo(
    (c->r * d->r + c->i * d->i) / (pow(c->i, 2) + pow(d->i, 2)),
    (c->i * d->r - c->r * d->i) / (pow(c->i, 2) + pow(d->i, 2))
  );
}

int compara_complejo(Complejo c, Complejo d) {
  return (c->r == d->r) && (d->i == c->i);
}
