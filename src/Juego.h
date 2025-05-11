#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include <iostream>
#include"Casilla.h"
class Juego
{
private:
	Tablero tablero;
	Casilla origen{ 100, 100 };//pongo una cooredenada inicial fuera de 8x8
	Casilla final{ 100, 100 };
public:
	void dibuja();
	void ratonjuego(int button, int state, int x, int y);
	Casilla getCoord(int x, int y);
};