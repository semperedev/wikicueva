---
title: Ejercicios Resueltos
---

# Probabilidad

### Ejercicio 1

> En una urna hay cinco bolas blancas y dos bolas rojas. Si cojo una bola, ¿cuál es la probabilidad de que sea blanca?, ¿y de que sea roja?

Los posibles sucesos son: \\( \Omega = \\{ B, B, B, B, B, R, R \\} \\), expresado de forma más sencilla: \\( \| \Omega \| = 7 \\)

Nos interesa el color de la bola que sacamos, que puede ser blanca o roja. Para el primer caso, hay cinco bolas blancas que nos interesan, por tanto la probabilidad es:

\\[ P(B) = \frac{5}{7} \\]

Para el segundo caso simplemente modificamos los casos favorables, que ahora son 2, pues hay dos bolas rojas:

\\[ P(R) = \frac{2}{7} \\]

### Ejercicio 2

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que las dos sean rojas?

Los posibles sucesos son: obtener dos bolas blancas, obtener dos bolas rojas u obtener una de cada color; en notación: \\( \Omega = \\{ BB, BB, RR, RR, BR, RB \\} \\)

Dado que cogemos más de una bola, podemos expresar los casos posibles más comodamente usando números combinatorios: \\( \| \Omega \| = {4 \choose 2} = 6 \\).

Para los casos favorables operaremos de la misma forma, tenemos dos bolas rojas y necesitamos dos bolas rojas: \\( {2 \choose 2} = 1 \\)

Por tanto, la probabilidad buscada es:

\\[ P(RR) = \frac{1}{6} \\]

### Ejercicio 3

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que cada una sea de un color distinto?

\\( \Omega = \\{ BB, RR, BR \\} \\) o visto con números combinatorios: \\( {4 \choose 2} = 6 \\)

En este caso tenemos que coger las bolas en dos pasos. Por el principio multiplicativo sabemos que el número de formas de coger dos bolas es el número de formas de coger la primera multiplicado por el número de formas de coger la segunda, con lo cual:

\\[ P(BR) = \frac{2 \cdot 2}{6} = \frac{4}{6} \\]

### Ejercicio 4

> Estamos jugando al póker con una baraja **española** (40 cartas). Me reparten 5 cartas, ¿cuál es la probabilidad de tener póker de ases?

Tenemos que calcular la probabilidad de que nos hayan dado los cuatro ases de la baraja y otra carta que nos da igual, así que usaremos números combinatorios:

\\[ P(AAAA + otro) = \frac{ {4 \choose 4} \cdot {36 \choose 1} }{ {40 \choose 5} } \\]

### Ejercicio 4 (probabilidad condicionada)

> En un curso de la universidad hay cuatro grupos: G1, G2, G3 Y G4. Cada grupo compone el 25% del total de alumnos. El porcentaje de aprobados es: 56% para el G1, 48% para el G2, 51% para el G3 y 49% para el G4. ¿Qué probabilidad hay de aprobar? ¿Qué probabilidad hay de ser del G1 y aprobar?

\\[ P(A) = 0.25 \cdot 0.56 + 0.25 \cdot 0.48 + 0.25 \cdot 0.51 + 0.25 \cdot 0.49 \\]

\\[ P(A\ y\ G1) = 0.25 \cdot 0.56 \\]

### Ejercicio 5 (probabilidad condicionada)

> Hay tres empresas: A, B y C. De mis compras, el 40% son de A, el 35% son de B y el 25% son de C. El porcentaje de fallos por empresa es: 3% para A, 4% para B y 6% para C. ¿Qué probabilidad hay de que mis compras sean defectuosas?

\\[ P(D) = P(A) \cdot P(D \| A) + P(B) \cdot P(D \| B) + P(C) \cdot P(D \| C) \\]

\\[ P(D) = 0.4 \cdot 0.03 + 0.35 \cdot 0.04 + 0.25 \cdot 0.06 \\]

### Ejercicio 6 (Bayes)

> El 100% de los alumnos de un curso están repartidos en tres grupos: el 30% en G1, el 40% en G2 y otro 30% en G3. En cada grupo hay un porcentaje de alumnos que saben C, cuyas probabilidades son:
>
> \\( P(C\|G1) = 0.05 \\)  
> \\( P(C\|G2) = 0.03 \\)  
> \\( P(C\|G3) = 0.04 \\)
>
> Hay un alumno que sabe C, ¿de qué grupo podría ser?

Aplicando la Regla de Bayes sabemos que podemos calcular la probabilidad de que un alumno que sabe C sea de un grupo \\( G_i \\):

\\[ P(G_i\|C) = \frac{P(C\|G_i) \cdot P(C)}{P(G_i)} \\]

Calculamos \\( P(C) \\) primero:

\\[ P(C) = 0.3 \cdot 0.05 + 0.4 \cdot 0.03 + 0.3 \cdot 0.04 = 0.039 \\]

Y ahora calculamos las probabilidades de cada grupo:

\\[ P(G1\|C) = \frac{0.05 \cdot 0.39}{0.3} = 0.065 \\]

\\[ P(G2\|C) = \frac{0.03 \cdot 0.39}{0.3} = 0.039 \\]

\\[ P(G3\|C) = \frac{0.04 \cdot 0.39}{0.3} = 0.052 \\]

Por tanto lo más probable es que el alumno sea del G1.

# Listas

### Ejercicio 1

> ¿Cuántas listas de longitud 8 podemos formar con los dígitos 0, 1 y 2?

Hay 3 formas de rellenar cada uno de los ocho huecos, por tanto:

\\( n = 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \cdot 3 \\)

### Ejercicio 2

> Haz una lista de cartas (baraja española), de longitud 4, de modo que el rey de oros esté en la primera **_o_** en la segunda posición. ¿De cuántas formas se pueden ordenar los elementos de la lista?

Primero, distinguimos los casos favorables:

* Rey en 1ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)
* Rey en 2ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)

Para ambos casos, fijamos al rey en una posición, y con el resto de cartas seguimos haciendo la lista. Como los dos casos **no se pueden dar a la vez**, el total de formas es la **suma** de ambos casos. Por tanto:

\\(Total = 1 \cdot 39 \cdot 38 \cdot 37 + 1 \cdot 39 \cdot 38 \cdot 37 \\)

### Ejercicio 3

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

### Ejercicio 4

> Formamos una lista que contenga: 4 vocales distintas, 2 dígitos consecutivos y dos asteriscos. Los dígitos deben estar juntos. ¿De cuántas formas distintas podemos formar esta lista?

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

### Ejercicio 5

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


### Ejercicio 6 (listas con separación)

> Hacemos una lista con A, B, C, 1 y 2 de forma que los dígitos estén separados

Primero ordenamos los elementos que no tienen condiciones, dejando huecos entre ellos:

\_ A \_ B \_ C \_

Para hacer esa lista hemos usado \\( 3! \\), y ahora agregamos los dígitos en los huecos:

\_ A 1 B \_ C 2

Para este paso simplemente vemos las formas que tenemos de llenar cada hueco: 4 para el primero y 3 para el segundo. En total:

\\[ n = 3! \cdot 4 \cdot 3 \\]

### Ejercicio 7 (listas con separación y grupos)

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

\\[ {5 \choose 3} \cdot {4 \choose 2} \cdot 1 \cdot 4! \cdot 5 \cdot 4 \\]
