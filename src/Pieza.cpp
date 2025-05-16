#include "Pieza.h"
#include "ETSIDI.h"
Pieza::Pieza()
{
	movida = 0;
}
Pieza::Pieza(const Pieza& p)
{
	tipo = p.tipo;
	color = p.color;
	//casilla = p.casilla;
}

Pieza::~Pieza() {}

void Pieza::dibuja(float x, float y)
{
	float dim = (float)9 / 8;
	float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
	float cen = (dim - dim1) / 2;

	if (color == BLANCO || color == NEGRO)
	{
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		switch (tipo)
		{
		case PEON:

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon_blanco.png").id);
			break;
		case REY:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey_negro.png").id);
			break;
		case REINA:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reina_blanca.png").id);
			break;
		case TORRE:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torre_blanco.png").id);
			break;
		case CABALLO:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo_blanco.png").id);
			break;
		case ALFIL:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil_blanco.png").id);
			break;
		}
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glColor4f(1, 1, 1, 0.9);
		glTexCoord2d(0, 1); glVertex3f(x + cen, y + cen, 0.01);
		glTexCoord2d(1, 1); glVertex3f(x + cen + dim1, y + cen, 0.01);
		glTexCoord2d(1, 0); glVertex3f(x + dim1 + cen, y + dim1 + cen, 0.01);
		glTexCoord2d(0, 0); glVertex3f(x + cen, y + dim1 + cen, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}