#include <stdio.h>

#include "tda-7.h"

int main(int argc, char const *argv[]) {
  printf("Probando TDA Polilinea\n\n");

  Polilinea p = Polilinea_crea();

  Polilinea_agrega(p, Punto_crea(0, 0));
  Polilinea_agrega(p, Punto_crea(0, 1));
  Polilinea_agrega(p, Punto_crea(1, 0));
  Polilinea_agrega(p, Punto_crea(1, 1));

  Polilinea_muestra(p);

  printf("\nCercano a (0.15, 0)\n");
  Punto punto = Polilinea_selecciona(p, 0.15, 0);
  Punto_muestra(punto);

  printf("\nAgrega puntoNuevo\n");
  Punto puntoNuevo = Punto_crea(1, 3);
  Polilinea_agrega(p, puntoNuevo);
  Polilinea_muestra(p);

  printf("\nElimina puntoNuevo\n");
  Polilinea_elimina(p, puntoNuevo);
  Polilinea_muestra(p);

  Punto_libera(puntoNuevo);
  Polilinea_libera(p);

  return 0;
}
