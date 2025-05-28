#pragma once
#include "Pieza.h"
class Alfil :public Pieza
{
public:
	Alfil(Tipo tipo, Color color) :Pieza(tipo, color) {};
	void miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]) override;
	void dibuja(float x, float y) override;
	~Alfil()override;
};


