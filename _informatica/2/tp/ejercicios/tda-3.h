/**
 * 3) Implementa el TDA Complejo, descrito a continuación:
 */

// El tipo Complejo representa un número complejo mediante dos
// números reales: la parte real y la parte imaginaria
typedef struct ComplejoRep * Complejo;

// Devuelve un nuevo Complejo con las partes real e imaginaria pasadas
// como parámetros
Complejo Complejo_crea(double r, double i);

// Devuelve un nuevo Complejo a partir de su módulo (r) y su ángulo (o)
Complejo Complejo_crea_polares(double r, double o);

// Libera la memoria asociada al Complejo c
void Complejo_libera(Complejo c);

// Muestra el Complejo c por la pantalla
void Complejo_muestra(Complejo c);

// Devuelve la parte real del Complejo c
double Complejo_recupera_parte_real(Complejo c);

// Devuelve la parte imaginaria del Complejo c
double Complejo_recupera_parte_imaginaria(Complejo c);

// Devuelve el módulo del número complejo c
double Complejo_modulo(Complejo c);

// Devuelve un nuevo número complejo, resultado de sumar c y d
Complejo Complejo_suma(Complejo c, Complejo d);

// Devuelve un nuevo número complejo, resultado de restar c y d
Complejo Complejo_resta(Complejo c, Complejo d);

// Devuelve un nuevo número complejo, resultado de multiplicar c y d
Complejo Complejo_multiplica(Complejo c, Complejo d);

// Devuelve un nuevo número complejo, resultado de dividir c entre d
Complejo Complejo_divide(Complejo c, Complejo d);

// Devuelve 1 si c == d y 0 en caso contrario
int Complejo_compara(Complejo c, Complejo d);
