#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#include "tda-1.h"
#include "tda-7.h"

typedef struct Nodo * NodoPtr;

struct Nodo {
  Punto p;
  NodoPtr sig;
};

struct PolilineaRep {
  NodoPtr cabecera, ultimo;
};

Polilinea crea_polilinea() {
  Polilinea p = malloc(sizeof(struct PolilineaRep));
  
  p->cabecera = malloc(sizeof(struct Nodo));
  p->cabecera->sig = NULL;
  p->cabecera->p = NULL;

  p->ultimo = p->cabecera;

  return p;
}

void libera_polilinea(Polilinea p) {
  NodoPtr aux = p->cabecera;

  while (p->cabecera->sig != NULL) {
    aux = p->cabecera->sig;
    p->cabecera->sig = aux->sig;
    free(aux);
  }

  free(p);
}

void muestra_polilinea(Polilinea p) {
  NodoPtr aux = p->cabecera;

  while (aux->sig != NULL) {
    muestra_punto(aux->sig->p);
    aux = aux->sig;
  }
}

void agrega_punto_polilinea(Polilinea p, Punto q) {
  NodoPtr nodo = malloc(sizeof(struct Nodo));
  nodo->p = q;
  nodo->sig = NULL;

  p->ultimo->sig = nodo;
  p->ultimo = nodo;
}

Punto selecciona_polilinea(Polilinea p, double x, double y) {
  NodoPtr aux = p->cabecera;

  Punto punto = NULL;
  float dist;
  float minDist = INT_MAX;

  int px, py;

  while (aux->sig != NULL) {
    px = recupera_x_punto(aux->sig->p);
    py = recupera_y_punto(aux->sig->p);

    dist = sqrt(pow(px + x, 2) + pow(py + y, 2));

    if (dist < minDist) {
      punto = aux->sig->p;
    }

    aux = aux->sig;
  }

  return punto;
}

void elimina_punto_polilinea(Polilinea p, Punto q) {
  NodoPtr aux = p->cabecera;

  while ((aux->sig != NULL) && (aux->sig->p != q)) {
    aux = aux->sig;
  }

  if (aux->sig != NULL) {
    NodoPtr borrar = aux->sig;
    aux->sig = aux->sig->sig;
    free(borrar);
  }
}
