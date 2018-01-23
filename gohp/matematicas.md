<!-- TITLE: Matemáticas -->
<!-- SUBTITLE: Conceptos matemáticos de GOHP -->

# Programación Lineal

Podemos plantearlo en función del Máximo Rendimiento o del Mínimo Coste.

\\(m_{i}\\)= margen unitario del producto \\(i\\)  
\\(a_{ij}\\)= coeficiente técnico  
\\(Q_{j}\\)= cantidad del producto \\(j\\) a fabricar  
\\(R_{i}\\)= cantidad disponible (o límite de capacidad) del recurso \\(i\\)

[^coef-tecnico]: Coeficiente técnico: Cantidad necesaria del recurso \\(i\\)para fabricar el producto \\(j\\).

## Máximo Rendimiento
Función objetivo:

\\( f: \sum_{i=1}^n m_{i}Q_{i} \\)

Condiciones o restricciones:

\\( a_{mn}Q_{n} \leq R_{m} \\)

## Mínimo Coste de Producción
Función objetivo:

\\( f: \sum_{i=1}^n c_{i}R_{i} \\)

Condiciones o restricciones:

\\( a_{nm}R_{m} \leq Q_{n} \\)

> Nótese el cambio de subíndices de \\(mn\\) a \\(nm\\) para ajustar los demás valores.

# Tasa de Variación
Hablando de la productividad en dos años:

\\(P_{i}\\) = Productividad del año \\(i\\)  
\\(T_{V}\\) = Tasa de Variación

\\( T_{V} = \frac{P_{2} - P_{1}}{P_{1}} \\)

\\( 0 \leq T_{V} \leq 1 \\)