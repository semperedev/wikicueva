---
title: Transistores
---

[&lt;&lt; Volver a **FFI**](../ffi.md)

## BJT

![Transistor BJT](/uploads/informatica/2/ffi/bjt.png)

Utilizamos un transistor BJT para regular el paso de corriente entre colector y emisor utilizando la corriente de la base. Existe una caída de tensión entre el colector y el emisor: \\(V_{CE}\\)

Tomamos que entre la base y el emisor hay un diodo. Por tanto el transistor sólo permite paso de corriente cuando \\(V_{BE} > 0.7\\ \text V\\)

### Zonas de Trabajo

Podemos distinguir tres estados distintos para el transistor BJT:

#### Corte

El transistor no permite paso de corriente del colector al emisor, es decir, se comporta como un circuito abierto: \\(V_{CE} = V_{CC}\\)

\\[ I_C = I_B = 0 \\]

\\[ 0 < V_{BE} < 0.7 \\]

#### Activa

Existe paso de corriente, es decir, \\(0 < V_{CE} < V_{CC}\\). Como el diodo está regulando, sabemos que \\(V_{BE} \simeq 0.7\\ \text V\\).

Podemos relacionar la tensión del colector y la base:

\\[ I_c = \beta \cdot I_b \\]

#### Saturación

El transistor no ofrece ninguna resistencia, es decir, se comporta como un corto-circuito: \\(V_{CE} \simeq 0\\). El diodo no puede regular, con lo cual: \\(V_{BE} > 0.7\\ \text V\\)

La corriente del colector es máxima y no obedece a la corriente de la base, por tanto: \\(I_c \neq \beta \cdot I_b \\)
