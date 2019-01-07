---
title: Tema 5 - Administración de Memoria
---

[&lt;&lt; Volver a **ISO**](../iso.md)

* Tabla de Contenidos
{:toc}

## Introducción

El objetivo es proporcionar al programador la ilusión de una memoria infinita y ultrarrápida.

## Sin Memoria Virtual

A cada proceso de le asigna una única zona contigua de memoria principal.

### Multiprogramación con particiones fijas

Asignamos una zona de tamaño fijo al SO y dividimos el resto de la memoria en N partes. Una vez creadas, las particiones no varían su extensión una vez creadas, lo cual limita el grado de multiprogramación (número de procesos en memoria simultáneamente). Un gran inconveniente es que los procesos pequeños generan fragmentación interna, debido en parte a cómo se asignan las particiones a los procesos:

#### Una cola por partición

Cada partición tiene su propia cola, y los procesos se asignan a las colas de las particiones de menor tamaño, esto acarrea ub inconveniente: las colas de las particiones grandes estarán mayormente vacías; para solucionar esto podríamos hacer todas las particiones pequeñas, pero entonces no podríamos atender trabajos de gran tamaño.

#### Cola única

Una única cola para todas las particiones. Cuando una partición queda libre, se le asigna al menor proceso que quepa en ella; problema: una tarea pequeña podría desperdiciar una partición grande. Para solucionarlo se podría buscar el proceso más grande que quepa, pero dejaríamos fuera tareas pequeñas. Una solución posible seria establecer un límite, en el cual cuando un trabajo se ha excluído más de k veces, no se vuelve a excluir.

> También se produce fragmentación externa cuando hay suficiente memoria libre para un proceso pero no se puede asignar por estar repartida en varias particiones.
