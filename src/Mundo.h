#pragma once
#include"Juego.h"
//La idea principal era dibujar el tablero en el mundo 
//Pero despues de la reunion de Viernes, hemos decicidido cambiar la estructura
//Ahora Mundo sera simplemente una maquina de estado general que
//gestiona en qu¨¦ modo estamos
class Mundo
{
	Juego juego;
	enum Estado_mundo { PANT_INI, DOS_JUGADOR, CONTRA_AI,BLACK,WHITE, END , END_FORREAL};
	Estado_mundo estado_mundo;

public:
	Mundo();
	void dibuja();
	void raton(int button, int state, int x, int y);
};

