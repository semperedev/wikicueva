#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tda-3.h"

struct ComplejoRep {
  double r, i;
};

Complejo Complejo_crea(double r, double i) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  c->r = r;
  c->i = i;

  return c;
}

Complejo Complejo_crea_polares(double r, double o) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  // Parte real => r * cos(o)
  // Parte imaginaria => r * sin(o)

  c->r = r * cos(o);
  c->i = r * sin(o);

  return c;
}

void Complejo_libera(Complejo c) {
  free(c);
}

void Complejo_muestra(Complejo c) {
  printf("%f + %fi\n", c->r, c->i);
}

double Complejo_recupera_parte_real(Complejo c) {
  return c->r;
}

double Complejo_recupera_parte_imaginaria(Complejo c) {
  return c->i;
}

double Complejo_modulo(Complejo c) {
  // sqrt = raíz cuadrada
  // pow = potencia

  return sqrt(pow(c->r, 2) + pow(c->i, 2));
}

Complejo Complejo_suma(Complejo c, Complejo d) {
  return Complejo_crea(c->r + d->r, c->i + d->i);
}

Complejo Complejo_resta(Complejo c, Complejo d) {
  return Complejo_crea(c->r - d->r, c->i - d->i);
}

Complejo Complejo_multiplica(Complejo c, Complejo d) {
  return Complejo_crea(c->r * d->r - c->i + d->i, c->r * d->i + c->i * d->r);
}

Complejo Complejo_divide(Complejo c, Complejo d) {
  return Complejo_crea(
    (c->r * d->r + c->i * d->i) / (pow(c->i, 2) + pow(d->i, 2)),
    (c->r * d->r - c->i * d->i) / (pow(c->i, 2) + pow(d->i, 2))
  );
}

int Complejo_compara(Complejo c, Complejo d) {
  return (c->r == d->r) && (d->i == c->i);
}
