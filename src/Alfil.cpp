#include "Alfil.h"
#include <math.h>
#include<iostream>

//CONSTRUTOR
Alfil::Alfil(Casilla coordenadas, Color color) :Pieza(coordenadas, color, Tipo::ALFIL){}


//FUNCIONES PARA VER MOVIMIENTOS

bool Alfil::PuedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[5][5])
{
	std::cout << "\nComprobar movimiento del ALFIL desde la casilla: " << origen.fila << "," << origen.columna << " hasta el destino: " << destino.fila << "," << destino.columna << "\n";

	int DiferenciaF = destino.fila - origen.fila;
	int DiferenciaC = destino.columna - origen.columna;

	if (coordenadas[origen.fila][origen.columna]->getColor() == BLANCO)
	{
		std::cout << "Movemos una pieza (ALFIL) de color BLANCO";

		//LOS ALFILES SE MUEVEN Y COMEN EN DIAGONAL

		// DIBUJO DEL AJEDREZ :

		/*

		|B|N|B|N|B|            F5   |51|52|53|54|55|        Otra opción       |N|B|N|B|N|
		|N|B|N|B|N|            F4   |41|42|43|44|45|        sería:            |B|N|B|N|B|
		|B|N|B|N|B|            F3   |31|32|33|34|35|        DUDA????          |N|B|N|B|N|
		|N|B|N|B|N|            F2   |21|22|23|24|25|                          |B|N|B|N|B|
		|B|N|B|N|B|            F1   |11|12|13|14|15|                          |N|B|N|B|N|

									C1|C2|C3|C4|C5

        */
		//Si estoy en la casilla 12 y quiero desplazarme mis opciones sería: 21,23,34,45
		//es decir varían tanto las filas como las columnas.
		// Podemos decir que el movimiento en diagonal obliga a los alfiles a desplazarse el 
		// mismo numero de filas que de columnas, si no este movimiento no se estaría cumpliendo
		//Además, solo pueden desplazarse por las casillas que tienen el color de la casilla del inicio
		//Al contrario que los Peones los alfiles pueden ir y volver

		//COMPROBACION DIAGONAL: la diferencia de fila.destino-fila.origen == columna.destino-columna.origen

		if (abs(DiferenciaF) != abs(DiferenciaC))
		{
			return false;
		}


	}

	





}