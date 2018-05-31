---
title: Preguntas teóricas de TP
---

[&lt;&lt; Volver a **TP**](../tp.md)

> ¿La memoria de una variable local de tipo entero declarada dentro de una función se libera automáticamente al terminar la función o hay que liberarla usando free?

Se libera **automáticamente** porque se trata de una variable local y no se encuentra en memoria dinámica.

> ¿La memoria reservada con malloc se libera automáticamente o hay que liberarla usando free?

Como hemos reservado la memoria **manualmente** utilizando malloc, tendremos que liberarla también.

> ¿Cómo se puede simular el paso por referencia al escribir una función en C?

A la hora de pasar argumentos, lo que le daremos a la función serán **punteros** a las variables que queremos pasar por referencia, de esta forma dentro de la función podremos modificar su valor.

Esto se puede lograr utilizando `&` antes del nombre de la variable.

> ¿Cómo se sabe si una función es recursiva?

Cuando en su implementación incluye una **llamada a sí misma**.

> ¿Qué debe tener una función recursiva para que no sea incorrecta?

Debe tener un **caso base**, es decir, un caso cuya **solución es directa** y no requiere continuar la recursividad.

> Explica por qué debe haber al menos un caso base para que una función recursiva sea correcta

Porque en caso de no existir un caso base, la recursividad nunca tendría condición de **finalización** y estaríamos ante un **bucle infinito**.

> ¿Puede una función recursiva tener más de un caso base?

Sí. La condición mínima es que tenga un caso base, aunque algunas definiciones de recursividad podrían utilizar varios.

> Explica qué es un TDA

Es un tipo de dato creado por el usuario cuya implementación y representación son independientes y están **ocultas**. La única forma de trabajar con dicho tipo es utilizando las operaciones definidas en el TDA.

> ¿Qué diferencia hay entre la especificación y la implementación de un TDA?

La especificación o definición de un TDA, es la parte **pública**, y se compone de la definición del tipo y las operaciones de dicho TDA.

La implementación es la parte **privada** y es donde se define la estructura del tipo y el código de sus operaciones.

> ¿Pueden haber dos implementaciones distintas de una misma especificación de TDA?

Sí, cualquier implementación que cumpla con la especificación del TDA, es válida.

> ¿Por qué se debe ocultar la representación al implementar un TDA?

Para cumplir con el principio de ocultación. Esto tiene ciertas **ventajas**, tales como la simplificación del desarrollo, mantenimiento y reusabilidad.

> Describe el funcionamiento de una pila

Es una lista en la cual las inserciones y las extracciones se realizan en el **mismo extremo**, es decir, el último dato introducido es el primero en ser extraído (tipo **LIFO**).

> Describe el funcionamiento de una cola

Es una lista en la cual las inserciones y las extracciones se realizan en **extremos contrarios**, es decir, el primer dato introducido es el primero en ser extraído (tipo **FIFO**).

> Describe las ventajas y los inconvenientes de una lista implementada mediante estructuras doblemente enlazadas frente a una con estructuras de simple enlace

Una lista doblemente enlazada nos permite recorrer la lista en cualquier dirección y hace más sencillas las eliminaciones, pero tenemos que almacenar más datos (un puntero extra) en cada nodo.

> Describe las ventajas y los inconvenientes de implementar una pila con arrays frente a hacerlo con estructuras enlazadas

Con listas enlazadas, cada vez que queramos borrar un dato, tenemos que liberar su memoria, mientras que con arrays simplemente modificamos la variable de posición.

En arrays tenemos un tamaño limitado, mientras que con una lista enlazada podemos aumentar su tamaño todo lo que queramos.

> Describe las ventajas y los inconvenientes de implementar una cola con arrays frente a hacerlo con estructuras enlazadas

En arrays, a la hora de eliminar (o introducir, según introduzcamos por el final o por el principio), hay que reordenar todos los demás elementos; y el tamaño es fijo.

En estructuras enlazadas, solamente tenemos que mantener dos punteros, uno al inicio y otro al final. Tanto las inserciones como las eliminaciones son muy sencillas y eficientes.

> Tiene alguna ventaja usar una estructura doblemente enlazada para implementar una Pila

No, puesto que siempre agregamos y eliminamos por el principio.

> Tiene alguna ventaja usar una estructura doblemente enlazada para implementar una Cola

Realmente no tiene ninguna ventaja, puesto que si agregamos por el final y eliminamos por el principio, solamente necesitaríamos dos punteros.

> Describe las ventajas e inconvenientes de implementar una Lista con arrays frente a hacerlo con estructuras enlazadas

En arrays, tanto para insertar como para eliminar en posiciones arbitrarias, es necesario reordenar todos los demás elementos; pero por otro lado, es mucho más sencillo acceder a posiciones arbitrarias.

En estructuras enlazadas, para acceder a un elemento determinado, primero debemos recorrer todos los elementos anteriores, pero es más eficiente insertar y eliminar.

> Describe las ventajas e inconvenientes de usar un árbol binario de búsqueda frente a usar una lista ordenada a la hora de buscar un elemento

*Por redactar*

> Si se quiere ordenar una colección de datos ¿qué es más eficiente tenerlos en un array o en una estructura enlazada de simple enlace?

Es mucho más eficiente utilizar un array, dado que en una estructura enlazada tendríamos que recorrer los datos demasiadas veces para aplicar el mismo algoritmo de ordenación.

> Si se quiere ordenar una colección de datos ¿qué es más eficiente usar una estructura enlazada de simple enlace o un árbol binario de búsqueda?

Utilizariamos árboles binarios de búsqueda, dado que sus inserciones devuelven un árbol ordenado y la búsqueda de huecos sería más eficiente.

La forma más sencilla sería creando una nueva colección e ir insertando los elementos ordenados en el nuevo árbol.

> Si una lista vacía implementada con estructuras enlazadas lineales se representa mediante un puntero a un nodo cuyo campo de datos es ignorado y cuyo campo siguiente vale NULL. ¿Se está usando una estrategia de implementación de la lista con cabecera o sin ella?

Se trata claramente de una implementación con cabecera, pues en el caso contrario, se representaría con un puntero a NULL.

> Si usamos arrays para implementar una Lista ¿Cómo se representa la lista vacía?

El entero que representa la cantidad de elementos debería valer 0.

> Si usamos estructuras enlazadas lineales con cabecera para implementar una  Lista ¿Cómo se representa una lista vacía?

Con un puntero a un nodo cuyo campo de datos es ignorado y cuyo campo siguiente vale NULL.

#### ¿Cuál es el coste de inserción de una lista implementada con un array de tamaño fijo?

En un array podemos insertar facilmente por el final, y en el caso de hacerlo por el medio, primero hay que desplazar los siguientes elementos para hacer hueco.

Como en una lista podemos insertar en cualquier posición, diremos que el coste de inserción sería de \\(O(n)\\), pues en el peor de los casos (insertar por el principio) tendríamos que desplazar todos los elementos.
