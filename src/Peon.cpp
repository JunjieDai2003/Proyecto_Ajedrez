#include "Peon.h"
#include <math.h>
#include<iostream>


//CONSTRUCTOR
Peon::Peon(Casilla coordenadas, Color color) :Pieza(coordenadas, color, Tipo::PEON) {}

//FUNCION POSIBLE MOVIMIENTO
//El PEON puede moverse hacia delante (en el caso que se mueva) O hacia los dos vertices (en el caso en que coma)
// TENEMOS QUE ESTUDIAR Y ENTENDER BIEN QUE HACE por eso hago los dibujos y comentarios
bool Peon::MovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[8][8])
{
	//Las clases derivadas de piezas tienen "CASILLAS", formadas por dos int
	std::cout << "\nComprobar movimiento del PEON desde la casilla: " << origen.fila << "," << origen.columna << " hasta el destino: " << destino.fila << "," << destino.columna << "\n";

	int DiferenciaF = destino.fila - origen.fila;
	int DiferenciaC = destino.columna - origen.columna;


	//FUNCIONES PARA COMPROBAR COLOR PIEZA A MOVER


	//CASO COLOR BLANCO:
	if (coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) //coordenadas es una PIEZA, el getColor() es de una pieza, no una casilla.Realmente casilla no tiene color solo dos atributos int
	{
		std::cout << "Movimiento de un Peon color BLANCO";


		//He dibujado un tablero en el cuaderno(para hacerlo más fácil he imaginado un tablero 5x5)
		// y he nombrado las filas y columnas de abajo a arriba y de izquierdas a derechas
		//Si haces eso podeis comprobar que si se mueve hacia adelante obviamente solo cambia
		//la fila,
		//por ejemplo si el peon est?en la posición 11 y lo movemos hacia delante,
		//pasaría a la posicion 21, es decir solo se modifica la fila

	//DIBUJO DEL AJEDREZ:

	/*

	|B|N|B|N|B|            F5   |51|52|53|54|55|        Otra opción       |N|B|N|B|N|
	|N|B|N|B|N|            F4   |41|42|43|44|45|        sería:            |B|N|B|N|B|
	|B|N|B|N|B|            F3   |31|32|33|34|35|        DUDA????          |N|B|N|B|N|
	|N|B|N|B|N|            F2   |21|22|23|24|25|                          |B|N|B|N|B|
	|B|N|B|N|B|            F1   |11|12|13|14|15|                          |N|B|N|B|N|

								C1|C2|C3|C4|C5
	*/
	//IMPORTANTE SUPONGO QUE LAS PIEZAS BLANCAS EMPIEZAN ABAJO Y LAS NEGRAS EMPIEZAN ARRIBA
	// Si las piezas blancas empiezan abajo, para que el Peón avance la fila AUMENTA un número
	//Si las piezas negras empiezan arriba, para que el Peon avance la fila DISMINUYE un numero
	//las columnas como hemos visto antes en este caso nos dan igual porque va a ser la misma (en el caso movimiento hacia delante)

	//MOVIMIENTO DEL PEON (HACIA DELANTE)
		if (DiferenciaC == 0 && DiferenciaF == 1) //PEON se mueve UNA casilla
		{
			std::cout << "Movimiento del Peon hacia delante en UNA casilla, varia la posicion<<" << origen.fila << "," << origen.columna << "hacia " << destino.fila << "," << destino.columna;
			//Hay que comprobar que la casilla de destino no este ocupada por otra pieza
			if (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO)//Usamos la FUNCION getTipo() declarada también en la clase PIEZA
			{
				std::cout << "La pieza puede moverse";
				return true;
			}
			/*else
			{
				std::cout << "La pieza NO puede moverse";
				return false;
			}*/

		}
		if (DiferenciaC == 0 && DiferenciaF == 2) //PEON se mueve DOS casillas
		{
			std::cout << "Movimiento del Peon hacia delante en DOS casillas, varia la posicion<<" << origen.fila << "," << origen.columna << "hacia " << destino.fila << "," << destino.columna;
			//Hay que comprobar que la casilla de destino no est?ocupada por otra pieza
			if (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO)
			{
				std::cout << "La pieza puede moverse";
				return true;
			}
			/*else
			{
				std::cout << "La pieza NO puede moverse";
				return false;

			}*/

		}

		//MOVIMIENTO COMER DEL PEON
		//Para comer el Peon se dirige de forma diagonal, es decir si esta en la casilla 13 puede ir a la
		//casilla 22 o a la casilla 24, es decir siempre se aumenta en una unidad la fila 
		//mientras que la columna puede aumentar o disminuir en una unidad. Usamos valor absoluto(abs).

		if (abs(DiferenciaC) == 1 && DiferenciaF == 1 && coordenadas[destino.fila][origen.columna]->getColor() == NEGRO)
		{
			return true;
			std::cout << "La pieza come";
		}
		/*else
		{
			return false;
			std::cout << "La pieza NO come";
		}*/

		if (abs(DiferenciaC) == 1 && DiferenciaF == 1 && coordenadas[destino.fila][origen.columna]->getColor() == BLANCO) //Podemos comernos nuestras propias piezas
		{
			return true;
			std::cout << "La pieza come";
		}

	}


	//CASO COLOR NEGRO: Es lo mismo pero adaptando los ifs a lo explicado antes,SUPONEMOS QUE LAS PIEZAS NEGRAS EMPIEZAN ARRIBA DEL TABLERO
	else if (coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) //coordenadas es una PIEZA, el getColor() es de una pieza, no una casilla.Realmente casilla no tiene color solo dos atributos int
	{
		std::cout << "Movimiento de un Peon color NEGRA";

		//MOVIMIENTO DEL PEON (HACIA DELANTE)
		if (DiferenciaC == 0 && DiferenciaF == -1) //PEON se mueve UNA casilla
		{
			std::cout << "Movimiento del Peon hacia delante en UNA casilla, varia la posicion<<" << origen.fila << "," << origen.columna << "hacia " << destino.fila << "," << destino.columna;
			//Hay que comprobar que la casilla de destino no est?ocupada por otra pieza
			if (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO)//Usamos la FUNCION getTipo() declarada también en la clase PIEZA
			{
				std::cout << "La pieza puede moverse";
				return true;
			}
			/*else
			{
				std::cout << "La pieza NO puede moverse";
				return false;
			}*/

		}
		if (DiferenciaC == 0 && DiferenciaF == -2) //PEON se mueve DOS casillas
		{
			std::cout << "Movimiento del Peon hacia delante en DOS casillas, varia la posicion<<" << origen.fila << "," << origen.columna << "hacia " << destino.fila << "," << destino.columna;
			//Hay que comprobar que la casilla de destino no est?ocupada por otra pieza
			if (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO)
			{
				std::cout << "La pieza puede moverse";
				return true;
			}
			/*else
			{
				std::cout << "La pieza NO puede moverse";
				return false;

			}*/

		}

		//MOVIMIENTO COMER DEL PEON
		if (abs(DiferenciaC) == 1 && DiferenciaF == -1 && coordenadas[destino.fila][origen.columna]->getColor() == BLANCO)
		{
			return true;
			std::cout << "La pieza come";
		}
		/*else
		{
			return false;
			std::cout << "La pieza NO come";
		}*/
		if (abs(DiferenciaC) == 1 && DiferenciaF == -1 && coordenadas[destino.fila][origen.columna]->getColor() == NEGRO)
		{
			return true;
			std::cout << "La pieza come";
		}
	}


	return false; //DUDO si dejo este false aqui no devolvería siempre false ????

}




//EN ESTA FUNCION DEVUELVE LAS POSIBLES POSICIONES DE MOVIMIENTO RESPECTO UNA MATRIZ TABLERO
//como hemos dicho va a Devolver:
//  1- vacio (no existe pieza)
//  2- otro color (la pieza que existe es de otro color)
//  3- mismo color (la pieza que existe es del mismo color)
//  0- invalido (no se puede trastaladar la pieza en esa posicion

int MoviMatriz(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[8][8])
{
	int matrix[8][8];
	//Bucle que recorre la matriz auxiliar de coordenadas haciendo que todas las casillas inicialmente sean movimientos invalidos o 0s.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matrix[i][j] == 0;
		}
	}
	//Ahora la Matriz auxiliar imprime todo ceros

	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j]<<" , ";
			if (j == 8)
			{
				std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
			}
		}
	}

	//CASO 1)
	//En este caso el peon AVANZAR hacia delante una posición y no hay ninguna otra pieza;
	if ((destino.fila == origen.fila + 1) && (destino.columna == origen.columna) && (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor  de matriz auxiliar: 1" << "\n";
		matrix[destino.fila][destino.columna] == 1;
	}

	//CASO 2)
	//En este caso el peon puede AVANZAR hacia delante dos posiciones y no hay ninguna otra pieza;
	if ((destino.fila == origen.fila + 2) && (destino.columna == origen.columna) && (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor 1" << "\n";
		matrix[destino.fila][destino.columna] == 1;
	}

	//CASO 3)
	//En este caso el peon si es BLANCO puede COMER hacia un lado cuando sea la otra pieza sea NEGRA
	if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (destino.fila == origen.fila + 1) && (destino.columna == origen.columna + 1) && (coordenadas[destino.fila][destino.columna]->getTipo() == NEGRO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor 3" << "\n";
		matrix[destino.fila][destino.columna] == 2;
	}

	//CASO 4)
	//En este caso el peon si es BLANCO puede COMER hacia un lado cuando la otra pieza sea BLANCA
	if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (destino.fila == origen.fila + 1) && (destino.columna == origen.columna + 1) && (coordenadas[destino.fila][destino.columna]->getTipo() == BLANCO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor 2" << "\n";
		matrix[destino.fila][destino.columna] == 3;
	}

	//CASO 5)
	//En este caso si el Peon es NEGRO puede COMER hacia un lado cuando la otra pieza sea BLANCA //Equivalente caso 3)
	if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (destino.fila == origen.fila + 1) && (destino.columna == origen.columna + 1) && (coordenadas[destino.fila][destino.columna]->getTipo() == BLANCO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor 3" << "\n";
		matrix[destino.fila][destino.columna] == 2;
	}


	//CASO 6)
	//En este caso si el PEON es NEGRO puede comer hacia un lado cuando la otra pieza sea NEGRA //Equivalente caso 4)
	if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (destino.fila == origen.fila + 1) && (destino.columna == origen.columna + 1) && (coordenadas[destino.fila][destino.columna]->getTipo() == NEGRO))
	{
		std::cout << "El Peon puede desplazarse a: la casilla: [ " << destino.fila << "," << destino.columna << "]" << "Que toma el valor 2" << "\n";
		matrix[destino.fila][destino.columna] == 3;
	}


	//Una vez recorridos los IFs la Matriz Auxiliar (que hemos inicializado en cero con el primer bucle) tendra unos doses y treses; 
	//Imprimimos para ver que queda;

	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << " , ";
			if (j == 8)
			{
				std::cout << "\n"; 
			}
		}
	}
	return 5;
	//SOLO Falta que devuelva la matriz matrix
}


