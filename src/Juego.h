#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include <iostream>
#include"Casilla.h"
class Juego
{
private:
	//maquina de estado de menu, primera seleccion y segunda seleccion de cada turno, estado de fin
	enum Estado_juego { Seleccion1, TurnoBlanco,TurnoBlanco2,TurnoNegro,TurnoNegro2,END};
	Estado_juego estado_juego;
	Tablero tablero;
	Casilla origen{ 100, 100 };//pongo una cooredenada inicial fuera de 8x8, aunque ya no es necesario pq no pinta hasta primer getCasilla
	Casilla final{ 100, 100 };
public:
	Juego();
	void dibuja();
	int ratonjuego(int button, int state, int x, int y);
	Casilla getCoord(int x, int y);
};