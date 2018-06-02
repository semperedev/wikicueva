#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tda-7.h"

struct PolilineaRep {
  Punto punto;
  struct PolilineaRep * sig;
};

Polilinea Polilinea_crea() {
  Polilinea p = malloc(sizeof(struct PolilineaRep));

  p->sig = NULL;

  return p;
}

void Polilinea_libera(Polilinea p) {
  Polilinea aux = p;

  // Avanzamos en la lista borrando todos los nodos que encontramos
  while (aux != NULL) {
    Polilinea borrar = aux;
    aux = borrar->sig;
    free(borrar);
  }
}

void Polilinea_muestra(Polilinea p) {
  Polilinea aux = p;

  while (aux->sig != NULL) {
    Punto_muestra(aux->sig->punto);

    aux = aux->sig;
  }
}

void Polilinea_agrega(Polilinea p, Punto q) {
  Polilinea aux = p;

  // Primero recorremos la lista para llegar hasta el último nodo
  while (aux->sig != NULL) {
    aux = aux->sig;
  }

  Polilinea nueva = malloc(sizeof(struct PolilineaRep));

  nueva->punto = q;
  nueva->sig = aux->sig; // aux->sig == NULL

  aux->sig = nueva;
}

// Función auxiliar para calcular la distancia euclídea
double distanciaPunto(Punto p1, Punto p2) {
  double x1 = Punto_recupera_x(p1);
  double y1 = Punto_recupera_y(p1);

  double x2 = Punto_recupera_x(p2);
  double y2 = Punto_recupera_y(p2);

  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Punto Polilinea_selecciona(Polilinea p, double x, double y) {
  // Si la lista está vacía, no existe ningún punto cercano a (x, y)
  if (p->sig == NULL) {
    return NULL;
  }

  // Lo que necesitamos es recorrer la lista buscando el punto más cercano
  // Para ello, almacenamos la distancia mínima y el punto más cercano,
  // y cuando encontremos uno más cercano, actualizamos la variable
  Punto centro = Punto_crea(x, y);

  Punto min = p->sig->punto;
  double minDist = distanciaPunto(centro, min);

  Polilinea aux = p->sig;

  while (aux->sig != NULL) {
    double dist = distanciaPunto(centro, aux->sig->punto);

    // Si la distancia es menor a la guardada, actualizamos el punto mínimo
    // y la distancia mínima
    if (dist < minDist) {
      min = aux->sig->punto;
      minDist = dist;
    }

    aux = aux->sig;
  }

  Punto_libera(centro);

  return min;
}

int puntosIguales(Punto p, Punto q) {
  return (
    (Punto_recupera_x(p) == Punto_recupera_x(q)) &&
    (Punto_recupera_y(p) == Punto_recupera_y(q))
  );
}

void Polilinea_elimina(Polilinea p, Punto q) {
  Polilinea aux = p;

  // Recorremos la lista hasta encontrar el nodo que queremos borrar
  while ((aux->sig != NULL) && !puntosIguales(aux->sig->punto, q)) {
    aux = aux->sig;
  }

  // Si el siguiente nodo no es nulo, es porque es el nodo que queremos borrar
  if (aux->sig != NULL) {
    Polilinea borrar = aux->sig;
    aux->sig = aux->sig->sig;

    Punto_libera(borrar->punto);
    free(borrar);
  }
}
