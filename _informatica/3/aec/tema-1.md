---
title: Tema 1 - Análisis de Prestaciones
---

[&lt;&lt; Volver a **AEC**](../aec.md)

* Tabla de Contenidos
{:toc}

## Rendimiento

\\(X\\) es \\(n\%\\) más rápido que \\(Y\\) si:

\\[
  r = \frac{\text{Rendimiento}_X}{\text{Rendimiento}_Y} = 1 + \frac{n}{100}
\\]

Si definimos \\(T_{CPU}\\) como la inversa del rendimiento:

\\[
  r = \frac{T_{CPU_Y}}{T_{CPU_X}} = 1 + \frac{n}{100}
\\]

## Métricas

### Tiempo de ejecución

Se trata de una medida coherente y fiable. Podemos calcular el tiempo de ejecución (o tiempo de CPU), con la siguiente fórmula (tal y como vimos en FC y ETC):

\\[
  T_{CPU} = NI \cdot CPI \cdot T_{ciclo}
\\]

Dadas dos máquinas, la que tenga un menor tiempo de CPU será la más rápida, y por tanto, preferida.

#### Ejemplo 1

> Dada la siguiente distribución de instrucciones:
>
> * 33% Aritméticas - 2 ciclos
> * 21% Carga - 3 ciclos
> * 12% Almacenamiento - 3 ciclos
> * 24% Salto - 3 ciclos
> * 10% Coma flotante - 12 ciclos
>
> En un intento de optimizar la máquina, hemos reducido las operaciones de coma flotante (FP - floating point) a la mitad, aunque ello nos ha provocado:
>
> * Un incremento en el tiempo de ciclo del 25%.
> * Ahora las operaciones de cargas utilizan 4 ciclos
>
> ¿Hemos obtenido una mejora? En caso afirmativo, ¿en qué factor?

Tenemos dos máquinas: la máquina original, que denotaremos por M1, y la máquina modificada, M2.

Para comparar los rendimientos de ambas máquinas vamos a utilizar el Tiempo de CPU, que es una medida fiable y sencilla de calcular. Sabemos que el tiempo de ciclo se incrementa en un 25%, con lo que \\(T_{C2}\\) será \\(T_C + 25%\\), es decir:

\\[ T_{C2} = 1.12 \cdot T_C \\]

Procedemos a obtener los tiempos de CPU; para ello primero calculamos el CPI original y el alternativo teniendo en cuenta los cambios en los ciclos:

\\[
  CPI_1 = 0.33 \cdot 2 + 0.21 \cdot 3 + 0.12 \cdot 3 + 0.24 \cdot 3 + 0.1 \cdot 12 = 3.57
\\]

\\[
  CPI_2 = 0.33 \cdot 2 + 0.21 \cdot 4 + 0.12 \cdot 3 + 0.24 \cdot 3 + 0.1 \cdot 6 = 3.18
\\]

Como el número de instrucciones es el mismo en ambas máquina, sólo queda plantear los datos y realizar la comparación:

\\[
  r = \frac{T_{CPU_2}}{T_{CPU_1}}
    = \frac{NI \cdot 3.18 \cdot T_C \cdot 1.25}{NI \cdot 3.57 \cdot T_C}
    = \frac{3.18 \cdot 1.25}{3.57}
    = 1.1135
\\]

Aplicando la fórmula, tenemos que:

\\[
  n = (r - 1) \cdot 100 = (1.1135 - 1) \cdot 100 = 11.35\%
\\]

Con lo cual, hemos visto que la máquina original es un 11.35% más rápida que la modificada. En este caso no se ha logrado una optimización.

#### Ejemplo 2

> Revisando las modificaciones de la máquina del ejercicio anterior, hemos logrado que las cargas vuelvan a consumir solamente 3 ciclos.
>
> ¿Varía el resultado obtenido anteriormente? ¿Qué máquina es más rápida ahora?

El primer dato que se ve afectado es el CPI de la segunda máquina, que procedemos a actualizar:

\\[
  CPI_2 = 0.33 \cdot 2 + 0.21 \cdot 3 + 0.12 \cdot 3 + 0.24 \cdot 3 + 0.1 \cdot 6 = 2.97
\\]

Ahora realizamos la comparación de nuevo:

\\[
  r = \frac{T_{CPU_2}}{T_{CPU_1}}
    = \frac{NI \cdot 2.97 \cdot T_C \cdot 1.25}{NI \cdot 3.57 \cdot T_C}
    = \frac{2.97 \cdot 1.25}{3.57}
    = 1.0399
\\]

Aplicando la fórmula, tenemos que:

\\[
  n = (r - 1) \cdot 100 = (1.0399 - 1) \cdot 100 = 3.99\%
\\]

A pesar de que hemos reducido el tiempo de CPU de la máquina 2, seguimos sin lograr nuestro objetivo, y la máquina original sigue siendo más rápida, aunque ahora solamente un 3.99% más rápida.

### MIPS

Millones de Instrucciones Por Segundo

\\[
  MIPS = \frac{NI}{T_{CPU} \cdot 10^6} = \frac{f (MHz)}{CPI}
\\]

Es una medida fácil de entender: más MIPS quiere decir más rápido, pero **no es una medida fiable**, pues puede llegar a ser inversa al rendimiento.

### MFLOPS

Millones de instrucciones en coma FLOtante Por Segundo

\\[
  MFLOPS = \frac{NI_{FP}}{T_{CPU} \cdot 10^6}
\\]

De nuevo, **no es una medida fiable**. En este caso, las operaciones en coma flotante no son las mismas en todas las máquinas.

### Ley de Amdahl

Con esta Ley somos capaces de medir la aceleración de un programa debida a una mejora. Para ello comprobaremos la mejora en el periodo de tiempo afectado.

\\[
  Speedup = \frac{T}{T_E} = \frac{1}{(1 - f) + \frac f S}
\\]

Siendo:

* \\(f\\) fracción del tiempo mejorada (porcentaje sobre 1)
* \\(E\\) mejora aplicada
* \\(S\\) factor de mejora

#### Ejemplo 3

> Continuando el ejercicio 1, las instrucciones de coma flotante ocupaban 12 ciclos y fueron reducidas a 6, es decir, se logró que fuesen el doble de rápidas: \\(S = 2\\)
>
> Sabiendo que sólo el 10% de las instrucciones son de coma flotante, ¿cuánto ha mejorado según la Ley de Amdahl?

Las instrucciones afectadas componen el 10% del total, con lo que tenemos la fracción de tiempo afectada: \\(f = \frac{10}{100} = 0.1\\)

Ahora simplemente aplicamos la fórmula:

\\[
  Speedup = \frac{1}{(1 - 0.1) + \frac{0.1}{2}} = 1.053
\\]

Aplicando la fórmula del rendimiento obtenemos que la parte de operaciones de coma flotante ha mejorado un 5.3%

En contraste con el ejercicio 1: la Ley de Amdahl nos indica que la parte de la mejora, en efecto, ha mejorado; pero para conseguir dicha mejora fue necesario modificar otros parámetros que empeoraron el desempeño general de la máquina.
