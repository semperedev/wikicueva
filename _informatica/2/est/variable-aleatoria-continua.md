---
title: Variable Aleatoria Contínua
---

[&lt;&lt; Volver a **Estadística**](../est.md)

* Tabla de Contenidos
{:toc}

## Valores

Para representar utilizaremos solamente algunos de sus valores:

#### Ejemplo

> Introducimos la variable \\( x \in [1.5, 2] \\) en R:

```r
val <- seq(1.5, 2, 0.1)
```

## Probabilidades

En discreta cada valor tiene una probabilidad.

En contínua siempre tenemos \\( P(x = a) = 0 \\); por tanto utilizaremos la **Función de Densidad** \\( f(x) \\), que nos indica la forma del histograma. Y tiene ciertas propiedades:

* \\( f(x) \\) siempre es positiva
* El área de \\( f(x) \\) siempre vale 1, es decir: \\( \int_a^b f(x)dx = 1 \\)

#### Ejemplo

> Se sabe que cuanto más alto eres, más probabilidaddes hay de que te duela la columna. Queremos la probabilidad de que esto suceda para alturas entre 1.50 y 2 metros.

\\[ P(dolor\ de\ columna) = k \cdot x \\]

Ahora ajustamos \\( k \\) para obtener la función con área 1:

\\[ \int_{1.5}^2 k x dx = 1 \\]

\\[ k = \frac{1}{\frac{1.75}{2}} \\]

Que resolveremos mejor por ordenador:

```r
a = 1.5
b = 2

# Definimos f(x)
f <- function(x) { return(x) }

# Integramos f
A <- integrate(f, a, b) # 0.875 with absolute error < 9.7e-15

k <- 1 / A$value # 1.142857
```

Ahora ya tenemos nuestra \\( k \\) calculada, y podemos redefinir la función de densidad en R:

```r
f <- function(x) { return(k * x) }
```

Podemos dibujar la función:

```r
x <- seq(a, b, 0.1)

plot(x, f(x), type="l")
```

![Variable Aleatoria Contínua 1](/uploads/informatica/2/est/variable-aleatoria-continua-1.png)

## Propiedades de la variable

### Media

```r
x.media.f <- function(x) { return(x * f(x)) }
x.media <- integrate(x.media.f, a, b)
```

### Varianza

```r
x.var.f <- function(x) { return((x - x.media)**2 * f(x)) }
x.var <- integrate(x.var.f, a, b)
```

### Desviación Típica

```r
x.sd <- sqrt(x.var)
```

### Función de Distribución

Debemos resolver manualmente la integral en función de \\( x \\) y \\( F(x) \\):

\\[ F_x(x) = \int_a^n kx dx = k \cdot (\frac{n^2}{2} - \frac{a^2}{2}) \\]

## Ejemplo de ejercicio

### Ejercicio 1

> Una variable aleatoria contínua toma valores entre 1 y 2 con \\( f(x) = k \cdot x^2 \\)

#### Apartado A

> Ajustar \\( k \\)

Introducimos la función e integramos:

```r
preF <- function(x) { return(x**2) }
A <- integrate(preF, 1, 2)
k <- 1 / A$value # 0.4285714
```

Y redefinimos la función utilizando el valor de \\( k \\):

```r
f <- function(x) { return(k * x**2) }
```

#### Apartado B

> Analizar la variable

```r
# Introducimos los valores
x <- seq(1, 2, 0.01)

# Dibujamos la probabilidad
plot(x, f(x), type="l")
```

![Variable Aleatoria Contínua 2](/uploads/informatica/2/est/variable-aleatoria-continua-2.png)

```r
# Calculamos la media
x.m.f <- function(x) { return(x * f(x)) }
x.m <- integrate(x.m.f, 1, 2)$value # 1.607143
```

```r
# Calculamos la varianza
x.var.f <- function(x) { return((x - x.m)**2 * f(x)) }
x.var <- integrate(x.var.f, 1, 2)$value
x.var
```

La función de distribución la calculamos manualmente:

\\[ F_x(x) = \int_1^x k x^2 dx = k \cdot (\frac{x^3}{3} - \frac{1}{3}) \\]

Y la introducimos en R:

```r
F_x <- function(x) { return(k * (x**3/3 - 1/3)) }

plot(x, F_x(x), type="l")
```

![Variable Aleatoria Contínua 3](/uploads/informatica/2/est/variable-aleatoria-continua-3.png)

#### Apartado C

> Calcular \\( P(x < 1.7) \\)

\\[ P(x < 1.7) = P(x \leq 1.7) = F_x(1.7) \\]

> NOTA: En contínua sabemos que \\( P(x < n) = P(x \leq n) \\)

```r
F_x(1.7)
```

## Variables Contínuas Notables

Comparando con las variables notables en discreta, tenemos las siguientes equivalencias:

> NOTA: Pasar a tabla en vez de lista

* Bernouilli: No hay
* Uniforme: Uniforme contínua (Todos misma probabilidad)
* Geométrica: Exponencial (Tiempo hasta que ocurre algo)
* Binomial y Poisson: Normal (Medir)

### Uniforme contínua

Toma valores en un intervalo \\( [a, b] \\) y el histograma esperado es plano, pues el dibujo es un rectángulo.

Por ejemplo, en R:

```r
q1 <- qunif(prob, a, b)
```

Y sus propiedades:

```r
m   <- (a + b) / 2
var <- (b - a)**2 / 12 # El 12 del denominador viene de una integral que no vamos a hacer
```

#### Ejemplo

> Un programa de ordenador devuelve un número a suertes entre 0 y 1
> a) Analiza la variable
> b) Probabilidad de que un número esté entre 0.2 y 0.3

```r
val <- seq(0, 1, 0.1)
# f(x) es dunif(x, 0, 1) // no es necesario definirla de nuevo

plot(val, dunif(val, 0, 1), type="l")
```

![Variable Aleatoria Contínua 4](/uploads/informatica/2/est/variable-aleatoria-continua-4.png)

```r
val.m <- (0 + 1)/2
val.var <- (1 - 0)**2 / 12

# F_x(x) es punif(x, 0, 1) // no es necesaria definirla de nuevo
plot(val, punif(val, 0, 1))
```

![Variable Aleatoria Contínua 5](/uploads/informatica/2/est/variable-aleatoria-continua-5.png)

Y para terminar:

\\[ P(0.2 < x < 0.3) = P(x \leq 0.3) - P(x \leq 0.2) \\]

```r
punif(0.3, 0, 1) - punif(0.2, 0, 1) # 0.1
```

### Uniforme Exponencial

Hay un suceso que me interesa del que conozco, en media, las veces que ocurre por intervalo de tiempo: \\( \lambda \\)

Me interesa el tiempo que transcurrirá hasta que vuelva a ocurrir ese suceso. Por tanto, la elegiremos **siempre que nos pregunten por tiempo**.

Valores: \\( [0, + \infty) \\)  
Probabilidad: \\( \lambda \cdot e^{-\lambda \cdot t} \\)  
Media: \\( \frac{1}{\lambda} \\)  
Varianza: \\( \frac{1}{\lambda^2} \\)  
Desviación típica: \\( \sqrt{\frac{1}{\lambda^2}} = \frac{1}{\lambda} = media \\)

\\[ P(X > t) = e^{-\lambda \cdot t} \\]
\\[ F(t) = 1 - e^{-\lambda \cdot t} \\]

Trabajando en R:

```r
q25 <- qexp(25, lambda)
```

El dibujo esperado es una curva decreciente.

#### Observaciones

* La exponencial no tiene memoria
* \\( F_x \\) tiene fórmula:

\\[ F_x = \int_0^x \lambda \cdot e^{-\lambda \cdot t} \\]

#### Ejemplo 1

> Los autobuses que suben a una facultad tienen, en media, una frecuencia de 4 a la hora. Me interesa el tiempo que va a tardar en llegar el siguiente autobús.
>
> a) Analiza la variable
> b) Calcula la probabilidad de que el siguiente llegue antes de 15 minutos
> c) Repito el experimento dos días seguidos, calcula la probabilidad de que al menos uno de esos dos días el autobús llegue antes de 15 minutos

**Apartado A**

\\( X =  \\) tiempo haste el siguiente autobús  
\\( \lambda = 4 \\) (horas)  
Valores: \\( [0, +\infty) \\)

**Nota**: Al dar valor a \\( \lambda \\), estamos fijando las unidades en las que vamos a trabajar, en este caso: horas

Cogeremos los valores entre 0 y \\( m + 3\cdot sd \\), con lo cual necesitaremos calcular ambas propiedades:

\\[ m = \frac{1}{4} \\]
\\[ var = \frac{1}{4^2}; sd = \sqrt{\frac{1}{4^2}} = \frac{1}{4} \\]

Llegaremos hasta: \\( \frac{1}{4} + 3 \cdot \frac{1}{4} = 1 \\)

Vamos a introducirlo en R:

```r
# Definimos valores
val <- seq(0, 1, 0.01)
f_x <- dexp(val, 4)
F_x <- pexp(val, 4)

# Dibujamos
plot(val, f_x, type="l")
plot(val, F_x, type="l")
```

![Variable Aleatoria Contínua 6-1](/uploads/informatica/2/est/variable-aleatoria-continua-6-1.png)
![Variable Aleatoria Contínua 6-2](/uploads/informatica/2/est/variable-aleatoria-continua-6-2.png)

**Apartado B**

La probabilidad de que tarde menos de 15 minutos es que tarde menos de \\( \frac{1}{4} \\), pues estamos trabajando en **horas**.

\\[ P(X < \frac{1}{4}) = P(X \leq \frac{1}{4}) \\]

En R:

```r
p_b <- pexp(1/4, 4) # 0.6321206
```

**Apartado C**

\\[ x_1 = tiempo\ 1^{er}\ día \\]
\\[ x_2 = tiempo\ 2^o\ día \\]

\\[ P_T = P(X_1 < \frac{1}{4} \lor X_2 < \frac{1}{4}) \\]
\\[ P_T = P(X_1 < \frac{1}{4}) + P(X_2 < \frac{1}{4}) - P(X_1 < \frac{1}{4} \land X_2 < \frac{1}{4}) \\]
\\[ P_T = P(X_1 < \frac{1}{4}) + P(X_2 < \frac{1}{4}) - P(X_1 < \frac{1}{4}) \cdot P(X_2 < \frac{1}{4}) \\]

Calcularemos \\( P_T \\) utilizando \\( P(X < \frac{1}{4} \\) que hemos calculado antes en R: `pexp(1/4, 4)`

#### Ejemplo 2

> Un ordenador manda un mensaje de aviso cuando se calienta mucho. Esto ocurre, en media, 4 veces al día. Me interesa el tiempo que pasará antes del siguiente aviso.
> a) Analizar la variable
> b) Calcular la probabilidad de que el próximo aviso se produzca entre 5 y 7 horas
> c) Calcular 2 valores a y b de modo que el tiempo que tarde en avisar esté entre a y b con probabilidad del 90%

**Apartado A**

\\( X =  \\) tiempo hasta el siguiente aviso  
\\( \lambda = \frac{4}{24} \\) (cada hora)  
Valores: \\( [0, +\infty) \\)

\\[ m = sd = \frac{1}{\frac{4}{24}} = 6 \\]

Llegaremos hasta: \\( 6 + 3 \cdot 6 = 24 \\)

Introducimos en R:

```r
val    <- seq(0, 24, 0.1)
lambda <- 4/24
f_x    <- dexp(val, lambda)
F_x    <- pexp(val, lambda)

plot(val, f_x, type="l")
plot(val, F_x, type="l")
```

![Variable Aleatoria Contínua 7-1](/uploads/informatica/2/est/variable-aleatoria-continua-7-1.png)
![Variable Aleatoria Contínua 7-2](/uploads/informatica/2/est/variable-aleatoria-continua-7-2.png)

**Apartado B**

\\[ P(5 < X < 7) = P(5 \leq X \leq 7) = P(X \leq 7) - P(X \leq 5) \\]

```r
pexp(7, lambda) - pexp(5, lambda) # 0.123195
```

**Apartado C**

Necesitamos calcular dos valores que dejan un porcentaje de valores a sus lados, se trata claramente de percentiles. Diremos que \\( a \\) deja a su izquierda un 5% de los datos y que \\( b \\) deja a su derecha otro 5% de los datos.

Calculamos:

```r
a <- qexp(5/100, lambda) # 0.3077598
b <- qexp(95/100, lambda) # 17.97439
```

Vemos entonces que el próximo aviso llegará entre 3 y 18 horas.

### Variable Normal (o de Gauss)

Nos interesa una medida, y nos proporcionan la media y la desviación típica.

Valores: \\( [-\infty, + \infty) \\)  
Probabilidad: \\( \lambda \cdot e^{-\lambda \cdot t} \\)  

Trabajaremos con los valores del rango: \\( [m - 3 \cdot sd, m + 3 \cdot sd] \\)

El dibujo es una campana de Gauss y la función de la curva es:

\\[ f(x) = \frac{1}{\sqrt{2 \cdot \pi} \cdot sd} \cdot e^{-\frac{(x - m)^2}{2 \cdot var}} \\]

Trabajando en R:

```r
q25 <- qnorm(25, m, sd)
```

#### Ejemplo

> La altura de un hombre es una normal con media 1.75 metros y una desviación típica de 0.05
>
> a) Analiza la variable
> b) Probabilidad de medir más de 1.8
> c) Se considera que alguien es muy alto si es del 5% que más miden. ¿A partir de qué medida se considera que alguien es muy alto?

**Apartado A**

\\( X =  \\) altura  
\\( m = 1.75 \\)  
\\( sd = 0.05 \\)  
Valores: \\( [-\infty, +\infty) \\)

Llegaremos desde \\( 1.75 - 3 \cdot 0.05 \\) hasta \\( 1.75 + 3 \cdot 0.05 \\), es decir, entre 1.60 y 1.90 metros.

Introducimos en R:

```r
val <- seq(1.6, 1.9, 0.01)
m   <- 1.75
sd  <- 0.05
f_x <- dnorm(val, m, sd)
F_x <- pnorm(val, m, sd)

plot(val, f_x, type="l")
plot(val, F_x, type="l")
```

![Variable Aleatoria Contínua 8-1](/uploads/informatica/2/est/variable-aleatoria-continua-8-1.png)
![Variable Aleatoria Contínua 8-2](/uploads/informatica/2/est/variable-aleatoria-continua-8-2.png)

**Apartado B**

\\[ P(X > 1.8) = 1 - P(X \leq 1.8) \\]

```r
1 - pnorm(1.8, m, sd) # 0.1586553
```

**Apartado C**

Necesitamos el percentil del 95%

```r
qnorm(0.95, m, sd) # 1.832243
```

#### Propiedades

**Suma**

La suma de variables normales da como resultado una variable normal:

\\[ N(m_1, sd_1) + N(m_2, sd_2) = N(m_1 + m_2, \sqrt{(sd_1)^2 + (sd_2)^2}) \\]

La suma de una variable normal y una constante da como resultado una variable normal:

\\[ N(m_1, sd_1) + k = N(m_1 + k, sd_1) \\]

**Multiplicación**

Una variable normal multiplicada por una constante da como resultado una variable normal:

\\[ N(m, sd) \cdot k = N(m \cdot k, sd \cdot |k|) \\]

#### Ejemplo

> Tengo un ordenador con 3 componentes: A, B y C. Los consumos de esos componentes son normales. Sus consumos son:
>
> \\( X_A = N(100, 5) \\)
> \\( X_B = N(60, 1) \\)
> \\( X_C = N(200, 5) \\)

**Apartado A**

> Me interesa el consumo total del ordenador: \\( X \\). El cual espero que sea \\( 360 \pm 10 \\), ¿cuál es la probabilidad de acertar?

\\[ X = X_A + X_B + X_C \\]
\\[ X = N(100, 5) + N(60, 1) + N(200, 5) = N(360, \sqrt{5^2 + 1^2 + 5^2}) = N(360, \sqrt{51}) \\]

\\[ P(350 < X < 370) = P(X \leq 370) - P(X \leq 350) \\]

```r
pnorm(370, 360, sqrt(51)) - pnorm(350, 360, sqrt(51)) # 0.8385705
```

**Apartado B**

> Nuestro ordenador tiene ahora 2 componentes de tipo A, 1 de tipo B y 3 de tipo C. Nos interesa su consumo actual.
> Calcula dos valores \\( a \\) y \\( b \\) de modo que ese consumo se encuentre entre dichos valores con una seguridad de \\( \frac{999}{1000} \\)

\\[ X = X_A + X_A + X_B + X_C + X_C + X_C = N(860, \sqrt{126}) \\]

Buscamos los percentiles que dejan \\( \frac{2}{1000} \\) antes y después. Es decir:

```r
qnorm(0.0005, 860, sqrt(126)) # a = 823.0639
qnorm(0.9995, 860, sqrt(126)) # b = 896.9361
```

**Apartado C**

> Tengo dos cursos. Hago un examen. Las notas de cada curso son una normal:
>
> Curso 1: \\( N(6, 0.5) \\)
> Curso 2: \\( N(5.5, 1) \\)
>
> Cojo un alumno a suertes de cada grupo. ¿Cuál es la probabilidad de que la nota del alumno del primer curso sea mayor que la del segundo curso?

\\[ P(X_1 > X_2) = P(N(6, 0.5), N(5.5, 1)) \\]
\\[ N(6, 0.5) > N(5.5, 1) \rightarrow N(6, 0.5) - N(5.5, 1) > 0 \\]

Dado que sólo sabemos sumar y multiplicar, primero haremos un pequeño cálculo: \\( -1 \cdot N(5.5, 1) = N(-5.5, 1) \\)

\\[ N(6, 0.5) + N(-5.5, 1) = N(0.5, \sqrt{1.25}) \\]

\\[ P(N(0.5, \sqrt{1.25}) > 0) = 1 - P(N(0.5, \sqrt{1.25}) \leq 0) \\]

```r
1 - pnorm(0, 0.5, sqrt(1.25)) # 0.6726396
```

#### Ejemplo 2

> La altura de las personas de dos países A y B, son variables normales.
>
> \\( X_A = N(1.75, 0.05)  \\)
> \\( X_B = N(1.72, 0.1) \\)
>
> Cojo uno de cada país. ¿Cuál es la probabilidad de que el primer país sea más alto que el segundo?

\\[ P(X_A > X_B) = P(X_A - X_B > 0) \\]
\\[ N(1.75, 0.05) - N(1.72, 0.1) = N(0.03, \sqrt{0.0125}) \\]
\\[ P(N(0.03, \sqrt{0.0125}) > 0) = 1 - P(N(0.03, \sqrt{0.0125}) \leq 0) \\]

```r
1 - pnorm(0, 0.03, sqrt(0.0125)) # 0.6057766
```

#### Tipificación

Hay una normal especialmente sencilla, la normal estándar: \\( N(0, 1) \\), de la cual podemos obtener otras distintas:

\\[ N(m, sd) = N(0, 1) * sd + m \\]

Y al contrario también:

\\[ N(0, 1) = \frac{N(m, sd) - m}{sd} \\]

Este proceso se denomina tipificación.

**Observaciones**

\\( sd = 0 \\) es una constante

Cuanto mayor sea \\( sd \\), mayor será la oscilación de los valores.

En programación usaremos una normal cuando:

* Queremos oscilación
* Queremos que los valores se parezcan a un valor m
* Quiero controlar cuánto oscilan los valores

#### Ejemplo

> Tengo unos datos que pienso que son de una normal, y quiero calcular la media y la desviación típica.
>
> Se sabe que esos datos pasan de 100 en una determinada proporción: \\( \frac{1}{10} \\)
> Se sabe que esos datos pasan de 200 en otra determinada proporción: \\( \frac{1}{1000} \\)

\\[ X = N(m, s) \\]

Podemos traducir esos datos a:

\\[ P(X > 100) = \frac{1}{10} \\]
\\[ P(X > 200) = \frac{1}{1000} \\]

Si tipificamos:

\\[ P(\frac{x - m}{s} > \frac{100 - m}{s}) = \frac{1}{10} \\]

Sabemos que la primera parte, \\( \frac{X - m}{s} \\), es \\( N(0, 1) \\). Y nos deja a un lado \\( \frac{9}{10} \\) y al otro \\( \frac{1}{10} \\). Por tanto el dato que buscamos es el percentil del 90% de \\( N(0, 1) \\).

```r
qnorm(0.9, 0, 1) # 1.281552
```

Y para el segundo dato, repetimos los mismos pasos:

\\[ P(\frac{x - m}{s} > \frac{200 - m}{s}) = \frac{1}{1000} \\]

Sabemos que la primera parte, \\( \frac{X - m}{s} \\), es \\( N(0, 1) \\).

El dato que buscamos es el percentil del \\( \frac{999}{1000} \\) de \\( N(0, 1) \\):

```r
qnorm(999/1000, 0, 1) # 3.090232
```

Si reemplazamos en las ecuaciones:

\\[ m + 1.28 \cdot s = 100 \\]
\\[ m + 3.09 \cdot s = 200 \\]

Y despejando:

\\[ s = \frac{100}{1.81} \\]

\\[ m = 200 - 3.09 \cdot \frac{100}{1.81} \\]
