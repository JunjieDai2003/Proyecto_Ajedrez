#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include <iostream>
#include"Casilla.h"
class Juego
{
private:
	enum Estado_juego { Seleccion1, Seleccion2 };
	enum Turno { Blanco, Negro }; //para cambiar turnov2 = Blanco
	Turno turnov2;
	int turnov1; //para cambiar turno++ y comprobar si es par o no
	Estado_juego estado_juego;
	Tablero tablero;
	Casilla origen{ 100, 100 };//pongo una cooredenada inicial fuera de 8x8
	Casilla final{ 100, 100 };
public:
	Juego();
	void dibuja();
	void ratonjuego(int button, int state, int x, int y);
	Casilla getCoord(int x, int y);
};