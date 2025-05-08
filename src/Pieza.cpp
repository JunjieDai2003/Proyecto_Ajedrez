#include "Pieza.h"

Pieza::Pieza()
{
	movida = 0;
}
Pieza::Pieza(const Pieza& p) //SIGO SIN SABER PORQUE USA &
{
	tipo = p.tipo;
	color = p.color;
	casilla = p.casilla;
}

Pieza::~Pieza() {}