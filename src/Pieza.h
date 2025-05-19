#pragma once
#include "Casilla.h"
#include<vector>
#include "freeglut.h"
enum  Tipo { VACIO, PEON, CABALLO, ALFIL, TORRE, REY, REINA };
enum Color { NO_COLOR = 0, BLANCO, NEGRO };

class Pieza
{
	//Hago :public Casilla porque todas las piezas contienen
	//una casilla asi puedes usar su constructor
protected: //Lo hago protected porque de pieza van a heredar otras clases
	Tipo tipo;
	Color color;
	//Casilla casilla;
	int fila, columna;

	//Todas las piezas tienen un color, son un tipo,
	//y están en una Casilla
	//Inicializo movida en 0, siempre presuponemos que no se mueve VER funcion puedeMoverse()
public:
	//CONSTRUCTORES
	Pieza(Tipo tipo, Color color) :tipo(tipo), color(color) {};
	Pieza(); //CONSTRUCTOR por defecto

	//DESTRUCTOR por defecto
	//~Pieza();
	//////////////////////////////////////////////////////////////////////////////////////////



	//GETTERS
	Tipo getTipo()const { return tipo; }
	Color getColor()const { return color; }
	//Casilla getCasilla()const { return casilla; }

	//int getFila()const { return casilla.fila; }
	//int getColumna()const { return casilla.columna; }

	//SETTERS
	//Una vez que mueves piezas se usan las siguientes funciones
	void setTipo(Tipo nuevoTipo) { tipo = nuevoTipo; }
	void setColor(Color nuevoColor) { color = nuevoColor; }
	//me gustaria averiguar esto
	//void setCasilla(Casilla casilla) { casilla.fila =fila; casilla.columna = columna; }
	//void setCasilla(int fil, int colum) { casilla.fila = fil; casilla.columna = colum; }


	virtual void miMov(const Casilla& origen, const Pieza* casilla[8][8], int matMov[8][8]);
	//virtual ~Pieza() = default;




	void dibuja(float x, float y);



};