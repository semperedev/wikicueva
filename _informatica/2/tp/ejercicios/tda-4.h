// El tipo Matriz representa una Matriz de las usadas en álgebra
// Los valores almacenados serán de tipo real
typedef struct MatrizRep * Matriz;

// Devuelve una nueva Matriz con f filas y c columnas
Matriz crea_matriz(int f, int c);

// Devuelve una nueva Matriz cuadrada con n filas y n columnas
// con todos los elementos de su diagonal iguales a 1.0
Matriz matriz_identidad(int n);

// Libera la memoria asociada a la Matriz m
void libera_matriz(Matriz m);

// Muestra la Matriz m por la pantalla
void muestra_matriz(Matriz m);

// Devuelve el valor que situado en la fila f y columna c
double recupera_valor_matriz(Matriz m, int f, int c);

// Asigna el valor r a la posición de la fila f y columna c
void asigna_valor_matriz(Matriz m, int f, int c, double r);

// Devuelve el número de filas de la Matriz m
int recupera_filas_matriz(Matriz m);

// Devuelve el número de columnas de la Matriz m
int recupera_columnas_matriz(Matriz m);

// Devuelve una nueva Matriz resultado de multiplicar todos los
// valores de m por esumar m y n siempre
Matriz escala_matriz(Matriz m, double e);

// Devuelve una nueva Matriz resultado de sumar m y n siempre
// que sea posible hacerlo. En caso contrario devuelve NULL
Matriz suma_matriz(Matriz m, Matriz n);

// Devuelve una nueva Matriz resultado de multiplicar m y n
// siempre que sea posible hacerlo. En caso contrario devuelve
// NULL
Matriz multiplica_matriz(Matriz m, Matriz n);

// Devuelve una nueva Matriz resultado de trasponer m
Matriz matriz_traspuesta(Matriz m);
