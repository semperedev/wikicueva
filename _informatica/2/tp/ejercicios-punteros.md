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

Incluso podríamos usar esta misma técnica para todos los índices: declarando las variables `i` y `j` al inicio de la función y cambiando los bucles _for_ por bucles _while_, pero solamente aumentaría la complejidad del código sin aportar una mejora significativa al programa.

### Ejercicio 10

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con `n` puntos cuyas coordenadas estén generadas aleatoriamente.
>
> `struct PuntoRep * generaPuntos(int n);`

Nos proporcionan la siguiente estructura:

```c
struct PuntoRep {
  int x, y;
};
```

De igual forma que con tipos primitivos, reservamos memoria con malloc indicando que el tipo es la estructura PuntoRep:

```c
struct PuntoRep * array = malloc(sizeof(struct PuntoRep) * n);
```

Una vez tenemos la memoria, podemos empezar a dar valor a las estructuras, que el momento de la reserva tendrán valores basura. Para esto, recorremos el array con un bucle _for_ y asignamos valores usando `rand()`.

```c
for (int i = 0; i < n; i++) {
  array[i].x = rand() % 101;
  array[i].y = rand() % 101;
}
```

> Hemos utilizado `% 101` a modo ilustrativo.

Si lo juntamos todo:

```c
struct PuntoRep * generaPuntos(int n) {
  struct PuntoRep * array = malloc(sizeof(struct PuntoRep) * n);

  for (int i = 0; i < n; i++) {
    array[i].x = rand() % 101;
    array[i].y = rand() % 101;
  }

  return array;
}
```

### Ejercicio 11

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con todos los valores positivos que haya en el array `datos`, sabiendo que éste contiene `n` números enteros. Coloca un -1 como último elemento del array devuelto a modo de marca de fin.
>
> `int * positivos(int datos[], int n);`

Como siempre, lo primero es reservar memoria. En el caso de que todos sean positivos, tenemos que guardar los `n` elementos más la marca de fin, así que reservamos para `n+1`.

```c
int * array = malloc(sizeof(int) * (n + 1));
```

Ahora simplemente recorremos el array datos con un bucle _for_; para cada elemento comprobamos si es positivo, y en caso afirmativo lo agregamos al nuevo array. Utilizaremos una variable `j` para los índices del array resultado.

```c
int j = 0;

for (int i = 0; i < n; i++) {
  if (datos[i] >= 0) {
    array[j] = datos[i];

    j++;
  }
}
```

Finalmente quedaría agregar la marca de fin tras el bucle `array[j] = -1;`. Si juntamos todo nos queda algo así:

```c
int * positivos(int datos[], int n) {
  int * array = malloc(sizeof(int) * (n + 1));

  int j = 0;

  for (int i = 0; i < n; i++) {
    if (datos[i] >= 0) {
      array[j] = datos[i];

      j++;
    }
  }
  
  array[j] = -1;

  return array;
}
```

**Más allá**

Otra opción, más eficiente en memoria, sería recorrer el array primero para contar cuantos positivos tenemos, y reservar la memoria exacta que necesitaríamos.

### Ejercicio 12

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con `n+1` punteros a carácter. Cada uno apuntará a una nueva cadena de caracteres almacenada en memoria dinámica. El contenido de las primeras `n` cadenas será cada una de las `n` direcciones de correo electrónico encontradas en la cadena recibida como parámetro. La última cadena será la cadena de caracteres vacía. Las direcciones de correo electrónico aparecerán separadas por el carácter _;_ dentro de la cadena `direcciones`.
>
> `char ** divide(char * direcciones);`

**Importante**: asumimos que entre separadores siempre hay al menos un caracter y la cadena de entrada no está vacía

Nos encontramos ante un problema complejo, comencemos el análisis: tenemos que devolver un array de cadenas de caracteres (`char **`), para reservar la memoria correcta necesitamos saber la longitud de las cadenas, así que lo primero será obtener la cadena de mayor longitud.

#### 1. Obtener cadena mayor

Vamos a utilizar tres variables auxiliares:

* `n`: número de cadenas en `direcciones`
* `l`: longitud de la cadena actual
* `max`: longitud de la mayor cadena

```c
int n = 0, l = 0, max = 0;
```

Para recorrer la cadena `direcciones` utilizamos un bucle _for_ comprobando que el elemento actual sea distinto de la marca de fin. En cada iteración del bucle usamos `l++` para llevar la cuenta de la longitud.

```c
for (int i = 0; direcciones[i] != '\0'; i++) {
  // ...

  l++;
}
```

Cada vez que nos encontremos un separador (_;_) es porque hemos terminado una cadena, con lo cual:

* Aumentamos el número de cadenas: `n++;`
* Actualizamos `max` si es necesario: `if (l > max) max = l;`
* Reiniciamos el contador de longitud: `l = 0;`

El bucle resultante sería algo así:

```c
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
```

Es importante darse cuenta de que la última cadena, al no tener separador, no se comprueba en el bucle, así que tenemos que actualizar `max` y `n` si es necesario:

```c
if (l > max) {
  max = l;
}

n++;
```

En este paso tenemos el número de cadenas correcto y la longitud de la cadena mayor.

#### 2. Llenar el array

Para continuar, reservamos la memoria del array: `n + 1` punteros a caracter.

```c
char ** array = malloc(sizeof(char *) * (n + 1));
```

Ahora tenemos que volver a recorrer `direcciones` copiando cada cadena. Vamos a utilizar un bucle _for_ ya que tenemos el número de cadenas en `n`.

Para el índice de la cadena `direcciones` vamos a crear una variable `j`, y una variable `k` para el índice de cada cadena en el array.

```c
int j = 0, k = 0;
```

#### 3. Bucle de copia

Para cada iteración del bucle:

Primero reservamos memoria para una cadena de la máxima longitud:

```c
array[i] = malloc(sizeof(char) * (max + 1));
```

A continuación copiamos caracteres hasta encontrar un separador o una marca de fin. Reiniciamos el índice de la nueva cadena (`k = 0;`) y utilizamos un bucle _while_ para ir copiando mientras no nos encontremos la marca de fin o un separador:

```c
while ((direcciones[j] != '\0') && (direcciones[j] != ';')) {
  array[i][k] = direcciones[j];
  
  k++;
  j++;
}
```

Tras copiar la cadena, agregamos la marca de fin:

```c
array[i][k] = '\0';
```

El bucle completo sería algo así:

```c
int j = 0, k;

for (int i = 0; i < n; i++) {
  array[i] = malloc(sizeof(char) * (max + 1));

  k = 0;

  while ((direcciones[j] != '\0') && (direcciones[j] != ';')) {
    array[i][k++] = direcciones[j++];
  }

  array[i][k] = '\0';

  j++;
}
```

#### 4. Terminando

Agregamos la marca de fin, que se representa como una cadena vacía, es decir, el valor especial `NULL`.

```c
array[n] = NULL;
```

Finalmente, agrupamos todo el código en una función:

```c
char ** divide(char * direcciones) {
  int n = 0, l = 0, max = 0;

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

  if (l > max) {
    max = l;
  }

  n++;

  char ** array = malloc(sizeof(char *) * (n + 1));

  int j = 0, k;

  for (int i = 0; i < n; i++) {
    array[i] = malloc(sizeof(char) * (max + 1));

    k = 0;

    while ((direcciones[j] != '\0') && (direcciones[j] != ';')) {
      array[i][k++] = direcciones[j++];
    }

    array[i][k] = '\0';

    j++;
  }

  array[n] = NULL;

  return array;
}
```
