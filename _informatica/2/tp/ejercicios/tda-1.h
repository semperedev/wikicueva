/**
 * 1) Implementar el TDA Punto, descrito a continuación:
 */

// El tipo Punto representa un punto en el plano real
typedef struct PuntoRep * Punto;

// Devuelve un nuevo Punto con las coordenadas (x, y)
Punto Punto_crea(double x, double y);

// Libera la memoria asociada al Punto p
void Punto_libera(Punto p);

// Muestra el Punto p por la pantalla
void Punto_muestra(Punto p);

// Devuelve la coordenada x del Punto p
double Punto_recupera_x(Punto p);

// Devuelve la coordenada y del Punto p
double Punto_recupera_y(Punto p);

// Modifica las coordenadas del Punto p
void Punto_modifica(Punto p, double x, double y);
