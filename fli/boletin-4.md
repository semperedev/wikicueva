<!-- TITLE : Boletín 4 -->
<!-- SUBTITLE: Conceptos Básicos y Formalización en LC y L1 -->

# Boletín 4: Conceptos Básicos y Formalización en LC y L1

Este boletín se mandó como trabajo del alumno en el curso 2017/18 en la FIUM.

Se han omitido los ejercicios que por su trivialidad no aportaban ninguna información relevante para esta Wiki o su resolución era similar a la de otro ejercicio ya resuelto.

# Ejercicio 4

## Apartado A

> Qué diferencia existe entre interpretar en L0 e interpretar en L1?

Podemos verlo en su apartado en la Wiki: [Interpretar en L1](/fli/l1#interpretar-en-l1).

## Apartado B

> Explica el proceso que necesitas realizar para evaluar una expresión en L1.

Podemos verlo en su apartado en la Wiki: [Evaluar en L1](/fli/l1#evaluar-en-l1).

## Apartado C

> Si en L0, el elemento atómico “$p$” puede ser verdadero o puede ser falso, ¿cuál es la evaluación del elemento atómico “$P(x)$” en L1?

La evaluación de $P(x)$ dependerá del dominio y las relaciones del mundo en el que nos encontremos. Podemos ver más sobre esto en el apartado de la Wiki [Evaluar en L1](/fli/l1#evaluar-en-l1).

## Apartado D

> ¿Puede ser una f.b.f. la expresión $R(x, P(x))$?

Nos encontramos ante una relación $R$ de aridad dos, que necesitará dos elementos del dominio para devolver los valores de verdad $V$ o $F$, según se cumpla la relación o no.

En este caso, $P(x)$ no es un elemento del dominio, sino la evaluación de si un elemento del dominio cumple la categoría o no. Por tanto la fórmula dada **no** es una f.b.f.

## Apartado E

> ¿Qué sentido tienen las variables libres en la L1? ¿Cómo hay que tratarlas en la evaluación de expresiones en L1?

Las variables libres son elementos que no han sido modificados por cuantificadores, y por tanto no interfieren en la evaluación de dichos cuantificadores.

# Ejercicio 5

## Apartado B

> Indica cómo se representa una oración lógica que califica a un objeto en L0, LC y L1.

Ejemplo de estas oraciones:

* María es buena persona
* Mis amigos son buenas personas

### L0

$B$: Ser buena persona  
$M$: Ser María  
$A$: Ser uno de mis amigos

$ (B \land M) \lor (B \land A) $

### L1

$B(x)$: Ser buena persona  
$A(x)$: Ser uno de mis amigos  
$m$: María (constante)

$ \forall x (A(x) \to B(x)) \land B(m) $

# Ejercicio 7

> Formaliza los siguientes enunciados:

## Apartado A

> Cualquier base nitrogenada del ADN es Adenina, Citosina, Guanina o Timina. Y cualquiera dos bases se encuentran unidas por un puente de hidrógeno.

$B(x)$: Ser base nitrogenada  
$A(x)$: x es Adenina  
$C(x)$: x es Citosina  
$G(x)$: x es Guanina  
$T(x)$: x es Timina  
$P(x, y)$: x se une con y mediante un puente de hidrogeno

$ \forall x (B(x) \to (A(x) \lor C(x) \lor G(x) \lor T(x))) $  
$ \forall x \forall y (B(x) \land B(y) \to P(x, y)) $

## Apartado C

> En toda pareja de vecinos existe algún un envidioso.

$V(x)$: x es vecino  
$E(x)$: x es envidioso

$ \forall x \exists y (V(x) \land V(y) \to E(x) \lor E(y)) $

## Apartado D

> Todos los alumnos de informática son amigos de los aficionados a la lógica.

$E(x)$: x es estudiante de informatica  
$L(x)$: x es aficionado a la logica  
$A(x, y)$: x es amigo de y

$ \forall x (E(x) \to \forall y (L(y) \to A(x, y))) $

## Apartado E

> Algunos estudiantes de informática sólo son amigos de los aficionados a la lógica.

$E(x)$: x es estudiante de informatica  
$L(x)$: x es aficionado a la logica  
$A(x, y)$: x es amigo de y

$ \exists x (E(x) \land \forall y (L(y) \to A(y, x)) \land \forall z (\neg L(z) \to \neg A(z, x))) $

## Apartado F

> Toda recta contiene por los menos dos puntos.

$R(x)$: x es una recta  
$P(x)$: x es un punto  
$C(x, y)$: x contiene a y

$ \forall x (R(x) \to \exists y \exists z (P(y) \land P(z) \land C(x,y) \land C(x,z))) $

## Apartado G

> Si A y B son dos puntos, existe una y sólo una recta que contiene a estos puntos.

$ $

## Apartado H

> Si A es un punto y R es una recta que no contiene al punto A, entonces existe una recta que contiene al punto A y no intercepta a R.

$ $

# Ejercicio 8

## Apartado A

> Existen alumnos cuyo siguiente en el orden alfabético es aficionado al cine.

$A(x)$: x es alumno  
$C(x)$: x aficionado al cine  
$S(x, y)$: x es siguiente en orden alfabetico a y

$ \exists x (A(x) \land \forall y (A(y) \to S(y, x) \land C(y))) $

## Apartado B

> Ningún número resultado del producto de dos números naturales es un número primo.

$N(x)$: x es un numero natural  
$P(x)$: x es un numero primo  
$R(x, y, z)$: z es resultado del producto de x e y

$ \forall x \forall y (N(x) \land N(y)) \to \forall z (R(z,x,y) \to \neg P(z)) $

# Ejercicio 9

## Apartado A

$A(x)$: x es acusado  
$C(x)$: x es culpable  
$I(x)$: x es inocente  
$CT(x)$: x tiene la conciencia tranquila  
$CO(x)$: x tiene coartada  
$T(x, y)$: x testifica contra y  
$r$: Ramón (constante)

$ \forall x (A(x) \land C(x) \to \forall y (A(y) \land I(y) \to T(x, y))) $  
$ \forall x (C(x) \to \neg CT(x)) $  
$ \forall x (I(x) \land CO(x) \to CT(x)) $  
$ \vdash T(r, r) \to \neg CO(r) $

## Apartado B

> La sal y el azúcar son blancos. La sal no es el azúcar. Por lo tanto, nada es blanco.

$ D: \\{s, a\\} $  
$B(x)$: x es blanco

$ B(s) \land B(a) \land (s \to \neg a) \vdash \neg \exists z B(z) $
