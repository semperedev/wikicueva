---
title: Tema 1 - Introducción
---

[&lt;&lt; Volver a **ISO**](../iso.md)

* Tabla de Contenidos
{:toc}

## ¿Qué es un Sistema Operativo?

Podemos decir que un SO es un intermediario entre el usuario y el hardware de un ordenador. Se trata de la capa software inmediatamente superior al hardware.

Dada la amplitud de funciones de un SO, no existe una clasificación exacta, pero podemos diferenciar dos posiciones principales:

#### Máquina virtual

El SO es el encargado de ocultar el hardware a las capas superiores, proporcionando una interfaz de mayor nivel y dotando al hardware de capacidades extra: multiples procesos, sistemas de ficheros...

#### Controlador de recursos

Del mismo modo, el SO se encarga de asignar los distintos recursos del ordenador (memoria, CPU, dispositivos E/S) a cada proceso del sistema, a la vez que protege la información de cada uno de ellos.

### Resumiendo

Un sistema operativo es simplemente un programa muy extenso encargado de gestionar el hardware; este hecho propicia que las características de un SO suelan estar condicionadas por el hardware sobre el que se ejecuta.

## Protección del SO

Para asegurar el correcto funcionamiento de un SO, es necesario que el hardware subyacente disponga de tres elementos importantes de protección:

#### Modos de ejecución

El procesador debe disponer de, al menos, dos modos de ejecución: **núcleo y usuario**; siendo el primero un modo privilegiado (o supervisor) que puede ejecutar cualquier instrucción.

Mientras que el modo usuario está restringido, bloqueando el acceso a ciertas instrucciones, como por ejemplo las de E/S. Esto obliga a los procesos en modo usuario a pedir al SO que actúe en la E/S en su lugar, generalmente utilizando llamadas al sistema.

#### Protección de la memoria

Un proceso no privilegiado no puede acceder a las zonas de memoria de otros procesos. Si no fuese así, cualquier programa podría modificar la configuración del SO y hacerse con el control de la máquina.

#### Interrupciones periódicas

El hardware debe disponer de una señal específica de reloj que produzca interrupciones periodicamente y devuelva el control al SO para evitar que un proceso se apropie de la CPU.

### Nota

Es necesario que el hardware disponga de **todos** los mecanismos de protección.

## Historia y evolución

### Primera generación: válvulas y conexiones

Grandes máquinas formadas por miles de válvulas de vacío. El programador reservaba la máquina durante un determinado tiempo, propiciando dos situaciones: que el trabajo se terminase antes, con lo cual la máquina quedaba ociosa; o que el trabajo no se terminase, teniendo que reservar de nuevo y alargando el periodo de desarrollo.

La programación era completamente en lenguaje máquina y el propio programador debía incluir las rutinas de E/S.

### Segunda generación: transistores y sistemas de procesamiento por lotes

La aparición del transistor provocó que las máquinas se volviesen más fiables y se pudiesen proporcionar al público general, creando una clara separación entre diseñador del sistema y usuario del mismo.

Aparecieron los ensambladores, enlazadores... y las librerías de E/S. Aunque el programador seguía siendo responsable de preparar y utilizar la máquina, lo cual seguía provocando pérdidas de tiempo en algunos casos; para solucionar esto apareció la figura del _operador profesional_: el programador entregaba los trabajos al operador y éste le devolvía los resultados de la máquina. Una segunda medida para evitar pérdidas de tiempo consistió en agrupar los trabajos por características comunes tales como el lenguaje de programación.

Para agilizar el trabajo se crearon los primeros _sistemas operativos_, un tipo de programa denominado **monitor residente**, encargado de interpretar tarjetas de control situadas entre las tarjetas de datos de la máquina; de esta forma, los trabajos se podían ejecutar uno detrás de otro sin parar la CPU.

Apareció también la llamada _operación fuera de línea_, que consistía en ocupar la E/S lenta con CPUs sencillas para pasar los datos a la CPU más potente utilizando dispositivos E/S rápidos (como las cintas). Sobre esta técnica se desarrolló una forma de optimizar el proceso aún más: eliminando las terceras máquinas necesarias para llenar las cintas.

#### Buffers

El sistema era sencillo: cuando el dispositivo de E/S proporcionaba la entrada a la CPU, ésta le ordenaba seguir leyendo, y los datos se almacenaban en una memoria temporal para después ser leídos. Se logra así que la CPU y la E/S trabajen de forma simultánea, ahorrando tiempo.

Para que este método sea eficiente, es necesario que la CPU no intervenga en la trasferencia de datos entre la E/S y la memoria.

#### Spoolers

Este método consiste en almacenar la información de los dispositivos de E/S en disco, de esta forma, el programa en ejecución deposita su salida en disco y los programas que se ejecutarán posteriormente dispondrán de toda la información necesaria sin tener que realizar su E/S durante su ejecución.

Trabajando de esta forma logramos que se obtenga E/S de trabajos distintos a los que se están ejecutando, agilizando mucho más el procesamiento.

### Tercera generación: circuitos integrados y multiprogramación

La multiprogramación nos permite tener varios trabajos en memoria, de forma que cuando uno no puede continuar su ejecución (por ejemplo, debido a la E/S), la CPU procede con otro trabajo. Aparece así la necesidad de planificar los trabajos, de forma que no interfieran unos con otros y todos se ejecuten correctamente.

Aparece también una variante de la multiprogramación: el tiempo compartido o multitarea, que consiste en cambiar rápidamente entre trabajos, de forma que el usuario tenga la sensación de tener toda la máquina a su disposición.

Durante este periodo aparecieron SSOO importantes como OS/360 o MULTICS.

### Cuarta generación: ordenadores personales

Debido a los avances tecnológicos, se vuelve posible integrar millones de transistores en pequeños circuitos integrados, gracias a lo cual disminuye el precio de los equipos y permite su popularización. Aparecen MS-DOS y UNIX, los grandes SSOO de los ordenadores personales y las estaciones de trabajo.

Durante la década de los 80 comienzan a aparecer las redes de ordenadores, dando lugar a SSOO en red.

### Quinta generación: Internet y dispositivos móviles

Observamos la puesta en escena de los SSOO actuales como Windows, Linux o macOS. Y con la explosión de internet se propulsaron los dispositivos conectados como los teléfonos inteligentes, popularizados con la aparición del iPhone, y los SSOO que utilizaban: Android e iOS.

## Tipos de SO

Principalmente encontraremos sistemas operativos de propósito general, diseñados para realizar tareas de muy diverso tipo en entornos muy variados. Están caracterizados por su flexibilidad y capacidad de adaptación. Por ejemplo: Windows, Unix y macOS, entre otros.

Aunque podríamos utilizar solamente SO de propósito general, generalmente encontraremos distintos SO dependiendo del sistema que utilicemos:

#### Supercomputadores

Son sistemas formados por un gran número de componentes conectados en red, capaces de procesar grandes cantidades de datos con un gran rendimiento. El SO más utilizado en supercomputadores es Unix.

#### Mainframes

Los mainframes son sistemas diseñados para trabajar con una gran cantidad de E/S, principalmente para trabajos por lotes, transacciones o multitarea. De nuevo, el SO predominante es Unix.

#### Servidores

Se trata de sistemas que permiten compartir software y hardware de un computador a múltiples usuarios a través de la red.

#### Sistemas personales

Los sistemas personales están diseñados para proporcionar buen rendimiento y capacidad de multitarea a un único usuario; el SO mayoritario es [Windows](https://www.microsoft.com/en-us/windows), seguido de [macOS](https://www.apple.com/macos/) y las distribuciones basadas en [Linux](https://en.wikipedia.org/wiki/List_of_Linux_distributions).

#### Sistemas integrados

Son pequeños ordenadores con un hardware reducido, por ejemplo, tabletas o _smartphones_. Generalmente utilizan los mismos SOs que los sistemas personales, pero adaptados a los dispositivos específicos y sus capacidades.

> Tanto los sistemas personales como los integrados podrían también ser clasificados como **sistemas operativos en red**, pues son capaces de identificar e interactuar con otros sistemas conectados a la misma red.

#### Sistemas distribuidos

Igual que los sistemas en red, los sistemas distribuidos requieren de la red para funcionar, salvo que en este caso el usuario dispone de la visión de un único sistema operativo, a pesar de que sus funcionalidades se reparten entre varios computadores.

Ventajas de este tipo de sistemas serían la posibilidad de compartir recursos en distintas localizaciones o la aceleración de cálculos.

Ejemplos de estos SO serían [Amoeba](https://www.cs.vu.nl/pub/amoeba/) o [Plan 9](https://9p.io/plan9/); aunque la mayoría o no se desarrollan o llevan mucho tiempo sin recibir actualizaciones.

#### Sistemas en tiempo real

Se encuentran limitados por restricciones temporales. Podemos diferenciar entre rigurosos y no rigurosos.

Los rigurosos deben realizar una acción en un instante determinado, produciéndose situaciones críticas cuando no es así.

Por el contrario, en los no rigurosos se permiten algunos fallos siempre que se encuentren en un cierto intervalo de tolerancia.

Ejemplos de este tipo serían [VxWorks](https://www.windriver.com/products/vxworks/) o [QNX](https://blackberry.qnx.com/en).

#### Tarjetas inteligentes

Debido a las grandes limitaciones de recursos, estos sistemas sólo pueden realizar determinadas tareas. Generalmente disponen de una máquina virtual de Java donde ejecutar _applets_.

## Componentes y servicios

Internamente, los sistemas operativos se encuentran divididos en _módulos_; y ofrecen una interfaz que el programador puede utilizar mediante llamadas al sistema.

### Componentes del sistema

Antes de continuar vamos a realizar una distinción entre proceso y programa:

* Programa: código y datos almacenados en disco (entidad pasiva)
* Proceso: programa en ejecución almacenado en memoria (entidad activa)

#### Administración de procesos

Un proceso es la unidad de trabajo de un sistema. Algunos procesos pertenecen al SO (ejecutan código del sistema) mientras que los demás pertenecen al usuario. Los procesos requieren de ciertos recursos: CPU, memoria, E/S... que el SO debe proporcionar a cada proceso de forma correcta y equitativa.

Esencialmente, el SO se encarga de crear, eliminar, suspender y reanudar procesos del usuario y del sistema, así como de proporcionar los mecanismos necesarios para la comunicación entre procesos.

#### Administración de la memoria principal

La memoria es una parte esencial de cualquier computador: para que un programa se ejecute necesitamos que su código se encuentre en la memoria.

Ya que la memoria se comparte dentro de un mismo sistema, es necesario repartirla adecuadamente entre todos los procesos.

El SO es responsable de mantener un registro de las zonas de memoria de cada proceso y administrar dichas zonas correctamente.

#### Administración de E/S

Una de las tareas principales del SO es ocultar la implementación de la E/S tras una interfaz uniforme. Por ejemplo, en UNIX se utilizan manejadores de dispositivos, que son los únicos elementos de software que conocen las particularidades del hardware al que respaldan.

Un elemento de E/S importante es el almacenamiento secundario, que respalda a la memoria principal.

#### Administración de ficheros

Se encarga de gestionar los dispositivos de almacenamiento secundario mediante la abstracción hacia ficheros agrupados en directorios, de esta forma un sistema de ficheros muestra la misma interfaz independientemente del dispositivo sobre el que se soporta.

El SO se encarga de la creación y eliminación de ficheros y directorios, así como de todas las operaciones posibles sobre dichos elementos.

#### Sistema de protección

Los procesos de un sistema deben estar protegidos unos de otros, así como los recursos que utilizan, de forma que la información de cada proceso no pueda ser accedida desde otros lugares.

Ya hemos visto tres formas de implementar protección mediante hardware.

### Servicios del SO

El SO proporciona una interfaz para el usuario que podemos clasificar de la siguiente forma:

* Ejecución de programas
* Operaciones de E/S: los programas de usuario no pueden ejecutar E/S, por lo que el SO proporciona una forma de solicitar dichas operaciones
* Gestión del sistema de ficheros
* Comunicaciones: en ocasiones, los procesos pueden necesitar comunicarse entre ellos, utilizando herramientas del SO como tuberías o memoria compartida
* Detección de errores

Igualmente, también existen ciertos servicios para asegurar el correcto funcionamiento del sistema:

* Asignación de recursos
* Contabilidad: se trata de establecer métricas del uso de los recursos
* Protección: en un sistema multiusuario es necesario asegurar que un usuario sólo puede acceder a la información de la cual tiene permisos

### Llamadas al sistema

Definen la interfaz entre el SO y un proceso. Las llamadas pasan el control al SO, cambiando a modo núcleo; tras una llamada al sistema correcta, se cambia a modo usuario y el SO devuelve el control al proceso.

No existe una llamada al sistema para cada tipo de solicitud, sino que el proceso indica el número de servicio que desea realizar y proporciona los datos necesarios para realizar dicho servicio; para ello disponemos de tres métodos generales:

* Pasar parámetros en los registros
* Utilizar un bloque de memoria y pasar la dirección en un registro
* Pasar los parámetros mediante la pila

Las bibliotecas de lenguajes de alto nivel ocultan las llamadas con procedimientos más sencillos (por ejemplo `fopen` en C).

Podemos clasificar las llamadas al sistema en cinco grandes grupos: comunicación, control de procesos, manipulación de ficheros, manipulación de dispositivos y mantenimiento de información.

### Programas del sistema

Los sistemas operativos modernos proporcionan al usuario ciertos programas que facilitan su uso:

* Manipulación de ficheros: por ejemplo, el explorador de archivos de Windows.
* Información de estado: proporcionan datos formateados como la fecha o el espacio de memoria disponible.
* Apoyo a lenguajes de programación: se trata de compiladores e intérpretes.
* Comunicaciones: proporcionan el mecanismo para crear conexiones virtuales entre diferentes procesos o sistemas.
* Programas de aplicación: se trata de las aplicaciones comunes tales como editores de texto, hojas de cálculo, juegos...

Desde el punto de vista del SO, estos programas no tienen diferencia respecto a los programas del usuario.

El programa más importante probablemente sea el intérprete de comandos (cmd en Windows o bash en Linux), que permite al usuario ejecutar órdenes en el sistema.
