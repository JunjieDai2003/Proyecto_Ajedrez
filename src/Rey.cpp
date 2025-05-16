#include "Rey.h"
#include <math.h>
#include<iostream>

//CONSTRUCTOR
Rey::Rey(Casilla coordenadas, Color color) :Pieza(coordenadas, color, Tipo::REY) {}

bool Rey::MovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[8][8])
{
	//MOVIMIENTO DEL REY 
	//El rey puede ,moverse en todas las direcciones que le rodean, solo una casilla, es decir tiene ocho 
	//casillas a las que se puede Desplazar/Comer.
	//La LOGICA del Rey es facil, puede moverse una fila, una columna o una fila y una columna
	//La diferencia entre la filas y columnas puede ser uno o cero, si no no puede moverse.
	
	int DiferenciaF = abs(destino.fila - origen.fila);
	int DiferenciaC = abs(destino.columna - origen.columna);

	if (coordenadas[origen.fila][origen.columna]->getColor() == BLANCO)
	{
		std::cout << "Movimiento de un REY BALNCO \n";
	}
	else if (coordenadas[origen.fila][origen.columna]->getColor() == NEGRO)
	{
		std::cout << "Moviendo un REY NEGRO \n";
	}

	if (DiferenciaF <= 1 && DiferenciaC <= 1)
	{
		if (coordenadas[destino.fila][destino.columna]->getTipo() == VACIO || coordenadas[destino.fila][destino.columna]->getColor() != coordenadas[origen.fila][origen.columna]->getColor())
		{
			return true;
		}
	}
	return false;

}
