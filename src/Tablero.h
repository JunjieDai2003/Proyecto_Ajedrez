#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"
class Tablero
{
	//una matriz donde sus elementos son de clase pieza
	int **casillas1;
	Pieza* casillas3[8][8];
	std::vector<std::vector<Pieza*>> casillas2;
	std::vector<std::vector<int>> mov;

public:
	Tablero();
	~Tablero();
	void dibuja();
};



