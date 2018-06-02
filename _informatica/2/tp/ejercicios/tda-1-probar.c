#include <stdio.h>

#include "tda-1.h"

int main(int argc, char const *argv[]) {
  printf("Probando el TDA Punto\n\n");

  Punto p = Punto_crea(2.5, 4.6);

  Punto_muestra(p);

  printf("%f %f\n", Punto_recupera_x(p), Punto_recupera_y(p));

  Punto_modifica(p, 1.0, 2.0);

  Punto_muestra(p);

  Punto_libera(p);

  return 0;
}
