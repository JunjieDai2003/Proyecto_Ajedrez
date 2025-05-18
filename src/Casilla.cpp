#include "Casilla.h"
#include<math.h> //No hace falta, est?declarado en Casilla.h
#include<iostream>
int turno = 1;

//CONSTRUCTORES
//Crea una Casilla con dos parametros (int),fila y columna
Casilla::Casilla(int fil, int column)
{
	fila = fil;
	columna = column;
}
Casilla::Casilla() {}


//DESTRUCTOR
//elimina lo contenido en Casilla si lo llamamos
Casilla::~Casilla() {}

//FUNCIONES


bool operator==(const Casilla& c1, const Casilla& c2)
{
	return((c1.fila == c2.fila) && (c1.columna == c2.columna));
}


double Casilla::modulo()const
{
	return sqrt((fila * fila) + (columna * columna));//NO SE PARA QUE SIRVE
}
double Casilla::argumento()const
{
	return atan2(fila, columna); //NO SE PARA QUE SIRVE
}
// atan2(x,y) Calcula el ángulo EN RADIANES entre el eje positivo de X 
//y el vector (x,y)  