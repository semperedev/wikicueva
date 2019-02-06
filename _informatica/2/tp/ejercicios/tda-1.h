// El tipo Punto representa un punto en el plano real
typedef struct PuntoRep * Punto;

// Devuelve un nuevo Punto con las coordenadas (x,y)
Punto crea_punto(double x, double y);

// Libera la memoria asociada al Punto p
void libera_punto(Punto p);

// Muestra el Punto p por la pantalla
void muestra_punto(Punto p);

// Devuelve la coordenada x del Punto p
double recupera_x_punto(Punto p);

// Devuelve la coordenada y del Punto p
double recupera_y_punto(Punto p);

// Modifica las coordenadas del Punto p
void modifica_punto(Punto p, double x, double y);
