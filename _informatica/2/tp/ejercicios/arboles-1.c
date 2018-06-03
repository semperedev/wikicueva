/**
 * 1) Construye y devuelve un árbol binario con un único nodo cuyo
 * valor sea d
 *
 * ArbolBinario crea(Elemento d);
 */
ArbolBinario crea(Elemento d) {
  ArbolBinario a = malloc(sizeof(struct Nodo));

  a->elem = d;
  a->hijoIzquierdo = NULL;
  a->hijoDerecho = NULL;

  return a;
}

/**
 * 2) Construye y devuelve un árbol binario cuya raíz tenga valor 1, el hijo
 * izquierdo valor 2 y el derecho valor 3.
 *
 * ArbolBinario crea_lleno();
 */
ArbolBinario crea_lleno() {
  ArbolBinario a = malloc(sizeof(struct Nodo));

  a->elem = 1;

  a->hijoIzquierdo = malloc(sizeof(struct Nodo));
  a->hijoIzquierdo->elem = 2;
  a->hijoIzquierdo->hijoIzquierdo = NULL;
  a->hijoIzquierdo->hijoDerecho = NULL;

  a->hijoDerecho = malloc(sizeof(struct Nodo));
  a->hijoDerecho->elem = 3;
  a->hijoDerecho->hijoIzquierdo = NULL;
  a->hijoDerecho->hijoDerecho = NULL;

  return a;
}

/**
 * 3) Muestra todos los valores en preorden
 *
 * void muestra_preorden(ArbolBinario a);
 */
void muestra_preorden(ArbolBinario a) {
  if (a == NULL) {
    return;
  }

  printf("%d ", a->elem);

  muestra_preorden(a->hijoIzquierdo);
  muestra_preorden(a->hijoDerecho);
}

/**
 * 4) Muestra todos los valores en inorden
 *
 * void muestra_inorden(ArbolBinario a);
 */
void muestra_inorden(ArbolBinario a) {
  if (a == NULL) {
    return;
  }

  muestra_inorden(a->hijoIzquierdo);

  printf("%d ", a->elem);

  muestra_inorden(a->hijoDerecho);
}

/**
 * 5) Muestra todos los valores en postorden
 *
 * void muestra_postorden(ArbolBinario a);
 */
void muestra_postorden(ArbolBinario a) {
  if (a == NULL) {
    return;
  }

  muestra_postorden(a->hijoIzquierdo);
  muestra_postorden(a->hijoDerecho);

  printf("%d ", a->elem);
}

/**
 * 6) Libera toda la memoria del árbol a
 *
 * void libera(ArbolBinario a);
 */
void libera(ArbolBinario a) {
  if (a == NULL) {
    return;
  }

  libera(a->hijoIzquierdo);
  libera(a->hijoDerecho);

  free(a);
}

/**
 * 7) Devuelve el número de nodos del árbol a
 *
 * int cuenta(ArbolBinario a);
 */
int cuenta(ArbolBinario a) {
  if (a == NULL) {
    return 0;
  }

  int n = 1;

  n += cuenta(a->hijoIzquierdo);
  n += cuenta(a->hijoDerecho);

  return n;
}

/**
 * 8) Devuelve el número de hojas del árbol a
 *
 * int cuenta_hojas(ArbolBinario a);
 */
int cuenta_hojas(ArbolBinario a) {
  if (a == NULL) {
    return 0;
  }
  else if (a->hijoIzquierdo == NULL && a->hijoDerecho == NULL) {
    return 1;
  }

  int n = 0;

  n += cuenta_hojas(a->hijoIzquierdo);
  n += cuenta_hojas(a->hijoDerecho);

  return n;
}

/**
 * 9) Devuelve el número de nodos intermedios del árbol a
 *
 * int cuenta_intermedios(ArbolBinario a);
 */
int cuenta_intermedios(ArbolBinario a) {
  if (a == NULL) {
    return 0;
  }

  int n = a->hijoIzquierdo != NULL || a->hijoDerecho != NULL;

  n += cuenta_intermedios(a->hijoIzquierdo);
  n += cuenta_intermedios(a->hijoDerecho);

  return n;
}

/**
 * 12) Devuelve el número de nodos intermedios del árbol cuyo valor sea
 * distinto a cualquiera de los valores del array m
 *
 * int cuenta(ArbolBinario a, Elemento m[], int n);
 */
int cuenta_distinto(ArbolBinario a, Elemento m[], int n) {
  if (a == NULL) {
    return 0;
  }

  int cont = 0;

  if (a->hijoIzquierdo != NULL || a->hijoDerecho != NULL) {
    cont = 1;

    for (int i = 0; i < n && cont == 1; i++) {
      if (a->elem == m[i]) {
        cont = 0;
      }
    }
  }

  cont += cuenta_distinto(a->hijoIzquierdo, m, n);
  cont += cuenta_distinto(a->hijoDerecho, m, n);

  return cont;
}

/**
 * 13) Devuelve la suma de los valores de todos los nodos del árbol a
 *
 * int suma(ArbolBinario a);
 */
int suma(ArbolBinario a) {
  if (a == NULL) {
    return 0;
  }

  int n = a->elem;

  n += suma(a->hijoIzquierdo);
  n += suma(a->hijoDerecho);

  return n;
}

/**
 * 14) Devuelve 1 si el árbol contiene el elemento d y 0 en caso contrario
 *
 * int existe(ArbolBinario a, Elemento d);
 */
int existe(ArbolBinario a, Elemento d) {
  if (a == NULL) {
    return 0;
  }

  if (a->elem == d) {
    return 1;
  }

  return existe(a->hijoIzquierdo, d) || existe(a->hijoDerecho, d);
}

/**
 * 15) Devuelve el mayor de los valores guardados en los nodos del árbol,
 * suponiendo que todos los valores son mayores que cero
 *
 * int maximo(ArbolBinario a);
 */
int maximo(ArbolBinario a) {
  if (a == NULL) {
    return 0;
  }

  int n = maximo(a->hijoIzquierdo);
  int nd = maximo(a->hijoDerecho);

  if (nd > n) {
    n = nd;
  }

  if (a->elem > n) {
    n = a->elem;
  }

  return n;
}

/**
 * 16) Devuelve la altura del árbol, es decir, la longitud del camino
 * más largo de la raíz a cualquiera de sus descendientes
 *
 * int altura(ArbolBinario a);
 */
int altura(ArbolBinario a) {
  if (a == NULL || (a->hijoIzquierdo == NULL && a->hijoDerecho == NULL)) {
    return 0;
  }

  int ni = altura(a->hijoIzquierdo);
  int nd = altura(a->hijoDerecho);

  if (ni > nd) {
    return 1 + ni;
  }

  return 1 + nd;
}

/**
 * 17) Agrega a cada hoja dos nuevos hijos: el izquierda el valor del
 * doble del padre, y el derecho el doble más uno
 *
 * void amplia(ArbolBinario a);
 */
void amplia(ArbolBinario a) {
  if (a == NULL) {
    return;
  }

  if (a->hijoIzquierdo == NULL && a->hijoDerecho == NULL) {
    a->hijoIzquierdo = crea(a->elem * 2);
    a->hijoDerecho = crea(a->elem * 2 + 1);
  }
  else {
    amplia(a->hijoIzquierdo);
    amplia(a->hijoDerecho);
  }
}

/**
 * 18) Devuelve 1 si los dos árboles pasados como parámetros son iguales
 * y 0 en caso contrario
 *
 * int compara(ArbolBinario a, ArbolBinario b);
 */
int compara(ArbolBinario a, ArbolBinario b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  return (
    (a->elem == b->elem) &&
    compara(a->hijoIzquierdo, b->hijoIzquierdo) &&
    compara(a->hijoDerecho, b->hijoDerecho)
  );
}

/**
 * 19) Devuelve un árbol idéntico al pasado como parámetro
 *
 * ArbolBinario copia(ArbolBinario a);
 */
ArbolBinario copia(ArbolBinario a) {
  if (a == NULL) {
    return NULL;
  }

  ArbolBinario c = malloc(sizeof(struct Nodo));

  c->elem = a->elem;
  c->hijoIzquierdo = copia(a->hijoIzquierdo);
  c->hijoDerecho = copia(a->hijoDerecho);

  return c;
}

/**
 * 20) Devuelve una lista con los elementos contenidos en el árbol
 *
 * CeldaPtr enumera(ArbolBinario a);
 */
CeldaPtr enumera(ArbolBinario a) {
  if (a == NULL) {
    return NULL;
  }

  CeldaPtr lista = malloc(sizeof(struct Celda));

  lista->elem = a->elem;
  lista->sig = enumera(a->hijoIzquierdo);

  CeldaPtr d = enumera(a->hijoDerecho);

  if (d != NULL) {
    CeldaPtr aux = lista;

    while (aux->sig != NULL) {
      aux = aux->sig;
    }

    aux->sig = d;
  }

  return lista;
}
