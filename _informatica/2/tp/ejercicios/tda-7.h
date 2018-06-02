/**
 * 7) Usando el TDA Punto (ejercicio 1), implementa el TDA descrito
 * a continuación:
 */

#include "tda-1.h"

// Una polilínea representa una secuencia ordenada de puntos en
// el plano bidimensional. Los puntos de la polilínea de mantendrán
// en el orden en que sean añadidos.
typedef struct PolilineaRep * Polilinea;

// Devuelve una nueva polilínea vacía
Polilinea Polilinea_crea();

// Libera la memoria asociada a la polilínea p
void Polilinea_libera(Polilinea p);

// Muestra la polilínea p por la pantalla
void Polilinea_muestra(Polilinea p);

// Añade el punto q al final de la secuencia de puntos de p
void Polilinea_agrega(Polilinea p, Punto q);

// Devuelve el punto incluído en p que esté más cerca de las
// coordenadas (x, y) usando distancia euclídea
Punto Polilinea_selecciona(Polilinea p, double x, double y);

// Elimina el punto q de la secuencia de puntos de p
void Polilinea_elimina(Polilinea p, Punto q);
