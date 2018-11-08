---
title: Tema 2 - Gestión de Procesos
---

[&lt;&lt; Volver a **ISO**](../iso.md)

* Tabla de Contenidos
{:toc}

## Concepto de proceso

Distingamos entre proceso y programa:

* Programa: código y datos almacenados en disco (entidad pasiva)
* Proceso: programa en ejecución almacenado en memoria (entidad activa)

De forma resumida diremos:

> Un proceso es un programa en ejecución.

Los procesos son entidades dinámicas con un estado determinado por el contador de programa y los registros de la CPU.

Para lograr la multitarea, en la CPU se alternan rápidamente todos los procesos en ejecución. En el caso de CPUs con un sólo núcleo, se obtiene un pseudoparalelismo al realizar estos cambios muy rápido; mientras que en CPUs multi-núcleo es posible conseguir paralelismo real.

## Implementación de procesos

El SO mantiene un registro de todos los procesos en la llamada _tabla de procesos_; cada entrada en la tabla se llama PCB (_Process Control Block_). Este PCB se utiliza para mantener el contexto de un proceso cuando entra y sale de CPU.

### Creación de procesos

De forma genérica:

1. Asignación de nombre
2. Creación del PCB e inserción en la tabla de procesos
3. Determinación de la prioridad inicial
4. Asignación de recursos iniciales

En el caso específico de Unix:

1. Llamada a `fork()`
2. Asignación de un PID e inserción en la tabla de procesos
3. Copia de datos del PCB del padre al del nuevo proceso hijo
4. Asignación de memoria para datos y pila
5. Se incrementan los contadores de ficheros abiertos por el padre
6. El proceso hijo recibe el estado: listo

## Planificación de Procesos

> Decimos que una planificación es apropiativa cuando le quita la CPU a un proceso para dársela a otro (se apropia de la CPU), y es no apropiativa cuando deja que los procesos suelten la CPU.

Nombre | Naturaleza | Descripción | Problemas
---|---|---|---
FCFS | No apropiativa | Primero en llegar, primero en ser servido | Efecto convoy
SJF | No apropiativa | Primero el trabajo más corto | Requiere hacer estimaciones
SRTF | Apropiativa | Primero el que tenga el menor tiempo restante | -
RR | Apropiativa | Planificación circular | -

### FCFS: First Come, First Served

El primer proceso que solicita la CPU es el que la recibe, y el siguiente proceso en llegar recibirá CPU cuando el primer proceso la suelte.

Puede darse el **efecto convoy**: un proceso limitado por CPU ocupa toda la CPU mientras los procesos limitados por E/S esperan y los dispositivos E/S quedan inactivos. En resumen, se desaprovechan los recursos.

### SJF: Shortest Job First

De la cola de listos, damos la CPU al proceso que menos tiempo tarda en ejecutarse en total.

Es utilizado cuando se conocen los tiempos de ejecución de antemano. Ofrece el tiempo promedio de regreso mínimo. También se podría utilizar con procesos interactivos.

#### Maduración

Cuando no se conoce el tiempo exacto de ejecución, podemos hacer estimaciones basándonos en el comportamiento anterior:

\\[ E_t = a \cdot E_{t-1} + (1-a) \cdot T_{t-1} \\]

Siendo \\(E\\) la estimación, \\(T\\) el tiempo real y \\(a\\) un parámetro entre 0 y 1. Valores pequeños de \\(a\\) harán que los tiempos anteriores se olviden pronto.

### SRTF: Shortest Remaining Time First

Se trata de hacer apropiativa la planificación SJF. Cuando hay un proceso con menor tiempo restante que el proceso actual, se le quita la CPU al proceso en ejecución para dársela a este nuevo proceso.

### RR: Round Robin

Es la planificación más justa y de uso más amplio. Los procesos se atienden en orden de llegada, pero se les asigna un _**quantum**_ (intervalo de tiempo), y cuando finaliza ese _quantum_, se le quita la CPU al proceso en ejecución para que entre el siguiente de la cola.

Un proceso no debe esperar más de \\( (n-1) \cdot q \\) unidades de tiempo antes de volver a recibir CPU; siendo \\(q\\) la duración del quantum y \\(n\\) el número de procesos.

Es importante elegir bien el quantum:

* Si es muy pequeño, la CPU podría estar más tiempo cambiando de procesos que ejecutándolos
* Si es muy grande, los últimos procesos de la cola podrían tardar demasiado en ser atendidos
