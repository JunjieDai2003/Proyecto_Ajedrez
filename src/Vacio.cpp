#include"Vacio.h"

void Vacio::miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]) {
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			matMov[i][j] = 0;
		}
	}
    // implementaci¨®n aqu¨ª
    return;
}
void Vacio::dibuja(float x, float y)
{
    return;
}