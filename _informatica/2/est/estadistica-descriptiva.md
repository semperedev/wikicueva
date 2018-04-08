---
title: Estadística Descriptiva
---

* Tabla de Contenidos
{:toc}

## Variable Estadística

Definimos una variable estadística como una de las características o rasgos de los individuos que queremos estudiar. Las variables toman valores de un conjunto llamado *Dominio de la Variable*.

Podemos clasificar las variables de la siguiente forma:

* Cuantitativas: toman valores numéricos
  * Discretas: valores aislados, es decir, números naturales y enteros
  * Contínuas: puede tomar cualquier valor numérico
* Cualitativas: toman valores *no* numéricos
  * Ordinales: se pueden ordenar
  * Nominales: no se pueden ordenar

#### Intervalos de Clase

Cuando el conjunto de valores que puede tomar una variable cuantitativa es muy grande, agruparemos los datos en intervalos de clase, que deben:

* Cubrir todos los valores del dominio
* Ser disjuntos, es decir, semiabiertos por uno de los dos lados (normalmente el derecho)

## Tabla estadística

Una tabla estadística nos permite representar la distribución de una variable. Para formarla necesitaremos completar los siguientes campos:

#### Valor y Frecuencia Absoluta

La primera columna de la tabla son los valores que puede recibir la variable, representado como \\( x_i \\), y la segunda columna es la cantidad de veces que se repite cada valor, (\\( n_i \\)).

Indicaremos el número total de datos como \\( n \\).

#### Frecuencia Relativa

Cada celda de la frecuencia relativa se puede calcular dividiendo el valor de la frecuencia absoluta de su fila entre el número total de datos. Es decir:

\\[ f_i = \frac{n_i}{n} \\]

#### Frecuencias Acumuladas

Podemos agregar dos columnas más. La primera es la Frecuencia Absoluta Acumulada, que podemos calcular como la suma de las frecuencias absolutas anteriores:

\\[ N_i = \sum_{k = 0}^i n_k\\]

ó bien

\\[ N_i = N_{i - 1} + n_i \\]

Y por último, la Frecuencia Relativa Acumulada, que podemos calcular de dos formas; o bien sumando las frecuencias relativas anteriores:

\\[ F_i = F_{i - 1} + f_i \\]

o bien calculando cada celda utilizando la frecuencia absoluta acumulada:

\\[ F_i = \frac{N_i}{n} \\]

### Ejemplo

Tenemos una variable \\( x \\) que toma los valores de 1 a 6, y cada uno de ellos se repite las siguientes veces: 8, 6, 24, 40, 30, 12

Con esta información ya podemos crear la tabla:

Valor \\( x_i \\) | F. Absoluta \\( n_i \\)  | F. Abs. Acumulada \\( N_i \\) | F. Relativa \\( f_i \\) | F. Rel. Acumulada \\( F_i \\)
:---:|:---:|:---:|:---:|:---:
1 |  8 |       8 | 0.67 | 0.6667
2 |  6 |      14 | 0.05 | 0.1167
3 | 24 |      38 | 0.20 | 0.3167
4 | 40 |      78 | 0.33 | 0.6500
5 | 30 |     108 | 0.25 | 0.9000
6 | 12 | **120** | 0.10 |  **1**

Como podemos observar, la última celda de la frecuencia absoluta acumulada es siempre el número de datos, \\( n \\). Del mismo modo, la última celda de la frecuencia relativa acumulada siempre es 1.

### Trabajando con RStudio

Los valores y las frecuencias absolutas los introducimos como una colección de repeticiones:

```r
         # Valores       # Repeticiones
x <- rep(c(1,2,3,4,5,6), c(8,6,24,40,30,12))
```

Calculamos las propiedades de la variable:

```r
n_i <- table(x)
f_i <- n_i / length(x)

N_i <- cumsum(n_i)
F_i <- cumsum(f_i)
```

Y por último creamos la tabla:

```r
tabla <- cbind(n_i, N_i, f_i, F_i)
```

![Tabla Estadística Descriptiva](/uploads/informatica/2/est/descriptiva-tabla-1.png)
