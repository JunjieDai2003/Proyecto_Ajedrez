#include "Peon.h"
#include <math.h>
#include<iostream>


//CONSTRUCTOR
Peon::Peon(Casilla coordenadas, Color color) :Pieza(coordenadas, color, Tipo::PEON){}

//FUNCION MOVIMIENTO
//El PEON puede moverse hacia delante (en el caso que se mueva) O hacia los dos vertices (en el caso en que coma)
// TENEMOS QUE ESTUDIAR Y ENTENDER BIEN QUE HACE 
bool Peon::MovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[5][5])
{
	//Las clases derivadas de piezas tienen "CASILLAS", formadas por dos int
	std::cout << "Comprobar movimiento del PEON desde la casilla: " << origen.fila << "," << origen.columna << " hasta el destino: " << destino.fila << "," << destino.columna;

	int DiferenciaF = destino.fila - origen.fila;
	int DiferenciaC = destino.columna - origen.columna;


	

}