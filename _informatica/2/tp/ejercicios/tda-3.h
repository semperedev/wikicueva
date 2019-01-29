// El tipo Complejo representa un número complejo mediante dos
// números reales: la parte real y la parte imaginaria
typedef struct ComplejoRep * Complejo;

// Devuelve un nuevo Complejo con las partes real e imaginaria
// pasadas como parámetro
Complejo crea_complejo(double r, double i);

// Devuelve un nuevo Complejo a partir de su módulo (r) y su
// ángulo (o)
Complejo crea_polares_complejo(double r, double o);

// Libera la memoria asociada al Complejo c
void libera_complejo(Complejo c);

// Muestra el Complejo c por la pantalla
void muestra_complejo(Complejo c);

// Devuelve la parte real del Complejo c
double recupera_parte_real_complejo(Complejo c);

// Devuelve la parte imaginaria del Complejo c
double recupera_parte_imaginaria_complejo(Complejo c);

// Devuelve el módulo del número complejo c
double modulo_complejo(Complejo c);

// Devuelve un nuevo número complejo resultado de sumar c y d
Complejo suma_complejo(Complejo c, Complejo d);

// Devuelve un nuevo número complejo resultado de restar c y d
Complejo resta_complejo(Complejo c, Complejo d);

// Devuelve un nuevo número complejo resultado de multiplicar c
// y d
Complejo multiplica_complejo(Complejo c, Complejo d);

// Devuelve un nuevo número complejo resultado de dividir c
// entre d
Complejo divide_complejo(Complejo c, Complejo d);

// Devuelve 1 si c == d y 0 en caso contrario
int compara_complejo(Complejo c, Complejo d);
