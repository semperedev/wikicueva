---
title: Probabilidad
---

* Tabla de Contenidos
{:toc}

## Probabilidad de un suceso

La probabilidad de un suceso se calcula de la siguiente forma:

\\[ Probabilidad = \frac{Casos\ favorables}{Casos\ posibles} \\]

Denotaremos los casos posibles por \\( \Omega \\), de forma que la probabilidad de un suceso \\( A \\) será:

\\[ P(A) = \frac{favorables}{\| \Omega \|} \\]

La probabilidad de un suceso se encuentra siempre entre 0 y 1, y la suma de las probabilidades de todos los sucesos posibles siempre es 1.

## Probabilidad condicionada

Distinguimos entre:

* \\( P(A) \\): probabilidad del suceso A
* \\( P(A \| B) \\): probabilidad del suceso A condicionado a B

Dicho de otra forma, \\( P(A \| B) \\) es la probabilidad de que suceda A, sabiendo que **también sucede B**.

### Casos especiales

\\[ P(A\ y\ B) = P(A) \cdot P(B \| A) \\]

\\[ P(A\ ó\ B) = P(A) + P(B) \\]

## Regla de Bayes

Tenemos dos propiedades A y B, independientes. Si conozco \\( P(B\|A) \\) y quiero calcular \\( P(A\|B) \\):

\\[ P(B\|A) = \frac{P(A\|B) \cdot P(A)}{P(B)} \\]

## Estudio de la eficiencia de una medida

Se da una situación \\( B \\) y aplicamos una medida \\( A \\) para intentar mejorarla. Comparamos las siguientes probabilidades, situando en la parte superior de la fracción la que esperamos que sea menor:

\\[ x = \frac{P(B \| A)}{P(B)} \\]

Si no conocemos \\( P(B \| A) \\), utilizaremos la Regla de Bayes para calcularlo. Una vez obtenida \\( x \\), analizamos la situación:

* \\( x \lt 1 \\): La medida es eficiente
* \\( x = 1 \\): La medida no ha afectado
* \\( x \gt 1 \\): La medida **no** es eficiente

## Ejercicios Resueltos

### Ejercicio 1 - probabilidad simple

> En una urna hay cinco bolas blancas y dos bolas rojas. Si cojo una bola, ¿cuál es la probabilidad de que sea blanca?, ¿y de que sea roja?

Los posibles sucesos son: \\( \Omega = \\{ B, B, B, B, B, R, R \\} \\), expresado de forma más sencilla: \\( \| \Omega \| = 7 \\)

Nos interesa el color de la bola que sacamos, que puede ser blanca o roja. Para el primer caso, hay cinco bolas blancas que nos interesan, por tanto la probabilidad es:

\\[ P(B) = \frac{5}{7} \\]

Para el segundo caso simplemente modificamos los casos favorables, que ahora son 2, pues hay dos bolas rojas:

\\[ P(R) = \frac{2}{7} \\]

### Ejercicio 2 - probabilidad simple

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que las dos sean rojas?

Los posibles sucesos son: obtener dos bolas blancas, obtener dos bolas rojas u obtener una de cada color; en notación: \\( \Omega = \\{ BB, BB, RR, RR, BR, RB \\} \\)

Dado que cogemos más de una bola, podemos expresar los casos posibles más comodamente usando números combinatorios: \\( \| \Omega \| = {4 \choose 2} = 6 \\).

Para los casos favorables operaremos de la misma forma, tenemos dos bolas rojas y necesitamos dos bolas rojas: \\( {2 \choose 2} = 1 \\)

Por tanto, la probabilidad buscada es:

\\[ P(RR) = \frac{1}{6} \\]

### Ejercicio 3 - probabilidad simple

> Estamos jugando al póker con una baraja **española** (40 cartas). Me reparten 5 cartas, ¿cuál es la probabilidad de tener póker de ases?

Tenemos que calcular la probabilidad de que nos hayan dado los cuatro ases de la baraja y otra carta que nos da igual, así que usaremos números combinatorios:

\\[ P(AAAA + otro) = \frac{ {4 \choose 4} \cdot {36 \choose 1} }{ {40 \choose 5} } \\]

### Ejercicio 4 - principio multiplicativo

> En una urna hay dos bolas blancas y dos bolas rojas. Si cojo dos bolas, ¿cuál es la probabilidad de que cada una sea de un color distinto?

\\( \Omega = \\{ BB, RR, BR \\} \\) o visto con números combinatorios: \\( {4 \choose 2} = 6 \\)

En este caso tenemos que coger las bolas en dos pasos. Por el principio multiplicativo sabemos que el número de formas de coger dos bolas es el número de formas de coger la primera multiplicado por el número de formas de coger la segunda, con lo cual:

\\[ P(BR) = \frac{2 \cdot 2}{6} = \frac{4}{6} \\]

### Ejercicio 5 - probabilidad condicionada

> En un curso de la universidad hay cuatro grupos: G1, G2, G3 Y G4. Cada grupo compone el 25% del total de alumnos. El porcentaje de aprobados es: 56% para el G1, 48% para el G2, 51% para el G3 y 49% para el G4. ¿Qué probabilidad hay de aprobar? ¿Qué probabilidad hay de aprobar y ser del G1?

\\[ P(A) = 0.25 \cdot 0.56 + 0.25 \cdot 0.48 + 0.25 \cdot 0.51 + 0.25 \cdot 0.49 \\]

\\[ P(A\ y\ G1) = 0.25 \cdot 0.56 \\]

### Ejercicio 6 - probabilidad condicionada

> Hay tres empresas: A, B y C. De mis compras, el 40% son de A, el 35% son de B y el 25% son de C. El porcentaje de fallos por empresa es: 3% para A, 4% para B y 6% para C. ¿Qué probabilidad hay de que mis compras sean defectuosas?

\\[ P(D) = P(A) \cdot P(D \| A) + P(B) \cdot P(D \| B) + P(C) \cdot P(D \| C) \\]

\\[ P(D) = 0.4 \cdot 0.03 + 0.35 \cdot 0.04 + 0.25 \cdot 0.06 \\]

### Ejercicio 7 - Regla de Bayes

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

### Ejercicio 8 - estudio de la eficiencia

> * Lanzamos un antivirus.
> * Un virus afecta al 40% de la población.
> * Sacamos un parche y lo instalamos en el 20% de la población.
> * Dentro de los que siguen infectados, el 15% tiene el parche instalado.

Tenemos:

\\( P(A) = 0.2 \\)  
\\( P(V) = 0.4 \\)  
\\( P(A\|V) = 0.15 \\)

Comparamos las dos probabilidades:

\\[ n = \frac{P(V \| A)}{P(V)} \\]

Calculamos \\( P(V \| A) \\) mediante Bayes:

\\[ P(V \| A) = \frac{P(A\|V) \cdot P(V)}{P(A)} = 0.15 \\]

Y finalmente sustituimos:

\\[ n = \frac{P(V \| A)}{P(V)} = \frac{0.15}{0.4} = 0.75 \\]

El resultado es menor que la unidad, por tanto podemos afirmar que la medida es efectiva y la situación ha mejorado.
