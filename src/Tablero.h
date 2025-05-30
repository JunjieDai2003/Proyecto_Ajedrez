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
	//Matriz de punteros que apuntan a los objetos de tipo pieza, con el polimorfismo podemos lograr que apunte a peones, reina....
	Pieza* casillas1[8][8];
	//matriz para almacenar posiciones donde hay una pieza que pueda realiaz una ejecucion
	int ejecucion[8][8] = { //prueba de que funciona bien
	{0,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1}
	}; 
	//matriz que almacena los movimientos de las piezas
	//0 si no se puede, 1 si es espacio vacio, 2 si es pieza enemiga, 3 si es pieza aliada
	int movvalido[8][8] = { 0 }; 
	//matriz para pintar el camino de la pieza seleccionada
	int matrizPintar[8][8];
	//matriz que pinta la casilla con la pieza con ejecucion obligatoria
	//su movimiento sera obligatorio
	int matrizPintarEjecucion[8][8] = { 0 };



public:
	//Tablero();
	~Tablero();
	void dibuja();
	void configurarTablero();
	int getColor(const Casilla&);
	void moverPiezasyAscenso(Casilla&, Casilla&);
	int movValido(const Casilla&, const Casilla&);
	void ascensoPeon();
	void pintaMov(const Casilla&);
	int endGame();
	bool encontrarEjecucion(int turno);
	bool getTableroEjecucion(Casilla&);
	void destruir();
};



