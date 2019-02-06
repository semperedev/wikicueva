#include <stdio.h>
#include <stdlib.h>

#include "tda-8.h"

char * duplica(char * cadena) {
  int n = 1;

  while (cadena[n] != '\0') {
    n = n + 1;
  }

  char * copia = malloc(sizeof(char) * n);

  for (int i = 0; i < n; i = i + 1) {
    copia[i] = cadena[i];
  }

  return copia;
}

struct ContactoRep {
  char * nom, * tel;
};

Contacto crea_contacto(char * nombre) {
  Contacto c = malloc(sizeof(struct ContactoRep));

  c->nom = duplica(nombre);
  c->tel = duplica("000 000 000");

  return c;
}

void libera_contacto(Contacto c) {
  free(c->nom);
  free(c->tel);
  free(c);
}

void muestra_contacto(Contacto c) {
  printf("%s - %s\n", c->nom, c->tel);
}

char * recupera_nombre_contacto(Contacto c) {
  return duplica(c->nom);
}

char * recupera_tlf_contacto(Contacto c) {
  return duplica(c->tel);
}

void modifica_tlf_contacto(Contacto c, char * tlf) {
  free(c->tel);
  c->tel = duplica(tlf);
}
