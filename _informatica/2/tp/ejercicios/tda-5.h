// El tipo Monomio representa una expresión algebraica de un
// solo término con la forma cx^n siendo c el coeficiente y n el
// exponente. C será un número real y n un entero
typedef struct MonomioRep * Monomio;

// Devuelve un nuevo monomio representando a coef * X^exp
Monomio crea_monomio(double coef, int exp);

// Libera la memoria asociada al monomio m
void libera_monomio(Monomio m);

// Muestra el monomio m por la pantalla
void muestra_monomio(Monomio m);

// Devuelve el coeficiente del monomio m
double recupera_coeficiente_monomio(Monomio m);

// Devuelve el exponente del monomio m
int recupera_exponente_monomio(Monomio m);

// Asigna el coef como coeficiente del monomio m
void modifica_coeficiente_monomio(Monomio m, double coef);

// Devuelve el resultado de hacer cx^n
double evalua_monomio(Monomio m, double x);
