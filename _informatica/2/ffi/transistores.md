---
title: Transistores
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

## BJT (npn)

![Transistor BJT](/uploads/informatica/2/ffi/bjt.png)

Utilizamos un transistor BJT para regular el paso de corriente entre colector y emisor utilizando la corriente de la base. Existe una caída de tensión entre el colector y el emisor: \\(V_{CE}\\)

Tomamos que entre la base y el emisor hay un diodo. Por tanto el transistor sólo permite paso de corriente cuando \\(V_{BE} > 0.7\\ \text V\\)

### Zonas de Trabajo

Podemos distinguir tres estados distintos para el transistor BJT:

#### Corte

El transistor no permite paso de corriente del colector al emisor, es decir, se comporta como un circuito abierto: \\(V_{CE} = V_{CC}\\)

\\[ I_C = I_B = 0 \\]

\\[ 0 < V_{BE} < 0.7 \\]

#### Activa

Existe paso de corriente, es decir, \\(0 < V_{CE} < V_{CC}\\). Como el diodo está regulando, sabemos que \\(V_{BE} \simeq 0.7\\ \text V\\).

Podemos relacionar la tensión del colector y la base:

\\[ I_c = \beta \cdot I_b \\]

#### Saturación

El transistor no ofrece ninguna resistencia, es decir, se comporta como un corto-circuito: \\(V_{CE} \simeq 0\\). El diodo no puede regular, con lo cual: \\(V_{BE} > 0.7\\ \text V\\)

La corriente del colector es máxima y no obedece a la corriente de la base, por tanto: \\(I_c \neq \beta \cdot I_b \\)

### Punto de Trabajo

Definimos el punto de trabajo de un BJT como:

\\[ Q = \\{ V_{CE}, I_c \\} \\]

### Ejemplo

> Dado el siguiente circuito:
>
> ![Circuito BJT](/uploads/informatica/2/ffi/bjt-ejercicio-1.png)
>
> \\(\beta = 162\\),
> \\(V_{BE} = 0.7\\ \text V\\)
>
> \\(R_c = 0.5\\ k \Omega\\),
> \\(R_b = 90\\ k \Omega\\)

#### Calcular el punto de trabajo

Necesitamos \\(V_{CE}\\) e \\(I_c\\). Para obtener la corriente del colector podemos hacer uso de \\(I_c = \beta I_b\\) si calculamos \\(I_b\\). Aplicando las leyes de Kirchoff tenemos:

\\[ V_{CC} = V_{RB} + V_{BE} \\]

Sustituyendo:

\\[ 10 = 90k \cdot I_b + 0.7 \\]

\\[ I_b = 0.1\\ \text{mA} \\]

Con lo que:

\\[ I_c = 162 \cdot 0.1 \cdot 10^{-3} = 16.2\\ \text{mA} \\]

Ahora nos falta \\(V_{CE}\\), que podemos calcular haciendo uso de las leyes de Kirchoff en la otra malla:

\\[ V_{CC} = V_{RC} + V_{CE} \\]

\\[ 10 = 0.5k \cdot I_c + V_{CE} \\]

\\[ V_{CE} = 1.9\\ \text V \\]

Por tanto, el punto de trabajo es:

\\[ Q = \\{ 1.9\\ \text V, 16.2\\ \text{mA} \\} \\]

#### Dibujar la recta de carga

Sabemos que si \\(I_c > 0\\), el transistor no está en corte; y si \\(V_{CE} > 0\\), el transistor no está en saturación. Dado que ambas condiciones se cumplen, el transistor está en zona activa. Por tanto la gráfica tendrá una forma similar a la siguiente:

![Recta de Carga BJT](/uploads/informatica/2/ffi/bjt-ejercicio-2.png)

Podemos ver claramente el punto de trabajo, \\(Q\\), en el corte de la recta con la curva.
