#pragma once
#include"Pieza.h"

class Rey :public Pieza
{
	//CONSTRUCTOR
	Rey(Casilla, Color);

	//FUNCION PARA VER SI EL MOVIMIENTO ES VÁLIDO verifica los POSIBLES movimientos
	static bool MovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[8][8]);
	
};