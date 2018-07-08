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
