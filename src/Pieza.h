#pragma once
#include "ETSIDI.h"
#include "Casilla.h"
#include<vector>
#include "freeglut.h"
#include<iostream>
enum  Tipo { VACIO, PEON, CABALLO, ALFIL, TORRE, REY, REINA };
enum Color { NO_COLOR = 0, BLANCO, NEGRO };

class Pieza
{
	
protected: //Lo hago protected porque de pieza van a heredar otras clases
	Tipo tipo;
	Color color;
	int fila, columna;

	
public:
	//CONSTRUCTORES
	Pieza(Tipo tipo, Color color) :tipo(tipo), color(color) {};
	Pieza(); //CONSTRUCTOR por defecto
	virtual ~Pieza();
	///////////////////////////////////////////////////////////////////////////////



	//GETTERS
	Tipo getTipo()const { return tipo; }
	Color getColor()const { return color; }

	//funcion virtual para las clases hijas
	virtual void miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]);
	//virtual ~Pieza() = default;
	virtual void dibuja(float x, float y);



};