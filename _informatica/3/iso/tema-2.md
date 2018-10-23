---
title: Tema 2 - Gestión de Procesos
---

[&lt;&lt; Volver a **ISO**](../iso.md)

* Tabla de Contenidos
{:toc}

> NOTA: Pendiente de ampliación

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
