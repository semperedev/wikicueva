---
title: Corriente Contínua
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

* Tabla de Contenidos
{:toc}

Por convenio, tomaremos que la corriente va siempre del positivo al negativo.

## Resistencias

### Asociación

**En serie**

\\( \begin{align}
  R_T = R_1 + R_2
\end{align} \\)

**En paralelo**

\\( \begin{align}
  R_T = \frac{R_1 \cdot R_2}{R_1 + R_2}
\end{align} \\)

#### Consideraciones

Dadas dos o más resistencias conectadas en paralelo:

1. La tensión de entrada es la misma en todas las resistencias.
2. La corriente total a la entrada es la misma que a la salida.

## Condensadores

**Carga** de un condensador:

\\( \begin{align}
  Q(t) = VC \cdot \left( 1 - e^{\frac{-t}{RC}} \right)
\end{align} \\)

Siendo:

* \\(V\\) la tensión de entrada
* \\(C\\) la capacidad del condensador
* \\(R\\) la resistencia total del circuito

Y si conocemos la tensión en un instante \\(x\\):

\\( \begin{align}
  Q_x = V_x \cdot C
\end{align} \\)

**Energía** de un condensador:

\\( \begin{align}
  E = \frac{q^2}{2 \cdot C}
\end{align} \\)

A tiempo cero, es decir, nada más conectar el condensador, éste se comporta como un cable.

Pasado cierto tiempo, se comporta como una resistencia infinita, es decir, es un corto-circuito.

### Asociación

**En serie**

\\( \begin{align}
  C_T = \frac{C_1 \cdot C_2}{C_1 + C_2}
\end{align} \\)

**En paralelo**

\\( \begin{align}
  C_T = C_1 + C_2
\end{align} \\)

#### Consideraciones importantes

Dados dos condensadores en **serie**:

1. La carga es igual en ambos condensadores.
2. La caída de tensión en cada condensador es:

\\[ V_1 = V_e \cdot \frac{C_2}{C_1 + C_2} \\]

Dados dos condensadores en **paralelo**:

1. La suma de sus cargas es igual a la carga de su equivalente.
2. La tensión es igual en ambos condensadores.

### Tiempo de carga

**Hasta alcanzar carga Q**

\\( \begin{align}
  t = RC \cdot \left[- \ln \left( 1 - \frac{Q}{C V_0} \right) \right]
\end{align} \\)

Siendo:

* \\(V_0\\) la tensión inicial del circuito

> Esta fórmula se obtiene despejando el tiempo en la fórmula de la carga

**Hasta una tensión V**

\\( \begin{align}
  t = RC \cdot \left[- \ln \left( 1 - \frac{V}{V_0} \right) \right]
\end{align} \\)

> Esta fórmula se obtiene sustituyendo \\( V = \frac{Q}{C} \\) en la fórmula anterior
