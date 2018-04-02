---
title: Combinatoria y Probabilidad
---

# Probabilidad

La probabilidad de un suceso se calcula de la siguiente forma:

\\[ Probabilidad = \frac{Casos\ favorables}{Casos\ posibles} \\]

Denotaremos los casos posibles por \\( \Omega \\), de forma que la probabilidad de un suceso \\( A \\) será:

\\[ P(A) = \frac{favorables}{\| \Omega \|} \\]

La probabilidad de un suceso se encuentra siempre entre 0 y 1, y la suma de las probabilidades de todos los sucesos posibles siempre es 1.

# Números combinatorios

A la hora de elegir elementos de un conjunto, utilizaremos números combinatorios para saber de cuántas formas podemos hacerlo:

\\[ {n \choose k} \rightarrow de\ n\ cojo\ k \\]

Y se calcula con la siguiente fórmula:

\\[ {n \choose k} = \frac{n!}{k! \cdot (n - k)!} \\]

### Casos especiales

#### Elegimos: uno

Para elegir un elemento, podemos hacerlo de tantas formas como elementos haya:

\\( {n \choose 1} = n \\)

#### Elegimos: todo

Como es obvio, sólo hay una forma de elegir todos los elementos.

\\( {n \choose n} = 1 \\)

#### Elegimos: ninguno

Sólo hay una forma de no elegir, y es no eligiendo.

\\( {n \choose 0} = 1 \\)

#### Elegimos: todos menos uno

Visto de otra forma: elegimos el que no queremos.

\\( {n \choose n - 1} = n \\)
