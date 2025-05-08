#pragma once
#include<math.h>

class Casilla
{
protected:
	int fila, columna;
public:
	 //CONSTRUCTORES
	Casilla(int, int);
	Casilla();

	//DESTRUCTOR 
	~Casilla();

	double modulo() const; //Devuelve el modulo de la casilla
	double argumento()const; //Devuelve el argumento

	friend class Pieza; // No se porque los hace FRIEND
	friend class Tablero; // creo que es mejor ir haciéndolos public;
	friend class Ajedrez; //Tipo class Pieza:public Tablero{};
};