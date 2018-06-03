#ifndef __Lista_H__
#define __Lista_H__

typedef int Elemento;
typedef struct ListaRep * Lista;
typedef struct PosicionRep * Posicion;

// Devuelve una nueva lista vacía
Lista Lista_crea();

// Libera la memoria asociada a la lista l
void Lista_libera(Lista l);

// Inserta un nuevo nodo en la posición p con el dato e
void Lista_inserta(Lista l, Posicion p, Elemento e);

// Suprime el elemento que ocupa la posición p
// La posición p debe ser distinta del final de la lista
void Lista_suprime(Lista l, Posicion p);

// Devuelve el elemento que ocupa la posición p
Elemento Lista_recupera(Lista l, Posicion p);

// Sustituye el elemento que ocupa la posición p por e
void Lista_asigna(Lista l, Posicion p, Elemento e);

// Devuelve la longitud de la lista
int Lista_longitud(Lista l);

// Devuelve la posición que ocupa el primer elemento
Posicion Lista_inicio(Lista l);

// Devuelve la siguiente posición a la ocupada por el último de
// la lista
Posicion Lista_fin(Lista l);

// Devuelve la siguiente posición a p siempre que pe no sea Fin
Posicion Lista_siguiente(Lista l, Posicion p);

// Devuelve la posición anterior a p siempre que p no sea Inicio
Posicion Lista_anterior(Lista l, Posicion p);

#endif
