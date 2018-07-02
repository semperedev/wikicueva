---
title: Corriente Alterna
---

## Conceptos básicos

Las resistencias se llaman impedancias y se designan con la \\(Z\\).

## Bobinas

Se comportan como resistencias. Podemos calcular su reactancia (\\(X_L\\)) utilizando la siguiente fórmula:

\\[ X_L = 2 \pi f L \\]

Siendo \\(L\\) la inductancia de la bobina y \\(f\\) la frecuencia de la corriente alterna.

> A mayor frecuencia, mayor valor de resistencia.

## Condensadores

Se comportan como resistencias, y podemos calcular su reactancia:

\\[ X_C = \frac{1}{2 \pi f C} \\]

Siendo \\(C\\) la capacidad del condensador y \\(f\\) la frecuencia de la corriente alterna.

> A mayor frecuencia, menor valor de resistencia.

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
