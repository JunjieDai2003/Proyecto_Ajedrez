#include "Pieza.h"
#include "ETSIDI.h"
Pieza::Pieza()
{
}

void Pieza::miMov(const Casilla& origen,  Pieza* casilla[8][8], int matMov[8][8])
{
	return;
}



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
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon_blanco.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon_negro.png").id);
			break;
		case REY:
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey_blanco.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey_negro.png").id);
			break;
		case REINA:
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reina_blanca.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reina_negra.png").id);
			break;
		case TORRE:
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torre_blanco.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torre_negro.png").id);
			break;
		case CABALLO:
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo_blanco.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo_negro.png").id);
			break;
		case ALFIL:
			if (color == BLANCO)
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil_blanco.png").id);
			else
				glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfinal_negro.png").id);
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