# Examen Práctico - 18 de Enero de 2018

# Ejercicio 1

> Diseñar una función que reciba como parámetro S una secuencia de enteros del segundo modelo de acceso secuencial y devuelva un valor boolean indicando si existe una meseta cuya longitud exacta sea 2.

Por ejemplo, para S = (31, 31, 31, 22, 22, 45, 15, 15, 15, 15) la respuesta sería Verdadero, pues la meseta (22, 22) tiene longitud 2.

```pascal
function ExisteMeseta2(S : mse2) : boolean;
var
	longitud, mActual : integer;

begin
	iniciar_mse2(S);

	longitud := 1;

	if not esVacia_mse2(S) then
		avanzar_mse2(S);

		mActual := ea_mse2(S);

		while not esUltimo_mse2(S) and ((mActual = ea_mse2(S)) or (longitud <> 2)) do begin
			avanzar_mse2(S);

			if mActual = ea_mse2(S) then
				longitud := longitud + 1
			else if longitud <> 2 then begin
				mActual := ea_mse2(S);

				longitud := 1;
			end;
		end;

	ExisteMeseta2 := longitud = 2;
end;
```

# Ejercicio 2

> Diseñar un procedimiento OrdenarCamasLibres, que recibiendo como parámetro CLH una tabla de tipo CamasLibresHospital, devuelva mediante el mismo parámetro la tabla ordenada por orden decreciente de camas libres.

Se nos proporcionan estos tipos:

```pascal
type
	CamasModulo = record
		IdModulo : 1..M;
		CamasLibres : integer;
		CamasTotal : integer;
	end;

	CamasLibresHospital = array [1..M] of CamasModulo;
```

Se trata de implementar un algoritmo de ordenación por selección directa, en orden decreciente, que podemos encontrar en pseudocódigo en los apuntes de la asignatura.

```pascal
procedure OrdenarCamasLibres(var CLH : CamasLibresHospital);
var
	posicion, i, j : integer;
	maximo : CamasModulo;

begin
	for i := 1 to M - 1 do begin
		posicion := i;
		maximo := CLH[i];

		for j := i + 1 to M do
			if maximo.CamasLibres < CLH[j].CamasLibres then begin
				posicion := j;
				maximo := CLH[j];
			end;

		CLH[posicion] := CLH[i];
		CLH[i] := maximo;
	end;
end;
```