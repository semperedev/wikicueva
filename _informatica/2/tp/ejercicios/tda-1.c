#include <stdio.h>
#include <stdlib.h>

#include "tda-1.h"

struct PuntoRep {
  double x, y;
};

Punto crea_punto(double x, double y) {
  Punto p = malloc(sizeof(struct PuntoRep));

  p->x = x;
  p->y = y;

  return p;
}

void libera_punto(Punto p) {
  free(p);
}

void muestra_punto(Punto p) {
  printf("%f %f\n", p->x, p->y);
}

double recupera_x_punto(Punto p) {
  return p->x;
}

double recupera_y_punto(Punto p) {
  return p->y;
}

void modifica_punto(Punto p, double x, double y) {
  p->x = x;
  p->y = y;
}
