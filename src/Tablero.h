#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"
#include<vector>
#include "Peon.h"
#include "Vacio.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include"Reina.h"

class Tablero
{
	Pieza p;
	//una matriz donde sus elementos son de clase pieza
	//int **casillas1;
	Pieza* casillas1[8][8];
	int ejecucion[8][8] = { //prueba de que funciona bien
	{0,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}
	}; //para detectar pieza con ejecucion obligatoria
	int movvalido[8][8] = { 0 }; // para detectar mov validos
	//std::vector<std::vector<Pieza*>> casillas2;
	//std::vector<std::vector<int>> movvalido2;
	

	int matrizPintar[8][8];



public:
	//Tablero();
	~Tablero();
	void dibuja();
	void configurarTablero();
	int getColor(const Casilla&);
	void moverPiezasyAscenso(Casilla&, Casilla&);
	//Casilla getCasilla(const Casilla& casilla);
	int movValido(const Casilla&, const Casilla&);
	void ascensoPeon();
	void pintaMov(const Casilla&);
	int endGame();
};



