#include <stdlib.h>
#include <assert.h>

#include "lista.h"

struct ListaRep {
  Posicion cabecera;
  Posicion ultimo;
};

struct PosicionRep {
  Elemento dato;
  struct PosicionRep * sig;
};

Lista Lista_crea() {
  Lista l = malloc(sizeof(struct ListaRep));

  l->cabecera = malloc(sizeof(struct PosicionRep));
  l->cabecera->sig = NULL;

  l->ultimo = l->cabecera;

  return l;
}

void Lista_libera(Lista l) {
  Posicion aux = l->cabecera;

  while (aux != NULL) {
    Posicion sig = aux->sig;
    free(aux);
    aux = sig;
  }

  free(l);
}

void Lista_inserta(Lista l, Posicion p, Elemento e) {
  Posicion nuevo = malloc(sizeof(struct PosicionRep));

  nuevo->dato = e;

  nuevo->sig = p->sig;
  p->sig = nuevo;

  if (l->ultimo == p) {
    l->ultimo = nuevo;
  }
}

void Lista_suprime(Lista l, Posicion p) {
  assert(p != l->ultimo);

  Posicion borrar = p->sig;

  p->sig = borrar->sig;

  if (l->ultimo == borrar) {
    l->ultimo = p;
  }

  free(borrar);
}

Elemento Lista_recupera(Lista l, Posicion p) {
  assert(p != l->ultimo);

  return p->sig->dato;
}

void Lista_asigna(Lista l, Posicion p, Elemento e) {
  assert(p != l->ultimo);

  p->sig->dato = e;
}

int Lista_longitud(Lista l) {
  Posicion aux = l->cabecera;

  int n = 0;

  while (aux->sig != NULL) {
    n++;
    aux = aux->sig;
  }

  return n;
}

Posicion Lista_inicio(Lista l) {
  return l->cabecera;
}

Posicion Lista_fin(Lista l) {
  return l->ultimo;
}

Posicion Lista_siguiente(Lista l, Posicion p) {
  assert(p != l->ultimo);

  return p->sig;
}

Posicion Lista_anterior(Lista l, Posicion p) {
  assert(p != l->cabecera);

  Posicion aux = l->cabecera;

  while (aux->sig != p) {
    aux = aux->sig;
  }

  return aux;
}
