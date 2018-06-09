---
title: Método de Inducción
---

[&lt;&lt; Volver a **Cálculo**](../calc.md)

* Tabla de Contenidos
{:toc}

## Demostrar mediante inducción

> ¿Cómo es posible demostrar que una afirmación es cierta en el campo de los números naturales?

#### Paso 1: \\(n = 1\\)

Demostramos que la afirmación es cierta para un elemento concreto \\(n = 1\\).

#### Paso 2: \\(n + 1\\)

Si suponemos que la afirmación es cierta para un elemento concreto \\(n = 1\\), partimos de ahí para demostrar que también se cumple para el siguiente: \\(n + 1\\)

## Ejemplos

> Demuestra por inducción que las afirmaciones siguientes son ciertas para todo \\(n \in N\\)

### Ejercicio 1

> \\( \begin{align} 1 + 2 + 3 + ... + n = \frac{n(n + 1)}{2} \end{align} \\)

**Paso 1**

Primero vamos a demostrar que se cumple cuando \\(n = 1\\), para lo cual tenemos:

\\[1 \overset{?}{=} \frac{n(n + 1)}{2}\\]

Operamos:

\\[1 \overset{?}{=} \frac{1 \cdot (1 + 1)}{2}\\]
\\[1 \overset{?}{=} \frac{2}{2}\\]
\\[1 = 1\\]

Se trata de una equivalencia trivial, por lo que hemos demostrado que la igualdad se cumple para \\(n = 1\\). Ahora la intentaremos demostrar para \\(n + 1\\)

**Paso 2**

Hipótesis: Suponemos cierto \\(1 + 2 + 3 + ... + n = \frac{n(n + 1)}{2}\\)

Tesis: queremos probar que se cumple para \\(n + 1\\)

Agregando \\(n + 1\\) nos queda:

\\[
  (1 + 2 + 3 + ... + n) + (n + 1) \overset{?}{=} \frac{(n + 1)((n + 1) + 1)}{2}
\\]

Pero, ya sabemos cuánto vale la primera parte, \\(1 + 2 + ... + n\\), pues lo hemos demostrado en el paso anterior, así que sustituimos esa parte de la igualdad:

\\[
  \frac{n(n + 1)}{2} + (n + 1) \overset{?}{=} \frac{(n + 1)(n + 2)}{2}
\\]

Quitamos denominadores:

\\[
  n(n + 1) + 2 \cdot (n + 1) \overset{?}{=} (n + 1)(n + 2)
\\]

Sacamos factor común de \\((n + 1)\\):

\\[
  (n + 1)(n + 2) \overset{?}{=} (n + 1)(n + 2)
\\]

Y llegamos a una equivalencia trivial, aunque podríamos seguir despejando para que sea más claro aún:

\\[
  1 = 1
\\]

De esta forma hemos demostrado que la igualdad se cumple para un elemento concreto \\(n = 1\\) y para el siguiente \\(n + 1\\), con lo cual la afirmación original queda demostrada por inducción.

### Ejercicio 2

> \\( \begin{align} 1 + r + r^2 + r^3 + ... + r^n = \frac{r^{n + 1} - 1}{r - 1}, \text{para todo}\ r \neq 1 \end{align} \\)

**Paso 1**

Primero vamos a demostrar que se cumple para \\(n = 1\\), para lo cual utilizamos solamente el primer elemento, \\(r^1\\):

\\[1 + r \overset{?}{=} \frac{r^2 - 1}{r - 1}\\]

Y despejamos:

\\[(1 + r)(r - 1) \overset{?}{=} r^2 - 1\\]
\\[r - 1 + r^2 - r \overset{?}{=} r^2 - 1\\]
\\[-1 + r^2 = r^2 - 1\\]

Hemos llegado a una equivalencia trivial, con lo cual hemos demostrado que la igualdad es cierta para \\(n = 1\\), y ahora procederemos a demostrarla para \\(n + 1\\)

**Paso 2**

Hipótesis: Suponemos cierto \\(1 + r + r^2 + r^3 + ... + r^n = \frac{r^{n + 1} - 1}{r - 1}\\)

Y queremos probar:

\\[(1 + r + r^2 + r^3 + ... + r^n) + r^{n + 1} \overset{?}{=} \frac{r^{(n + 1) + 1} - 1}{r - 1}\\]

Pero, de nuevo, ya sabemos cuánto vale \\(1 + r + ... + r^n\\), así que sustituimos esa parte de la igualdad:

\\[
  \frac{r^{n + 1} - 1}{r - 1} + r^{n + 1} \overset{?}{=} \frac{r^{n + 2} - 1}{r - 1}
\\]

Quitamos denominadores:

\\[
  r^{n + 1} - 1 + r^{n + 1} \cdot (r - 1) \overset{?}{=} r^{n + 2} - 1
\\]

Y seguimos operando:

\\[
  r^{n + 1} - 1 + r^{n + 2} - r^{n + 1} \overset{?}{=} r^{n + 2} - 1
\\]

\\[
  -1 + r^{n + 2} = r^{n + 2} - 1
\\]

De nuevo, hemos llegado a una equivalencia trivial, y hemos demostrado que la igualdad se cumple para \\(n + 1\\).

Por tanto, mediante el método de inducción, hemos demostrado la igualdad inicial.
