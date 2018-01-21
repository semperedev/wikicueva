<!-- TITLE: Introducción a la Sintaxis de Pascal -->

# Introducción a la Sintaxis de Pascal

# Estructura de un fichero .pas

1. Nombre del programa
2. Librerias y unidades
3. Definición de Tipos
4. Definición de Variables
5. Funciones y procedimientos
6. Algoritmo principal

# Variables y Tipos

## Definición de Tipos

En el primer bloque que definimos, tras el nombre del programa y las librerías que usamos, definimos el bloque `type`.

### Producto de Tipos

Creamos una estructura con propiedades de tipos elementales.

```pascal
type
	nombreTipo = record begin
		propiedad1 : tipoBase;
		propiedad2 : tipoBase;
	end;
```

### Rango

Definimos un rango desde N hasta M, siendo N y M tipos ordinales: caracteres, enteros...

```pascal
type
	rangoNumeros = N..M;
```

### Enumerado

Definimos un tipo con dominio. Sus elementos se convierten en ordinales

```pascal
type
	enumerado = (elemento1, elemento2, elemento3);
```

### Tablas

Creamos una tabla (opcionalmente, de varias dimensiones) definiendo el tipo de los índices y el tipo base.

Los índices pueden ser enteros (definiendo un rango), o un tipo ordinal (base o enumerado).

```pascal
type
	tablaEnteros = array [indice] of tipoBase;
```

### Ejemplos

```pascal
type
	mesDelAnio = record begin
		nombre : string;
		numero : integer;
	end;

	mesesDelAnio = 1..12;

	mesesNombres = (Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre);

	tablaMeses = array [mesesDelAnio] of mesesNombres;
```

# Funciones y Procedimientos

La principal diferencia entre unos y otros es que una función devuelve un valor directamente, y un procedimiento **puede** hacerlo mediante un parámetro de salida.

Tanto dentro de procedimientos como de funciones podemos utilizar variables locales del bloque y variables globales del archivo. Además, utilizamos parámetros para pasar datos hacia su léxico local.

## Procedimientos

En procedimientos, devolvemos los valores a través de parámetros de salida o entrada-salida, que denotaremos con la palabra clave `var`.

```pascal
procedure nombreDelProcedimiento(parametro, parametro2 : tipoParametros; var parametro3 : tipoParametro3);
var
	variableLocal : tipoVariable;

begin
	<Cuerpo del algoritmo>
end;
```

### Ejemplo

```pascal
program ejemploProcedimiento;

// Variables globales
var
	entrada : integer;

// Procedimiento con un parámetro de entrada (texto) y uno de entrada-salida (numero)
procedure ObtenerNumero(texto : string; var numero : integer);
begin
	write(texto);
	readln(numero);
end;

// Algoritmo principal
begin
	ObtenerNumero('Introduzca un número: ', entrada);

	writeln('Número introducido: ', entrada);
end.
```

## Funciones

En funciones, los valores los devolvemos asignando el valor al nombre de la función, y especificamos el tipo de la variable de retorno en la propia definición.

```pascal
function nombreDeLaFuncion(parametro : tipoParametro) : tipoDeRetorno;
begin
	<Cuerpo del algoritmo>

	nombreDeLaFuncion := valorDeRetorno;
end;
```
