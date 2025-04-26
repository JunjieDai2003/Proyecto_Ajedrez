#pragma once
#include"tablero.h"
class mundo
{
	tablero tab;
	enum Estado { PANT_INI, JUEGO, JUGANDO };
	int fil, col;
	Estado estado;

public:
	mundo();
	~mundo();
	void teclado(unsigned char key);
	void dibuja();
	void raton(int button, int state, int x, int y);
};

