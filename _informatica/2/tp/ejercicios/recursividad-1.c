/**
 * 1) Calcula el factorial de un número entero
 */
int factorial(int n) {
  // Caso base
  if (n == 0) {
    return 1;
  }

  // Caso general
  return n * factorial(n - 1);
}

/**
 * 2) Calcula recursivamente el valor de a elevado a b
 *
 * int potencia(int a, int b);
 */
int potencia(int a, int b) {
  if (b == 1) {
    return a;
  }
  else if (b == 0) {
    return 1;
  }

  return a * potencia(a, b - 1);
}

/**
 * 3) Calcula de forma recursiva el número de Fibonacci de n
 *
 * int fibonacci(int n);
 */
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * 6) Calcula f(x) para x >= 0 siendo:
 * f(x) = f(x-2)*2 + f(x-3)*3
 * y con f(x) = 2*x si x < 3 y x >= 0
 */
int ejercicio6(int x) {
  if (x < 3) {
    return 2 * x;
  }

  return ejercicio6(x - 2) * 2 + ejercicio6(x - 3) * 3;
}

/**
 * 7) Muestra los dígitos de un número entero mayor que cero empezando
 * por el de más a la derecha
 */
void ejercicio7(int n) {
  if (n == 0) {
    return;
  }

  printf("%d ", n % 10);

  ejercicio7(n / 10);
}

/**
 * 11) Calcula la longitud de la cadena pasada como parámetro
 *
 * int longitud(char * cadena);
 */
int longitud(char * cadena) {
  if (cadena[0] == '\0') {
    return 0;
  }

  return 1 + longitud(cadena + 1);
}

/**
 * 12) Devuelve 1 si las dos cadenas pasadas son iguales y 0 en caso contrario
 *
 * int compara(char * a, char * b);
 */
int compara(char * a, char * b) {
  if (a[0] != b[0]) {
    return 0;
  }
  else if (a[0] == '\0' || b[0] == '\0') {
    return a[0] == b[0];
  }

  return compara(a + 1, b + 1);
}

/**
 * 14) Sustituye en la cadena todas las apariciones de la letra a por la b
 *
 * void sustituye(char * cadena, char a, char b);
 */
void sustituye(char * cadena, char a, char b) {
  if (*cadena == '\0') {
    return;
  }

  if (*cadena == a) {
    *cadena = b;
  }

  sustituye(cadena + 1, a, b);
}

/**
 * 15) Muestra por pantalla una secuencia de cadenas de longitud creciente
 * empezando por la última letra y progresando hasta ser igual a la cadena
 * original. Por ejemplo: "Hola" debe ser:
 * a
 * la
 * ola
 * Hola
 */
void ejercicio15(char * cadena) {
  if (*cadena == '\0') {
    return;
  }

  ejercicio15(cadena + 1);

  printf("%s\n", cadena);
}

/**
 * 17) Calcular la longitud de una estructura enlazada lineal sin cabecera
 *
 * int longitud_lista(NodoPtr lista);
 */
int longitud_lista(NodoPtr lista) {
  if (lista == NULL) {
    return 0;
  }

  return 1 + longitud_lista(lista->sig);
}

/**
 * 18) Muestra todos los elementos de la lista en el orden en el que están
 *
 * void muestra_lista(NodoPtr lista);
 */
void muestra_lista(NodoPtr lista) {
  if (lista == NULL) {
    return;
  }

  printf("%d\n", lista->elem);

  muestra_lista(lista->sig);
}

/**
 * 20) Libera toda la memoria asociada a una lista
 *
 * void libera(NodoPtr lista);
 */
void libera(NodoPtr lista) {
  if (lista == NULL) {
    return;
  }

  libera(lista->sig);

  free(lista);
}

/**
 * 21) Devuelve 1 si las dos listas son iguales y 0 en caso contrario
 *
 * int compara(NodoPtr a, NodoPtr b);
 */
int compara_lista(NodoPtr a, NodoPtr b) {
  if (a == NULL || b == NULL) {
    return a == b;
  }

  if (a->elem != b->elem) {
    return 0;
  }

  return compara_lista(a->sig, b->sig);
}
