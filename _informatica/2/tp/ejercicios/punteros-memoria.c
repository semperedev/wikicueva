#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
