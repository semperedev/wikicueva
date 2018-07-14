---
title: Diodos
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

## Los Diodos

![Diodo](/uploads/informatica/2/ffi/diodo.png)

Cuando la corriente va el ánodo al cátodo se dice que está en polarización **directa**, y **permite** el paso de corriente. En caso contrario, está en polarización **inversa** y **no permite** el paso de corriente.

Los diodos tienen una caída de tensión característica, normalmente 0.7 voltios.

## Diodo Zener

![Diodo Zener](/uploads/informatica/2/ffi/zener.png)

En polarización directa se comporta como un diodo normal, pero en polarización inversa permite el paso de corriente del cátodo al ánodo.

El funcionamiento es el siguiente: si la tensión de entrada \\(V\\) es mayor que la tensión de regulación \\(V_Z\\), el diodo regula y sólo deja pasar \\(V_Z\\). **Pero** se puede fundir a partir de una cierta potencia de ruptura \\(P_Z\\).

Conociendo \\(P_Z\\), podemos calcular las intensidades máxima y mínima en las que el diodo zener regula.

\\[ I_Z = \frac{P_Z}{V_Z} \\]

\\(I_{Z max}\\) = 90% de \\(I_Z\\)

\\(I_{Z min}\\) = 10% de \\(I_Z\\)
