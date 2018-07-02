---
title: Resolución de Circuitos
---

[&lt;&lt; Volver a **Física**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Conceptos básicos

A lo largo de un cable la tensión se mantiene constante.

Una fuente de contínua en sentido contrario al de la corriente, restará su tensión a la tensión del cable.

### Resistencias

Dos resistencias están en serie cuando están unidas por un único cable, y se pueden reemplazar por una cuyo valor sea la suma de sus valores: \\( R_{serie} = R_1 + R_2 \\)

Dos resistencias están en paralelo cuando sus extremos están unidos físicamente, y se pueden reemplazar por una sola resistencia con el siguiente valor:

\\[ R_{paralelo} = \frac{R_1 \cdot R_2}{R_1 + R_2} \\]

## Leyes de Ohm

La tensión que perdemos en una resistencia es la intensidad de la corriente (Amperios) por el valor de la resistencia (Ohmnios):

\\[ V = I \cdot R \\]

La potencia (Watios) en un punto del circuito es:

\\[ P = I \cdot V \\]

## Divisor de Tensión

Si queremos calcular una tensión menor que la de entrada y tenemos un circuito de la siguiente forma:

![Divisor de Tensión](/uploads/informatica/2/ffi/divisor-tension.png)

Podemos calcular \\(V_{out}\\) con la siguiente fórmula:

\\[ V_{out} = E \cdot \frac{R_2}{R_1 + R_2} \\]

Siendo \\(E\\) la tensión de entrada, es decir: la tensión del cable antes de \\(R_1\\)
