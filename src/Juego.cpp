#include "Juego.h"
#include <iostream>
Juego::Juego()
{
	estado_juego = Seleccion1;
	turno = 2;
	//fil = 0;
	//col = 0;
}
void Juego::dibuja()
{
	//colocamos un fondo con etsidi.h
	tablero.dibuja();
}
Casilla Juego::getCoord(int x, int y)
{
	//las coordenadas seran modificadas posteriormente, este funciona con mi pov, pero creo q usare pov de laboratorio
	Casilla casilla;
	casilla.columna = (x - 330) / 41.25;
	casilla.fila = (y - 330) / 41.25;
	std::cout << "estoy clickeando " << casilla.columna << " y " << casilla.fila << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	return casilla;
}
void Juego::ratonjuego(int button, int state, int x, int y)
{

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		switch (estado_juego)
		{
			case Seleccion1:
				origen = getCoord(x, y);
				//comprobar de que se ha seleccionado dentro, si no, break directamente;
				//if(turno%2!=0) estado_juego=Seleccion1://has seleccionado color incorrecto o vacio
				//else dibujo con tablero la casilla seleccionada y movimientos permitidos
				estado_juego = Seleccion2;
				break;
			case Seleccion2:
				final = getCoord(x, y);
				//comprobar de que se ha seleccionado dentro, si no, break directamente;
				//if(final=inicial) estado_juego=Seleccion1; Selecciono misma casilla
				//limpiamos lo dibujado; break;
				//if(movimiento no permitido)
				//limpiamos lo dibujado; break; es un or con anterior
				//else(cambiamos la matriz de tablero)
				//limpiamos lo destacado;
				//estado_juego=Seleccioon1;
				//turno++;
				//break;
		}	
	}
	return ;//hay q cambiar, dejo aqui para no saltar error
}