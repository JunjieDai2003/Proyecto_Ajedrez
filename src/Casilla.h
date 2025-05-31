#pragma once
#include<math.h>
#include"ostream"
extern int turno;
class Casilla
{	
public:
	int fila, columna;
	//CONSTRUCTORES
	Casilla(int, int);
	Casilla(); 

};
//sobrecarga de operador
bool operator == (const Casilla&, const Casilla&);
