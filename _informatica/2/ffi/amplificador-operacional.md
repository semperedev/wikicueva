---
title: Amplificador Operacional
---

## En lazo abierto

![Amplificador operacional](/uploads/informatica/2/ffi/amplificador-operacional.png)

Se trata de un elemento comparador: si en la entrada no inversora (\\(V_+\\)) hay una tensión mayor que en la entrada inversora (\\(V_-\\)), la salida \\(V_{out}\\) es igual a la entrada de alimentación superior \\(V_{S+}\\) y en caso contrario, la salida es igual a la entrada de alimentación inferior \\(V_{S-}\\)

#### Ganancia

\\[ G = \frac{V_{out}}{V_{in}} \\]

## En lazo cerrado

Utilizando realimentación negativa.

### Amplificador inversor

![Amplificador operacional inversor](/uploads/informatica/2/ffi/amplificador-inversor.png)

Conectamos la salida \\(V_{out}\\) a la entrada inversora con una resistencia y a la tensión de entrada \\(V_{in}\\) con otra resistencia. Con ello conseguimos que las tensiones de entrada sean prácticamente iguales:

\\[ V_+ = V_- \\]

De la misma forma, la impedancia del amplificador es tal, que la corriente que circula por él es prácticamente nula:

\\[ I_+ = I_- = 0 \\]

#### Tensión de salida

La tensión de salida está **amplificada e invertida**, pero recortada según los valores de la alimentación; es decir, si tenemos una tensión alterna \\(V_{in}\\) con \\(V_p = 10\\ \text V\\) pero una alimentación de 5V y 0V, la tensión de salida estará recortada superiormente a 5V e inferiormente a 0V.

#### Corrientes

Teniendo en cuenta esas dos _reglas_, podemos obtener fácilmente las corrientes que pasan por las resistencias:

\\[ I_{in} = \frac{V_{in}}{R_{in}} \\]

\\[ I_{f} = \frac{V_{out}}{R_{f}} \\]

#### Ganancia

Por la segunda regla (\\(I_+ = I_-\\)), si igualamos ambas corrientes, obtenemos lo siguiente:

\\[ V_{out} = - \frac{R_f}{R_{in}} V_{in} = - \frac{R_f}{R_{in}} \\]

Con lo que la ganancia es:

\\[ G = - \frac{R_f}{R_{in}} \\]
