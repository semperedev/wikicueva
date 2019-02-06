#include "tda-1.h"

// Una Polilínea representa una secuencia ordenada de puntos en
// el plano bidimensional. Los puntos de la Polilínea se
// mantendrán en el orden en que sean añadidos
typedef struct PolilineaRep * Polilinea;

// Devuelve una nueva polilínea vacía
Polilinea crea_polilinea();

// Libera la memoria asociada a la polilínea p
void libera_polilinea(Polilinea p);

// Muestra la polilínea p por la pantalla
void muestra_polilinea(Polilinea p);

// Agrega el punto q al final de la secuencia de puntos de p
void agrega_punto_polilinea(Polilinea p, Punto q);

// Devuelve el punto incluido en p que esté más cerca
// de las coordenadas (x,y) usando distancia euclídea
Punto selecciona_polilinea(Polilinea p, double x, double y);

// Elimina el punto q de la secuencia de puntos de p
void elimina_punto_polilinea(Polilinea p, Punto q);
