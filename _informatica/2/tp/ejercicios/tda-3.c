/**
 * 3) Implementa el TDA descrito a continuación:
 *
 * typedef struct ComplejoRep * Complejo;
 * Complejo Complejo_crea(double r, double i);
 * Complejo Complejo_crea_polares(double r, double o);
 * void Complejo_libera(Complejo c);
 * void Complejo_muestra(Complejo c);
 * double Complejo_recupera_parte_real(Complejo c);
 * double Complejo_recupera_parte_imaginaria(Complejo c);
 * double Complejo_modulo(Complejo c);
 * Complejo Complejo_suma(Complejo c, Complejo d);
 * Complejo Complejo_resta(Complejo c, Complejo d);
 * Complejo Complejo_multiplica(Complejo c, Complejo d);
 * Complejo Complejo_divide(Complejo c, Complejo d);
 * int Complejo_compara(Complejo c, Complejo d);
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ComplejoRep {
  double r, i;
};

typedef struct ComplejoRep * Complejo;

Complejo Complejo_crea(double r, double i) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  c->r = r;
  c->i = i;

  return c;
}

Complejo Complejo_crea_polares(double r, double o) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  // a = r * cos(o)
  // b = r * sin(o)
  // z = a + b

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

int main(int argc, char const *argv[]) {
  Complejo c = Complejo_crea(1, 23);
  Complejo d = Complejo_crea(2, 30);

  Complejo_muestra(c);
  Complejo_muestra(d);

  printf(
    "%f + %fi\n",
    Complejo_recupera_parte_real(c),
    Complejo_recupera_parte_imaginaria(c)
  );

  Complejo e = Complejo_suma(c, d);
  Complejo f = Complejo_resta(e, c);

  Complejo_muestra(f);

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
