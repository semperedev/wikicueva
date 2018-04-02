---
title: Ejercicios Resueltos
---

# Ejercicio 1

> En una urna hay cinco bolas blancas y dos bolas rojas. Si cojo una bola, ¿cuál es la probabilidad de que sea blanca?, ¿y de que sea roja?

Los posibles sucesos son: \\( \Omega = \\{ B, B, B, B, B, R, R \\} \\), expresado de forma más sencilla: \\( \| \Omega \| = 7 \\)

Nos interesa el color de la bola que sacamos, que puede ser blanca o roja. Para el primer caso, hay cinco bolas blancas que nos interesan, por tanto la probabilidad es:

\\[ P(B) = \frac{5}{7} \\]

Para el segundo caso simplemente modificamos los casos favorables, que ahora son 2, pues hay dos bolas rojas:

\\[ P(R) = \frac{2}{7} \\]

# Ejercicio 2

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que las dos sean rojas?

Los posibles sucesos son: obtener dos bolas blancas, obtener dos bolas rojas u obtener una de cada color; en notación: \\( \Omega = \\{ BB, BB, RR, RR, BR, RB \\} \\)

Dado que cogemos más de una bola, podemos expresar los casos posibles más comodamente usando números combinatorios: \\( \| \Omega \| = {4 \choose 2} = 6 \\).

Para los casos favorables operaremos de la misma forma, tenemos dos bolas rojas y necesitamos dos bolas rojas: \\( {2 \choose 2} = 1 \\)

Por tanto, la probabilidad buscada es:

\\[ P(RR) = \frac{1}{6} \\]

# Ejercicio 3

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que cada una sea de un color distinto?

\\( \Omega = \\{ BB, RR, BR \\} \\) o visto con números combinatorios: \\( {4 \choose 2} = 6 \\)

En este caso tenemos que coger las bolas en dos pasos. Por el principio multiplicativo sabemos que el número de formas de coger dos bolas es el número de formas de coger la primera multiplicado por el número de formas de coger la segunda, con lo cual:

\\[ P(BR) = \frac{2 \cdot 2}{6} = \frac{4}{6} \\]

# Ejercicio 4

> Haz una lista de cartas (baraja española) de modo que el rey de oros esté en la primera **_o_** en la segunda posición. ¿De cuántas formas se pueden ordenar los elementos de la lista?

Primero, distinguimos los casos favorables:

* Rey en 1ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)
* Rey en 2ª posición: \\(1 \cdot 39 \cdot 38 \cdot 37\\)

Para ambos casos, fijamos al rey en una posición, y con el resto de cartas seguimos haciendo la lista. Como los dos casos **no se pueden dar a la vez**, el total de formas es la **suma** de ambos casos. Por tanto:

\\(Total = 1 \cdot 39 \cdot 38 \cdot 37 + 1 \cdot 39 \cdot 38 \cdot 37 \\)
