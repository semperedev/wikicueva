#include <stdio.h>
#include <stdlib.h>

typedef int Elemento;

struct Nodo {
  Elemento elem;
  struct Nodo * sig;
};

typedef struct Nodo * NodoPtr;

/**
 * 1) Construye y devuelve una lista vacía.
 */
NodoPtr crea() {
  NodoPtr cabecera = malloc(sizeof(struct Nodo));

  cabecera->sig = NULL;

  return cabecera;
}

/**
 * 2) Construye y devuelve una lista con un único elemento dado
 */
NodoPtr crea_e(Elemento d) {
  NodoPtr cabecera = malloc(sizeof(struct Nodo));
  NodoPtr nodo = malloc(sizeof(struct Nodo));

  nodo->elem = d;
  nodo->sig = NULL;

  cabecera->sig = nodo;

  return cabecera;
}

/**
 * 3) Construye y devuelve una lista con todos los números en
 * el intervalo [a, b]
 */
NodoPtr crea_rango(Elemento a, Elemento b) {
  NodoPtr cabecera = malloc(sizeof(struct Nodo));
  cabecera->sig = NULL;

  for (Elemento elem = a; elem <= b; elem++) {
    NodoPtr nodo = malloc(sizeof(struct Nodo));

    nodo->elem = elem;

    nodo->sig = cabecera->sig;
    cabecera->sig = nodo;
  }

  return cabecera;
}

/**
 * 6) Libera la memoria de una lista
 * Suponemos que l apunta a la cabecera de una lista
 */
void libera(NodoPtr l) {
  NodoPtr aux = l;

  while (l->sig != NULL) {
    aux = l->sig;

    free(l);

    l = aux;
  }

  free(l);
}

/**
 * 7) Muestra todos los elementos separados por comas.
 * Suponemos que l apunta a la cabecera de una lista
 */
void muestra(NodoPtr l) {
  NodoPtr aux = l->sig;

  while (aux != NULL) {
    printf("%d, ", aux->elem);

    aux = aux->sig;
  }
}

/**
 * 8) Inserta como primer elemento de l un nuevo nodo con el dato d
 * Suponemos que l apunta a la cabecera de una lista
 */
void inserta(NodoPtr l, Elemento d) {
  NodoPtr aux = malloc(sizeof(struct Nodo));

  aux->elem = d;

  aux->sig = l->sig;
  l->sig = aux;
}

/**
 * 10) Agrega un nuevo nodo con el dato d si este no se encuentra ya en l
 * Suponemos que l apunta a la cabecera de una lista
 */
void inserta_no_repetido(NodoPtr l, Elemento d) {
  NodoPtr aux = l;

  while ((aux->sig != NULL) && (aux->elem != d)) {
    aux = aux->sig;
  }

  if ((aux->sig == NULL) && (aux->elem != d)) {
    NodoPtr nodo = malloc(sizeof(struct Nodo));

    nodo->elem = d;

    nodo->sig = l->sig;
    l->sig = nodo;
  }
}

// Main
int main(int argc, char const *argv[]) {
  NodoPtr lista = crea();

  inserta(lista, 2);
  inserta(lista, 4);
  inserta_no_repetido(lista, 2);
  inserta_no_repetido(lista, 3);

  muestra(lista);

  libera(lista);

  return 0;
}
