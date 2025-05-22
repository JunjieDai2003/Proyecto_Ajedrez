#include "Juego.h"
#include "ETSIDI.h"
#include <iostream>
Juego::Juego()
{
	estado_juego = Seleccion1;
	//turnov1 = 2;
	//fil = 0;
	//col = 0;
}
void Juego::dibuja()
{

	gluLookAt(4.5, 4.5, 20,  // posicion del ojo
		4.5, 4.5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
	tablero.dibuja();//hay que dibujarlo antes
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rift.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-7, -5);
	glTexCoord2d(1, 1); glVertex2f(15, -5);
	glTexCoord2d(1, 0); glVertex2f(15, 15);
	glTexCoord2d(0, 0); glVertex2f(-7, 15);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
Casilla Juego::getCoord(int x, int y)
{
	//las coordenadas seran modificadas posteriormente, este funciona con mi pov, pero creo q usare pov de laboratorio
	Casilla casilla;
	casilla.fila = (483 - y) / 45.87;
	casilla.columna = (x - 216) / 46.25;
	std::cout << "estoy clickeando " << x << " y " << y << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	std::cout << "estoy clickeando " << casilla.fila << " y " << casilla.columna << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	return casilla;
}
void Juego::ratonjuego(int button, int state, int x, int y)
{

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 216) && (x < 585) && (y > 116) && (y < 483))
	{
		switch (estado_juego)
		{
		case Seleccion1: //primera etapa
			//origen = getCoord(x, y);
			//comprobar de que se ha seleccionado dentro, si no, break directamente;
			//if(turno%2!=0) estado_juego=Seleccion1://has seleccionado color incorrecto o vacio
			//else dibujo con tablero la casilla seleccionada y movimientos permitidos
			tablero.configurarTablero();
			estado_juego = TurnoBlanco;
			turno = 0;
			std::cout << "estoy en seleccion inicial\n";
			break;
		case TurnoBlanco:
			std::cout << "Es turno de los blancos\n\n";
			origen = getCoord(x, y);
			//tablero.getCasilla(origen);
			if (/*turno % 2 == 0 &&*/ tablero.getColor(origen) == 1)
			{
				std::cout << "seleccionaste blanco en turno correcto, selecciona siguiente posicion\n";
				tablero.pintaMov(origen);
				estado_juego = TurnoBlanco2;
				turno = 0;
			}
			else
			{
				std::cout << "seleccionaste negro en turno erroneo, vuelve a seleccionar una pieza blanca\n";
				estado_juego = TurnoBlanco;
				turno = 0;
			}
			break;
		case TurnoBlanco2:
			final = getCoord(x, y);
			std::cout << "puedes eliminar tu propia pieza, por lo que no comprobamos el color salvo haya una ejecucion\n";
			//codigo de abajo es orientativo, sera sustituido en una line///////77
			////////////////////777
			/////////////////////
			if (tablero.movValido(origen, final) == 0)
			{
				estado_juego = TurnoBlanco;

				break;
			}
			if (final == origen)
			{
				std::cout << "seleccionaste misma pieza,vuele a seleccionar la pieza de inicio\n";
				estado_juego = TurnoBlanco;
			}
			else if (tablero.getColor(final) == 0)
			{
				std::cout << "seleccionaste vacio\n";
				tablero.moverPiezasyAscenso(origen, final);
				estado_juego = TurnoNegro;
				turno = 1;

			}
			else if (tablero.getColor(final) == 2)
			{
				std::cout << "ejecutas tu propia pieza\n";
				tablero.moverPiezasyAscenso(origen, final);
				estado_juego = TurnoNegro;
				vidablanca--;
				turno = 1;
			}
			else
			{
				std::cout << "ejecutas pieza negra\n";
				tablero.moverPiezasyAscenso(origen, final);
				estado_juego = TurnoNegro;
				turno = 1;
				vidanegra--;
			}
			if (vidablanca == 0 || vidanegra == 0)
			{
				estado_juego = END;
			}
			break;
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case TurnoNegro:
			std::cout << "Es turno de los negros\n\n";
			origen = getCoord(x, y);
			if (/*turno % 2 == 1 &&*/ tablero.getColor(origen) == 2)
			{
				std::cout << "seleccionaste negro en turno correcto, selecciona siguiente posicion\n";
				tablero.pintaMov(origen);
				estado_juego = TurnoNegro2;
				turno = 1;
			}
			else
			{
				std::cout << "seleccionaste blanco en turno erroneo, vuelve a seleccionar una pieza negro\n";
				estado_juego = TurnoNegro;
				turno = 1;
			}
			break;
		case TurnoNegro2:
			final = getCoord(x, y);
			std::cout << "puedes eliminar tu propia pieza, por lo que no comprobamos el color salvo haya una ejecucion\n";
			if (tablero.movValido(origen, final) == 0)
			{
				estado_juego = TurnoNegro;
				turno = 1;
				break;
			}
			//codigo de abajo es orientativo
			if (final == origen)//quiero usar sobrecarga de operador para comprobar,final y origen son de clase casilla
				//sobrecarga en casilla
				//es como poner final.fila==origen.fila && final.columa==origen.columna
			{
				std::cout << "seleccionaste misma pieza,vuele a seleccionar la pieza de inicio\n";
				estado_juego = TurnoNegro;
				turno = 1;
				break;
			}
			//esto es orientativo, se puede sustituir por una fila de operacion exitoso
			else if (tablero.getColor(final) == 0)
			{
				std::cout << "seleccionaste vacio\n";
				tablero.moverPiezasyAscenso(origen, final);
				estado_juego = TurnoBlanco;
				turno = 0;
			}
			else if (tablero.getColor(final) == 1)
			{
				std::cout << "ejecutas tu propia pieza\n";
				tablero.moverPiezasyAscenso(origen, final);
				estado_juego = TurnoBlanco;
				vidanegra--;
				turno = 0;
			}
			else
			{
				std::cout << "ejecutas pieza blanca\n";
				estado_juego = TurnoBlanco;
				tablero.moverPiezasyAscenso(origen, final);
				vidablanca--;
				turno = 0;
			}
			if (vidablanca == 0 || vidanegra == 0)
			{
				estado_juego = END;
			}
			break;
		case END:
		{
			std::cout << "se ha terminado\n";
			break;
		}

		}
		//tablero.ascensoPeon();
	}
	return;//hay q cambiar, dejo aqui para no saltar error
}