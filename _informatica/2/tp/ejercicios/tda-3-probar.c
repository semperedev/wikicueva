#include <stdio.h>

#include "tda-3.h"

int main(int argc, char const *argv[]) {
  printf("Probando el TDA Complejo\n\n");

  Complejo c = Complejo_crea(1, 23);
  Complejo d = Complejo_crea(2, 30);

  Complejo_muestra(c);
  Complejo_muestra(d);

  printf(
    "\nRecupera:\n%f + %fi\n",
    Complejo_recupera_parte_real(c),
    Complejo_recupera_parte_imaginaria(c)
  );

  printf("\nOperaciones aritméticas:\n");
  Complejo e = Complejo_suma(c, d);
  Complejo f = Complejo_resta(e, c);

  Complejo_muestra(f);

  printf("\nComparación:\n");
  if (Complejo_compara(d, f)) {
    printf("Son iguales\n");
  }
  else {
    printf("No son iguales\n");
  }

  Complejo_libera(c);
  Complejo_libera(d);

  Complejo_libera(e);
  Complejo_libera(f);

  return 0;
}
