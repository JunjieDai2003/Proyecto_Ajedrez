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
	int FilaAuxiliar;
	int ColumnaAuxiliar;

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
		//Si estoy en la casilla 33 y quiero desplazarme mis opciones serían: 42,51,44,55,22,11,24,15; 
		//es decir varían tanto las filas como las columnas.
		// 
		//LÓGICAAAAAA 
		//La lógica de los alfiles para saber en que posición pueden desplazarse sería:(siguiendo con el ejemplo de la casilla 33)
		//Creamos dos variables auxiliares: FILAauxiliar y COLUMNAauxiliar.
		//hacemos un bucle que recorra la matriz o tablero compuesto por filas y columnas es decir
		// FILAauxiliar y COLUMNAauxiliar va a tomar todos los valores posibles del tablero desde el 11 hasta el 55
		// 
		// Si  FILAauxiliar + COLUMNAauxiliar es == a 3+3 (fila y columna donde está situada la pieza),
		// entonces esa casilla es un posible punto donde el ALFIL PUEDE DESPLAZARSE
		//   
		// Si FILAauxiliar - COLUMNAauxiliar es == a  3-3 (fila y columna donde está situada la pieza),
		// entonces esa casilla TAMBIÉN es un  posible punto donde el ALFIL PUEDE DESPLAZARSE
		//
		//INSISTO si os dibujais el tablero en un cuaderno y haces las operaciones lo veis mejor.
		//
		// 
		// Además podemos comprobar si el movimiento es diagonal o no, ya que siempre pasa:
		// abs(fila.destino-fila.origen)=abs(columna.destino-columna.origen), ya que al ser un movimiento diagonal SIEMPRE
		// avanzamos el mismo numero de filas que de columnas.


		//COMPROBACIÓN MOVIMIENTO DIAGONAL
		if (abs(DiferenciaF) != abs(DiferenciaC))
		{
			std::cout << "Movimeinto NO diagonal";
			return false;
		}


	


	


	}

	





}