#pragma once
#include"Tablero.h"
class Maquina
{
	Tablero tab;
	enum Estado { PANT_INI, JUEGO, JUGANDO };
	int fil, col;
	Estado estado;

public:
	Maquina();
	~Maquina();
	void teclado(unsigned char key);
	void dibuja();
	void raton(int button, int state, int x, int y);
};

