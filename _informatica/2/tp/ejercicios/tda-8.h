// El tipo Contacto representa la información de contacto de una
// persona conocida. En concreto su nombre y su teléfono.
// Tanto el nombre como el teléfono serán cadenas de caracteres
// de longitud máxima no limitada.
typedef struct ContactoRep * Contacto;

// Devuelve un nuevo Contacto para la persona llamada nombre
// El teléfono asignado por defecto será “000 000 000”
Contacto crea_contacto(char * nombre);

// Libera la memoria asociada al Contacto c
void libera_contacto(Contacto c);

// Muestra el Contacto c por la pantalla
void muestra_contacto(Contacto c);

// Devuelve una copia en memoria dinámica del nombre del Contacto c
char * recupera_nombre_contacto(Contacto c);

// Devuelve una copia en memoria dinámica del tlf del Contacto c
char * recupera_tlf_contacto(Contacto c);

// Modifica el teléfono del Contacto c pasando a ser tlf
void modifica_tlf_contacto(Contacto c, char * tlf);
