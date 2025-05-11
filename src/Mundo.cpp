#include "Mundo.h"
#include"ETSIDI.h"
#include"freeglut.h"
#include<iostream>
#include"Juego.h"
//enum Estado { PANT_INI, DOS_JUGADOR,CONTRA_AI};
Mundo::Mundo()
{
	estado = PANT_INI;
	//fil = 0;
	//col = 0;
}
/*Mundo::~Mundo()
{
	//todavia no entiendo muy bien como funciona destructor
}*/
void Mundo::dibuja()
{
	switch (estado)
	{
	case PANT_INI:
		std::cout << "QUE QUIERES JUGAR?\n";
		//DIBUJAR EN UNA PANTALLA UN CUADRO DONDE PONE LAS DIFERENNTES POCIONES DE JUEGO
		//dibujar pantalla de inicio
		gluLookAt(0.0, 0.0, 20,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 5, 0.0);      // definimos hacia arriba (eje Y)    
		glutWireCube(5);
		//aqui es donde hay que poner el c¨®digo de dibujo
		//glutWireCube(5);
		break;
	case DOS_JUGADOR:
		juego.dibuja();
		//imprimimos el tablero aqui
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
	switch (estado)
	{
	case PANT_INI:
		if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 280) && (x < 520) && (y > 180) && (y < 420))
		{
			estado = DOS_JUGADOR;
		}
		else
		{
			estado = CONTRA_AI;
			std::cout << "fuera de rango y por lo tanto vs ai\n";//por alguna razon imprime 2 veces esto, no molesta, esto es para orientar
		}
		break;

	}
	if (estado == CONTRA_AI || estado == DOS_JUGADOR)
	{
		juego.ratonjuego(button, state, x, y);
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