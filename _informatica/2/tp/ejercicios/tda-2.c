#include <stdio.h>
#include <stdlib.h>

#include "tda-2.h"

struct RectanguloRep {
  int x, y, ancho, alto;
};

Rectangulo crea_rectangulo(int x, int y, int ancho, int alto) {
  Rectangulo r = malloc(sizeof(struct RectanguloRep));

  r->x = x;
  r->y = y;
  r->ancho = ancho;
  r->alto = alto;

  return r;
}

void libera_rectangulo(Rectangulo r) {
  free(r);
}

void muestra_rectangulo(Rectangulo r) {
  printf("(x: %d, y: %d, ancho: %d, alto: %d)\n", r->x, r->y, r->ancho, r->alto);
}

int recupera_x_rectangulo(Rectangulo r) {
  return r->x;
}

int recupera_y_rectangulo(Rectangulo r) {
  return r->y;
}

void modifica_rectangulo(Rectangulo r, double x, double y) {
  r->x = x;
  r->y = y;
}

int dentro_rectangulo(Rectangulo r, int x, int y) {
  return (
    ((r->x <= x) && (r->x + r->ancho >= x)) &&
    ((r->y <= y) && (r->y + r->alto >= y))
  );
}
