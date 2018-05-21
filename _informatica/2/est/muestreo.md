---
title: Muestreo
---

[&lt;&lt; Volver a **Estadística**](../est.md)

* Tabla de Contenidos
{:toc}

## Introducción

Tengo unos datos pero no los conozco todos, sino unos pocos.

#### Terminología

* **Población**: todos los datos
* **Muestra**: datos de los que dispongo

> No conozco toda la población sino sólo la muestra

#### El problema

Me interesa un dato de esa población: la media, la desviación típica, una probabilidad... Si no puedo calcularlo, lo calcularé sólo para la muestra.

**Me interesa**

\\( m \\) = media de la población (parámetro)

**Puedo calcular**

\\( \bar{x} \\) = media de la muestra (estimador o estadístico)

> Supondremos que la muestra está elegida de forma imparcial

#### Observaciones

1. \\( m \\) es un número
2. \\( \bar{x} \\) varía dependiendo de la muestra
3. El rango entre dos valores \\( a \\) y \\( b \\) de modo que \\( \bar{x} \\) esté entre ellos, con seguridad del \\( k \\)%, se llama intervalo de confianza con seguridad del \\( k \\)%
4. \\( \bar{x} \\) es más preciso que \\( x \\). Muchos datos son más precisos que uno sólo

## Si los datos vienen de una normal

Conocemos \\( sd \\) y solamente nos falta calcular \\( m \\)

\\[ m + \frac{sd}{\sqrt{n}} \cdot N(0, 1) = \bar{x} \\]

Es decir:

* \\( m \\) y \\( \bar{x} \\) se parecen
* El error entre ellos es \\( \frac{sd}{\sqrt{n}} \cdot N(0, 1) \\)
* Puede ser positivo o negativo
* Cuantos más datos tenga, menor será el error

#### Ejemplo

> Me interesa la media de altura de una población, y sé que su desviación típica es 0.05. Cojo 100 personas, las mido y me sale que su media de altura es 1.75 metros.  
> Pienso que la media estará entre 1.7 y 1.8
>
> a) Probabilidad de acertar  
> b) Calcular dos valores, \\( a \\) y \\( b \\), de modo que \\( m \\) esté entre ellos, con una probabilidad del 90%

\\[ 1.75 = m + \frac{0.05}{\sqrt{100}} \cdot N(0, 1) \\]
\\[ m = 1.75 - 0.005 \cdot N(0, 1) \\]

Hacemos un par de cálculos:

\\[ N(0,1 ) \cdot -0.005 + 1.75 = N(0, 0.005) + 1.75 = N(1.75, 0.005) \\]

**Apartado A**

La probabilidad que buscamos es:

\\[ P(1.7 \leq m \leq 1.8) = P(N(1.75, 0.005) \leq 1.8) - P(N(1.75, 0.005) \leq 1.7) \\]

```r
pnorm(1.8, 1.75, 0.005) - pnorm(1.7, 1.75, 0.005)
```

**Apartado B**

Buscamos dos números, \\( a \\) y \\( b \\), que son los percentiles del 5% y del 95% respectivamente.

```r
qnorm(5/100, 1.75, 0.005) # a
qnorm(95/100, 1.75, 0.005) # b
```

#### Ejemplo 2

> Hay una empresa que vende ordenadores y el comsuno dice la empresa que es una normal N(100, 1). Se comparan 20 ordenadores de esa marca. Me interesa, en media, que consumen esos 100 ordenadores.  
> Pienso que la media estará entre 99 y 101
>
> a) Probabilidad de acertar  
> b) Calcular dos valores, a y b, de modo qe m esté entre ellos, con una seguridad del 99%

\\[ \bar{x} = 100 + \frac{1}{\sqrt{20}} \cdot N(0, 1) = N \left \(100, \frac{1}{\sqrt{20}} \right \) \\]

**Apartado A**

\\[
  P(99 \leq \bar{x} \leq 101) =
  P \Big \(99 \leq N \left \(100, \frac{1}{\sqrt{20}} \right \) \Big \) =
  P \Big \(N \left \(100, \frac{1}{\sqrt{20}} \right \) \leq 101 \Big \) - P \Big \(N \left \(100, \frac{1}{\sqrt{20}} \right \) \leq 99 \Big \)
\\]

```r
pnorm(101, 100, 1/sqrt(20)) - pnorm(99, 100, 1/sqrt(20))
```

**Apartado B**

De nuevo, tenemos que calcular percentiles:

* a = 0.5%
* b = 99.5%

```r
qnorm(0.5/100, 100, 1/sqrt(20)) # a
qnorm(99.5/100, 100, 1/sqrt(20)) # b
```

## Teorema central del límite

```r
f <- function(n) {
  return(sum(runif(n, 0, 1)))
}

dat <- c()

for (i in 1:10000) {
  dat <- c(dat, f(10))
}

hist(dat)
```

> Tengo una variable X, de la que me interesan su media y su desviación típica.

Cojo \\( n \\) datos: \\( x_1, x_2, ..., x_n \\)

\\[ x_1 + x_2 + ... + x_n \simeq N(n \cdot m, \sqrt{n \cdot sd^2})  \\]
\\[ \bar{x} = \frac{x_1 + x_2 + ... + x_n}{n} \simeq N \left \(m, \frac{sd}{\sqrt{n}} \right \) \\]

> Siempre que \\( n > 30 \\)

#### Ejemplo

> Me interesa el tiempo que tarda en arrancar el ordenador. El fabricante me dice que la desviación típica es 1. Arranco 50 veces, voy apuntando los tiempos de arranque y calculo su media: \\( \bar{x} = 15 \\)
>
> a) Probabilidad de que la media esté entre 14 y 16  
> b) Calcula un intervalo de confianza con seguridad del 80%

Aplicando la fórmula de la normal y el teorema central del límite:

\\[ 15 \simeq m + \frac{1}{\sqrt{50}} \cdot N(0, 1) \\]
\\[ m = N \left \(15, \frac{1}{\sqrt{50}} \right \) \\]

**Apartado A**

\\[
  P \Big \(14 \leq N \left \(15, \frac{1}{\sqrt{50}} \right \) \leq 16 \Big \) =
  P \Big \(N \left \(15, \frac{1}{\sqrt{50}} \right \) \leq 16 \Big \) -
  P \Big \(N \left \(15, \frac{1}{\sqrt{50}} \right \) \leq 14 \Big \)
\\]

```r
pnorm(16, 15, 1/sqrt(50)) - pnorm(14, 15, 1/sqrt(50))
```

**Apartado B**

Buscamos los percentiles del 10% y del 90%:

```r
qnorm(10/100, 15, 1/sqrt(50)) # a
qnorm(90/100, 15, 1/sqrt(50)) # b
```

## Test de Hipótesis

Tengo unos datos y estoy interesado en su media, \\( m \\). Me dan un cierto valor para dicha \\( m \\), ¿puedo saber si está bien o no?

Planteamos dos hipótesis:

* \\( H_0 \\): \\( m \\) está bien
* \\( H_1 \\): \\( m \\) está mal

Y realizamos el siguiente proceso:

1. Cojo unos cuantos datos
2. Elijo un valor que me indique la seguridad que quiero tener
3. Usando esos datos, puedo calcular \\( a \\) y \\( b \\) de modo que \\( m \\) debe estar entre dichos valores con esa seguridad

Si el valor que me han dado está entre \\( a \\) y \\( b \\), considero que es correcto.

#### Ejemplo

> Compro una GPU de la que me dicen que el tiempo medio de renderizado de una escena 3D es 1 segundo con desviación típica de 0.1
>
> Pruebo 30 veces esa GPU, apunto lo que tarda cada vez y calculo su media: 1.2
>
> ¿El valor que nos han proporcionado es correcto con seguridad del 80%? ¿Entre qué valores debería estar \\( m \\)?

Aplicando la fórmula:

\\[ \bar{x} = m + \frac{sd}{\sqrt{n}} \cdot N(0, 1) \\]

\\[ 1.2 = m + \frac{0.1}{\sqrt{30}} \cdot N(0, 1) \\]

\\[ m = 1.2 - \frac{0.1}{\sqrt{30}} \cdot N(0, 1) = N \left \(1.2, \frac{0.1}{\sqrt{30}} \right \) \\]

Ahora obtenemos los valores de \\( a \\) y \\( b \\):

```r
qnorm(10/100, 1.2, 0.1/sqrt(30)) # a
qnorm(90/100, 1.2, 0.1/sqrt(30)) # b
```

Si el valor de \\( m \\) no se encuentra en el intervalo, no es correcto y hemos sido engañados.

#### Ejemplo 2

> Me interesa la altura media de los españoles. Me dicen que es 1.75m son desviación típica 0.05
>
> Cogemos 100 personas a suertes y calculamos su media. Obtenemos 1.74 metros. ¿Es correcto el valor que nos proporcionaban con una seguridad del 90%?

\\[ \bar{x} = m + \frac{sd}{\sqrt{n}} \cdot N(0, 1) \\]

\\[ 1.74 = m + \frac{0.05}{\sqrt{100}} \cdot N(0, 1) \\]

\\[ m = 1.74 - \frac{0.05}{\sqrt{100}} \cdot N(0, 1) = N \left \(1.74, \frac{0.05}{\sqrt{100}} \right \) \\]

Y obtenemos \\( a \\) y \\( b \\)

```r
qnorm(5/100, 1.74, 0.05/sqrt(100)) # a
qnorm(95/100, 1.74, 0.05/sqrt(100)) # b
```

Supondremos que el resultado es incorrecto si el valor de \\( m \\) no se encuentra en el intervalo.

### Observaciones

1. En la vida real, es bastante habitual no fiarse de la desviación típica.
2. Si el test está bien, es decir, si \\( m \\) está en el intervalo, no tenemos la certeza de que sea correcta, sino que no disponemos de datos que nos indiquen que es incorrecta.
