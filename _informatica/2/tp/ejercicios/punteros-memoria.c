#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PuntoRep {
  int x, y;
};

/**
 * 5) Devuelve la dirección en memoria dinámica de un nuevo array
 * cuyos elementos sean el resultado de sumar los n valores contenidos
 * en los arrays a y b
 */
int * suma(int a[], int b[], int n) {
  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    array[i] = a[i] + b[i];
  }

  return array;
}

/**
 * 6) Devuelve la dirección en memoria dinámica de una nueva cadena
 * de caracteres idéntica a la recibida como parámetro
 */
int longitud(char * cadena) {
  int n = 0;

  while (cadena[n] != '\0') {
    n++;
  }

  return n;
}

char * duplica(char * cadena) {
  int n = longitud(cadena) + 1; // Sumamos uno para la marca de fin '\0'

  char * copy = malloc(sizeof(char) * n);

  for (int i = 0; i < n; i++) {
    copy[i] = cadena[i];
  }

  return copy;
}

/**
 * 7) Devuelve la dirección en memoria dinámica de una nueva cadena de
 * caracteres con la inversión de la recibida como parámetro
 */
char * invierteCadena(char * cadena) {
  int n = longitud(cadena);

  char * copy = malloc(sizeof(char) * (n + 1));

  for (int i = 0; i < n; i++) {
    copy[i] = cadena[n - i - 1];
  }

  copy[n] = '\0'; // n aquí es igual a i + 1

  return copy;
}

/**
 * 8) Devuelve la direcciónen memoria dinámica de una nueva cadena de
 * caracteres que contenga n letras elegidas aleatoriamente de entre
 * las incluidas en la cadena letras
 */
char * generaCadena(char * letras, int n) {
  int l = longitud(letras);

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
  int n = longitud(a) + longitud(b);

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
