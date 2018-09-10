---
title: Conceptos básicos de C
---

Dando por hecho que ya hemos trabajado con Pascal y tenemos unos conocimientos básicos de programación, vamos a ver de forma muy breve las principales novedades que aporta C.

### Programa en C

Comenzaremos con el ejemplo clásico de Hola Mundo:

```c
#include <stdio.h>

int main() {
  printf("Hola mundo\n");

  return 0;
}
```

La primera línea se trata de una instrucción del compilador: estamos incluyendo en nuestro programa la librería `stdio.h`, que es la librería estándar de entrada-salida en C; esta librería nos permite utilizar la función `printf` para mostrar la cadena _Hola Mundo_.

Todo programa en C requiere de una función `main`, que es el punto de entrada del programa. Opcionalmente podríamos utilizar dos argumentos (`int argc, const char* argv[]`) para recibir los argumentos de la ejecución, pero esto queda fuera del ámbito del artículo. La función `main` debe devolver tipo entero (`int`).

El cuerpo de la función es muy sencillo: llamamos a la función `printf` y devolvemos el valor `0` (indica que no hay errores en el programa).

#### Compilar

> Todos los ejemplos de este sitio son para Linux

Para compilar un programa de un único archivo `.c` simplemente utilizaremos `GCC`, el Compilador de C de GNU:

```
gcc -std=c99 -c NOMBRE_ARCHIVO.c -o NOMBRE_SALIDA
```

Ya que estamos trabajando con la versión C99, incluimos la etiqueta `-std=c99`.

### Módulos

Para estructurar mejor nuestro programa y no escribirlo todo en el mismo archivo, vamos a dividir el código en módulos, es decir, archivos que agrupan funciones, estructuras, constantes... con un propósito similar.

En C vamos a encontrar dos tipos de archivos para definir estos módulos: `.h` y `.c`, en el primero encontraremos la parte pública de un módulo (o definición), y en el segundo la parte privada (o implementación).

Podemos escribir cuantas implementaciones queramos para una misma definición.

#### Compilar

En nuestro código C hemos incluído los archivos de definición que queremos usar, pero debemos indicarle al compilador dónde están las implementaciones para esas definiciones.

Para lograr esto, primero compilaremos todos los módulos junto a nuestro `main` con `GCC` y luego los uniremos utilizando `G++`:

```
gcc -std=c99 -c modulo1.c -o modulo1.o
gcc -std=c99 -c modulo2.c -o modulo2.o
gcc -std=c99 -c main.c -o main.o

g++ modulo1.o modulo2.o main.o -o main
```

Un par de anotaciones:

* Hemos utilizado `main.o` y similares, pero podríamos haber utilizado cualquier otro nombre.
* El orden en el que compilemos o enlacemos los archivos no importa.
