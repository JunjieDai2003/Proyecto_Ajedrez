#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"
#include<vector>
class Tablero
{
	Pieza p;
	//una matriz donde sus elementos son de clase pieza
	//int **casillas1;
	Pieza* casillas1[8][8];
	int ejecucion[8][8]; //para detectar pieza con ejecucion obligatoria
	int movvalido[8][8] = { 0,0,1 }; // para detectar mov validos
	//std::vector<std::vector<Pieza*>> casillas2;
	//std::vector<std::vector<int>> movvalido2;
	std::vector<Tipo> PIEZAS = { Tipo::TORRE, Tipo::CABALLO, Tipo::ALFIL, Tipo::REINA, Tipo::REY,Tipo::ALFIL,Tipo::CABALLO,Tipo::TORRE };

public:
	//Tablero();
	//~Tablero();
	void dibuja();
	void configurarTablero();
	Color getColor(const Casilla&);
	void moverPiezasyAscenso(Casilla&, Casilla&);
	Casilla getCasilla(const Casilla& casilla);
	int movValido(const Casilla&, const Casilla&);
	void ascensoPeon();
	int cantidadBlanco();
	int cantidadNegro();
};



