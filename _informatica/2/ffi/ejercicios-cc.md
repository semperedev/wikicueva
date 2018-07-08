---
title: Ejercicios Resueltos - Corriente Contínua
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Condensadores

### Ejercicio 1

> Se carga un condensador de \\( 4 pF \\) con una batería de \\( 150V \\). ¿Qué energía adicional se necesita para cargarlo a \\( 300V \\)?

Nos piden la variación de energía, \\( \Delta E \\), que podemos descomponer en \\( E_f - E_i \\), sabiendo que la energía de un condensador es:

\\( E = \frac{q^2}{2 \cdot C} = \frac{(V \cdot C)^2}{2 \cdot C} \\)

Por tanto:

\\( \Delta E = \frac{V_f^2 \cdot C^2}{2 \cdot C} - \frac{V_i^2 \cdot C^2}{2 \cdot C} = \frac{C}{2} \cdot (V_f^2 - V_i^2) \\)

Sustituyendo:

\\( \Delta E = \frac{4 \cdot 10^{-12}}{2} \cdot (300^2 - 150^2) = 1.35 \cdot 10^{-7} J = 0.135\ \mu J \\)

### Ejercicio 3

> Determinar la capacidad del condensador equivalente entre a y b:
>
> ![Ejercicio 3](/uploads/informatica/2/ffi/ejercicios-cc/3.png)

Tenemos que darnos cuenta de que los dos condensadores de la derecha están en serie, con lo cual podemos calcular su equivalente:

\\[
  C_e = \frac{\frac{C}{2} \cdot 2C}{\frac{C}{2} + 2C} =
  \frac{C^2}{\frac{5}{2} C} = \frac{2}{5} C
\\]

Esto nos deja dos condensadores en paralelo. Resolvemos el ejercicio calculando su equivalente:

\\[ C_T = C + \frac{2}{5} C = \frac{7}{5} C \\]

### Ejercicio 57

> Obtener la carga almacenada en el condensador y la potencia disipada en la resistencia \\(R_1\\)
>
> ![Ejercicio 57](/uploads/informatica/2/ffi/ejercicios-cc/57.png)
>
> \\(R_1 = 1k \Omega\\)  
> \\(R_1 = 500 \Omega\\)  
> \\(C = 30 \cdot 10^{-6} F\\)  
> \\(\varepsilon = 12 V\\)

#### Carga del condensador

Puesto que no nos lo indican, supondremos que el circuito ya está estable, y por tanto el condensador está completamente cargado. Por tanto, se comporta como un corto-circuito, y podemos redibujar el circuito así:

![Ejercicio 57 (2)](/uploads/informatica/2/ffi/ejercicios-cc/57-2.png)

A continuación, vamos a calcular la tensión en A para poder obtener la carga del condensador utilizando \\(Q = V C\\).

Está claro que la tensión en A es la misma que la tensión en \\(R_2\\), para calcularla necesitamos la corriente que pasa por ella.

Calculamos la resistencia equivalente de \\(R_1\\) y \\(R_2\\) que están en serie:

\\[ R_T = 1k + 500 = 1.5k \Omega \\]

Y obtenemos la corriente del circuito:

\\[ I = \frac{V}{R} = \frac{12}{1.5k} = 8 mA \\]

Finalmente:

\\[ V_A = 500 \Omega \cdot 8 mA \\]

\\[ Q_C = C \cdot V_A = 30 \cdot 10^{-6} \cdot 4 = 1.2 \cdot 10^{-4} C \\]

#### Potencia disipada

Sabemos que \\(P = V \cdot I\\) y \\(V = R \cdot I\\), con lo que:

\\[ P = R \cdot I^2 = 1k \cdot \left( 8 \cdot 10^{-3} \right)^2 = 0.064W \\]
