#pragma once
#include"Pieza.h"

class Alfil :public Pieza
{
public:
	//CONSTRUCTOR
	Alfil();
	Alfil(Casilla, Color);

	//FUNCION PARA VERIFICAR MOVIMIENTOS
	static bool PuedeMoverse(const Casilla&, const Casilla&, Pieza* coordenaddas[5][5]);
};