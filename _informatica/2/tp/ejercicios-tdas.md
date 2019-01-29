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

**Punto_crea**

Tenemos que crear la estructura, asignar los valores que nos dan y devolverla. Ya que el tipo `Punto` es un puntero a la estructura que hemos creado antes, tenemos que guardar la estructura en memoria dinámica:

```c
Punto Punto_crea(double x, double y) {
  Punto p = malloc(sizeof(struct PuntoRep));

  p->x = x;
  p->y = y;

  return p;
}
```

**Punto_libera**

Nos proporcionan una dirección de memoria y tenemos que liberarla, fácil y corto:

```c
void Punto_libera(Punto p) {
  free(p);
}
```

**Punto_muestra**

Vamos a utilizar `printf` para mostrar las dos propiedades del tipo de datos: `x` e `y`, que tenemos almacenadas en la estructura:

```c
void Punto_muestra(Punto p) {
  printf("%f %f\n", p->x, p->y);
}
```

**Punto_recupera**

Dado que tenemos las propiedades en la estructura, simplemente tenemos que devolver sus valores:

```c
double Punto_recupera_x(Punto p) {
  return p->x;
}

double Punto_recupera_y(Punto p) {
  return p->y;
}
```

**Punto_modifica**

Nos pasan por argumentos la dirección del Punto y los nuevos valores de sus propiedades. Simplemente asignamos dichos valores a las variables de la estructura:

```c
void Punto_modifica(Punto p, double x, double y) {
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

### Ejercicio 7

#### [tda-7.h](ejercicios/tda-7.h)

{% highlight c %}
{% include_relative ejercicios/tda-7.h %}
{% endhighlight %}

#### [tda-7.c](ejercicios/tda-7.c)

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
