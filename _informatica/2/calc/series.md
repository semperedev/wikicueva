---
title: Series
---

Tratamos la serie \\(S_n\\):

\\[ S_n = \sum_{k = 1}^n a_k \\]

## Series no negativas

### Criterio de la divergencia

Si el límite de \\(a_n\\) no existe o es distinto de cero, la serie \\(S_n\\) es divergente.

### Comparación

#### Si \\(a_n \sim b_n\\)

\\[
  \sum_{n=1}^\infty a_n\ \text{converge} \iff
  \sum_{n=1}^\infty b_n\ \text{converge}
\\]

\\[
  \sum_{k=1}^n a_k \sim \sum_{k=1}^n b_k
\\]

#### Si \\(a_n \ll b_n\\)

\\[
  \sum_{n=1}^\infty b_n\ \text{converge} \implies
  \sum_{n=1}^\infty a_n\ \text{converge}
\\]

\\[
  \sum_{n=1}^\infty a_n\ \text{diverge} \implies
  \sum_{n=1}^\infty b_n\ \text{diverge}
\\]

### Criterio de la Integral

\\[ a_n = f(n) \\]
\\[ J_n = \int_1^n f(x) dx \\]

#### Si \\(a_n\\) decreciente

\\[ \int_1^\infty f(x) dx\ \text{converge} \iff \sum_{n=1}^\infty a_n\ \text{converge} \\]

\\[ S_n \sim J_n \\]

#### Si \\(a_n\\) es creciente

\\[ a_n\ \text{diverge} \\]

\\[ a_n \ll J_n \implies S_n \sim J_n \\]

### Criterio de la Raíz

\\[ \lim_{n \to \infty} \sqrt[n]{a_n} = L \\]
\\[ L < 1 \implies a_n\ \text{converge} \\]
\\[ L > 1 \implies a_n\ \text{diverge} \\]

### Criterio del Cociente

\\[ \lim_{n \to \infty} \frac{a_{n+1}}{a_n} = L \\]
\\[ L < 1 \implies a_n\ \text{converge} \\]
\\[ L > 1 \implies a_n\ \text{diverge} \\]

## Series alternadas

Una serie es alternada si \\(a_n\\) y \\(a_{n+1}\\) tienen signos distintos.

### Criterio de Leibniz

Si \\( \lim_{n \to \infty} a_n = 0 \\) y \\(\|a_{n+1}\| \leq \|a_n\|\\), entonces \\(a_n\\) es convergente.

En otras palabras: si \\(a_n\\) converge a 0 y es monótona decreciente, la serie \\(S_n\\) converge.
