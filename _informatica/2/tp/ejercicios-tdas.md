---
title: Ejercicios de TDAs
---

[&lt;&lt; Volver a **TP**](../tp.md)

* Tabla de Contenidos
{:toc}

Para realizar los ejercicios, debemos implementar los TDAs cuya definición (archivo `.h`) nos proporcionan.

En un examen solamente deberemos escribir el archivo `.c` con la implementación.

## Ejercicio 1

### [tda-1.h](ejercicios/tda-1.h)

{% highlight c %}
{% include_relative ejercicios/tda-1.h %}
{% endhighlight %}

### [tda-1.c](ejercicios/tda-1.c)

{% highlight c %}
{% include_relative ejercicios/tda-1.c %}
{% endhighlight %}

### Función de prueba

Descargar el archivo [tda-1-probar.c](ejercicios/tda-1-probar.c):

{% highlight c %}
{% include_relative ejercicios/tda-1-probar.c %}
{% endhighlight %}

Compilar (en unix):

```bash
# Compilar
mkdir build
gcc -g -Wall -std=c99 -c tda-1.c -o build/tda-1.o
gcc -g -Wall -std=c99 -c tda-1-probar.c -o build/tda-1-probar.o
g++ build/tda-1.o build/tda-1-probar.o -o build/tda-1

# Ejecutar
./build/tda-1
```

## Ejercicio 3

### [tda-3.h](ejercicios/tda-3.h)

{% highlight c %}
{% include_relative ejercicios/tda-3.h %}
{% endhighlight %}

### [tda-3.c](ejercicios/tda-3.c)

{% highlight c %}
{% include_relative ejercicios/tda-3.c %}
{% endhighlight %}

### Función de prueba

Descargar el archivo [tda-3-probar.c](ejercicios/tda-3-probar.c):

{% highlight c %}
{% include_relative ejercicios/tda-3-probar.c %}
{% endhighlight %}

Compilar (en unix):

> Atención: al compilar agregamos `-lm` para incluir la librería `math.h`

```bash
# Compilar
mkdir build
gcc -g -Wall -std=c99 -lm -c tda-3.c -o build/tda-3.o
gcc -g -Wall -std=c99 -c tda-3-probar.c -o build/tda-3-probar.o
g++ build/tda-3.o build/tda-3-probar.o -o build/tda-3

# Ejecutar
./build/tda-3
```

## Ejercicio 7

### [tda-7.h](ejercicios/tda-7.h)

{% highlight c %}
{% include_relative ejercicios/tda-7.h %}
{% endhighlight %}

### [tda-7.c](ejercicios/tda-7.c)

{% highlight c %}
{% include_relative ejercicios/tda-7.c %}
{% endhighlight %}

### Función de prueba

Descargar el archivo [tda-7-probar.c](ejercicios/tda-7-probar.c):

{% highlight c %}
{% include_relative ejercicios/tda-7-probar.c %}
{% endhighlight %}

Compilar (en unix):

```bash
# Compilar
mkdir build
gcc -g -Wall -std=c99 -c tda-1.c -o build/tda-1.o
gcc -g -Wall -std=c99 -c tda-7.c -o build/tda-7.o
gcc -g -Wall -std=c99 -c tda-7-probar.c -o build/tda-7-probar.o
g++ build/tda-1.o build/tda-7.o build/tda-7-probar.o -o build/tda-7

# Ejecutar
./build/tda-7
```
