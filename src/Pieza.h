#pragma once
#include "Casilla.h"
#include<vector>
#include "freeglut.h"
enum  Tipo { VACIO, PEON, CABALLO, ALFIL, TORRE, REY, REINA };
enum Color { NO_COLOR=0, BLANCO, NEGRO };

class Pieza :public Casilla
{
	//Hago :public Casilla porque todas las piezas contienen
	//una casilla asi puedes usar su constructor
protected: //Lo hago protected porque de pieza van a heredar otras clases
	Tipo tipo;
	Color color;
	Casilla casilla;
	int fila, columna;
	bool movida = 0;//Para ver si la pieza se ha movido durante la partida, lo veremos proximamente
	//Todas las piezas tienen un color, son un tipo,
	//y están en una Casilla
	//Inicializo movida en 0, siempre presuponemos que no se mueve VER funcion puedeMoverse()
public:
	//CONSTRUCTORES
	Pieza(Tipo tipo, Color color, int fila, int col) :tipo(tipo), color(color), casilla(fila, col), fila(fila), columna(col) {};
	Pieza(); //CONSTRUCTOR por defecto
	Pieza(/*int fila, int columna,*/  Casilla cas, Color color, Tipo tipo) :/*fila(fila), columna(columna),*/  Casilla(cas), color(color), tipo(tipo) {}
	//Porque crea fila y columna en vez de meter directamente la Casilla??? asi se ahorra crear y aprovecha lo creado???
	//MODIFICAR EL CONSTRUCTOR
	Pieza(const Pieza& p); //CONSTRUCTOR PUEDE COPIAR A OTRA PIEZA?????
	//DESTRUCTOR por defecto
	~Pieza();
	//////////////////////////////////////////////////////////////////////////////////////////
	


	//GETTERS
	Tipo getTipo()const { return tipo; }
	Color getColor()const { return color; }
	Casilla getCasilla()const { return casilla; }
	bool getMovida()const { return movida; }//TODAVIA NO SE PARA QUE SIRVE NI COMO SE UTILIZA
	int getFila()const { return casilla.fila; }
	int getColumna()const { return casilla.columna; }

	//SETTERS
	//Una vez que mueves piezas se usan las siguientes funciones
	void setTipo(Tipo nuevoTipo) { tipo = nuevoTipo; }
	void setColor(Color nuevoColor) { color = nuevoColor; }
	//me gustaria averiguar esto
	//void setCasilla(Casilla casilla) { casilla.fila =fila; casilla.columna = columna; }
	void setCasilla(int fil, int colum) { casilla.fila = fil; casilla.columna = colum; }
	void setMovida(bool a) { movida = a; }//ESTO NO SIRVE??? 
	//No hace falta settear la fila y columna porque en nuestro caso usamos directamente
	//la casilla que creo que es mejor, ya veremos si lo cambiamos o que 

	virtual bool Movimeintovalido(const Casilla& origen, const Casilla& destino, Pieza* Casilla[5][5])
	{
		return false;
	}
	//Este método va a retornar siempre False,es decir que la pieza no puede moverse,
	//las clases derivadas de PIEZA (PEON,CABALLO,ALFIL...) son las que podrán modificarlo
	//TENGO QUE ESTUDIAR LAS SALIDAS QUE NO TERMINO DE ENTENDERLO

	void dibuja(float x, float y);



};