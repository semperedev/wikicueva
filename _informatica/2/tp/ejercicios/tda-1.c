/**
 * 1) Implementar el TDA descrito a continuación:
 *
 * typedef struct PuntoRep * Punto;
 * Punto Punto_crea(double x, double y);
 * void Punto_libera(Punto p);
 * void Punto_muestra(Punto p);
 * double Punto_recupera_x(Punto p);
 * double Punto_recupera_y(Punto p);
 * void Punto_modifica(Punto p, double x, double y);
 */

#include <stdio.h>
#include <stdlib.h>

struct PuntoRep {
  double x, y;
};

typedef struct PuntoRep * Punto;

Punto Punto_crea(double x, double y) {
  Punto p = malloc(sizeof(struct PuntoRep));

  p->x  = x;
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

int main(int argc, char const *argv[]) {
  Punto p = Punto_crea(2.5, 4.6);

  Punto_muestra(p);

  printf("%f %f\n", Punto_recupera_x(p), Punto_recupera_y(p));

  Punto_modifica(p, 1.0, 2.0);

  Punto_muestra(p);

  Punto_libera(p);

  return 0;
}
