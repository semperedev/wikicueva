---
title: Preguntas teóricas de TP
---

[&lt;&lt; Volver a **TP**](../tp.md)

#### ¿Qué es un TDA?

Es un tipo de dato implementado por el usuario cuya implementación y representación son independientes y están ocultas.

La única forma de trabajar con dicho tipo es utilizando las funciones definidas en el TDA.

#### Funcionamiento de una Pila

Es una lista en la cual las inserciones y las extracciones se realizan en el mismo extremo, es decir, el último dato introducido es el primero en ser extraído (tipo LIFO).

#### ¿Cuál es el coste de inserción de una lista implementada con un array de tamaño fijo?

En un array podemos insertar facilmente por el final, y en el caso de hacerlo por el medio, primero hay que desplazar los siguientes elementos para hacer hueco.

Como en una lista podemos insertar en cualquier posición, diremos que el coste de inserción sería de \\(O(n)\\), pues en el peor de los casos (insertar por el principio) tendríamos que desplazar todos los elementos.
