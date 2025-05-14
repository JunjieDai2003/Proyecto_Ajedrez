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
	int movvalido[8][8] = { 0,0,1 }; // para detectar mov validos
	//std::vector<std::vector<Pieza*>> casillas2;
	//std::vector<std::vector<int>> mov;
	std::vector<Tipo> PIEZAS = { Tipo::TORRE, Tipo::CABALLO, Tipo::ALFIL, Tipo::REINA, Tipo::REY,Tipo::ALFIL,Tipo::CABALLO,Tipo::TORRE };

public:
	//Tablero();
	//~Tablero();
	void dibuja();
	void ColocarPeonInicial(int, Color);
	void ColocarPiezaInicial(int fila, Color color, std::vector<Tipo>PIEZAS);
	void Vacio(int fila);
	void configurarTablero();
};



