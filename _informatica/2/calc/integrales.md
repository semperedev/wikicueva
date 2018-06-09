---
title: Cálculo de Integrales
---

[&lt;&lt; Volver a **Cálculo**](../calc.md)

* Tabla de Contenidos
{:toc}

## Integración por partes

Aplicaremos este método cuando tengamos una integral de la forma:

\\[
  \int f(x) g(x) dx
\\]

y no podamos resolverla directamente ni utilizar cambio de variable.

Con este método, lo que trataremos de conseguir es que la integral a calcular se reduzca a una más sencilla, dividiéndola en funciones más simples y aplicando la siguiente fórmula:

\\[
  \int udv = uv - \int vdu
\\]

> Regla mnemotécnica: **Un día vi una vaca sin cola vestida de uniforme**

Para comenzar, primero debemos elegir una de las dos funciones siguiendo este orden de preferencia:

* Logarítmicas (ej. \\(\ln x\\))
* Inversas trigonométricas (ej. \\(\arctan x\\))
* Algebráicas (ej. \\(x^4\\))
* Trigonométricas (ej. \\(\sin x\\))
* Exponenciales (ej. \\(e^x\\))

Denominaremos esta función con la letra \\(u\\), y la otra función **junto a \\(dx\\)**, la denominaremos por \\(dv\\). De forma que tendremos:

\\[u = f(x) \\\\ dv = g(x) dx\\]

Aún nos faltan \\(du\\) y \\(v\\). Para la primera, \\(du\\), simplemente derivamos la función \\(u\\); y para \\(v\\) tenemos que hacer la integral de \\(dv\\), que, si hemos elegido bien nuestra función \\(u\\), será sencilla de calcular. Al final tendremos esto:

\\[u = f(x) \\\\ du = f'(x) dx\\]
\\[v = \int g(x)dx \\\\ dv = g(x) dx\\]

Y ya podremos sustituir en nuestra fórmula y para operar y resolver nuestra integral.

Con este método, en lugar de resolver una integral compleja, hemos calculado dos integrales más sencillas.

## Descomposición en fracciones simples

Dada la siguiente fracción:

\\[ \frac{1}{x \cdot (x + 1)} \\]

Queremos obtener fracciones con denominadores más sencillos, siguiendo la estructura:

\\[ \frac{1}{x \cdot (x + 1)} = \frac{A}{x} + \frac{B}{x + 1} \\]

Quitamos los denominadores operando para quedarnos solamente con una ecuación que incluya las constantes:

\\[ 1 = A \cdot (x + 1) + B \cdot x \\]

Y damos valores a \\(x\\) para obtener los valores de A y B:

\\[ \text{Si}\ x = 0 \\\\ A = 1 \\]

\\[ \text{Si}\ x = -1 \\\\ B = -1 \\]

Y, de esta forma, obtenemos nuestras fracciones simples:

\\[ \frac{1}{x \cdot (x + 1)} = \frac{1}{x} + \frac{-1}{x + 1} \\]

### Raíces múltiples

Si alguno de los componentes del denominador tiene grado mayor que uno (es decir, más de una raíz), debemos incluir tantas fracciones simples como grados tenga, restando uno en cada aparición:

\\[
  \frac{1}{(x-1)^2 \cdot (x+1)} =
    \frac{A}{(x-1)^2} +
    \frac{B}{(x-1)} +
    \frac{C}{(x+1)}
\\]

De nuevo, operamos para quitar denominadores y nos queda:

\\[ 1 = A \cdot (x+1) + B \cdot (x-1) \cdot (x+1) + C \cdot (x-1)^2 \\]

Damos valores a \\(x\\) y obtenemos los siguientes resultados:

\\[ A = \frac{1}{2}, B = \frac{1}{4}, C = -\frac{1}{4} \\]

Y, finalmente, tenemos nuestras fracciones simples:

\\[
  \frac{1}{(x-1)^2 \cdot (x+1)} =
    \frac{\frac{1}{2}}{(x-1)^2} +
    \frac{\frac{1}{4}}{(x-1)} -
    \frac{\frac{1}{4}}{(x+1)}
\\]
