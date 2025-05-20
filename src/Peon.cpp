#include "Peon.h"
#include <math.h>
#include<iostream>

void Peon::miMov(const Casilla& origen, Pieza* coordenadas[8][8], int matrix[8][8]) {
	// implementaci¨®n aqu¨ª
	//int matrix[8][8];
	//Bucle que recorre la matriz auxiliar de coordenadas haciendo que todas las casillas inicialmente sean movimientos invalidos o 0s.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (coordenadas[i][j]->getTipo() != VACIO)
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			}
		}
		std::cout << std::endl;
	}
	//Ahora la Matriz auxiliar imprime todo ceros

	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
			}
		}
	}

	// cambiar destino.fila por i
	//cambiar destino.columna por j
	//cambiar coordenadas[destino.fila][destino.columna] por coordenadas[i][j]


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0;j < 8;j++)
		{
			//CASO 1) BLANCAS AVANZA 1
			//En este caso el peon AVANZA hacia delante una posicion y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor  de matriz auxiliar: 1" << "\n";
				matrix[i][j] = 1;
			}

			//CASO 2) BLANCAS AVANZA 2
			//En este caso el peon puede AVANZAR hacia delante dos posiciones y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 2) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO) && (coordenadas[i - 1][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] = 1;
			}

			//CASO 1) NEGRAS AVANZA 1
			//En este caso el peon AVANZA hacia delante una posicion y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] = 1;
			}

			//CASO 2) NEGRAS AVANZA 2
			//En este  caso el peon puede AVANZAR hacia delante dos posiciones y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 2) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO) && (coordenadas[i + 1][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] = 1;
			}


			//CASO 3) BLANCO SE MUEVE A DCHA DIAGONAL Y COME A NEGRO
			//En este caso el peon si es BLANCO puede COMER hacia un lado cuando sea la otra pieza sea NEGRA
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] = 2;
			}

			//CASO 4) BLANCO SE MUEVE A DCHA DIAGONAL Y COME A BLANCO
			//En este caso el peon si es BLANCO puede COMER hacia un lado cuando la otra pieza sea BLANCA
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] = 3;
			}

			//CASO 5) BLANCO SE MUEVE A IZQDA DIAGONAL Y COME A BLANCO
			//En este caso si el Peon es BLANCO puede COMER hacia un lado cuando la otra pieza sea BLANCA //Equivalente caso 3)
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] = 3;
			}

			//CASO 6) BLANCO SE MUEVE A IZQDA DIAGONAL Y COME A NEGRO
			//En este caso si el PEON es BLANCO puede comer hacia un lado cuando la otra pieza sea NEGRA //Equivalente caso 4)
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] = 2;
			}


			/// REPITO LOS CUATRO ULTIMOS CASOS PERO CON NEGRO


			//CASO 3) NEGRO SE MUEVE A DCHA DIAGONAL Y COME A BLANCO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] = 2;
			}

			//CASO 4) NEGRO SE MUEVE A DCHA DIAGONAL Y COME A NEGRO

			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] = 3;
			}

			//CASO 5) NEGRO SE MUEVE A IZQDA DIAGONAL Y COME A BLANCO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] = 2;
			}

			//CASO 6) NEGRO SE MUEVE A IZQDA DIAGONAL Y COME A NEGRO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] = 3;
			}
		}
	}

	//Una vez recorridos los IFs la Matriz Auxiliar (que hemos inicializado en cero con el primer bucle) tendra unos doses y treses; 
	//Imprimimos para ver que queda;
	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n";
			}
		}
	}

	//return 5;
	//SOLO Falta que devuelva la matriz matrix
	return;
}







//EN ESTA FUNCION DEVUELVE LAS POSIBLES POSICIONES DE MOVIMIENTO RESPECTO UNA MATRIZ TABLERO
//como hemos dicho va a Devolver:
//  1- vacio (no existe pieza)
//  2- otro color (la pieza que existe es de otro color)
//  3- mismo color (la pieza que existe es del mismo color)
//  0- invalido (no se puede trastaladar la pieza en esa posicion

int MoviMatriz(const Casilla& origen, Pieza* coordenadas[8][8], int matrix[8][8])
{
	//int matrix[8][8];
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
			std::cout << matrix[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
			}
		}
	}

	// cambiar destino.fila por i
	//cambiar destino.columna por j
	//cambiar coordenadas[destino.fila][destino.columna] por coordenadas[i][j]


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0;j < 8;j++)
		{
			//CASO 1) BLANCAS AVANZA 1
			//En este caso el peon AVANZA hacia delante una posicion y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor  de matriz auxiliar: 1" << "\n";
				matrix[i][j] == 1;
			}

			//CASO 2) BLANCAS AVANZA 2
			//En este caso el peon puede AVANZAR hacia delante dos posiciones y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 2) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO) && (coordenadas[i - 1][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] == 1;
			}

			//CASO 1) NEGRAS AVANZA 1
			//En este caso el peon AVANZA hacia delante una posicion y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] == 1;
			}

			//CASO 2) NEGRAS AVANZA 2
			//En este  caso el peon puede AVANZAR hacia delante dos posiciones y no hay ninguna otra pieza;
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 2) && (j == origen.columna) && (coordenadas[i][j]->getTipo() == VACIO) && (coordenadas[i + 1][j]->getTipo() == VACIO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 1" << "\n";
				matrix[i][j] == 1;
			}


			//CASO 3) BLANCO SE MUEVE A DCHA DIAGONAL Y COME A NEGRO
			//En este caso el peon si es BLANCO puede COMER hacia un lado cuando sea la otra pieza sea NEGRA
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] == 2;
			}

			//CASO 4) BLANCO SE MUEVE A DCHA DIAGONAL Y COME A BLANCO
			//En este caso el peon si es BLANCO puede COMER hacia un lado cuando la otra pieza sea BLANCA
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] == 3;
			}

			//CASO 5) BLANCO SE MUEVE A IZQDA DIAGONAL Y COME A BLANCO
			//En este caso si el Peon es BLANCO puede COMER hacia un lado cuando la otra pieza sea BLANCA //Equivalente caso 3)
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] == 3;
			}

			//CASO 6) BLANCO SE MUEVE A IZQDA DIAGONAL Y COME A NEGRO
			//En este caso si el PEON es BLANCO puede comer hacia un lado cuando la otra pieza sea NEGRA //Equivalente caso 4)
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == BLANCO) && (i == origen.fila + 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] == 2;
			}


			/// REPITO LOS CUATRO ULTIMOS CASOS PERO CON NEGRO


			//CASO 3) NEGRO SE MUEVE A DCHA DIAGONAL Y COME A BLANCO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] == 2;
			}

			//CASO 4) NEGRO SE MUEVE A DCHA DIAGONAL Y COME A NEGRO

			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna - 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] == 3;
			}

			//CASO 5) NEGRO SE MUEVE A IZQDA DIAGONAL Y COME A BLANCO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == BLANCO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 3" << "\n";
				matrix[i][j] == 2;
			}

			//CASO 6) NEGRO SE MUEVE A IZQDA DIAGONAL Y COME A NEGRO
			if ((coordenadas[origen.fila][origen.columna]->getTipo() == NEGRO) && (i == origen.fila - 1) && (j == origen.columna + 1) && (coordenadas[i][j]->getTipo() == NEGRO))
			{
				std::cout << "El Peon puede desplazarse a: la casilla: [ " << i << "," << j << "]" << "Que toma el valor 2" << "\n";
				matrix[i][j] == 3;
			}
		}
	}

	//Una vez recorridos los IFs la Matriz Auxiliar (que hemos inicializado en cero con el primer bucle) tendra unos doses y treses; 
	//Imprimimos para ver que queda;
	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n";
			}
		}
	}

	return 5;
	//SOLO Falta que devuelva la matriz matrix
}