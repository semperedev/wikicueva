#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PuntoRep {
  int x, y;
};

/**
 * 8) Devuelve la direcciónen memoria dinámica de una nueva cadena de
 * caracteres que contenga n letras elegidas aleatoriamente de entre
 * las incluidas en la cadena letras
 */
char * generaCadena(char * letras, int n) {
  int l = 1;

  while (letras[l] != '\0') {
    l++;
  }

  char * cadena = malloc(sizeof(char) * (n + 1)); // +1 por marca de fin

  for (int i = 0; i < n; i++) {
    cadena[i] = letras[rand() % l];
  }

  cadena[n] = '\0';

  return cadena;
}

/**
 * 9) Devuelve la dirección en memoria dinámica de una nueva cadena de
 * caracteres que contenga la cadena formada por la concatenación de
 * las cadenas a y b
 */
char * concatena(char * a, char * b) {
  int n = 1;

  while (a[n] != '\0') {
    n++;
  }

  while (b[n] != '\0') {
    n++;
  }

  char * cadena = malloc(sizeof(char) * (n + 1));

  int i = 0;

  while (a[i] != '\0') {
    cadena[i] = a[i];

    i++;
  }

  int j = 0;

  while (b[j] != '\0') {
    cadena[i] = b[j];

    i++;
    j++;
  }

  cadena[n] = '\0';

  return cadena;
}

/**
 * 10) Devuelve la dirección en memoria dinámica de un nuevo array con
 * n puntos cuyas coordenadas estén generadas aleatoriamente
 */
struct PuntoRep * generaPuntos(int n) {
  struct PuntoRep * array = malloc(sizeof(struct PuntoRep) * n);

  for (int i = 0; i < n; i++) {
    array[i].x = rand() % 101;
    array[i].y = rand() % 101;
  }

  return array;
}

/**
 * 11) Devuelve la dirección en memoria dinámica de un nuevo array con
 * todos los valores positivos que haya en el array datos, sabiendo que
 * éste contiene n números enteros
 */
int * positivos(int datos[], int n) {
  int * array = malloc(sizeof(int) * n);

  int j = 0;

  for (int i = 0; i < n; i++) {
    if (datos[i] >= 0) {
      array[j] = datos[i];

      j++;
    }
  }

  return array;
}

/**
 * 12) Devuelve la dirección en memoria dinámica de un nuevo array con
 * n+1 punteros a carácter. Cada uno apuntará a una nueva cadena de
 * caracteres almacenada en memoria dinámica. El contenido de las primeras
 * n cadenas será cada una de las n direcciones de correo electrónico
 * encontradas en la cadena recibida como parámetro. La última cadena
 * será la cadena de caracteres vacía. Las direcciones de correo electrónico
 * aparecerán separadas por el carácter ';' dentro de la cadena direcciones
 */
char ** divide(char * direcciones) {
  int n = 0;
  int l = 0;
  int max = 0;

  for (int i = 0; direcciones[i] != '\0'; i++) {
    if (direcciones[i] == ';') {
      n++;

      if (l > max) {
        max = l;
      }

      l = 0;
    }

    l++;
  }

  n++;

  char ** array = malloc(sizeof(char *) * (n + 1));

  int j = 0;
  int x = 0;

  for (int i = 0; i < n; i++) {
    array[i] = malloc(sizeof(char) * max);

    while ((direcciones[j] != '\0') && (direcciones[j] != ';')) {
      array[i][x] = direcciones[j];

      j++;
      x++;
    }

    array[i][x] = '\0';

    x = 0;
    j++;
  }

  array[n] = malloc(sizeof(char) * max);

  for (int i = 0; i < max; i++) {
    array[n][i] = '\0';
  }

  return array;
}
