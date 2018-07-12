---
title: Ejercicios Resueltos - Corriente Alterna
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Ejercicio 3

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

<!-- TODO: Agregar ejercicio 4 -->
