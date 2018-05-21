---
title: Variable Aleatoria Discreta
---

[&lt;&lt; Volver a **Estadística**](../est.md)

* Tabla de Contenidos
{:toc}

## Variable Aleatoria Discreta

Estudiamos un experimento aleatorio, y para cada resultado me quedo con una característica que sea un número entero.

De los resultados siempre debo conocer:

```r
val  <- c(-1,   0,   2)  # Posibles valores
prob <- c(2/6, 3/6, 1/6) # Probabilidades de cada elemento

plot(val, prob, type="l")
```

![Variable Aleatoria Discreta: lineal](/uploads/informatica/2/est/variable-aleatoria-discreta-1.png)

Una vez que los tengamos, podemos calcular ciertas propiedades:

```r
media          <- sum(val * prob)
varianza       <- sum(((val - media) ** 2) * prob)
desv_tipica    <- sqrt(varianza)
prob_acumulada <- cumsum(prob)

# Representamos con gráfica escalonada
plot(val, prob_acumulada, type="s")
```

![Variable Aleatoria Discreta: escalonada](/uploads/informatica/2/est/variable-aleatoria-discreta-2.png)

## Variables Notables

Vamos a ver cinco variables notables. En la primera de ellas, todos los sucesos tienen la misma probabilidad. En las otras cuatro hay un suceso que nos interesa y conocemos su probabilidad:

* Me interesa solamente si se da o no
* ¿Cuántos intentos tienen que darse para que ocurra ese suceso?
* Si lo hago varias veces, ¿cuántas veces ocurre ese suceso?
* No conozco la probabilidad y me interesa cuántas veces ocurre ese suceso

#### Trabajando en RStudio

Podemos declarar las variables notables con el siguiente formato:

```
Ctipo(val, ...args)
```

Siendo ```C``` una de las siguientes constantes:

* ```d```: Calcular probabilidades: \\( P(x = y) \\)
* ```p```: Función de distribución: \\( P(x \leq y) \\)
* ```q```: Percentiles expresados entre 0 y 1: `porcentaje/100`
* ```r```: Funcionar como un *random*

Y los parámetros:

* ```val```: valores que proporcionamos
* ```args```: propiedades necesarias para definir la variable

Por ejemplo:

```r
# Binomial
prob <- dbinom(val, n, p)      # Función de probabilidad para B(n, p)

# Poisson
perc <- qpois(23/100, lambda)  # Percentil del 23% para P(lambda)

# Geométrica
F_x <- pgeom(val, p)           # Función de distribución para G(p)
```

### Uniforme

Número de valores finito y todos con la misma probabilidad.

#### Ejemplo

> Tiro un dado y me interesa el número que sale.

```r
n <- 6

val  <- 1:n
prob <- rep(1/n, n)

m   <- sum(val * prob)       # Media aritmética
var <- sum((val-m)^2 * prob) # Varianza
sd  <- sqrt(var)             # Desviación típica

plot(val, prob)               # El dibujo es plano
```

![Variables Notables: Uniforme](/uploads/informatica/2/est/variable-notable-uniforme-1.png)

### Bernouilli

Hay un suceso que me interesa y conozco su probabilidad \\( p \\). Se trata de una variable booleana:

```r
# P es la probabilidad conocida

# 0: no se cumple
# 1: se cumple

val  <- c(0, 1)
prob <- c(1 - P, P)

m   <- P
var <- P * (1 - P)
```

#### Ejemplo

> La probabilidad de que funcione un USB es del 80%

Podemos definir la x como:

* Funciona: 1
* No funciona: 0

\\( Valores = \{0, 1\} \\)  
\\( Probabilidades = \{0.2, 0.8\} \\)

Y podemos calcular:

\\( media = 0.8 \\)  
\\( varianza = 0.2 \cdot 0.8 = 0.16 \\)  
\\( desviación\ típica = \sqrt{0.16} = 0.4 \\)

### Binomial

Si el mismo experimento lo hacemos \\( n \\) veces, tenemos que \\( x \\) es el número de veces que ocurre el suceso que me interesa.

Escrito matemáticamente: \\( x = B(n, p) \\), es decir, \\( x \\) es una variable Binomial, con \\( n \\) sucesos y \\( p \\) la probabilidad dada.

El histograma esperado es una campana de Gauss, cuyo máximo se da en la media.

```r
val  <- 0:n
prob <- dbinom(val, n, p)

m   <- n * p
var <- n * p * (1 - p)

FX  <- pbinom(val, n, p)
```

#### Ejemplo

> La probabilidad de que un USB falle es del 20%. Tengo 5000 USBs. Me interesa el número de los que fallan.

Pasos a seguir:

1. Analiza la variable
2. Calcula \\( m - sd \\) y \\( m + sd \\)
3. Calcula \\( P(x \geq m + sd) \\)
4. Calcula \\( P(m - sd \leq x \leq m + sd) \\)
5. Encuentra un intervalo donde creas que está \\( x \\)

```r
# 1.- Analizamos la variable
n <- 5000
p <- 0.2

val  <- 0:n
prob <- dbinom(val, n, p)

m  <- n * p
va <- n*p*(1-p)
sd <- sqrt(va)

## La dibujamos
plot(val, prob, type="l")
```

![Variables Notables: Binomial](/uploads/informatica/2/est/variable-notable-binom-1.png)

```r
# 2.- Calculamos m-sd y m+sd
m - sd # 971.7157
m + sd # 1028.284

# 3.- Calculamos P(x >= m + sd) = P(x > 1028) = 1 - P(x <= 1028)
1 - pbinom(1028, n, p)

# 4.- Calculamos P(m - sd <= x <= m + sd) = P(971 < x <= 1028) = P(x <= 1028) - P(x <= 971)
pbinom(1028, n, p) - pbinom(971, n, p)
```

Para el último paso tenemos que encontrar dos números, \\( a \\) y \\( b \\), que dejan entre ellos el porcentaje de aciertos con seguridad (si no nos indican ningún valor, utilizaremos el 95%).

Haremos uso de percentiles: \\( a \\) es un percentil del 2.5% y \\( b \\) es el percentil del 97.5%

```r
# 5 .- Ajustamos mejor el intervalo
a <- qbinom(2.5/100, n, p)

b <- qbinom(97.5/100, n, p)
```

A la vista de los resultados, vemos claramente que los USBs rotos se encuentran en el rango \\( [921, 1055] \\).

> Nota: si la cantidad se sale de este rango, muy posiblemente nos estén engañando, e incluso se podría calcular la probabilidad de que esto esté sucediendo.

### Poisson

**No conocemos la probabilidad** de que se dé un suceso, pero nos interesa la cantidad de veces que ocurre.

Deben darse las siguientes condiciones:

* Conocemos, en media, cuántas veces ocurre ese suceso en un intervalo de tiempo (representado con \\( \lambda \\))
* La media es escalable (doble de intervalos = doble de casos)

\\( Valores = [0, +\infty) \\)

Escrito matemáticamente: \\( x = P(\lambda) \\), es decir, \\( x \\) es una variable de Poisson, siendo \\( \lambda \\) la media dada.

El histograma esperado es una campana de Gauss, cuyo máximo se da en la media.

```r
# lambda es el valor de la media

val  <- 0:Inf
prob <- dpois(val, lambda)

media    <- lambda
varianza <- lambda
```

#### Ejemplo

> En un sistema de atención al público, llegan, en media, 80 USBs rotos al mes. Nos interesa la cantidad de USBs rotos el próximo mes, con una seguridad del 90%.

Pasos a seguir:

1. Analiza la variable
2. Calcula \\( m - sd \\) y \\( m + sd \\)
3. Calcula \\( P(m - sd \leq x \leq m + sd) \\)
4. Encuentra un intervalo donde creas que está \\( x \\)

Como es lógico, no podemos trabajar con un intervalo de cero a infinito, por lo cual estableceremos el intervalo de estudio:

Sabemos que \\( m = 80 \\), \\( var = 80 \\) y por tanto, \\( sd = \sqrt{80} \approx 9 \\). Trabajaremos con el intervalo \\( [0, m + 2\cdot sd] \\), es decir, \\( [0, 98] \\)

```r
l = 80

val  <- 0:98
prob <- dpois(val, l)

plot(val, prob, type="l")
```

![Variables Notables: Poisson](/uploads/informatica/2/est/variable-notable-poisson-1.png)

Al realizar el dibujo, podemos ver claramente que hemos cortado muy pronto, por lo que aumentamos el intervalo hasta \\( [0, m + 3 \cdot sd] \\):

```r
l = 80

val  <- 0:107
prob <- dpois(val, l)

plot(val, prob, type="l")
```

![Variables Notables: Poisson](/uploads/informatica/2/est/variable-notable-poisson-2.png)

Ahora podemos continuar con el ejercicio:

```r
# 3.- Calcular P(71 <= x <= 89) = P(x <= 89) - P(x <= 70)
ppois(89, l) - ppois(70, l)

# 4 .- Ajustamos mejor el intervalo
a <- qpois(0.25 / 100, l)
b <- qpois(97.25 / 100, l)
```

#### Nota

Binomial y Poisson sirven para contar, por tanto el dibujo es el mismo.

> Si conozco la probabilidad del suceso, se trata de binomial, en caso contrario, de Poisson.

### Geométrica

Repetimos un experimento hasta que ocurra un suceso que queremos estudiar, y nos interesa la cantidad de fallos hasta dicho suceso. Si la probabilidad del suceso no varía con el tiempo, se trata de una variable geométrica.

\\( Valores = [0, +\infty) \\)

Escrito matemáticamente: \\( x = G(p) \\), es decir, \\( x \\) es una variable Geométrica, y \\( p \\) es la probabilidad del suceso.

\\( media = \frac{1\ -\ p}{p} \\)  
\\( varianza = \frac{1\ -\ p}{p^2} \\)

El histograma esperado es una curva decreciente con asíntota en el eje X.

**Observación**: *la geométrica no tiene memoria*. Como \\( p \\) no depende del tiempo, la probabilidad de un suceso después de muchos fallos, es la misma que al comenzar.

```r
val  <- 0:Inf
prob <- dgeom(val, p)

media    <- (1 - p) / p
varianza <- (1 - p) / p**2
```

## Elegir el tipo de variable

Nos realizaremos una serie de preguntas para ir descartando opciones.

* ¿Tiene sólo dos valores? \\( \leftarrow \\) Bernouilli
* ¿Todos los valores tienen igual probabilidad? \\( \leftarrow \\) Uniforme
* ¿Tengo que esperar? \\( \leftarrow \\) Geométrica

Si tengo que contar:

*¿Binomial o Poisson?*

Si nos dan la media y la varianza, y ambas son iguales: es una Poisson.

* Si nos dan la probabilidad \\( \leftarrow \\) Binomial
* Si nos dan la media \\( \leftarrow \\) Poisson

* Si el valor máximo está definido \\( \leftarrow \\) Binomial
* Si no lo está \\( \leftarrow \\) Poisson

#### Ejemplos

> Me interesa si un disco duro presenta problemas.

Sólo hay dos valores posibles: o funciona, o no funciona. Es por tanto una **Bernouilli**.

> Lanzo un dado y me interesa el resultado.

Hay más de dos valores, pero sus probabilidades son iguales, se trata entonces de una **uniforme**.

> Elijo un elemento de una lista y me interesa qué elemento ha salido

Son más de dos valores y todos tienen la misma probabilidad de salir, es por tanto **uniforme**.

> El 20% de los trabajadores de una empresa irá a una huelga. Se seleccionan 5 trabajadores de dicha empresa. Nos interesa el número de asistencia a la huelga entre los 5 seleccionados.

Hay más de dos valores, sus probabilidades no son iguales y nos piden que contemos, por tanto tenemos que elegir entre binomial y Poisson.

Como conozco la probabilidad de ir a la huelga y hay un valor "tope" definido, se trata claramente de una **binomial**.

> Se realiza un examen tipo test de diez preguntas, teniendo en cuenta que cada pregunta tiene cuatro respuestas, y sólo una es correcta. Nos interesa la probabilidad de acertar al menos la mitad respondiendo aleatoriamente.

Hay más de dos valores y sus probabilidades no son iguales. Nos piden que contemos y el valor "tope" está claro, por ello es una **binomial**.

> El número medio de accidentes ocurridos en una planta petrolera es de 2 accidentes en 2 meses. Nos interesa el número de accidentes ocurridos en los próximos dos meses.

Hay más de dos valores, tengo que contar y no conozco la probabilidad. Como nos dan la media se trata de una **Poisson**.

## Ejercicios Resueltos

### Ejercicio 1

> En una biblioteca se cuenta el número de estudiantes que entran por turno y se observa que los posibles valores van de 2 a 15 con frecuencias inversamente proporcionales a esos números, es decir, \\( P(X = i) = \frac{k}{i} \\), para \\( i = 2, 3, \cdot \cdot \cdot, 15 \\). Se pide:

#### Apartado A

> Calcula \\( k \\)

Sabemos que los valores van de 2 a 15, y la suma de las probabilidades es siempre la unidad, por tanto:

\\[ \frac{k}{2} + \frac{k}{3} + \cdot \cdot \cdot + \frac{k}{15} = 1 \\]

```r
val  <- 2:15
prob <- 1/val

suma <- sum(prob)
k    <- 1 / suma
```

#### Apartado B

> Analiza la Variable: valores, funciones de probabilidad, distribución, media y desviación típica

```r
prob     <- k * prob # Obtenemos las probabilidades reales
media    <- sum(val * prob)
varianza <- sum(((val - media) ** 2) * prob)
sd       <- sqrt(varianza)
F_x      <- cumsum(prob)

# Podemos dibujar las funciones usando plot
plot(val, prob, type="l")
plot(val, F_x,  type="s")
```

### Ejercicio 2

> La consulta de un médico recibe 150 pacientes al día. Se sabe que la proporción de pacientes con enfermedades graves es del 4%. Un día se considera bueno si es del 55% de los días en los que el número de pacientes graves atendidos es menor y se considera malo si es del 10% de los días en que se atienden a más pacientes graves. Si el día no es ni bueno ni malo, se considera estándar.

#### Apartado A

> ¿Entre qué valores debe estar el número de pacientes con enfermedades graves atendidos en un día para que se considere estándar?

Recopilando los datos:

* 150 pacientes/día
* Proporción enfermos graves: 4%

Nos piden el número de pacientes graves, tenemos que contar y nos dan una probabilidad, se trata de una variable **binomial**.

Si posicionamos los tipos de días, vemos que:

* 05% son buenos
* 85% son estándar
* 10% son malos

Lo que nos piden son las cantidades que separan los tipos, con lo cual tenemos que calcular los **percentiles** de la variable:

\\[ X = Nº\ de\ pacientes\ graves = Binomial \left \(150, \frac{4}{100} \right \) \\]

```r
percentil_a <- qbinom(5/100, 150, 4/100)
percentil_b <- qbinom(90/100, 150, 4/100)
```

#### Apartado B

> ¿Cuál es la probabilidad de que el número de días malos en un mes sea mayor que 5?. ¿Cuántos días malos esperamos que haya al mes?

De nuevo, se trata de una binomial.

\\[ Y = Nº\ días\ malos = Binomial \left \(30, \frac{10}{100} \right \) \\]

Y nos piden la siguiente probabilidad:

\\[ P(Y \gt 5) = 1 - P(Y \leq 5 ) \\]

```r
p = 1 - pbinom(5, 30, 10/100)
```

Como la probabilidad es del 10% y tenemos un mes (30 días), esperamos:

\\[ 10\% \cdot 30 = 3\ días\ malos \\]

#### Apartado C

> ¿Cuál es la probabilidad de que pase una semana antes de que haya un día bueno?

\\[ Z = Nº\ días\ antes\ de\ que\ haya\ uno\ bueno = Geométrica \left \(\frac{5}{100} \right \) \\]

Calculamos la probabilidad:

\\[ P(Z \geq 7) = P(Z \gt 6) = 1 - P(Z \leq 6) \\]

```r
p = 1 - pgeom(6, 5/100)
```
