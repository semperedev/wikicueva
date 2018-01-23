<!-- TITLE: SAGE -->

# Introducción al lenguaje

SAGE se basa en [Python](https://www.python.org/), por eso resulta interesante conocer un poco cómo funciona este lenguaje antes de comenzar con las prácticas de AMD.

Para declarar variables, escribimos `nombre = valor`. En un nombre de variable podemos utilizar letras (mayúsculas o minúsculas), números y barras bajas, pero no se puede empezar por un número.

Podemos agregar comentarios en el propio código si ponemos un `#` antes del comentario. (No tiene por qué ser al principio de la línea)

```python
# Esto es un comentario

numeroPi = 3.141592 # Definimos PI
```

## Matrices

Las matrices en SAGE son *arrays* bidimensionales de Python. Si las definimos como `column_matrix` les proporcionamos las filas, y en caso contrario, las columnas.

Ten en cuenta que el valor de la matriz lo guardamos en una variable.

Utilizaremos la siguiente sintaxis:

```python
matrizPrimera = matrix(identificadorCuerpo, [[a, b], [c, d]])

matrizSegunda = column_matrix(idCuerpo, [[a, c], [b, d]])
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

### Operaciones con matrices

```python
nombreMatriz.echelon_form()
```
