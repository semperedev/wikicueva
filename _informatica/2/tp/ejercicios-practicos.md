---
title: Ejercicios Prácticos
---

[&lt;&lt; Volver a **TP**](../tp.md)

## Arrays

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

## Cadenas de texto

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

## Memoria dinámica

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

## Listas

```c
typedef int Elemento;

struct Nodo {
  Elemento elem;
  struct Nodo * sig;
};

typedef struct Nodo * NodoPtr;
```

> Crea y devuelve una lista de n elementos aleatorios entre a y b

```c
NodoPtr crea(int n, Elemento a, Elemento b) {
  NodoPtr cabecera = malloc(sizeof(struct Nodo));
  cabecera->sig = NULL;

  for (int i = 0; i < n; i++) {
    NodoPtr nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = (rand() % a-b + 1) + a;
    nuevo->sig = cabecera->sig;
    cabecera->sig = nuevo;
  }

  return cabecera;
}
```

> Inserta un elemento a continuación de otro

```c
void inserta(NodoPtr l, Elemento d) {
  NodoPtr nuevo = malloc(sizeof(struct Nodo));
  nuevo->elem = d;
  nuevo->sig = l->sig;

  l->sig = nuevo;
}
```

> Inserta un elemento si no se encuentra ya en la lista

Cuando recorremos la lista, comprobamos siempre el elemento siguiente; de esta forma, cuando vayamos a insertar tendremos un elemento al que unir nuestro nuevo nodo.

```c
void inserta(NodoPtr l, Elemento d) {
  NodoPtr aux = l;

  while ((aux->sig != NULL) && (aux->sig->elem != d)) {
    aux = aux->sig;
  }

  if (aux->sig != NULL) {
    NodoPtr nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = d;
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
  }
}
```

> Inserta un elemento en una lista ordenada de menor a mayor con elementos repetidos

```c
void inserta(NodoPtr l, Elemento d) {
  NodoPtr aux = l;

  while ((aux->sig != NULL) && (aux->sig->elem < d)) {
    aux = aux->sig;
  }

  NodoPtr nuevo = malloc(sizeof(struct Nodo));
  nuevo->elem = d;
  nuevo->sig = aux->sig;
  aux->sig = nuevo;
}
```

> Inserta un elemento en una lista ordenada de menor a mayor **sin** elementos repetidos

En este caso solamente insertaremos cuando el elemento sea distinto del que queremos insertar.

```c
void inserta(NodoPtr l, Elemento d) {
  NodoPtr aux = l;

  while ((aux->sig != NULL) && (aux->sig->elem < d)) {
    aux = aux->sig;
  }

  if ((aux->sig == NULL) || (aux->sig->elem != d)) {
    NodoPtr nuevo = malloc(sizeof(struct Nodo));
    nuevo->elem = d;
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
  }
}
```

> Elimina el elemento i-ésimo

```c
void suprime(NodoPtr l, int i) {
  if (i < 1) {
    return;
  }

  NodoPtr aux = l;

  while ((aux->sig != NULL) && (i > 1)) {
    aux = aux->sig;
    i--;
  }

  NodoPtr borrar = aux->sig;
  aux->sig = borrar->sig;

  free(borrar);
}
```

> Elimina el elemento i-ésimo desde el final

El truco está en mantener un puntero que mantenga siempre el elemento i puestos por detrás del elemento actual, de esta forma cuando el elemento actual llegue al final, tendremos un puntero que nos permitirá acceder directamente al elemento que queremos borrar.

```c
void suprime(NodoPtr l, int i) {
  if (i < 1) {
    return;
  }

  NodoPtr aux = l;
  NotoPtr anterior = l;

  while (aux->sig != NULL) {
    aux = aux->sig;

    i--;

    if (i <= 0) {
      anterior = anterior->sig;
    }
  }

  NodoPtr borrar = anterior->sig;
  anterior->sig = borrar->sig;

  free(borrar);
}
```
