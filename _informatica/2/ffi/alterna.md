---
title: Corriente Alterna
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Conceptos básicos

La corriente alterna se define con una frecuencia \\(f\\) (o un periodo \\(T = \frac{1}{f})\\) y un valor de tensión \\(V_p\\).

Las resistencias se llaman impedancias y se designan con la \\(Z\\).

### Tensión

Dada una función de tensión alterna, el valor pico, \\(V_p\\), es la distancia entre el pico de la onda y el eje X.

\\( \begin{align}
  V_{pico\\ pico} = 2 \cdot V_{p}
\end{align} \\)

\\( \begin{align}
  V_{eficaz} = \frac{V_p}{\sqrt{2}}
\end{align} \\)

### Expresión sobre el tiempo

\\( \begin{align}
  \omega = 2 \pi f
\end{align} \\)

\\( \begin{align}
  V(t) = V_p \cdot \sin \left( \omega t + \varphi \right)
\end{align} \\)

### Impedancia

\\[ Z = R + (X_L - X_C)j \\]

### Convenios

Salvo que se especifique de otra forma:

* La tensión de una fuente se proporciona en voltios pico (\\(V_p\\))
* La tensión y la corriente se expresan en forma fasorial (polar)
* La impedancia se expresa en forma binómica (rectangular)

## Bobinas

A tiempo cero, es decir, nada más conectar la bobina, la reactancia es 0: se comporta como un cable.

Se comportan como resistencias. Podemos calcular su reactancia (\\(X_L\\)) utilizando la siguiente fórmula:

\\[ X_L = 2 \pi f L \\]

Siendo \\(L\\) la inductancia de la bobina y \\(f\\) la frecuencia de la corriente alterna.

**Impedancia**

Multiplicamos la reactancia por \\(j\\)

\\[ Z_L = 2 \pi f L j \\]

**Energía almacenada**

\\[ E = \frac{1}{2} \cdot L \cdot I^2 \\]

### Desfase

Las bobinas provocan un desfase en la corriente de -90º.

## Condensadores

A tiempo cero, es decir, nada más conectar el condensador, la reactancia es 0: se comporta como un cable.

Se comportan como resistencias, y podemos calcular su reactancia:

\\[ X_C = \frac{1}{2 \pi f C} \\]

Siendo \\(C\\) la capacidad del condensador y \\(f\\) la frecuencia de la corriente alterna.

**Impedancia**

Multiplicamos la reactancia por \\(-j\\)

\\[ Z_C = \frac{-j}{2 \pi f C} \\]

### Desfase

Los condensadores provocan un desfase en la corriente de 90º.

## Circuitos RLC

### En serie (**sin** fasores)

Dado un circuito con la siguiente forma:

![Circuito RLC](/uploads/informatica/2/ffi/circuito-rlc.png)

Podemos calcular la resistencia equivalente:

\\[ X = X_L - X_C \\]

\\[ R_T = \sqrt{R^2 + (X_L - X_C)^2} \\]

Y el desfase de la corriente respecto a la tensión:

\\[ \varphi = \arctan\left(\frac{X_L - X_C}{R}\right) \\]

Si \\(\varphi < 0\\), el circuito es capacitivo: los condensadores prevalece

Si \\(\varphi > 0\\), el circuito es inductivo: las bobinas prevalecen

### Resonancia

La frecuencia de resonancia se puede obtener despejando \\(f\\) de la igualación \\(X_L = X_C\\):

\\[ f = \frac{1}{2 \pi \sqrt{R C}} \\]

\\[ \omega = \frac 1 \sqrt{RC} \\]

## Potencia

#### Potencia activa

\\[ P = I \cdot V \cos \varphi \\]

#### Potencia reactiva

\\[ Q = I \cdot V \sin \varphi \\]

#### Potencia aparente

Es la suma de las dos anteriores.

\\[ S = IV \\]
