#pragma once
#include "Casilla.h"
#include<vector>
#include "freeglut.h"
enum  Tipo { VACIO, PEON, CABALLO, ALFIL, TORRE, REY, REINA };
enum Color { NO_COLOR=0, BLANCO, NEGRO };

class Pieza 
{
	//Hago :public Casilla porque todas las piezas contienen
	//una casilla asi puedes usar su constructor
protected: //Lo hago protected porque de pieza van a heredar otras clases
	Tipo tipo;
	Color color;
	Casilla casilla;
	int fila, columna;
	
	//Todas las piezas tienen un color, son un tipo,
	//y están en una Casilla
	//Inicializo movida en 0, siempre presuponemos que no se mueve VER funcion puedeMoverse()
public:
	//CONSTRUCTORES
	Pieza(Tipo tipo, Color color, Casilla casilla) :tipo(tipo), color(color), casilla(casilla){};
	Pieza(); //CONSTRUCTOR por defecto
	
	//DESTRUCTOR por defecto
	~Pieza();
	//////////////////////////////////////////////////////////////////////////////////////////
	


	//GETTERS
	Tipo getTipo()const { return tipo; }
	Color getColor()const { return color; }
	Casilla getCasilla()const { return casilla; }
	
	int getFila()const { return casilla.fila; }
	int getColumna()const { return casilla.columna; }

	//SETTERS
	//Una vez que mueves piezas se usan las siguientes funciones
	void setTipo(Tipo nuevoTipo) { tipo = nuevoTipo; }
	void setColor(Color nuevoColor) { color = nuevoColor; }
	//me gustaria averiguar esto
	//void setCasilla(Casilla casilla) { casilla.fila =fila; casilla.columna = columna; }
	void setCasilla(int fil, int colum) { casilla.fila = fil; casilla.columna = colum; }
	
	//No hace falta settear la fila y columna porque en nuestro caso usamos directamente
	//la casilla que creo que es mejor, ya veremos si lo cambiamos o que 

	virtual bool puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* Casilla[5][5])
	{
		return false;
	}
	//Este método va a retornar siempre False,es decir que la pieza no puede moverse,
	//las clases derivadas de PIEZA (PEON,CABALLO,ALFIL...) son las que podrán modificarlo
	//TENGO QUE ESTUDIAR LAS SALIDAS QUE NO TERMINO DE ENTENDERLO

	void dibuja(float x, float y);



};