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
	Casilla(); //Realmente no serviría???

	//DESTRUCTOR 
	~Casilla();

	void MostrarCasilla(Casilla); //A lo mejor lo usamos


	//friend class Pieza; // No se porque los hace FRIEND
	//friend class Tablero; // creo que es mejor ir haciéndolos public;
	//friend class Juego; //Tipo class Pieza:public Tablero{};
};
bool operator == (const Casilla&, const Casilla&);
