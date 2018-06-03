---
title: Ejercicios de Árboles
---

[&lt;&lt; Volver a **TP**](../tp.md)

* Tabla de Contenidos
{:toc}

## Árboles Binarios

### Definición

```c
typedef int Elemento;

struct Nodo {
  Elemento elem;
  struct Nodo * hijoIzquierdo;
  struct Nodo * hijoDerecho;
};

typedef struct Nodo * ArbolBinario;
```

### [arboles-1.c](ejercicios/arboles-1.c)

{% highlight c %}
{% include_relative ejercicios/arboles-1.c %}
{% endhighlight %}

## Árboles Generales

### Definición

```c
typedef int Elemento;

struct Nodo {
  Elemento elem;
  struct Nodo * primerHijo;
  struct Nodo * hermanoDerecho;
};

typedef struct Nodo * ArbolGeneral;
```

### [arboles-2.c](ejercicios/arboles-2.c)

{% highlight c %}
{% include_relative ejercicios/arboles-2.c %}
{% endhighlight %}
