#pragma once
#include"Juego.h"
//La idea principal era dibujar el tablero en el mundo 
//Pero despues de la reunion de Viernes, hemos decicidido cambiar la estructura
//Ahora Mundo sera simplemente una maquina de estado general que
//gestiona en qu¨¦ modo estamos
class Mundo
{
	Juego juego;
	enum Estado_mundo { PANT_INI, DOS_JUGADOR, CONTRA_AI};
	//int fil, col;
	//esta linea ya no lo neecsitamos si dibujamos en otra funcion
	Estado_mundo estado_mundo;

public:
	Mundo();
	//~Mundo(); 
	//void teclado(unsigned char key);
	void dibuja();
	void raton(int button, int state, int x, int y);
	//void ratonmundo(int button, int state, int x, int y);
};

