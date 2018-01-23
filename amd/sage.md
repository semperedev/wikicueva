<!-- TITLE: SAGE -->

# Introducción al lenguaje

SAGE se basa en [Python](https://www.python.org/), por eso resulta interesante conocer un poco cómo funciona este lenguaje antes de comenzar con las prácticas de AMD.

## Variables

Para declarar variables, utilizamos la siguiente sintaxis:

```python
nombreVariable = contenidoDeLaVariable
```

## Matrices

Las matrices en SAGE son *arrays* bidimensionales de Python. Si las definimos como `column_matrix` les proporcionamos las filas, y en caso contrario, las columnas. Utilizaremos la siguiente sintaxis:

```python
nombreMatriz = matrix(identificadorCuerpo, [[a, b], [c, d]])

matrizColumna = column_matrix(idCuerpo, [[a, c], [b, d]])
```

Donde `identificadorCuerpo` puede ser:

* `R` para los Reales
* `QQ` para Racionales
* `Zmod(n)` para \\(Z_{n}\\)

Por ejemplo:

\\( A = \begin{pmatrix}
  1 & 2 \\\\
  3 & 4
\end{pmatrix} en\ Z_{5} \\)

Se escribiria en SAGE:

```python
A = matrix(Zmod(5), [[1, 2], [3, 4]])
```