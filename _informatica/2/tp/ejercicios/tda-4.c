#include <stdio.h>
#include <stdlib.h>

#include "tda-4.h"

struct MatrizRep {
  double ** arr;
  int f, c;
};

Matriz crea_matriz(int f, int c) {
  Matriz m = malloc(sizeof(struct MatrizRep));
  
  m->f = f;
  m->c = c;

  m->arr = malloc(sizeof(double *) * f);

  for (int i = 0; i < f; i = i + 1) {
    m->arr[i] = malloc(sizeof(double) * c);
  }

  return m;
}

Matriz matriz_identidad(int n) {
  Matriz m = crea_matriz(n, n);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      if (i == j) {
        m->arr[i][j] = 1;
      }
    }
  }

  return m;
}

void libera_matriz(Matriz m) {
  for (int i = 0; i < m->f; i = i + 1) {
    free(m->arr[i]);
  }

  free(m->arr);
  free(m);
}

void muestra_matriz(Matriz m) {
  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      printf("%f ", m->arr[i][j]);
    }

    printf("\n");
  }
}

double recupera_valor_matriz(Matriz m, int f, int c) {
  return m->arr[f][c];
}

void asigna_valor_matriz(Matriz m, int f, int c, double r) {
  m->arr[f][c] = r;
}

int recupera_filas_matriz(Matriz m) {
  return m->f;
}

int recupera_columnas_matriz(Matriz m) {
  return m->c;
}

Matriz escala_matriz(Matriz m, double e) {
  Matriz n = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      n->arr[i][j] = m->arr[i][j] * e;
    }
  }

  return n;
}

Matriz suma_matriz(Matriz m, Matriz n) {
  if (m->f != n->f || m->c != n->c) {
    return NULL;
  }

  Matriz suma = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      suma->arr[i][j] = m->arr[i][j] + n->arr[i][j];
    }
  }

  return suma;
}

Matriz multiplica_matriz(Matriz m, Matriz n) {
  if (m->c != n->f) {
    return NULL;
  }

  Matriz mul = crea_matriz(m->f, n->c);
  
  int suma;

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < n->c; j = j + 1) {
      suma = 0;

      for (int k = 0; k < m->c; k = k + 1) {
        suma = suma + m->arr[i][k] * n->arr[k][j];
      }

      mul->arr[i][j] = suma;
    }
  }

  return mul;
}

Matriz matriz_traspuesta(Matriz m) {
  Matriz n = crea_matriz(m->f, m->c);

  for (int i = 0; i < m->f; i = i + 1) {
    for (int j = 0; j < m->c; j = j + 1) {
      n->arr[i][j] = m->arr[j][i];
    }
  }

  return n;
}
