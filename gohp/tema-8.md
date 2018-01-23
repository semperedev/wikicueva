<!-- TITLE: Tema 8 -->
<!-- SUBTITLE: La Función Financiera -->

# Dirección Financiera

Objetivo: obtención de recursos financieros y empleo adecuado de los mismos.

### Financiación en la Empresa

Conseguir fondos seleccionando las fuentes adecuadas y tratando de obtenerlos al menor coste posible.

# La Inversión en la Empresa

Consiste en invertir fondos consiguiendo una buena rentabilidad y la liquidez precisa.

Existen dos tipos de inversiones:

* Activo circulante: relacionados con tesorería, compras y ventas
* Activo fijo: objetivo del análisis de inversiones

Condiciones que debe cumplir cualquier inversión:

* Los resultados deben igualar o superar los recursos inmovilizados más la rentabilidad exigida
* La empresa debe poder soportar la tensión financiera derivada de la inversión

## Flujo de caja

El flujo de caja de un año \\(j\\) se define como la diferencia entre los cobros y los pagos de dicho año.

\\( Q_{j} = C_{j} - P_{j} \\)

# Selección de Inversiones: Criterios Estáticos

Diferenciamos entre métodos estáticos, que no consideran el efecto del tiempo, y dinámicos, que sí lo hacen.

## Periodo de Recuperación (PayBack)

> Se selecciona la inversión que menos tarde en recuperarse.

\\(Q\\) = Flujo de caja total
\\(A\\) = Inversión Inicial

\\( PayBack = \frac{A}{Q} \\)

<table>
  <thead>
    <tr>
      <th>Ventajas</th>
      <th>Inconvenientes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>
        <ul>
          <li>Se calcula muy fácilmente y es de sencilla compresión</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>No considera los flujos de caja que se puedan generar tras la recuperación</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

## Ratio coste-beneficio

Si C/B > 1, la inversión es rentable.
Si C/B = 1, los beneficios igualan a los costes: no hay ganancias.
Si C/B < 1, la inversión no es rentable.

\\(Q_{i}\\) = Flujo de caja del año \\(i\\)
\\(A\\) = Inversión Inicial
\\(n\\) = Duración en años

### Total

\\( C/B = \frac{\sum_{i=1}^n Q_{i}}{|A|} \\)

### Medio anual

\\( C/B = \frac{\sum_{i=1}^n Q_{i}}{|A| \cdot n} \\)

# Selección de Inversiones: Criterios Dinámicos

## Valor Actual Neto

> Se elegirá el proyecto con mayor VAN positivo

<table>
  <thead>
    <tr>
      <th>Ventajas</th>
      <th>Inconvenientes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>
        <ul>
          <li>Consideración temporal de los flujos de caja</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Especificación de la tasa de descuento</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

### Misma tasa de descuento

\\(k\\) = Tasa de descuento

\\( VAN = -A + \sum_{i=1}^n \frac{Q_{i}}{(1+k)^i} \\)

### Diferentes tasas de descuento

\\(k_{i}\\) = Tasa de descuento en el momento \\(i\\)

\\( VAN = -A + \sum_{i=1}^n \frac{Q_{i}}{\prod_{j=1}^i (1+k_{j})} \\)

## Tasa Interna de Rendimiento

> Se trata del tipo de actualización que hace VAN=0

> Interesan aquellos proyectos que cumplen \\(r\\) > \\(k\\), eligiendo la que tenga mayor \\(r\\)

<table>
  <thead>
    <tr>
      <th>Ventajas</th>
      <th>Inconvenientes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>
        <ul>
          <li>Consideración temporal de los flujos de caja</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Existencia de tipos de rendimiento múltiples (tantas soluciones de r como años)</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

\\( VAN = -A + \sum_{i=1}^n \frac{Q_{i}}{(1+r)^t} = 0 \\)

# Financiación

## Tasa Anual Equivalente

Para calcular el disponible, restamos al nominal los interéses, comisiones y gastos derivados.

\\( Intereses = \frac{Interes\ anual}{100} \cdot \frac{Vencimiento}{365} \cdot Nominal \\)

\\( Comisiones = \frac{Comision}{1000} \cdot Nominal \\)

\\( Disponible\ Descuento = \frac{Nominal}{1 + i_{12}} \\)

\\( (1 + TAE) = (1 + i_{12})^{12} \\)