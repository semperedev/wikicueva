---
title: Resolución de Circuitos
---

[&lt;&lt; Volver a **Física**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Conceptos básicos

### Estructura

Un nodo es una sección de cable cuya tensión es constante, es decir, un cable que une dos o más componentes es un nodo.

Una malla es cualquier circuito cerrado:

![Mallas](/uploads/informatica/2/ffi/mallas.png)

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

## Kirchhoff

### Ley de las Corrientes

> Todas las corrientes que entran en un nodo, salen

Es decir, la suma de las corrientes entrantes es igual a la suma de las corrientes que salen:

![Kirchhoff: ley de las corrientes](/uploads/informatica/2/ffi/kirchhoff-corrientes.png)

### Ley de las Tensiones

> Todas las tensiones que suben en una malla, bajan

Es decir, la suma de todas las variaciones de tensión en una malla es nula.

Una fuente de contínua en sentido contrario al de la corriente, restará su tensión a la tensión del cable.

![Kirchhoff: ley de las corrientes](/uploads/informatica/2/ffi/kirchhoff-tensiones.png)

\\[ V_a - V_1 - V_b - V_2 - V_3 = 0 \\]

## Divisor de Corriente

Si tenemos un circuito de la siguiente forma:

![Divisor de Corriente](/uploads/informatica/2/ffi/divisor-corriente.png)

Podemos calcular la corriente que circula por cada resistencia:

\\[ I_{R2} = I_{ent} \frac{R1}{R1 + R2} \\]

## Equivalente Thevenin

Dado cualquier circuito, podemos obtener un circuito equivalente compuesto por una resistencia y una fuente de tensión.

![Equivalencia Thevenin](/uploads/informatica/2/ffi/thevenin.png)

En vez de A y B, podemos tener una carga \\(R_L\\), que deberemos eliminar antes de operar.

### Resistencia Thevenin

Eliminamos todas las fuentes y calculamos la resistencia equivalente a todas las resistencias que quedan.

### Tensión Thevenin

\\[ V_{TH} = V_A - V_B \\]

El problema está en obtener las tensiones en A y B, que calcularemos mediante cualquiera de los métodos anteriores.

## Teorema de Norton

En caso de querer una resistencia y una fuente de corriente, en vez de una fuente de tensión, aplicaremos el Teorema de Norton en lugar de Thevenin.

Las resistencias equivalentes de Thevenin y Norton se calculan de la misma forma:

\\[ R_N = R_{TH} \\]

Para calcular el valor de la fuente de corriente utilizaremos la tensión de Thevenin:

\\[ I_N = \frac{V_{TH}}{R_{TH}} \\]

## Mallas

Dado un circuito con esta forma:

![Mallas: 1](/uploads/informatica/2/ffi/malla-1.png)

Podemos calcular el valor de las corriente que circula por cada malla.

**Paso 1**: Identificamos las mallas.

**Paso 2**: Marcamos las corrientes y sus sentidos. El truco es que las corrientes tengan sentidos opuestos para que sea más sencillo operar con la resistencia central.

![Mallas: 2](/uploads/informatica/2/ffi/malla-2.png)

**Paso 3**: Aplicamos Kirchhoff para obtener una ecuación de tensiones por cada malla. El resultado es un sistema de tantas incógnitas como mallas tengamos.

## Teorema de Kennelly

Queremos convertir una asociación de resistencias triangular en algo más sencillo.

![Teorema de Kennelly](/uploads/informatica/2/ffi/kennelly.png)

\\[ R_a = \frac{R_{ab} \cdot R_{ac}}{R_{ab} + R_{ac} + R_{bc}} \\]

> Multiplico las adyacentes y divido por la suma de todas las R
