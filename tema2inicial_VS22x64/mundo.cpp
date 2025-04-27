#include "mundo.h"
#include"freeglut.h"
#include<iostream>
#include"tablero.h"

//empezasmos la maquina de estado con PANT_INI, enum ESTADO, la idea es ir ampliando el enum para los posibles estados futuros
// como podria ser 
// el de seleccionar pieza e comprobar la validez de movimiento,
// estado de jaque y obligacion de matar
// estado de fin 
// estado de IA

mundo::mundo()
{
	estado = PANT_INI;
	fil = 0;
	col = 0;
}
mundo::~mundo()
{
	//todavia no entiendo muy bien como funciona destructor
}
void mundo::dibuja()
{
	switch (estado)
	{
	case PANT_INI:
		std::cout << "hola\n";
		//DIBUJAR EN UNA PANTALLA UN CUADRO DONDE PONE LAS DIFERENNTES POCIONES DE JUEGO
		//dibujar pantalla de inicio
		gluLookAt(0.0, 0.0, 20,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 5, 0.0);      // definimos hacia arriba (eje Y)    

		//aqui es donde hay que poner el c¨®digo de dibujo
		glutWireCube(5);
		break;
		//IMPRIMIR EL TABLERO
		//JUEGO Y JUGANDO PUEDE SER UNA MISMA FUNCION
	case JUEGO:
		tab.dibuja(100, 100);//IMPRIIMIIR POR PRIMERA VEZ SIN SELECCION DE PIEZA, SE PUEDE RECICLAR PARA POS SELECCION
		break;
	case JUGANDO:
		tab.dibuja(mundo::fil, mundo::col); //tab.dibuja(mund::fil,mundo::col) //SELECCION DE CASILLA, FALTA LA CONVERSION DE EJE A CASILLA
		break;
	}
}
//ESTE CODIGO ESTA COMENTADO PQ HAY UN BUG DE QUE SOLO REFRESCA SI CLICKEAMOS EL RATON
//HABRA QUE SOLUCIONARLO POSTERIORMENTE
/*void mundo::teclado(unsigned char key)
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
void mundo::raton(int button, int state, int x, int y)
{
	switch (estado)
	{
	case PANT_INI:
		if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 280) && (x < 520) && (y > 180) && (y < 420))
		{
			estado = JUEGO;
		}
		else
		{
			std::cout << "fuera de rango\n";//por alguna razon imprime 2 veces esto, no molesta, esto es para orientar
		}
		break;
	case JUEGO:
		if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 235) && (x < 565) && (y > 135) && (y < 465))
		{
			estado = JUEGO;
			estado = JUGANDO;
			//conversion de x y a fil col
			mundo::col = (x - 330) / 41.25;
			mundo::fil = (y - 330) / 41.25;
			std::cout << "casilla x" << mundo::fil << "casilla y " << mundo::col;
		}
	case JUGANDO:
		if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 235) && (x < 565) && (y > 135) && (y < 465))
		{
			estado = JUEGO;
			estado = JUGANDO;
			//conversion de x y a fil col
			mundo::col = (x - 235) / 41.25;
			mundo::fil = (y - 135) / 41.25;
			std::cout << "casilla x" << mundo::fil << "casilla y " << mundo::col;
		}
	}
}
//*/