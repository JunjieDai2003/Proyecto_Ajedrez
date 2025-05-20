#pragma once
#include "Pieza.h"
class Peon : public Pieza
{

public:
	Peon(Tipo tipo, Color color) :Pieza(tipo, color) {};
	void miMov(const Casilla& origen,  Pieza* casilla[8][8], int matMov[8][8]) override;






	int MoviMatriz(const Casilla& origen, Pieza* coordenadas[8][8]);

};