---
title: Ejercicios Prácticos
---

> Devuelve un array en orden inverso

```c
int * invierte(int datos[], int n) {
  int * nuevo = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    nuevo[n - 1 - i] = datos[i];
  }

  return nuevo;
}
```

> Devuelve una cadena de longitud n formada por letras aleatorias de la cadena dada

Primero debemos obtener la longitud de la cadena `fuente`. Y a la hora de reservar memoria debemos tener en cuenta que aparte de los caracteres también debemos guardar espacio para la marca de fin.

```c
char * genera(char * fuente, int n) {
  int longitud = 0;

  while (fuente[longitud] != '\0') {
    longitud++;
  }

  char * nueva = malloc((n + 1) * sizeof(char));

  for (int i = 0; i < n; i++) {
    int r = rand() % longitud;

    nueva[i] = fuentes[r];
  }

  nueva[n] = '\0';

  return nueva;
}
```

> Devolver un array con n puntos con coordenadas generadas aleatoriamente

```c
struct PuntoRep {
  int x, y;
}

struct PuntoRep * genera(int n) {
  struct PuntoRep * array = malloc(sizeof(struct PuntoRep) * n);

  for (int i = 0; i < n; i++) {
    nuevo[i].x = rand();
    nuevo[i].y = rand();
  }

  return array;
}
```
