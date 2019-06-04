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
for (int i = 0; i < n; i = i + 1) {
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

  for (int i = 0; i < n; i = i + 1) {
    array[i] = (rand() % (b - a + 1)) + a;
  }

  return array;
}
```

**Más allá**

Podríamos agregar un poco de código al inicio de la función para comprobar que los parámetros son correctos, asegurándonos de que `n > 0` y `b > a`:

```c
assert(n > 0);

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
  assert(n > 0);

  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i = i + 1) {
    array[i] = datos[i];
  }

  return array;
}
```

### Ejercicio 4

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con los `n` valores contenidos en el array `datos` en el orden inverso.
>
> `int * invierte(int datos[], int n)`

Como en los ejercicios anteriores, lo primero será comprobar los parámetros y reservar memoria:

```c
assert(n > 0);

int * array = malloc(sizeof(int) * n);
```

Ahora vamos con lo complicado: asignar los elementos en orden **inverso**.

Hay varias formas de afrontar este problema, nosotros vamos a optar por la siguiente: recorrer nuestro array en orden correcto pero obteniendo los elementos del array `datos` desde el final hacia el principio.

Ahora tenemos que obtener los índices correctos del array `datos`, para lo cual emplearemos la técnica del ejercicio 2.

Si el índice actual es `i`, podemos obtener el elemento simétrico a `array[i]` utilizando `datos[n - i - 1]`, de forma que el bucle se nos quedaría esto:

```c
int * invierte(int datos[], int n) {
  assert(n > 0);

  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i = i + 1) {
    array[i] = datos[n - i - 1];
  }

  return array;
}
```

**Más allá**

Otra forma de trabajar sería recorrer `datos` de forma contraria y asignando valores a nuestro array desde el final hasta el principio:

```c
for (int i = 0; i < n; i = i + 1) {
  array[n - i - 1] = datos[i];
}
```

### Ejercicio 5

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array cuyos elementos sean el resultado de sumar los `n` valores contenidos en los arrays `a` y `b`.
>
> `int * suma(int a[], int b[], int n);`

Reservamos memoria:

```c
int * array = malloc(sizeof(int) * n);
```

A continuación tenemos que recorrer los arrays y sumar sus valores; esto es bastante sencillo dado que ambos arrays tienen la misma longitud, así que podemos utilizar un bucle `for` sencillo: `for (int i = 0; i < n; i = i + 1) { }`

En el cuerpo del bucle simplemente accedemos a los elementos de los tres arrays utilizando la sintaxis de siempre, `array[indice]`, y nos queda:

```c
int * suma(int a[], int b[], int n) {
  int * array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i = i + 1) {
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
// La longitud empieza valiendo uno para tener en cuenta la marca de fin, pero el índice del bucle para acceder al array empieza en cero
int n = 1;
int i = 0;

while (cadena[i] != '\0') {
  n = n + 1;
  i = i + 1;
}
```

Ahora que ya tenemos la longitud de la cadena, reservamos memoria para la copia:

```c
char * copy = malloc(sizeof(char) * n);
```

Y podemos proceder a la copia, para ello simplemente recorremos la cadena original asignando sus valores a la nueva cadena:

```c
for (int i = 0; i < n; i = i + 1) {
  copy[i] = cadena[i];
}
```

Si juntamos todo:

```c
char * duplica(char * cadena) {
  int n = 1;

  while (cadena[n] != '\0') {
    n = n + 1;
  }

  char * copy = malloc(sizeof(char) * n);

  for (int i = 0; i < n; i = i + 1) {
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
  n = n + 1;
}

// Sumamos uno por la marca de fin
char * copia = malloc(sizeof(char) * (n + 1));
```

Para la copia inversa tenemos dos opciones: recorrer la cadena en sentido contrario o llenar la copia en sentido contrario; vamos a optar por la primera opción.

A cada elemento `i` de la copia le asignamos el elemento original de la misma posición pero desde el final: `n - i - 1`; restamos 1 por la marca de fin, que agregaremos luego a mano. El bucle queda así:

```c
for (int i = 0; i < n; i = i + 1) {
  copia[i] = cadena[n - i - 1];
}

copia[n] = '\0';
```

Si lo juntamos todo:

```c
char * invierteCadena(char * cadena) {
  int n = 0;

  while (cadena[n] != '\0') {
    n = n + 1;
  }

  char * copia = malloc(sizeof(char) * (n + 1));

  for (int i = 0; i < n; i = i + 1) {
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

Antes de comenzar, ya que `n` y `longitud` no tienen por qué coincidir, vamos a obtener la longitud de la cadena `letras`, para ello utilizaremos nuestro tan conocido bucle:

```c
int longitud = 1;

while (letras[longitud] != '\0') {
  longitud = longitud + 1;
}
```

Como siempre, reservamos memoria:

```c
char * cadena = malloc(sizeof(char) * (n + 1)); // +1 por marca de fin
```

Ahora simplemente tenemos que rellenar la nueva cadena. Para ello recorremos la cadena, y escogemos caracteres aleatorios de `letras`.

Para obtener los índices utilizamos la función `rand()`, de la librería estándar de C. Esta función puede devolver cualquier número, así que utilizamos el módulo (`% longitud`) para asegurarnos de que el número se encuentra en el rango correcto. Quedaría algo así:

```c
for (int i = 0; i < n; i = i + 1) {
  cadena[i] = letras[rand() % longitud];
}
```

Finalmente agregamos la marca de fin `cadena[n] = '\0';` y devolvemos la cadena. Si lo juntamos todo:

```c
char * generaCadena(char * letras, int n) {
  int longitud = 1;

  while (letras[longitud] != '\0') {
    longitud = longitud + 1;
  }

  char * cadena = malloc(sizeof(char) * (n + 1)); // +1 por marca de fin

  for (int i = 0; i < n; i = i + 1) {
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

for (int i = 0; a[i] != '\0'; i = i + 1) {
  n = n + 1;
}

for (int i = 0; b[i] != '\0'; i = i + 1) {
  n = n + 1;
}
```

Ahora que tenemos la longitud en `n`, reservamos memoria para `n` caracteres y la marca de fin:

```c
char * cadena = malloc(sizeof(char) * (n + 1));
```

Para terminar solamente nos queda copiar las cadenas una después de la otra. Utilizaremos una variable `i` para mantener la posición en la cadena nueva, y bucles _for_ para recorrer cada cadena. Y no debemos olvidar la marca de fin.

```c
int i = 0;

for (int j = 0; a[j] != '\0'; j = j + 1) {
  cadena[i] = a[j];
  i = i + 1;
}

for (int j = 0; b[j] != '\0'; j = j + 1) {
  cadena[i] = b[j];
  i = i + 1;
}

cadena[i] = '\0';
```

Si juntamos todo en una función:

```c
char * concatena(char * a, char * b) {
  int n = 0;

  for (int i = 0; a[i] != '\0'; i = i + 1) {
    n = n + 1;
  }

  for (int i = 0; b[i] != '\0'; i = i + 1) {
    n = n + 1;
  }

  char * cadena = malloc(sizeof(char) * (n + 1));

  int i = 0;

  for (int j = 0; a[j] != '\0'; j = j + 1) {
    cadena[i] = a[j];
    i = i + 1;
  }

  for (int j = 0; b[j] != '\0'; j = j + 1) {
    cadena[i] = b[j];
    i = i + 1;
  }

  cadena[i] = '\0';

  return cadena;
}
```

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

Una vez tenemos la memoria, podemos empezar a dar valor a las estructuras, que en el momento de la reserva tendrán valores basura. Para esto, recorremos el array con un bucle _for_ y asignamos valores usando `rand()`.

```c
for (int i = 0; i < n; i = i + 1) {
  array[i].x = rand() % 101;
  array[i].y = rand() % 101;
}
```

> Hemos utilizado `% 101` a modo ilustrativo.

Si lo juntamos todo:

```c
struct PuntoRep * generaPuntos(int n) {
  struct PuntoRep * array = malloc(sizeof(struct PuntoRep) * n);

  for (int i = 0; i < n; i = i + 1) {
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

for (int i = 0; i < n; i = i + 1) {
  if (datos[i] >= 0) {
    array[j] = datos[i];

    j = j + 1;
  }
}
```

Finalmente quedaría agregar la marca de fin tras el bucle `array[j] = -1;`. Si juntamos todo nos queda algo así:

```c
int * positivos(int datos[], int n) {
  int * array = malloc(sizeof(int) * (n + 1));

  int j = 0;

  for (int i = 0; i < n; i = i + 1) {
    if (datos[i] >= 0) {
      array[j] = datos[i];

      j = j + 1;
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

Nos encontramos ante un problema complejo, comencemos el análisis: tenemos que devolver un array de cadenas de caracteres (`char **`), para reservar la memoria correcta necesitamos saber el número de cadenas, así que recorremos el array contando los separadores.

Avanzamos mientras no encontremos la marca de fin, y cada vez que aparezca un `;` incrementamos el contador porque ha terminado la secuencia de un correo. Tras el bucle incrementamos en uno porque el último correo no termina con `;`.

```c
int n = 0;

for (int i = 0; direcciones[i] != '\0'; i = i + 1) {
  if (direcciones[i] == ';') {
    n = n + 1;
  }
}

n = n + 1;
```

Ahora que conocemos la cantidad de cadenas, reservamos la memoria del array para las `n` cadenas más la cadena de fin.

```c
char ** array = malloc(sizeof(char *) * (n + 1));
```

Ahora tenemos que volver a recorrer `direcciones` copiando cada cadena: vamos a utilizar un bucle _for_ (índice `i`) ya que tenemos el número de cadenas en `n`. Vamos a utilizar dos índices para ello:

```c
int j = 0, k = 0;
```

Usaremos `j` para obtener la longitud de cada cadena, y `k` para volver a recorrerlas copiándolas. El bucle exterior tendría esta forma:

```c
for (int i = 0; i < n; i = i + 1) {
  // Obtener longitud
  // Reservar memoria
  // Copiar cadena
}
```

Así que comencemos obteniendo la longitud: avanzamos con `j` el siguiente correo a copiar, y luego restamos los dos índices; `k` apuntará al último separador, mientras que `j` estará apuntando al siguiente separador o a la marca de fin, es decir, entre `j` y `k` está la cadena completa y su resta nos da la longitud exacta.

```c
while (direcciones[j] != ';' && direcciones[j] != '\0') {
  j = j + 1;
}

int len = j - k;
```

A continuación reservamos memoria y copiamos el correo avanzando en la cadena original con un índice `k`:

```c
array[i] = malloc(sizeof(char) * (len + 1));

for (int x = 0; x < len; x = x + 1) {
  array[i][x] = direcciones[k];

  k = k + 1;
}
```

Finalmente, agregamos la marca de fin y avanzamos `j` y `k` para pasar los separadores:

```c
array[i][len] = '\0';

j = j + 1;
k = k + 1;
```

El bucle completo sería algo así:

```c
for (int i = 0; i < n; i = i + 1) {
  while (direcciones[j] != ';' && direcciones[j] != '\0') {
    j = j + 1;
  }

  int len = j - k;

  array[i] = malloc(sizeof(char) * (len + 1));

  for (int x = 0; x < len; x = x + 1) {
    array[i][x] = direcciones[k];

    k = k + 1;
  }

  array[i][len] = '\0';

  j = j + 1;
  k = k + 1;
}
```

Después del bucle, agregamos la marca de fin al array de cadenas, que se representa como una cadena vacía `\0`:

```c
array[n] = malloc(sizeof(char));

array[n][0] = '\0';
```

Finalmente, agrupamos todo el código en una función:

```c
char ** divide(char * direcciones) {
  int n = 0;

  for (int i = 0; direcciones[i] != '\0'; i = i + 1) {
    if (direcciones[i] == ';') {
      n = n + 1;
    }
  }

  n = n + 1;

  char ** array = malloc(sizeof(char *) * (n + 1));

  int j = 0, k = 0;

  for (int i = 0; i < n; i = i + 1) {
    while (direcciones[j] != ';' && direcciones[j] != '\0') {
      j = j + 1;
    }

    int len = j - k;

    array[i] = malloc(sizeof(char) * (len + 1));

    for (int x = 0; x < len; x = x + 1) {
      array[i][x] = direcciones[k];

      k = k + 1;
    }

    array[i][len] = '\0';
    
    j = j + 1;
    k = k + 1;
  }

  array[n] = malloc(sizeof(char));

  array[n][0] = '\0';

  return array;
}
```

### Ejercicio 13

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con todos los valores positivos que haya en el array `datos`, sabiendo que éste contiene `n` números enteros. Pero esta vez no deben aparecer números repetidos. Coloca un `-1` como último elemento del array devuelto a modo de marca de fin. Por ejemplo, si `datos = {1,2,3,1,2}` hay que devolver `{1,2,3,-1}`.
>
> `int * positivos(int datos[], int n);`

Lo primero de todo, reservamos memoria para `n` elementos más la marca de fin:

```c
int * array = malloc(sizeof(int) * (n + 1));
```

Ahora tenemos que recorrer el array `datos` y copiar los elementos no duplicados. Hay varias formas de hacer esto, nosotros vamos a utilizar dos bucles _for_ anidados y una variable `k` para el índice del nuevo array.

El exterior para recorrer `datos` (de 0 a `n`):

```c
for (int i = 0; i < n; i = i + 1) {
  // ...
}
```

El interior para buscar el elemento actual en el nuevo array:

```c
for (int j = 0; j < k; j = j + 1) {
  if (datos[i] == array[j]) {
    // El elemento está repetido
    break;
  }
}
```

Si llegamos al final del nuevo array, el elemento no está repetido y lo podemos insertar:

```c
if (j == k) {
  array[k] = datos[i];

  k = k + 1;
}
```

Si juntamos todas las piezas del bucle:

```c
for (int i = 0; i < n; i = i + 1) {
  for (int j = 0; j < k; j = j + 1) {
    if (datos[i] == array[j]) {
      break;
    }
  }

  if (j == k) {
    array[k] = datos[i];

    k = k + 1;
  }
}
```

Finalmente agregamos la marca de fin:

```c
array[k] = -1;
```

Todo junto se quedaría algo parecido a esto:

```c
int * positivos(int datos[], int n) {
  int * array = malloc(sizeof(int) * (n + 1));

  int k = 0;

  for (int i = 0; i < n; i = i + 1) {
    for (int j = 0; j < k; j = j + 1) {
      if (datos[i] == array[j]) {
        break;
      }
    }

    if (j == k) {
      array[k] = datos[i];

      k = k + 1;
    }
  }

  array[k] = -1;

  return array;
}
```

### Ejercicio 14

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de un nuevo array con las coordenadas correspondientes a las celdas del array bidimensional `datos`, de `f` filas y `c` columnas, en las que haya un valor negativo. El número de valores negativos encontrados, que se corresponderá con el tamaño del nuevo array generado en memoria dinámica, se devolverá a través del parámetro `n`.
>
> `struct CoordenadaRep * encuentra(int f, int c, int datos[f][c], int * n);`

Nos proporcionan la siguiente estructura:

```c
struct CoordenadaRep {
  int x, y;
};
```

Reservamos memoria para todos los elementos (más adelante veremos una forma de hacerlo que gestiona mejor la memoria):

```c
struct CoordenadaRep * array = malloc(sizeof(struct CoordenadaRep *) * f * c);
```

Recorremos el array bidimensional con dos bucles _for_, y para cada elemento, si es negativo, lo agregamos al nuevo array como coordenada, donde `x = i` e `y = j`. Utilizamos una variable `k` como índice del nuevo array.

```c
for (int i = 0; i < f; i = i + 1) {
  for (int j = 0; j < c; j = j + 1) {
    if (datos[i][j] < 0) {
      array[k].x = i;
      array[k].y = j;

      k = k + 1;
    }
  }
}
```

Finalmente, modificamos el valor de la variable apuntada por `n` para que refleje el número de elementos, que tenemos en `k`:

```c
*n = k;
```

Todo junto quedaría algo así:

```c
struct CoordenadaRep * encuentra(int f, int c, int datos[f][c], int * n) {
  struct CoordenadaRep * array = malloc(sizeof(struct CoordenadaRep *) * f * c);

  int k = 0;

  for (int i = 0; i < f; i = i + 1) {
    for (int j = 0; j < c; j = j + 1) {
      if (datos[i][j] < 0) {
        array[k].x = i;
        array[k].y = j;

        k = k + 1;
      }
    }
  }

  *n = k;

  return array;
}
```

**Más allá**

El algoritmo que hemos diseñado es rápido pero consume muchísima memoria, una forma de mejorarlo sería recorrer el array `datos` primero para obtener la cantidad de elementos negativos, de esta forma sólo reservaríamos memoria para los elementos que vamos a devolver. Simplemente habría que agregar dos bucles anidados y modificar la llamada a `malloc`:

```c
int l = 0;

for (int i = 0; i < f; i = i + 1) {
  for (int j = 0; j < c; j = j + 1) {
    if (datos[i][j] < 0) {
      l = l + 1;
    }
  }
}

struct CoordenadaRep * array = malloc(sizeof(struct CoordenadaRep *) * l);
```

### Ejercicio 15

> Completa el código de la siguiente función para que devuelva la dirección en memoria dinámica de una matriz (array de dos dimensiones) con `n` filas y `n` columnas conteniendo la diferencia en valor absoluto entre cada pareja de elementos de los arrays `a` y `b`, sabiendo que ambos contienen `n` elementos.
>
> `int ** genera(int a[], int b[], int n);`

Comenzamos reservando memoria para el primer nivel del array:

```c
int ** array = malloc(sizeof(int *) * n);
```

Para cada elemento de `a` tenemos que recorrer `b` calculando la diferencia en valor absoluto. Para recorrer utilizaremos dos bucles _for_ anidados, el exterior para `a` y el interior para `b`.

En cada iteración del bucle exterior reservaremos memoria para esa fila del array bidimensional. Y en cada iteración del bucle interno calcularemos la diferencia en valor absoluto y la agregaremos al array.

```c
for (int i = 0; i < n; i = i + 1) {
  array[i] = malloc(sizeof(int) * n);

  for (int j = 0; j < n; j = j + 1) {
    array[i][j] = abs(a[i] - b[j]);
  }
}
```

Si juntamos todo:

```c
int ** genera(int a[], int b[], int n) {
  int ** array = malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i = i + 1) {
    array[i] = malloc(sizeof(int) * n);

    for (int j = 0; j < n; j = j + 1) {
      int x = a[i] - b[j];

      if (x < 0) {
        x = 0 - x;
      }

      array[i][j] = x;
    }
  }

  return array;
}
```
