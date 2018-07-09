---
title: Ejercicios Resueltos - Corriente Contínua
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

## Ejercicio 1

> Se carga un condensador de \\( 4 pF \\) con una batería de \\( 150V \\). ¿Qué energía adicional se necesita para cargarlo a \\( 300V \\)?

Nos piden la variación de energía, \\( \Delta E \\), que podemos descomponer en \\( E_f - E_i \\), sabiendo que la energía de un condensador es:

\\( E = \frac{q^2}{2 \cdot C} = \frac{(V \cdot C)^2}{2 \cdot C} \\)

Por tanto:

\\( \Delta E = \frac{V_f^2 \cdot C^2}{2 \cdot C} - \frac{V_i^2 \cdot C^2}{2 \cdot C} = \frac{C}{2} \cdot (V_f^2 - V_i^2) \\)

Sustituyendo:

\\( \Delta E = \frac{4 \cdot 10^{-12}}{2} \cdot (300^2 - 150^2) = 1.35 \cdot 10^{-7} J = 0.135\ \mu J \\)

## Ejercicio 3

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

## Ejercicio 54

> Un condensador de \\(0.12 \mu F\\) inicialmente descargado se conecta en serie con una resistencia de \\(10 k \Omega\\) y una batería de \\(12 V\\). Calcular el tiempo que tarda el condensador en alcanzar el 90% de su carga final, es decir: \\(V = 0.9 V_0\\)

Sabemos que la carga de un condensador se calcula con las siguientes fórmulas:

\\[ Q = VC \cdot \left( 1 - e^{\frac{-t}{RC}} \right) \\]

Operamos para intentar despejar \\(t\\)

\\[ \frac{Q}{CV} = 1 - e^{\frac{-t}{RC}} \\]

\\[ 1 - \frac{Q}{CV} = e^{\frac{-t}{RC}} \\]

Aplicamos logaritmos

\\[ \ln \left( 1 - \frac{Q}{CV} \right) = - \frac{t}{RC} \\]

Seguimos operando

\\[
  t = -RC \cdot \ln \left( 1 - \frac{Q}{C \cdot V} \right)
\\]

No conocemos la carga, así que la reemplazamos por su expresión:

\\[ Q_{90} = V_{90} \cdot C \\]

Y sustituyendo:

\\[
  t = - RC \cdot \ln \left( 1 - \frac{V_{90} \cdot C}{C \cdot V_0} \right)
\\]

\\[ t = - RC \cdot \ln \left( 1 - \frac{V_{90}}{V_0} \right) \\]

\\[ t = - RC \cdot \ln \left( 1 - \frac{V_0 \cdot 0.9}{V_0} \right) \\]

\\[ t = - RC \cdot \ln (1 - 0.9) \\]

Ahora simplemente reemplazamos con los datos:

\\[ t = (-1) \cdot 10^4 \cdot 0.12 \cdot 10^{-6} \cdot \ln (0.1) \\]

\\[ t = 2.8 ms \\]

## Ejercicio 57

> Obtener la carga almacenada en el condensador y la potencia disipada en la resistencia \\(R_1\\)
>
> ![Ejercicio 57](/uploads/informatica/2/ffi/ejercicios-cc/57.png)
>
> \\(R_1 = 1k \Omega\\)  
> \\(R_1 = 500 \Omega\\)  
> \\(C = 30 \cdot 10^{-6} F\\)  
> \\(\varepsilon = 12 V\\)

### Carga del condensador

Puesto que no nos lo indican, supondremos que el circuito ya está estable, y por tanto el condensador está completamente cargado. Con lo cual, se comporta como un circuito abierto, y es posible redibujar el circuito completo de la siguiente forma:

![Ejercicio 57 (2)](/uploads/informatica/2/ffi/ejercicios-cc/57-2.png)

Podemos calcular la carga del condensador utilizando \\(Q = V C\\), para lo que debemos calcular la tensión en A, que es la misma que la tensión en \\(R_2\\), y para calcularla necesitamos la corriente que pasa por ella.

Calculamos la resistencia equivalente de \\(R_1\\) y \\(R_2\\) que están en serie:

\\[ R_T = 1k + 500 = 1.5k \Omega \\]

Y obtenemos la corriente del circuito:

\\[ I = \frac{V}{R} = \frac{12}{1.5k} = 8 mA \\]

Finalmente:

\\[ V_A = 500 \Omega \cdot 8 mA \\]

\\[ Q_C = C \cdot V_A = 30 \cdot 10^{-6} \cdot 4 = 1.2 \cdot 10^{-4} C \\]

### Potencia disipada

Sabemos que la potencia disipada por \\(R_1\\) se calcula con la siguiente fórmula: \\(P = V \cdot I\\), siendo \\(V\\) la tensión de entrada de la resistencia; e \\(I\\) la intensidad de la corriente, que es la misma en todo el circuito.

Si reemplazamos \\(V\\) utilizando la Ley de Ohm, \\(V = R \cdot I\\), nos queda la siguiente fórmula:

\\[ P_1 = R_1 \cdot I^2 \\]

Y dando valores:

\\[ P_1 = 1k \cdot \left( 8 \cdot 10^{-3} \right)^2 = 0.064W \\]
