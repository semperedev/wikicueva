#include <stdio.h>
#include <stdlib.h>

#include "tda-1.h"

struct PuntoRep {
  double x, y;
};

Punto Punto_crea(double x, double y) {
  Punto p = malloc(sizeof(struct PuntoRep));

  p->x = x;
  p->y = y;

  return p;
}

void Punto_libera(Punto p) {
  free(p);
}

void Punto_muestra(Punto p) {
  printf("%f %f\n", p->x, p->y);
}

double Punto_recupera_x(Punto p) {
  return p->x;
}

double Punto_recupera_y(Punto p) {
  return p->y;
}

void Punto_modifica(Punto p, double x, double y) {
  p->x = x;
  p->y = y;
}
