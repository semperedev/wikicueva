// El tipo Rectangulo representa un rectángulo en el plano
typedef struct RectanguloRep * Rectangulo;

// Devuelve un nuevo Rectangulo cuya esquina superior izquierda
// estará situada en las coordenadas (x,y) y tendrá la anchura y
// altura indicadas. Todos los valores serán de tipo entero.
Rectangulo crea_rectangulo(int x, int y, int ancho, int alto);

// Libera la memoria asociada al Rectangulo r
void libera_rectangulo(Rectangulo r);

// Muestra el Rectangulo r por la pantalla
void muestra_rectangulo(Rectangulo r);

// Devuelve la coordenada x del Rectangulo r
int recupera_x_rectangulo(Rectangulo r);

// Devuelve la coordenada y del Rectangulo r
int recupera_y_rectangulo(Rectangulo r);

// Modifica las coordenadas del Rectangulo r
void modifica_rectangulo(Rectangulo r, int x, int y);

// Devuelve 1 si el punto (x,y) está dentro del rectángulo r
int dentro_rectangulo(Rectangulo r, int x, int y);
