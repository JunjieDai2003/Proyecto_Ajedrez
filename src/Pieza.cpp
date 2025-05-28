#include "Pieza.h"
#include "ETSIDI.h"
Pieza::Pieza()
{
}

void Pieza::miMov(const Casilla& origen,  Pieza* casilla[8][8], int matMov[8][8])
{
	return;
}

Pieza::~Pieza()
{
	std::cout << "bASE DESTR\n";
}

void Pieza::dibuja(float x, float y)
{
	/*
	float dim = (float)9 / 8;
	float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
	float cen = (dim - dim1) / 2;

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	*/	
	return;
}