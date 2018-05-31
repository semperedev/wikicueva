---
title: Preguntas teóricas de TP
---

[&lt;&lt; Volver a **TP**](../tp.md)

> ¿La memoria de una variable local de tipo entero declarada dentro de una función se libera automáticamente al terminar la función o hay que liberarla usando free?

Se libera automáticamente porque se trata de una variable local y no se encuentra en memoria dinámica.

> ¿La memoria reservada con malloc se libera automáticamente o hay que liberarla usando free?

Como hemos reservado la memoria **manualmente** utilizando malloc, tendremos que liberarla también.

> ¿Cómo se puede simular el paso por referencia al escribir una función en C?

A la hora de pasar argumentos, lo que le daremos a la función serán punteros a las variables que queremos pasar por referencia, de esta forma dentro de la función podremos modificar su valor.

Esto se puede lograr utilizando `&` antes del nombre de la variable.

> ¿Cómo se sabe si una función es recursiva?

Cuando en su implementación incluye una **llamada a sí misma**.

> ¿Qué debe tener una función recursiva para que no sea incorrecta?

Debe tener un **caso base**, es decir, un caso cuya **solución es directa** y no requiere continuar la recursividad.

> Explica por qué debe haber al menos un caso base para que una función  recursiva sea correcta

Porque en caso de no existir un caso base, la recursividad nunca tendría condición de finalización y estaríamos ante un bucle infinito.

> ¿Puede una función recursiva tener más de un caso base?

Sí. La condición mínima es que tenga un caso base, aunque algunas definiciones de recursividad podrían utilizar varios.

> Explica qué es un TDA

Es un tipo de dato creado por el usuario cuya implementación y representación son independientes y están ocultas. La única forma de trabajar con dicho tipo es utilizando las operaciones definidas en el TDA.

#### Funcionamiento de una Pila

Es una lista en la cual las inserciones y las extracciones se realizan en el mismo extremo, es decir, el último dato introducido es el primero en ser extraído (tipo LIFO).

#### ¿Cuál es el coste de inserción de una lista implementada con un array de tamaño fijo?

En un array podemos insertar facilmente por el final, y en el caso de hacerlo por el medio, primero hay que desplazar los siguientes elementos para hacer hueco.

Como en una lista podemos insertar en cualquier posición, diremos que el coste de inserción sería de \\(O(n)\\), pues en el peor de los casos (insertar por el principio) tendríamos que desplazar todos los elementos.
