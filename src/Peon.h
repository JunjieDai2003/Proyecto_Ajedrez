#pragma once
#include "Pieza.h"

//Peon,Torre,Caballo,Alfil,Rey,Reina van a tener #include"Pieza.h"
//Creo que la mejor opción en vez de usar friend es :public Pieza
//Así tienen acceso a las funciones, métodos... de pieza
//Podemos ir viendo y cambiarlo si algo no nos cuadra

class Peon :public Pieza
{
	//CONSTRUCTOR
	Peon(Casilla, Color);



	//FUNCION PARA VER SI EL MOVIMIENTO ES VÁLIDO verifica los POSIBLES movimientos
	static bool MovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* coordenadas[5][5]);
	//FUNCION parecida a la que se encuentra en pieza 
	/*
	virtual bool puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* Casilla[5][5])
	{
		return false;
	}*/
};