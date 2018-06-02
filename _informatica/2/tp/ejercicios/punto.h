typedef struct PuntoRep * Punto;

Punto Punto_crea(double x, double y);
void Punto_libera(Punto p);

void Punto_muestra(Punto p);
double Punto_recupera_x(Punto p);
double Punto_recupera_y(Punto p);

void Punto_modifica(Punto p, double x, double y);
