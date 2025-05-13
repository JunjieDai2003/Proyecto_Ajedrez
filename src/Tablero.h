#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"
class Tablero
{
	//una matriz donde sus elementos son de clase pieza
	//int **casillas1;
	Pieza* casillas1[8][8];
	int ejecucion[8][8] ={ //prueba de que funciona bien
	{0,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1} 
	}; //para detectar pieza con ejecucion obligatoria
	int movvalido[8][8] = { 0,0,1 }; // para detectar mov validos
	//std::vector<std::vector<Pieza*>> casillas2;
	//std::vector<std::vector<int>> mov;

public:
	//Tablero();
	//~Tablero();
	void dibuja();
};



