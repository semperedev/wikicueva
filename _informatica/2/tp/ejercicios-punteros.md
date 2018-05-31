---
title: Punteros y Memoria Dinámica
---

## Ejercicios

> Intercambia los valores de las variables **apuntadas** por a y b
>
> `void intercambia(int * a, int * b)`

```c
void intercambia(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
```

> Devuelve la dirección en memoria dinámica de un nuevo array con n enteros generados aleatoriamente en el intervalo [a, b]
>
> `int * genera(int n, int a, int b)`

```c
int * genera(int n, int a, int b) {
  int * array = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    array[i] = (rand() % (b - a + 1)) + a;
  }

  return array;
}
```

> Devuelve la dirección en memoria dinámica de un nuevo array con los n valores contenidos en el array `datos`
>
> `int * copia(int datos[], int n)`

```c
int * copia(int datos[], int n) {
  if (n == 0) {
    return NULL;
  }

  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    array[i] = datos[i];
  }

  return array;
}
```
