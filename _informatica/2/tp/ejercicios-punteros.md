---
title: Punteros y Memoria Dinámica
---

[&lt;&lt; Volver a **TP**](../tp.md)

* Tabla de Contenidos
{:toc}

## Ejercicios

### Ejercicio 1

> Completa el código de la siguiente función para que intercambie los valores de las variables apuntadas por a y b.
>
> `void intercambia(int * a, int * b)`

Igual que en Pascal, aquí también vamos a necesitar una variable auxiliar para mantener temporalmente el valor de una de las variables.

Pero antes de escribir tenemos que darnos cuenta de un detalle importante: nos piden que intercambiemos los **valores** de las variables.

Si recordamos, podemos acceder al valor al que apunta un puntero utilizando la sintaxis `x = *ptr` y del mismo modo podemos modificar dicho valor con `*ptr = x`. Ahora ya podemos hacer el ejercicio:

```c
void intercambia(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
```

### Ejercicio 2

> Devuelve la dirección en memoria dinámica de un nuevo array con `n` enteros generados aleatoriamente en el intervalo `[a, b]`
>
> `int * genera(int n, int a, int b)`

Este ejercicio es un poco más complejo porque tenemos que utilizar memoria dinámica.

Lo primero de todo será reservar la memoria del array con `malloc`. Tenemos que pedir al sistema operativo hueco para `n` elementos de tipo entero:

```c
int * array = malloc(n * sizeof(int));
```

Ahora tenemos que llenar el array con valores. Para ello recorremos el array en memoria dinámica y vamos asignando valores a cada _hueco_:

```c
for (int i = 0; i < n; i++) {
  array[i] = VALOR;
}
```

Para calcular el valor de cada elemento del array tenemos que darle un par de vueltas al asunto. Queremos que estén en el intervalo `[a, b]`, pero con `rand() % x` sólo podemos conseguir valores en `[0, x]`. Aquí el truco estará en restar `a` a `b` para hacer el `rand` y luego sumarle `a` al resultado:

```c
(rand() % (b - a)) + a
```

Pero, el que sepa matemáticas se habrá dado cuenta de que con esto lo que obtenemos son valores para el intervalo `[a, b)`. Arreglar eso es tan sencillo como sumar 1 a la resta `b - a`:

```c
(rand() % (b - a + 1)) + a
```

Y por último tenemos que devolver la dirección del array que hemos creado. Si juntamos todo el código quedaría algo parecido a esto:

```c
int * genera(int n, int a, int b) {
  int * array = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    array[i] = (rand() % (b - a + 1)) + a;
  }

  return array;
}
```

**Más allá**

Podríamos agregar un poco de código al inicio de la función para comprobar que los parámetros son correctos, asegurándonos de que `n > 0` y `b > a`:

```c
if (n <= 0) {
  return NULL;
}

if (b < a) {
  int aux = a;
  a = b;
  b = aux;
}
```

### Ejercicio 3

> Devuelve la dirección en memoria dinámica de un nuevo array con los n valores contenidos en el array datos
>
> `int * copia(int datos[], int n)`

Igual que en el ejercicio anterior, lo primero es reservar memoria para el array:

```c
int * array = malloc(sizeof(int) * n);
```

Ahora simplemente recorremos el array `datos` asignando a nuestro array cada uno de sus valores, devolviendo la dirección del array al final. Quedaría algo así:

```c
int * copia(int datos[], int n) {
  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    array[i] = datos[i];
  }

  return array;
}
```

**Más allá**

Podríamos agregar un poco de código al inicio de la función para asegurarnos de que `n > 0`:

```c
if (n <= 0) {
  return NULL;
}
```

Pero, ¿y si `n` no es realmente el número de elementos del array `datos`? Por ahora, tendremos que confiar en que nos pasan un número correcto.

### Ejercicio 4

> Devuelve la dirección en memoria dinámica de un nuevo array con los n valores contenidos en el array datos en orden inverso
>
> `int * invierte(int datos[], int n)`

Como en los ejercicios anteriores, lo primero será comprobar los parámetros y reservar memoria:

```c
if (n <= 0) {
  return NULL;
}

int * array = malloc(sizeof(int) * n);
```

Ahora vamos con lo complicado: asignar los elementos en orden **inverso**.

Hay varias formas de afrontar este problema, nosotros vamos a optar por la siguiente: recorrer nuestro array en orden correcto pero asignando los elementos del array `datos` desde el final hacia el principio.

La dificultad está en obtener los índices correctos del array datos, para lo cual emplearemos la técnica del ejercicio 2.

Si el índice es `i`, podemos obtener el elemento simétrico a `array[i]` utilizando `datos[n - i - 1]`, de forma que el bucle se nos queda:

```c
for (int i = 0; i < n; i++) {
  array[i] = datos[n - i - 1];
}
```

Podríamos hacerlo de forma contraria: recorriendo datos de forma usual y asignando al array desde el final hasta el principio:

```c
for (int i = 0; i < n; i++) {
  array[n - i - 1] = datos[i];
}
```

Juntando todo el código (con la primera opción), quedaría esto:

```c
int * invierte(int datos[], int n) {
  if (n <= 0) {
    return NULL;
  }

  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    array[i] = datos[n - i - 1];
  }

  return array;
}
```

## Fichero antiguo

{% highlight c %}
{% include_relative ejercicios/punteros-memoria.c %}
{% endhighlight %}
