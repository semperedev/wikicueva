/**
 * 1) Construye y devuelve un árbol general con un único nodo cuyo
 * valor sea d
 *
 * ArbolGeneral crea(Elemento d);
 */
ArbolGeneral crea(Elemento d) {
  ArbolGeneral a = malloc(sizeof(struct Nodo));

  a->elem = d;

  a->primerHijo = NULL;
  a->hermanoDerecho = NULL;

  return a;
}

/**
 * 2) Construye y devuelve un árbol general cuya raíz tenga valor 1, el hijo
 * valor 2 y el hermano valor 3.
 *
 * ArbolGeneral crea_lleno();
 */
ArbolGeneral crea_lleno() {
  ArbolGeneral a = malloc(sizeof(struct Nodo));

  a->elem = 1;

  a->primerHijo = crea(2);
  a->hermanoDerecho = crea(3);

  return a;
}

/**
 * 3) Muestra todos los valores en preorden
 *
 * void muestra_preorden(ArbolGeneral a);
 */
void muestra_preorden(ArbolGeneral a) {
  if (a == NULL) {
    return;
  }

  printf("%d ", a->elem);

  ArbolGeneral aux = a->primerHijo;

  while (aux != NULL) {
    muestra_preorden(aux);

    aux = aux->hermanoDerecho;
  }
}

/**
 * 5) Muestra todos los valores en postorden
 *
 * void muestra_postorden(ArbolGeneral a);
 */
void muestra_postorden(ArbolGeneral a) {
  if (a == NULL) {
    return;
  }

  ArbolGeneral aux = a->primerHijo;

  while (aux != NULL) {
    muestra_postorden(aux);

    aux = aux->hermanoDerecho;
  }

  printf("%d ", a->elem);
}

/**
 * 6) Libera toda la memoria del árbol a
 *
 * void libera(ArbolGeneral a);
 */
void libera(ArbolGeneral a) {
  if (a == NULL) {
    return;
  }

  libera(a->primerHijo);
  libera(a->hermanoDerecho);

  free(a);
}

/**
 * 7) Devuelve el número de nodos del árbol a
 *
 * int cuenta(ArbolGeneral a);
 */
int cuenta(ArbolGeneral a) {
  if (a == NULL) {
    return 0;
  }

  return 1 + cuenta(a->primerHijo) + cuenta(a->hermanoDerecho);
}

/**
 * 8) Devuelve el número de hojas del árbol a
 *
 * int cuenta_hojas(ArbolGeneral a);
 */
int cuenta_hojas(ArbolGeneral a) {
  if (a == NULL) {
    return 0;
  }

  return (
    (a->primerHijo == NULL)
    + cuenta_hojas(a->primerHijo)
    + cuenta_hojas(a->hermanoDerecho)
  );
}

/**
 * 9) Devuelve el número de nodos intermedios del árbol a
 *
 * int cuenta_intermedios(ArbolGeneral a);
 */
int cuenta_intermedios(ArbolGeneral a) {
  if (a == NULL) {
    return 0;
  }

  return (
    (a->primerHijo != NULL)
    + cuenta_intermedios(a->primerHijo)
    + cuenta_intermedios(a->hermanoDerecho)
  );
}

/**
 * 12) Devuelve el número de nodos intermedios del árbol cuyo valor sea
 * distinto a cualquiera de los valores del array m
 *
 * int cuenta(ArbolGeneral a, Elemento m[], int n);
 */
int cuenta_distinto(ArbolGeneral a, Elemento m[], int n) {
  if (a == NULL) {
    return 0;
  }

  int c = 0;

  if (a->primerHijo != NULL) {
    c = 1;

    for (int i = 0; i < n && c == 1; i++) {
      if (a->elem == m[i]) {
        c = 0;
      }
    }
  }

  c += cuenta_distinto(a->primerHijo, m, n);
  c += cuenta_distinto(a->hermanoDerecho, m, n);

  return c;
}

/**
 * 13) Devuelve la suma de los valores de todos los nodos del árbol a
 *
 * int suma(ArbolGeneral a);
 */
int suma(ArbolGeneral a) {
  if (a == NULL) {
    return 0;
  }

  int n = a->elem;

  n += suma(a->primerHijo);
  n += suma(a->hermanoDerecho);

  return n;
}


/**
 * 14) Devuelve 1 si el árbol contiene el elemento d y 0 en caso contrario
 *
 * int existe(ArbolGeneral a, Elemento d);
 */
int existe(ArbolGeneral a, Elemento d) {
  if (a == NULL) {
    return 0;
  }

  if (a->elem == d) {
    return 1;
  }

  return existe(a->primerHijo, d) || existe(a->hermanoDerecho, d);
}

/**
 * 15) Devuelve el mayor de los valores guardados en los nodos del árbol,
 * suponiendo que todos los valores son mayores que cero
 *
 * int maximo(ArbolGeneral a);
 */
int maximo(ArbolGeneral a) {
  if (a == NULL) {
    return 0;
  }

  int max = a->elem;
  int maxHermano = maximo(a->hermanoDerecho);
  int maxHijo = maximo(a->primerHijo);

  if (maxHermano > max) {
    max = maxHermano;
  }

  if (maxHijo > max) {
    max = maxHijo;
  }

  return max;
}

/**
 * 16) Devuelve la altura del árbol, es decir, la longitud del camino
 * más largo de la raíz a cualquiera de sus descendientes
 *
 * int altura(ArbolGeneral a);
 */
int altura(ArbolGeneral a) {
  if (a == NULL || a->primerHijo == NULL) {
    return 0;
  }

  ArbolGeneral aux = a->primerHijo;
  int max = 0;

  while (aux != NULL) {
    int a = altura(aux);

    if (a > max) {
      max = a;
    }

    aux = aux->hermanoDerecho;
  }

  return 1 + max;
}

/**
 * 17) Agrega a cada hoja dos nuevos hijos: uno con el valor del
 * doble del padre, y otro el doble más uno
 *
 * void amplia(ArbolGeneral a);
 */
void amplia(ArbolGeneral a) {
  if (a == NULL) {
    return;
  }

  amplia(a->hermanoDerecho);

  if (a->primerHijo == NULL) {
    a->primerHijo = crea(a->elem * 2);
    a->primerHijo->hermanoDerecho = crea(a->elem * 2 + 1);
  }
  else {
    amplia(a->primerHijo);
  }
}

/**
 * 18) Devuelve 1 si los dos árboles pasados como parámetros son iguales
 * y 0 en caso contrario
 *
 * int compara(ArbolGeneral a, ArbolGeneral b);
 */
int compara(ArbolGeneral a, ArbolGeneral b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  if (a->elem != b->elem) {
    return 0;
  }

  return (
    compara(a->primerHijo, b->primerHijo) &&
    compara(a->hermanoDerecho, b->hermanoDerecho)
  );
}

/**
 * 19) Devuelve un árbol idéntico al pasado como parámetro
 *
 * ArbolGeneral copia(ArbolGeneral a);
 */
ArbolGeneral copia(ArbolGeneral a) {
  if (a == NULL) {
    return NULL;
  }

  ArbolGeneral c = crea(a->elem);

  c->primerHijo = copia(a->primerHijo);
  c->hermanoDerecho = copia(a->hermanoDerecho);

  return c;
}

/**
 * 20) Devuelve una lista con los elementos contenidos en el árbol
 *
 * CeldaPtr enumera(ArbolGeneral a);
 */
CeldaPtr enumera(ArbolGeneral a) {
  if (a == NULL) {
    return NULL;
  }

  CeldaPtr nuevo = malloc(sizeof(struct Celda));

  nuevo->elem = a->elem;
  nuevo->sig = enumera(a->primerHijo);

  CeldaPtr hermanos = enumera(a->hermanoDerecho);

  if (hermanos != NULL) {
    CeldaPtr aux = nuevo;

    while (aux->sig != NULL) {
      aux = aux->sig;
    }

    aux->sig = hermanos;
  }

  return nuevo;
}
