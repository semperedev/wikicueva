---
title: Gestión de la Caché
---

## Formulario

#### Direcciones

\\[ D_{palabra} = D_{byte} \div T_{palabra} \\]

\\[ D_{bloque} = D_{byte} \div T_{bloque} \\]

#### Estructura de la Caché

\\[ I = D_{bloque} \mod N_{S} \\]

\\[ E = D_{bloque} \div N_{conjuntos} \\]

\\[
  N_{conjuntos} = \frac{N_{palabras}}{N_{palabras/bloque}
  \cdot N_{bloques/conjunto}}
\\]

\\[ N_{conjuntos} = \frac{T_{efectivo}}{N_{bloques} \cdot T_{bloque}} \\]

#### Tamaño de la Caché

\\[
  T_{efectivo} = N_{conjuntos} \cdot
  N_{bloques/conjunto} \cdot
  N_{palabras/bloque}
\\]

\\[
  T_{total} = N_{conjuntos} \cdot
  N_{bloques/conjunto} \cdot
  \left(
    N_{palabras/bloque} \cdot T_{palabra} + T_{etiqueta} + b_{control}
  \right)
\\]
