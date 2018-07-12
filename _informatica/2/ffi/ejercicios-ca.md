---
title: Ejercicios Resueltos - Corriente Alterna
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Elementos de Alterna

### Ejercicio 6

> Si a una frecuencia de \\(2 kHz\\) la reactancia de una bobina de \\(100 \Omega \\), ¿cuánto vale su autoinducción?

Sabemos que \\( X_L = 2 \pi f L \\)

Si despejamos \\(L\\) nos queda:

\\[
  L = \frac{X_L}{2 \pi f} =
  \frac{100}{2 \pi \cdot 2 \cdot 10^3} = 8\\ \text{mH}
\\]

### Ejercicio 9

> Un condensador de \\(10 \mu F\\) presenta en un circuito \\(100 \Omega\\) de reactancia. ¿Cuál es la frecuencia de funcionamiento?

Solamente tenemos que despejar \\(f\\) de la fórmula de la reactancia de un condensador:

\\[ X_C = \frac{1}{2 \pi f C} \\]

\\[ f = \frac{1}{2 \pi \cdot C \cdot X_C} = \frac{1}{2 \pi \cdot 100 \cdot 10^{-7}} = 159.15\\ \text{Hz} \\]

### Ejercicio 3

> Calcular las energías almacenadas en el condensador y la bobina
>
> ![Ejercicio 3](/uploads/informatica/2/ffi/ejercicios-ca/3.png)

Daremos por hecho que nos encontramos en el régimen de contínua, con lo cual el condensador se comporta como una resistencia infinita y la bobina como un cable. Por lo que podemos re-dibujar el circuito de la siguiente forma:

![Ejercicio 3 (1)](/uploads/informatica/2/ffi/ejercicios-ca/3-1.png)

Para calcular las distintas energías necesitamos conocer la intensidad de corriente en una de las ramas y la diferencia de tensión entre los puntos A y B.

Sabemos que las resistencias equivalentes son \\(10 \Omega\\) y \\(5 \Omega\\) para la izquierda y la derecha respectivamente; y podemos obtener la intensidad de cada rama con un divisor de corriente, comenzaremos con la rama de la derecha:

\\[ I_2 = 3 \cdot \frac{10}{10 + 5} = 2A \\]

Con esta corriente ya podemos obtener la energía de la bobina:

\\[ E_L = \frac 1 2 \cdot 0.5 \cdot 2^2 = 1J \\]

Para la diferencia de tensión vamos a utilizar un divisor de tensión en cada rama:

\\[ V_A = 10 \cdot \frac{4}{6 + 4} = 4V \\]

\\[ V_B = 10 \cdot \frac{3}{2 + 3} = 6V \\]

\\[ V_C = V_B - V_A = 6 - 4 = 2V \\]

Y con estos datos ya podemos calcular la energía del condensador:

\\[ E_C = \frac 1 2 \cdot 1 \cdot 2^2 = 2J \\]

## Tensión y corriente

### Ejercicio 4

> Una tensión alterna tiene un valor eficaz de \\(56.5V\\) y una frecuencia de \\(47 Hz\\). Calcular su expresión en función del tiempo.

La expresión de la tensión respecto al tiempo es la siguiente:

\\[ V(t) = V_p \sin (\omega t + \varphi) \\]

Puesto que no hay ningún elemento pasivo, tomaremos que el desfase (\\(\varphi\\)) es 0.

El resto de valores podemos calcularlos sencillamente:

\\[ V_p = \sqrt 2 \cdot V_e = \sqrt 2 \cdot 56.5 = 80 \text V \\]

\\[ \omega = 2 \pi f = 2 \pi \cdot 47 = 295.3\\ \text{rad/s} \\]

Con lo cual, la expresión resultante es:

\\[ V(t) = 80 \sin (295 t) \\]

### Ejercicio 8

> La tensión \\(V(t) = 30 \sin 3000t\\) se aplica a una bobina con autoinducción \\(0.02 mH\\). ¿Qué intensidad de corriente circula por ella?

El formato de la corriente respecto al tiempo es:

\\[ I(t) = A_I \sin (\omega t + \varphi) \\]

Ya tenemos \\(\omega\\), pues es la misma que en la tensión: \\(3000\\ \text{rad/s}\\)

Por la ley de Ohm sabemos que \\( I = \frac V Z \\), por lo que procedemos a calcular la impedancia de la bobina:

\\[ X_L = 3000 \cdot 0.02 \cdot 10^-3 = 0.06\\ \Omega \\]

\\[ Z_L = X_L \cdot j = 0.06j\\ \Omega \\]

Con este dato podemos calcular la amplitud de la corriente:

\\[ A_I = \frac{A_V}{\|Z\|} = \frac{30}{0.06} = 500 A \\]

Y solamente nos falta \\(\varphi\\), que serán \\(-90º\\), pues es el desfase que provoca la bobina. Por tanto, la ecuación final es:

\\[ I(t) = 500 \sin (3000t - 90º) \\]
