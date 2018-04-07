---
title: Combinatoria
---

* Tabla de Contenidos
{:toc}

## Números combinatorios

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

## Ejercicios Resueltos

### Ejercicio 1 - listas simples

> ¿Cuántas listas de longitud 8 podemos formar con los dígitos 0, 1 y 2?

Hay 3 formas de rellenar cada uno de los ocho huecos, por tanto:

\\( n = 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \\)

### Ejercicio 2 - caso del *o*

> Haz una lista de cartas (baraja española), de longitud 4, de modo que el rey de oros esté en la primera **_o_** en la segunda posición. ¿De cuántas formas se pueden ordenar los elementos de la lista?

Primero, distinguimos los casos favorables:

* Rey en 1ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)
* Rey en 2ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)

Para ambos casos, fijamos al rey en una posición, y con el resto de cartas seguimos haciendo la lista. Como los dos casos **no se pueden dar a la vez**, el total de formas es la **suma** de ambos casos. Por tanto:

\\(Total = 1 \cdot 39 \cdot 38 \cdot 37 + 1 \cdot 39 \cdot 38 \cdot 37 \\)

### Ejercicio 3 - probabilidad y listas

> Queremos hacer una lista de longitud 5, con los dígitos del 0 al 9. ¿Cuál es la probabilidad de no usar el 5?

#### Si podemos repetir dígitos

\\[ \|\Omega\| = 10 \cdot 10 \cdot 10 \cdot 10 \cdot 10 \\]

Para cada hueco de la lista podemos meter 9 dígitos que no son 5, con lo cual tenemos:

\\[ n = 9 \cdot 9 \cdot 9 \cdot 9 \cdot 9 \\]

Y la probabilidad buscada es:

\\[ P(A) = \frac{n}{\|\Omega\|} = \frac{9 \cdot 9 \cdot 9 \cdot 9 \cdot 9}{10 \cdot 10 \cdot 10 \cdot 10 \cdot 10} \\]

#### Si *no* podemos repetir dígitos

\\[ \|\Omega\| = 10 \cdot 9 \cdot 8 \cdot 7 \cdot 6 \\]

Para cada hueco de la lista podemos meter 9 dígitos que no son 5, con lo cual tenemos:

\\[ n = 9 \cdot 8 \cdot 7 \cdot 6 \cdot 5 \\]

Y la probabilidad buscada es:

\\[ P(A) = \frac{n}{\|\Omega\|} = \frac{9 \cdot 8 \cdot 7 \cdot 6 \cdot 5}{10 \cdot 9 \cdot 8 \cdot 7 \cdot 6} = \frac{5}{10} = 0.5 \\]

### Ejercicio 4 - listas con grupos

> Formamos una lista que contenga: 4 vocales distintas, 2 dígitos y dos asteriscos. Los dígitos deben estar **juntos**. ¿De cuántas formas distintas podemos formar esta lista?

Primero, cogemos los elementos que vamos a usar:

* 4 vocales: \\( {5 \choose 4} \\)
* 2 dígitos: \\( {10 \choose 2} \\)
* 2 asteriscos: \\( {1 \choose 1} \\)

A continuación, ordenamos los elementos para hacer grupos:

* 2 dígitos: \\( 2! \\)

Ahora juntamos los grupos:

* 4 vocales
* 1 grupo de dígitos
* 2 asteriscos

\\[ \frac{7!}{2!} \\]

Y por último unimos todo y hacemos la lista multiplicando por \\( 4! \\)

\\[ n = \frac{ {5 \choose 4} \cdot {10 \choose 2} \cdot {1 \choose 1} \cdot 2! \cdot 7! }{2!} \\]

### Ejercicio 5 - listas con grupos

> Tenemos 5 cuadrados distintos, 3 círculos iguales y 2 triángulos iguales. Hacemos una lista con 3 cuadrados, 2 círculos y 2 triángulos, de forma que los cuadrados estén juntos y los triángulos también estén juntos.

Cogemos los elementos que vamos a usar:

* 3 cuadrados: \\( {5 \choose 3} \\)
* 2 círculos: \\( {3 \choose 2} \\)
* 2 triángulos: \\( {2 \choose 2} \\)

Hacemos los grupos:

* Cuadrados: \\( 3! \\)
* Triángulos: \\( \frac{2!}{2!} \\)

Juntamos los grupos:

* 1 grupo de cuadrados
* 2 círculos iguales
* 1 grupo de triángulos

Tenemos 4 elementos, y repetimos dos de ellos.

\\[ \frac{4!}{2!} \\]

Hacemos la lista, sin olvidarnos del \\( 4! \\)

\\[ n = \frac{ {5 \choose 3} \cdot {3 \choose 2} \cdot {2 \choose 2} \cdot 3! \cdot 4! \cdot 4! }{2! \cdot 2!} \\]

### Ejercicio 6 - listas con separación

> Hacemos una lista con A, B, C, 1 y 2 de forma que los dígitos estén separados

Primero ordenamos los elementos que no tienen condiciones, dejando huecos entre ellos:

\_ A \_ B \_ C \_

Para hacer esa lista hemos usado \\( 3! \\), y ahora agregamos los dígitos en los huecos:

\_ A 1 B \_ C 2

Para este paso simplemente vemos las formas que tenemos de llenar cada hueco: 4 para el primero y 3 para el segundo. En total:

\\[ n = 3! \cdot 4 \cdot 3 \\]

### Ejercicio 7 - listas con separación y grupos

> Hacemos una lista con las vocales, los dígitos del 1 al 4 y dos asteriscos; de forma que usemos 3 vocales, dos dígitos distintos *separados* y un asterisco.

Elegimos los elementos:

* 3 vocales: \\( {5 \choose 3} \\)
* 2 dígitos: \\( {4 \choose 2} \\)
* 1 asterisco: \\( {2 \choose 2} \\)

Hacemos los grupos con los elementos que no tienen condiciones:

* 3 vocales
* 1 asterisco

\\[ 4! \\]

Para agregar los elementos con condiciones tenemos 5 huecos, que rellenamos: \\( 5 \cdot 4 \\)

Y hacemos la lista:

\\[ n = {5 \choose 3} \cdot {4 \choose 2} \cdot 1 \cdot 4! \cdot 5 \cdot 4 \\]
