/**
 * 10) Muestra todos los elementos en el orden que están almacenados
 *
 * void muestra(Lista l);
 */
void muestra(Lista l) {
  Posicion aux = Lista_inicio(l);

  while (aux != Lista_fin(l)) {
    printf("%d ", Lista_recupera(l, aux));

    aux = Lista_siguiente(l, aux);
  }
}

/**
 * 11) Muestra todos los elementos en el orden contrario al que
 * están almacenados
 *
 * void muestra_reverso(Lista l);
 */
void muestra_reverso(Lista l) {
  Posicion aux = Lista_fin(l);

  do {
    aux = Lista_anterior(l, aux);

    printf("%d ", Lista_recupera(l, aux));
  } while (aux != Lista_inicio(l));
}

/**
 * 12) Devuelve 1 si la lista contiene al menos un elemento repetido y 0
 * en caso contrario
 *
 * int existe(Lista l);
 */
int existe(Lista l) {
  Posicion aux = Lista_inicio(l);

  int resultado = 0;

  while (aux != Lista_fin(l) && !resultado) {
    int x = Lista_recupera(l, aux);

    Posicion aux2 = Lista_siguiente(l, aux);

    while (aux2 != Lista_fin(l) && !resultado) {
      int n = Lista_recupera(l, aux2);

      if (n == x) {
        resultado = 1;
      }

      aux2 = Lista_siguiente(l, aux2);
    }

    aux = Lista_siguiente(l, aux);
  }

  return resultado;
}

/**
 * 13) Sustituye por b los elementos cuyo valor coincida con a
 *
 * void sustituye(Lista l, Elemento a, Elemento b);
 */
void sustituye(Lista l, Elemento a, Elemento b) {
  Posicion aux = Lista_inicio(l);

  while (aux != Lista_fin(l)) {
    if (Lista_recupera(l, aux) == a) {
      Lista_asigna(l, aux, b);
    }

    aux = Lista_siguiente(l, aux);
  }
}

/**
 * 14) Elimina todos los elementos cuyo valor sea igual a d
 *
 * void elimina(Lista l, Elemento d);
 */
void elimina(Lista l, Elemento d) {
  Posicion aux = Lista_inicio(l);
  Posicion fin = Lista_anterior(l, Lista_fin(l));

  while (aux != fin) {
    if (Lista_recupera(l, aux) == d) {
      Lista_suprime(l, aux);
    }

    aux = Lista_siguiente(l, aux);
  }
}

/**
 * 15) Devuelve una nueva lista conteniendo los elementos de l ordenados
 * de menor a mayor
 *
 * Lista recupera(Lista l);
 */
Lista recupera(Lista l) {
  Lista nueva = Lista_crea();

  Posicion aux = Lista_inicio(l);

  while (aux != Lista_fin(l)) {
    int n = Lista_recupera(l, aux);

    Posicion aux2 = Lista_inicio(nueva);

    while (aux2 != Lista_fin(nueva) && n > Lista_recupera(nueva, aux2)) {
      aux2 = Lista_siguiente(nueva, aux2);
    }

    Lista_inserta(nueva, aux2, n);

    aux = Lista_siguiente(l, aux);
  }

  return nueva;
}

/**
 * 16) Devuelve una nueva lista conteniendo los elementos de l sin
 * ninguna repetición.
 */
Lista recupera_norepetidos(Lista l) {
  Lista nueva = Lista_crea();

  Posicion aux = Lista_inicio(l);

  while (aux != Lista_fin(l)) {
    int n = Lista_recupera(l, aux);

    Posicion aux2 = Lista_inicio(nueva);

    while (aux2 != Lista_fin(nueva) && n != Lista_recupera(nueva, aux2)) {
      aux2 = Lista_siguiente(nueva, aux2);
    }

    if (aux2 == Lista_fin(nueva)) {
      Lista_inserta(nueva, aux2, n);
    }

    aux = Lista_siguiente(l, aux);
  }

  return nueva;
}
