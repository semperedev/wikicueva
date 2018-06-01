---
title: Ejercicios de Estructuras Enlazadas Lineales
---

[&lt;&lt; Volver a **TP**](../tp.md)

* Tabla de Contenidos
{:toc}

## Creación de código

{% highlight c %}
{% include_relative ejercicios/lineales-1.c %}
{% endhighlight %}

## Comprensión de código

### Ejercicios 1

> Suponemos que `p` es una variable de tipo `NodoPtr`. ¿Qué hace el código?

```c
if (p->sig != NULL) {
  NodoPtr aux = p->sig;
  p->sig = p->sig->sig;
  free(aux);
}
```

Si el siguiente elemento de la lista `p->sig` no es nulo, lo elimina y puentea el elemento `p` con el siguiente al eliminado.

### Ejercicio 2 y 3

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a un nodo (o a una cabecera, puesto que también es un nodo) de una lista. ¿Cuándo fallaría?

```c
NodoPtr aux = p->sig;
p->sig = p->sig->sig;
free(aux);
```

Fallaría cuando no exista un elemento siguiente `p->sig`, puesto que no podríamos acceder a `p->sig->sig`.

### Ejercicio 4

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a un nodo de una lista. ¿Qué hace el código?

```c
NodoPtr aux = malloc(sizeof(struct Nodo));
aux->elem = 0;
aux->sig = p->sig;
p->sig = aux;
```

Crea un nuevo nodo, le asigna el elemento `0` y lo enlaza en la lista después del elemento `p`.

### Ejercicio 5

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a la cabecera de una lista. ¿Qué hace el código?

```c
NodoPtr aux = p;

while (aux->sig != NULL) {
  if (aux->sig->elem > 10) {
    aux->sig->elem = 0;
  }

  aux = aux->sig;
}
```

El bucle avanza por la lista mientras que el nodo siguiente no sea nulo, si el elemento del nodo siguiente es mayor que 10, le asigna el valor `0`.

### Ejercicio 6

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a la cabecera de una lista. ¿Qué hace el código?

```c
NodoPtr aux = p->sig;

while (aux != NULL) {
  NodoPtr aux2 = aux;
  aux = aux->sig;
  free(aux2);
}
```

Mientras que el nodo actual no sea nulo, guarda la dirección del nodo actual, avanza en la lista y elimina el nodo guardado.

### Ejercicio 8

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a la cabecera de una lista. ¿Qué hace el código?

```c
NodoPtr aux = p->sig;

while (aux != NULL) {
  printf("%d\n", aux->elem);
  aux = aux->sig;
}
```

Recorre toda la lista mostrando el dato de cada nodo.

### Ejercicio 10

> Suponemos que `p` es una variable de tipo `NodoPtr` que apunta a la cabecera de una lista. ¿Qué hace el código?

```c
NodoPtr aux = p;

while (aux->sig != NULL && aux->sig->elem < 100) {
  aux = aux->sig;
}

if (aux->sig != NULL && aux->sig->elem == 100) {
  printf("Ok\n");
}
```

Se trata de un algoritmo de búsqueda. Mientra el nodo actual no sea nulo, o sea menor estrictamente de 100, avanza en la lista.

Al salir del bucle, si el elemento actual no es nulo, y es igual a 100, muestra el mensaje `Ok`.

### Ejercicio 11

> La función debe liberar la memoria asociada a `lista`, ¿por qué falla?

```c
void libera(NodoPtr lista) {
  NodoPtr borrar = lista;

  libera(lista->sig);

  free(borrar);
}
```

Se trata de una función recursiva **sin caso base**: no se comprueba si el siguiente elemento es nulo. Finalizará con un error de memoria al intentar acceder a un elemento que no existe.

### Ejercicio 12

> La función debe liberar la memoria asociada a `lista`, ¿por qué falla?

```c
void libera(NodoPtr lista) {
  NodoPtr aux = lista;

  while (aux != NULL) {
    NodoPtr borrar = aux;
    free(borrar);
  }
}
```

En el bucle no se avanza, por lo que se trataría de un bucle infinito, pero el código finalizaría con un error al tratar de liberar el mismo elemento dos veces.
