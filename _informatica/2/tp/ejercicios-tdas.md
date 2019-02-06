---
title: Ejercicios de TDAs
---

[&lt;&lt; Volver a **TP**](../tp.md)

* Tabla de Contenidos
{:toc}

## Implementar TDAs

Para realizar los ejercicios, debemos implementar los TDAs cuya especificación (archivo `.h`) nos proporcionan.

### Ejercicio 1: TDA Punto

#### Especificación

> [tda-1.h](ejercicios/tda-1.h)

{% highlight c %}
{% include_relative ejercicios/tda-1.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Para comenzar, tenemos que implementar la estructura `PuntoRep`. Si analizamos las operaciones, vemos que para crear un punto nos proporcionan las coordenadas como argumentos de tipo `double`, y tanto las operaciones de consulta como de modificación trabajan con `double`, así que vamos a definir la estructura como dos variables de tipo `double` con nombres `x` e `y`:

```c
struct PuntoRep {
  double x, y;
};
```

**crea_punto**

Tenemos que crear la estructura, asignar los valores que nos dan y devolverla. Ya que el tipo `Punto` es un puntero a la estructura que hemos creado antes, tenemos que guardar la estructura en memoria dinámica:

```c
Punto crea_punto(double x, double y) {
  Punto p = malloc(sizeof(struct PuntoRep));

  p->x = x;
  p->y = y;

  return p;
}
```

**libera_punto**

Nos proporcionan una dirección de memoria y tenemos que liberarla, fácil y corto:

```c
void libera_punto(Punto p) {
  free(p);
}
```

**muestra_punto**

Vamos a utilizar `printf` para mostrar las dos propiedades del tipo de datos: `x` e `y`, que tenemos almacenadas en la estructura:

```c
void muestra_punto(Punto p) {
  printf("%f %f\n", p->x, p->y);
}
```

**recupera_punto**

Dado que tenemos las propiedades en la estructura, simplemente tenemos que devolver sus valores:

```c
double recupera_x_punto(Punto p) {
  return p->x;
}

double recupera_y_punto(Punto p) {
  return p->y;
}
```

**modifica_punto**

Nos pasan por argumentos la dirección del Punto y los nuevos valores de sus propiedades. Simplemente asignamos dichos valores a las variables de la estructura:

```c
void modifica_punto(Punto p, double x, double y) {
  p->x = x;
  p->y = y;
}
```

#### Todo junto

> [tda-1.c](ejercicios/tda-1.c)

{% highlight c %}
{% include_relative ejercicios/tda-1.c %}
{% endhighlight %}

### Ejercicio 2: TDA Rectangulo

#### Especificación

> [tda-2.h](ejercicios/tda-2.h)

{% highlight c %}
{% include_relative ejercicios/tda-2.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Para empezar, implementamos la estructura `RectanguloRep`. Analizando las operaciones vemos que para crear nos proporcionan cuatro propiedades: x, y, ancho y alto; y vamos a necesitarlas todas para las demás operaciones. Las almacenamos como enteros.

```c
struct RectanguloRep {
  int x, y, ancho, alto;
};
```

**crea_rectangulo**

Igual que en el TDA Punto, creamos la estructura en memoria dinámica y le asignamos los valores:

```c
Rectangulo crea_rectangulo(int x, int y, int ancho, int alto) {
  Rectangulo r = malloc(sizeof(struct RectanguloRep));

  r->x = x;
  r->y = y;
  r->ancho = ancho;
  r->alto = alto;

  return r;
}
```

**libera_rectangulo**

Simplemente liberamos memoria.

```c
void libera_rectangulo(Rectangulo r) {
  free(r);
}
```

**muestra_rectangulo**

Usamos `printf` para mostrar las propiedades.

```c
void muestra_rectangulo(Rectangulo r) {
  printf("(x: %d, y: %d, ancho: %d, alto: %d)\n", r->x, r->y, r->ancho, r->alto);
}
```

**recupera_rectangulo**

Devolvemos los valores de la estructura que nos piden:

```c
int recupera_x_rectangulo(Rectangulo r) {
  return r->x;
}

int recupera_y_rectangulo(Rectangulo r) {
  return r->y;
}
```

**modifica_rectangulo**

Simplemente asignamos los nuevos valores:

```c
void modifica_rectangulo(Rectangulo r, int x, int y) {
  r->x = x;
  r->y = y;
}
```

**dentro_rectangulo**

Nos proporcionan las coordenadas de un punto. Sabemos que el punto está dentro si sus coordenadas están entre los límites mayor y menor de los ejes vertical y horizontal. Es decir, si `x` es mayor que `r->x` pero menor que `r->x + r->ancho` está dentro del rectángulo horizontalmente; y lo mismo para la `y`. Si juntamos ambas condiciones queda así:

```c
int dentro_rectangulo(Rectangulo r, int x, int y) {
  return (
    ((r->x <= x) && (r->x + r->ancho >= x)) &&
    ((r->y <= y) && (r->y + r->alto >= y))
  );
}
```

#### Todo junto

> [tda-2.c](ejercicios/tda-2.c)

{% highlight c %}
{% include_relative ejercicios/tda-2.c %}
{% endhighlight %}

### Ejercicio 3: TDA Complejo

#### Especificación

> [tda-3.h](ejercicios/tda-3.h)

{% highlight c %}
{% include_relative ejercicios/tda-3.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Comenzamos implementando la estructura `ComplejoRep`. Nos indican en el enunciado que se trata de dos reales (`double`):

```c
struct ComplejoRep {
  double r, i;
};
```

**crea_complejo**

En la versión simple tan sólo hay que reservar memoria y asignar los nuevos valores:

```c
Complejo crea_complejo(double r, double i) {
  Complejo c = malloc(sizeof(struct ComplejoRep));

  c->r = r;
  c->i = i;

  return c;
}
```

En la versión de _polares_, la parte real es \\(r \cdot \cos o\\) y la imaginaria es \\(r \cdot \sin o\\), con lo cual podemos reutilizar la función `crea_complejo` pasando como argumentos los resultados de ambas operaciones:

```c
Complejo crea_polares_complejo(double r, double o) {
  return crea_complejo(r * cos(o), r * sin(o));
}
```

**libera_complejo**

Como siempre, liberamos con `free`:

```c
void libera_complejo(Complejo c) {
  free(c);
}
```

**muestra_complejo**

Mostramos con `printf`:

```c
void muestra_complejo(Complejo c) {
  printf("r: %f, i: %f\n", c->r, c->i);
}
```

**recupera_complejo**

Devolvemos los valores de la estructura:

```c
double recupera_parte_real_complejo(Complejo c) {
  return c->r;
}

double recupera_parte_imaginaria_complejo(Complejo c) {
  return c->i;
}
```

**modulo_complejo**

Simplemente tenemos que aplicar una fórmula matemática muy sencilla, para ello utilizaremos un par de funciones de la librería `math.h`: `sqrt` y `pow`. La fórmula del módulo es:

\\( mod = \sqrt{r^2 + i^2} \\)

```c
double modulo_complejo(Complejo c) {
  return sqrt(pow(c->r, 2) + pow(c->i, 2));
}
```

***operacion*_complejo**

La suma y resta de complejos es sencilla, simplemente operamos sus componentes. En estas operaciones, tenemos que crear un nuevo complejo y devolver su dirección, así que utilizaremos la función `crea_complejo` con los argumentos apropiados:

```c
Complejo suma_complejo(Complejo c, Complejo d) {
  return crea_complejo(c->r + d->r, c->i + d->i);
}

Complejo resta_complejo(Complejo c, Complejo d) {
  return crea_complejo(c->r - d->r, c->i - d->i);
}
```

En el caso de la multiplicación, vamos a aplicar la propiedad distributiva sobre las formas binómicas de ambos complejos:

\\(
  (a + bi) \cdot (c + di) =
  (ac - bd) +
  (ad + bc)i
\\)

Implementado quedaría:

```c
Complejo multiplica_complejo(Complejo c, Complejo d) {
  return crea_complejo(
    c->r * d->r - c->i * d->i,
    c->r * d->i + c->i * d->r
  );
}
```

La división es más compleja, así que simplemente dejaremos el resultado final y lo implementaremos:

\\(
  \frac{a + bi}{c + di} =
  \frac{ac + bd}{b^2 + d^2} +
  \frac{bc - ad}{b^2 + d^2}i
\\)

```c
Complejo divide_complejo(Complejo c, Complejo d) {
  return crea_complejo(
    (c->r * d->r + c->i * d->i) / (pow(c->i, 2) + pow(d->i, 2)),
    (c->i * d->r - c->r * d->i) / (pow(c->i, 2) + pow(d->i, 2))
  );
}
```

**compara_complejo**

Dos complejos son iguales si sus componentes son iguales, así que:

```c
int compara_complejo(Complejo c, Complejo d) {
  return (c->r == d->r) && (d->i == c->i);
}
```

#### Todo junto

> [tda-3.c](ejercicios/tda-3.c)

{% highlight c %}
{% include_relative ejercicios/tda-3.c %}
{% endhighlight %}

### Ejercicio 4: TDA Matriz

#### Especificación

> [tda-4.h](ejercicios/tda-4.h)

{% highlight c %}
{% include_relative ejercicios/tda-4.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Comenzamos implementando la estructura `MatrizRep`. Nos indican que los valores de la matriz son de tipo real, pero, ¿cómo estructuramos esos datos? Vamos a almacenar un array bidimensional de reales en memoria dinámica, es decir, un array (filas) de punteros (columnas). También necesitamos guardar el número de filas y columnas (enteros):

```c
struct MatrizRep {
  double ** arr;
  int f, c;
};
```

**crea_matriz**

Igual que en los casos anteriores, creamos la estructura en memoria dinámica y asignamos los valores de `f` y `c`. Pero en este caso, además, tenemos que dar valor al array bidimensional; para ello, creamos el primer nivel: array de punteros a real. A continuación, iteramos por el primer nivel creando los arrays del segundo.

```c
Matriz crea_matriz(int f, int c) {
  Matriz m = malloc(sizeof(struct MatrizRep));
  
  m->f = f;
  m->c = c;

  m->arr = malloc(sizeof(double *) * f);

  for (int i = 0; i < f; i = i + 1) {
    m->arr[i] = malloc(sizeof(double) * c);
  }

  return m;
}
```

**matriz_identidad**

Creamos la matriz con `crea_matriz`, y recorremos la matriz con dos bucles _for_ anidados, dando valor `1` cuando los índices coincidan.

```c
Matriz matriz_identidad(int n) {
  Matriz m = crea_matriz(n, n);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      if (i == j) {
        m->arr[i][j] = 1;
      }
    }
  }

  return m;
}
```

**libera_matriz**

El orden en el que liberamos la matriz es muy importante, pues tenemos varios niveles en memoria dinámica. Para hacerlo correctamente, comenzamos liberando desde el nivel más profundo hacia los superiores, tras esto podremos liberar la estructura:

```c
void libera_matriz(Matriz m) {
  for (int i = 0; i < m->f; i = i + 1) {
    free(m->arr[i]);
  }

  free(m->arr);
  free(m);
}
```

**muestra_matriz**

Esta operación es sencilla: iteramos por filas el array con dos bucles _for_ anidado, mostrando cada elemento de cada columna, y un salto de línea al terminar el bucle interior.

```c
void muestra_matriz(Matriz m) {
  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      printf("%f ", m->arr[i][j]);
    }

    printf("\n");
  }
}
```

***operacion*_valor_matriz**

Para acceder a un valor concreto de la matriz simplemente utilizamos la fila y la columna como índices del array bidimensional:

```c
double recupera_valor_matriz(Matriz m, int f, int c) {
  return m->arr[f][c];
}

void asigna_valor_matriz(Matriz m, int f, int c, double r) {
  m->arr[f][c] = r;
}
```

**recupera_matriz**

Simplemente devolvemos los valores de la estructura:

```c
int recupera_filas_matriz(Matriz m) {
  return m->f;
}

int recupera_columnas_matriz(Matriz m) {
  return m->c;
}
```

**escala_matriz**

Nos indican que tenemos que devolver una nueva matriz, por lo cual lo primero de todo será crear una matriz con el mismo número de filas y columnas que la que nos dan. A continuación, recorremos todo el array de la matriz original y asignamos a la nueva matriz los valores originales multiplicados por `e`.

```c
Matriz escala_matriz(Matriz m, double e) {
  Matriz n = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      n->arr[i][j] = m->arr[i][j] * e;
    }
  }

  return n;
}
```

**suma_matriz**

Primero comprobamos que se puede realizar la operación, es decir: si el número de filas y columnas de ambas matrices difieren, devolvemos `NULL`. Tras la comprobación, simplemente creamos una nueva matriz con las mismas dimensiones, y asignamos a cada elemento \\(suma_{ij}\\) la suma de las otras dos matrices: \\(suma_{ij} = m_{ij} + n_{ij}\\)

```c
Matriz suma_matriz(Matriz m, Matriz n) {
  if (m->f != n->f || m->c != n->c) {
    return NULL;
  }

  Matriz suma = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      suma->arr[i][j] = m->arr[i][j] + n->arr[i][j];
    }
  }

  return suma;
}
```

**multiplica_matriz**

Lo primero, comprobamos que se puede realizar la operación. Para ello el número de columnas de `m` tiene que coincidir con el número de filas de `n`, si esto no es así, devolvemos `NULL`. Ahora creamos la nueva matriz (`mul`) y recorremos su array con dos bucles _for_.

En cada iteración del bucle interior calculamos el valor de \\(mul_{ij}\\), que se obtiene multiplicando cada elemento de la fila i de la matriz `m` por cada elemento de la columna j de la matriz `n` y sumándolos. Para esto vamos a utilizar una variable `suma` y un bucle _for_ que recorre a la vez la fila i y la columna j, gracias a que tienen la misma longitud.

Finalmente, asignamos el valor de la suma a la posición correspondiente del array bidimensional.

```c
Matriz multiplica_matriz(Matriz m, Matriz n) {
  if (m->c != n->f) {
    return NULL;
  }

  Matriz mul = crea_matriz(m->f, n->c);
  
  int suma;

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < n->c; j = j + 1) {
      suma = 0;

      for (int k = 0; k < m->c; k = k + 1) {
        suma = suma + m->arr[i][k] * n->arr[k][j];
      }

      mul->arr[i][j] = suma;
    }
  }

  return mul;
}
```

**matriz_traspuesta**

Para trasponer una matriz simplemente copiamos la matriz `m` a la nueva matriz, pero cambiando los índices en la asignación en una de las dos matrices.

```c
Matriz matriz_traspuesta(Matriz m) {
  Matriz n = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      n->arr[i][j] = m->arr[j][i];
    }
  }

  return n;
}
```

#### Todo junto

> [tda-4.c](ejercicios/tda-4.c)

{% highlight c %}
{% include_relative ejercicios/tda-4.c %}
{% endhighlight %}

### Ejercicio 5: TDA Monomio

#### Especificación

> [tda-5.h](ejercicios/tda-5.h)

{% highlight c %}
{% include_relative ejercicios/tda-5.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Para la estructura vamos a necesitar almacenar el coeficiente y el exponente.

```c
struct MonomioRep {
  double c;
  int e;
};
```

**crea_monomio y libera_monomio**

Para crear y liberar usamos los mismos esquemas básicos de los primeros TDAs:

```c
Monomio crea_monomio(double coef, int exp) {
  Monomio m = malloc(sizeof(struct MonomioRep));

  m->c = coef;
  m->e = exp;

  return m;
}
```

```c
void libera_monomio(Monomio m) {
  free(m);
}
```

**muestra_monomio**

Usamos `printf` para mostrar las dos propiedades de la estructura:

```c
void muestra_monomio(Monomio m) {
  printf("%f * x^%d\n", m->c, m->e);
}
```

**recupera_monomio y modifica_monomio**

Simplemente devolvemos y modificamos los datos que nos indican directamente en la estructura:

```c
double recupera_coeficiente_monomio(Monomio m) {
  return m->c;
}

int recupera_exponente_monomio(Monomio m) {
  return m->e;
}

void modifica_coeficiente_monomio(Monomio m, double coef) {
  m->c = coef;
}
```

**evalua_monomio**

Tenemos que reemplazar la _x_ por el valor que nos proporcionan y devolver el valor que tendría la expresión resultante. Utilizaremos las funciones de `math.h` para ello.

```c
double evalua_monomio(Monomio m, double x) {
  return m->c * pow(x, m->e);
}
```

#### Todo junto

> [tda-5.c](ejercicios/tda-5.c)

{% highlight c %}
{% include_relative ejercicios/tda-5.c %}
{% endhighlight %}

### Ejercicio 7: TDA Polilinea

> Utilizando el [TDA Punto](#ejercicio-1-tda-punto)

#### Especificación

> [tda-7.h](ejercicios/tda-7.h)

{% highlight c %}
{% include_relative ejercicios/tda-7.h %}
{% endhighlight %}

#### Implementación

**Estructura**

Nos piden que mantengamos los puntos en el orden en que fueron agregados, por lo que para almacenarlos vamos a implementar una lista simplemente enlazada con nodo cabecera. Para ello vamos a definir dos estructuras: `Nodo` y `PolilineaRep`. La primera va a ser un nodo de la lista (dato y puntero a siguiente); y la segunda va a contener un puntero a nodo para la cabecera de la lista y otro puntero a nodo para la cola.

```c
struct Nodo {
  Punto p;
  NodoPtr sig;
};

struct PolilineaRep {
  NodoPtr cabecera, ultimo;
};
```

**crea_polilinea**

Para crear la polilinea, creamos la estructura en memoria dinámica y creamos el nodo cabecera. Los dos punteros de la polilinea apuntan al mismo nodo porque está vacía.

```c
Polilinea crea_polilinea() {
  Polilinea p = malloc(sizeof(struct PolilineaRep));
  
  p->cabecera = malloc(sizeof(struct Nodo));
  p->cabecera->sig = NULL;

  p->ultimo = p->cabecera;

  return p;
}
```

**libera_polilinea**

Para liberar la polilinea, tenemos que liberar la lista y después la cabecera, para ello recorremos la lista con un puntero auxiliar; en cada iteración re-enlazamos la lista y liberamos el nodo correspondiente:

```c
void libera_polilinea(Polilinea p) {
  NodoPtr aux = p->cabecera;

  while (p->cabecera->sig != NULL) {
    aux = p->cabecera->sig;
    p->cabecera->sig = aux->sig;
    free(aux);
  }

  free(p);
}
```

**muestra_polilinea**

Recorremos la lista y llamamos a `muestra_punto` (del TDA Punto) con cada punto:

```c
void muestra_polilinea(Polilinea p) {
  NodoPtr aux = p->cabecera;

  while (aux->sig != NULL) {
    muestra_punto(aux->sig->p);
    aux = aux->sig;
  }
}
```

**agrega_punto_polilinea**

Nos indican que agregamos por el final, con lo cual simplemente tenemos que crear el nodo y enlazarlo con el último nodo, que tenemos apuntado en la estructura de la polilinea.

```c
void agrega_punto_polilinea(Polilinea p, Punto q) {
  NodoPtr nodo = malloc(sizeof(struct Nodo));
  nodo->p = q;
  nodo->sig = NULL;

  p->ultimo->sig = nodo;
  p->ultimo = nodo;
}
```

**selecciona_polilinea**

Nos piden el punto más cercano, con lo cual tenemos que buscar en la lista el nodo con la distancia más corta, es decir, recorrer la lista e ir actualizando la distancia mínima y un puntero al punto con dicha distancia:

```c
Punto punto = NULL; // punto más cercano
float minDist = INT_MAX; // distancia mínima, obtenemos INT_MAX de <limits.h>
float dist; // distancia del nodo actual
```

Para hacer las cosas más fáciles vamos a utilizar un par de variables auxiliares para las coordenadas del punto del nodo actual:

```c
int px, py;
```

Calculamos la distancia con la fórmula de la distancia euclídea (\\(d = \sqrt{(x_1 + x_2)^2 + (x_1 + x_2)^2}\\)):

```c
dist = sqrt(pow(px + x, 2) + pow(py + y, 2));
```

Sólo queda recorrer la lista igual que en las otras operaciones y devolver el punto más cercano:

```c
Punto selecciona_polilinea(Polilinea p, double x, double y) {
  NodoPtr aux = p->cabecera;

  Punto punto = NULL;
  float dist;
  float minDist = INT_MAX;

  int px, py;

  while (aux->sig != NULL) {
    px = recupera_x_punto(aux->sig->p);
    py = recupera_y_punto(aux->sig->p);

    dist = sqrt(pow(px + x, 2) + pow(py + y, 2));;

    if (dist < minDist) {
      punto = aux->sig->p;
    }

    aux = aux->sig;
  }

  return punto;
}
```

**elimina_punto_polilinea**

Necesitamos encontrar el punto en la lista: con un bucle avanzamos mientras no lleguemos al final o encontremos el elemento. Tras esto, si no hemos llegado al final, re-enlazamos la lista sin el nodo encontrado y lo borramos.

```c
void elimina_punto_polilinea(Polilinea p, Punto q) {
  NodoPtr aux = p->cabecera;

  while ((aux->sig != NULL) && (aux->sig->p != q)) {
    aux = aux->sig;
  }

  if (aux->sig != NULL) {
    NodoPtr borrar = aux->sig;
    aux->sig = aux->sig->sig;
    free(borrar);
  }
}
```

#### Todo junto

> [tda-7.c](ejercicios/tda-7.c)

{% highlight c %}
{% include_relative ejercicios/tda-7.c %}
{% endhighlight %}

## Utilizar TDAs

Dado el siguiente TDA:

#### [lista.h](ejercicios/lista.h)

{% highlight c %}
{% include_relative ejercicios/lista.h %}
{% endhighlight %}

Hacer los siguientes ejercicios:

#### [tda-lista.c](ejercicios/tda-lista.c)

{% highlight c %}
{% include_relative ejercicios/tda-lista.c %}
{% endhighlight %}
