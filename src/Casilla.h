#pragma once
#include<math.h>
#include"ostream"
extern int turno;
extern int vidablanca;
extern int vidanegra;
class Casilla
{	//Me gustaria encontrar una forma en la que poner fila y columna en protected y tener acceso en otras clases
	//Falla en la clase PEON MovimientoValido me obliga a ponerlo en public, si no no tengo acceso a origen.fila
public:
	int fila, columna;
	//CONSTRUCTORES
	Casilla(int, int);
	Casilla(); //utilizado en pieza para construir pieza con el bucle y usando casilla

	

	void MostrarCasilla(Casilla); //A lo mejor lo usamos

	double modulo() const; //Devuelve el modulo de la casilla
	double argumento()const; //Devuelve el argumento
	
	//friend class Pieza;


};
bool operator == (const Casilla&, const Casilla&);
