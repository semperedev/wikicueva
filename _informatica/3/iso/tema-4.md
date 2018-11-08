---
title: Tema 4 - Sistemas de Ficheros
---

[&lt;&lt; Volver a **ISO**](../iso.md)

* Tabla de Contenidos
{:toc}


## Ejercicios

### nodos-i

\\[
  \text{direcciones/bloque} = \frac{\text{tamaño de bloque}}{\text{tamaño dirección}}
\\]

Para obtener el número de bloque de datos dividimos el desplazamiento en bytes entre el tamaño de bloque:

\\[
  \text{bloque de datos} = \frac{\text{despl. byte}}{\text{tamaño de bloque}}
\\]

Para obtener el número de bloque indirecto seguimos la siguiente estrategia: obtenemos el bloque más lejano del nodo-i y vamos buscando hacia atrás. El cálculo consiste en restar al número de bloque actual la cantidad de direcciones del siguiente bloque que ya hay en el nodo-i, y dividir este número entre la cantidad de direcciones por cada bloque indirecto:

\\( \begin{align}
  BSI = \frac{\text{bloque de datos} - \text{dir. en nodo-i}}{\text{direcciones/bloque}}
\end{align} \\)

\\( \begin{align}
  BDI = \frac{BSI - \text{dir. en nodo-i}}{\text{direcciones/bloque}}
\end{align} \\)

\\( \begin{align}
  BTI = \frac{BDI - \text{dir. en nodo-i}}{\text{direcciones/bloque}}
\end{align} \\)

Para obtener la posición de una dirección dentro de un bloque a la parte decimal le multiplicamos el número de direcciones que hay en cada bloque:

\\[
  Pos_{B} = (B - \lfloor B \rfloor) \cdot \text{direcciones/bloque}
\\]

### Ejercicio 7

>  En un sistema de archivos UNIX estándar tenemos bloques de 1K y direcciones de disco de 4 bytes, nodos-i con 10 bloques directos, un BSI, un BDI y un BTI. ¿Qué bloques tenemos que leer para llegar a leer el byte 12.345.678 de un fichero, y en qué puntero de cada bloque de metadatos se encuentra el siguiente bloque a buscar?

Lo primero es obtener el bloque de datos que queremos:

\\[
  bloque = \frac{12345678}{1024} = 12056.32... \simeq 12056
\\]

Una vez sabemos el bloque de datos, podemos obtener el número de bloque simplemente indirecto; pero antes vamos a ver cuántas direcciones caben en un bloque:

\\[
  \text{dir/bloque} = \frac{1024}{4} = 256
\\]

Y ahora obtenemos los bloques y sus desplazamientos:

\\[
  BSI = \frac{12056 - 10}{256} = 47.05... \simeq 47
\\]

\\[
  Pos_{BSI} = (47.05... - 47) \cdot 256 = 14
\\]

Por tanto, sabemos que necesitamos el BSI número 47, en cuya posición 14 estará la dirección del bloque de datos que buscamos. Vamos a ver ahora la posición del BDI:

\\[
  BDI = \frac{47 - 1}{256} = 0.179... \simeq 0
\\]

\\[
  Pos_{BDI} = (0.179... - 0) \cdot 256 = 46
\\]

Dado que el número de BDI es menor que 256, sabemos que no está en el BTI, con lo cual ya hemos encontrado todos los bloques.

En conclusión: tenemos que leer el nodo-i, el BDI 0, el BSI 47 y el bloque de datos 12056. En **total 4 accesos a disco** contando el nodo-i.
