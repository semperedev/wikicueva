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

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con `n` enteros generados aleatoriamente en el intervalo cerrado `[a,b]`.
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

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con los `n` valores contenidos en el array `datos`.
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

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con los `n` valores contenidos en el array `datos` en el orden inverso.
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

Hay varias formas de afrontar este problema, nosotros vamos a optar por la siguiente: recorrer nuestro array en orden correcto pero obteniendo los elementos del array `datos` desde el final hacia el principio.

Ahora tenemos que obtener los índices correctos del array `datos`, para lo cual emplearemos la técnica del ejercicio 2.

Si el índice actual es `i`, podemos obtener el elemento simétrico a `array[i]` utilizando `datos[n - i - 1]`, de forma que el bucle se nos queda:

```c
for (int i = 0; i < n; i++) {
  array[i] = datos[n - i - 1];
}
```

Podríamos hacerlo de forma contraria: recorriendo `datos` de forma usual y asignando valores a nuestro array desde el final hasta el principio:

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

### Ejercicio 5

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array cuyos elementos sean el resultado de sumar los `n` valores contenidos en los arrays `a` y `b`.
>
> `int * suma(int a[], int b[], int n);`

Lo primero es reservar memoria:

```c
int * array = malloc(sizeof(int) * n);
```

A continuación tenemos que recorrer los arrays y sumar sus valores; esto es bastante sencillo dado que ambos arrays tienen la misma longitud, así que podemos utilizar un bucle `for` sencillo: `for (int i = 0; i < n; i++) { }`

En el cuerpo del bucle simplemente accedemos a los elementos de los tres arrays utilizando la sintaxis de siempre, `array[indice]`, y nos queda:

```c
int * suma(int a[], int b[], int n) {
  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    array[i] = a[i] + b[i];
  }

  return array;
}
```

### Ejercicio 6

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de una nueva cadena de caracteres idéntica a la recibida como parámetro.
>
> `char * duplica(char * cadena);`

Dado que trabajamos con memoria dinámica, tenemos que reservar suficiente memoria para la nueva cadena, y para ello necesitamos conocer la longitud de la cadena, dato que no nos proporcionan.

Para calcular la longitud tenemos que recorrer la cadena hasta que encontremos la marca de fin `'\0'`:

```c
// Empezamos en uno para tener en cuenta la marca de fin
int n = 1;

while (cadena[n] != '\0') {
  n++;
}
```

Ahora que ya tenemos la longitud de la cadena, reservamos memoria para la copia:

```c
char * copy = malloc(sizeof(char) * n);
```

Y podemos proceder a la copia, para ello simplemente recorremos la cadena original asignando sus valores a la nueva cadena:

```c
for (int i = 0; i < n; i++) {
  copy[i] = cadena[i];
}
```

Si juntamos todo:

```c
char * duplica(char * cadena) {
  int n = 1;

  while (cadena[n] != '\0') {
    n++;
  }

  char * copy = malloc(sizeof(char) * n);

  for (int i = 0; i < n; i++) {
    copy[i] = cadena[i];
  }

  return copy;
}
```

### Ejercicio 7

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de una nueva cadena de caracteres con la inversión de la recibida como parámetro.
>
> `char * invierteCadena(char * cadena);`

Igual que en el ejercicio anterior, tenemos que obtener la longitud y reservar memoria dinámica:

```c
int n = 0;

while (cadena[n] != '\0') {
  n++;
}

// Sumamos uno por la marca de fin
char * copia = malloc(sizeof(char) * (n + 1));
```

Para la copia inversa tenemos dos opciones: recorrer la cadena en sentido contrario o llenar la copia en sentido contrario; vamos a optar por la primera opción.

A cada elemento `i` de la copia le asignamos el elemento original de la misma posición pero desde el final: `n - i - 1`; restamos 1 por la marca de fin, que agregaremos luego a mano. El bucle queda así:

```c
for (int i = 0; i < n; i++) {
  copia[i] = cadena[n - i - 1];
}

copia[n] = '\0';
```

Si lo juntamos todo:

```c
char * invierteCadena(char * cadena) {
  int n = 0;

  while (cadena[n] != '\0') {
    n++;
  }

  char * copia = malloc(sizeof(char) * (n + 1));

  for (int i = 0; i < n; i++) {
    copia[i] = cadena[n - i - 1];
  }

  copia[n] = '\0'; // n aquí es igual a i + 1

  return copia;
}
```

### Ejercicio 8

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de una nueva cadena de caracteres que contenga `n` letras elegidas aleatoriamente de entre las incluidas en la cadena `letras`.
>
> `char * generaCadena(char * letras, int n);`

Antes de comenzar, vamos a obtener la longitud de la cadena `letras`, para ello utilizaremos nuestro tan conocido bucle:

```c
int longitud = 1;

while (letras[longitud] != '\0') {
  longitud++;
}
```

Como siempre, reservamos memoria:

```c
char * cadena = malloc(sizeof(char) * (n + 1)); // +1 por marca de fin
```

Ahora simplemente tenemos que rellenar la nueva cadena. Para ello recorremos la cadena, y escogemos caracteres aleatorios de `letras`. Para obtener los índices utilizamos el método `rand()`, de la librería estándar de C, y limitamos los resultados con el módulo de la lista (`% longitud`). Quedaría algo así:

```c
for (int i = 0; i < n; i++) {
  cadena[i] = letras[rand() % longitud];
}
```

Finalmente agregamos la marca de fin `cadena[n] = '\0';` y devolvemos la cadena. Si lo juntamos todo:

```c
char * generaCadena(char * letras, int n) {
  int longitud = 1;

  while (letras[longitud] != '\0') {
    longitud++;
  }

  char * cadena = malloc(sizeof(char) * (n + 1)); // +1 por marca de fin

  for (int i = 0; i < n; i++) {
    cadena[i] = letras[rand() % longitud];
  }

  cadena[n] = '\0';

  return cadena;
}
```

### Ejercicio 9

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de una nueva cadena de caracteres que contenga la cadena formada por la concatenación de las cadenas `a` y `b`. Por ejemplo, si `a="hola"` y `b="mundo"`, el resultado será la cadena `"holamundo"`.
>
> `char * concatena(char * a, char * b);`

Básicamente tenemos que copiar cadenas a una nueva. Lo primero es obtener la longitud de la nueva cadena resultante, para ello recorremos las cadenas `a` y `b` aumentando un contador:

```c
int n = 0;

for (int i = 0; a[i] != '\0'; i++) {
  n++;
}

for (int i = 0; b[i] != '\0'; i++) {
  n++;
}
```

Ahora que tenemos la longitud en `n`, reservamos memoria para `n` caracteres y la marca de fin:

```c
char * cadena = malloc(sizeof(char) * (n + 1));
```

Para terminar solamente nos queda copiar las cadenas una después de la otra. Utilizaremos una variable `i` para mantener la posición en la cadena nueva, y bucles _for_ para recorrer cada cadena. Y no debemos olvidar la marca de fin.

```c
int i = 0;

for (int j = 0; a[j] != '\0'; j++) {
  cadena[i] = a[j];
  i++;
}

for (int j = 0; b[j] != '\0'; j++) {
  cadena[i] = b[j];
  i++;
}

cadena[i] = '\0';
```

Si juntamos todo en una función:

```c
char * concatena(char * a, char * b) {
  int n = 0;

  for (int i = 0; a[i] != '\0'; i++) {
    n++;
  }

  for (int i = 0; b[i] != '\0'; i++) {
    n++;
  }

  char * cadena = malloc(sizeof(char) * (n + 1));

  int i = 0;

  for (int j = 0; a[j] != '\0'; j++) {
    cadena[i] = a[j];
    i++;
  }

  for (int j = 0; b[j] != '\0'; j++) {
    cadena[i] = b[j];
    i++;
  }

  cadena[i] = '\0';

  return cadena;
}
```

**Más allá**

Se podría reducir el código de los bucles _for_ de copia si utilizamos el operador de incremento (`++`) en la variable `i` cuando la usamos como índice, pues dicho operador devuelve el valor de `i` antes de incrementarlo. Quedaría así:

```c
// Antes:
for (...) {
  cadena[i] = b[j];
  i++;
}

// Después:
for (...) {
  cadena[i++] = b[j];
}
```

Incluso podríamos reducir la cantidad de código declarando las variables `i` y `j` al inicio de la función y cambiando los bucles _for_ por bucles _while_. Sería algo así:

```c
char * concatena(char * a, char * b) {
  int n = 0, i = 0, j = 0;

  while (a[i] != '\0') {
    n++; i++;
  }

  i = 0;

  while (b[i] != '\0') {
    n++; i++;
  }

  char * cadena = malloc(sizeof(char) * (n + 1));

  i = 0; j = 0;

  while (a[j] != '\0') {
    cadena[i++] = a[j++];
  }
  
  j = 0;

  while (b[j] != '\0') {
    cadena[i++] = b[j++];
  }

  cadena[i] = '\0';

  return cadena;
}
```

## Fichero antiguo

{% highlight c %}
{% include_relative ejercicios/punteros-memoria.c %}
{% endhighlight %}
