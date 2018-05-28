---
title: Gestión de la Caché
---

## Formulario

#### Direcciones

\\( \begin{align} D_{palabra} = D_{byte} \div T_{palabra} \end{align} \\)

\\( \begin{align} D_{bloque} = D_{byte} \div T_{bloque} \end{align} \\)

#### Estructura de la Caché

\\( \begin{align} I = D_{bloque} \mod N_{S} \end{align} \\)

\\( \begin{align} E = D_{bloque} \div N_{conjuntos} \end{align} \\)

\\( \begin{align}
  N_{conjuntos} = \frac{N_{palabras}}{N_{palabras/bloque} \cdot N_{bloques/conjunto}}
\end{align} \\)

\\( \begin{align}
  N_{conjuntos} = \frac{T_{efectivo}}{N_{bloques} \cdot T_{bloque}}
\end{align} \\)

#### Tamaño de la Caché

\\( \begin{align}
  T_{efectivo} = N_{conjuntos} \cdot
  N_{bloques/conjunto} \cdot
  N_{palabras/bloque}
\end{align} \\)

\\( \begin{align}
  T_{total} = N_{conjuntos} \cdot
  N_{bloques/conjunto} \cdot
  \left(
    N_{palabras/bloque} \cdot T_{palabra} + T_{etiqueta} + b_{control}
  \right)
\end{align} \\)
