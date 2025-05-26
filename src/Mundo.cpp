#include "Mundo.h"
#include"ETSIDI.h"
#include"freeglut.h"
#include<iostream>
#include"Juego.h"
//enum Estado { PANT_INI, DOS_JUGADOR,CONTRA_AI, END};
Mundo::Mundo()
{
	estado_mundo = PANT_INI;
	//fil = 0;
	//col = 0;
}
/*Mundo::~Mundo()
{
	//todavia no entiendo muy bien como funciona destructor
}*/
void Mundo::dibuja()
{
	switch (estado_mundo)
	{
	case PANT_INI:
		std::cout << "QUE QUIERES JUGAR?\n";
		gluLookAt(0, 7.5, 20,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case DOS_JUGADOR:
		juego.dibuja();
		//imprimimos el tablero aqui
		break;
	case END:
		gluLookAt(0, 7.5, 20,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/termino.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case END_FORREAL:
		//teneis que llamar funciones para limpiar la memoria.
		exit(0);
		break;
	case CONTRA_AI:
		break;
	}
}
//ESTE CODIGO ESTA COMENTADO PQ HAY UN BUG DE QUE SOLO REFRESCA SI CLICKEAMOS EL RATON
//HABRA QUE SOLUCIONARLO POSTERIORMENTE
/*void Mundo::teclado(unsigned char key)
{
	switch (estado)
	{
	case PANT_INI:
		if (key == 'j' || key == 'J')
		{
			estado = JUEGO;
			dibuja();
		}
	}
}*/
///*
void Mundo::raton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch (estado_mundo)
		{
		case PANT_INI:
			if ((x > 224) && (x < 576) && (y > 298) && (y < 385))
			{
				estado_mundo = DOS_JUGADOR;
			}
			else
			{
				std::cout << "fuera de rango \n";//por alguna razon imprime 2 veces esto, no molesta, esto es para orientar
			}

			break;
		case END: {
			if ((x > 197) && (x < 599) && (y > 246) && (y < 338))
			{
				estado_mundo = DOS_JUGADOR;
			}
			else if ((x > 203) && (x < 599) && (y > 379) && (y < 471))
			{
				estado_mundo = END_FORREAL;
			}
			else
			{
				std::cout << "fuera de rango \n";//por alguna razon imprime 2 veces esto, no molesta, esto es para orientar
			}
		}

		}
		if (estado_mundo == CONTRA_AI || estado_mundo == DOS_JUGADOR)
		{
			if (juego.ratonjuego(button, state, x, y) == 1) {
				estado_mundo = END;
			}
		}
	}


}
//paso lla informacion de raton 
/*
void Mundo::ratonmundo(int button, int state, int x, int y)
{
	if(estado==CONTRA_AI || estado==DOS_JUGADOR)
	{
		juego.ratonjuego(button, state, x, y);
	}
}*/
//*/