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
	glTexCoord2d(0, 1); glVertex2f(-15, -5);
	glTexCoord2d(1, 1); glVertex2f(15, -5);
	glTexCoord2d(1, 0); glVertex2f(15, 20);
	glTexCoord2d(0, 0); glVertex2f(-15, 20);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
Casilla Juego::getCoord(int x, int y)
{
	//las coordenadas seran modificadas posteriormente, este funciona con mi pov, pero creo q usare pov de laboratorio
	Casilla casilla;
	casilla.columna = (y - 116) / 45.87;
	casilla.fila = (x - 216) / 46.25;
	std::cout << "estoy clickeando " << x << " y " << y << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	std::cout << "estoy clickeando " << casilla.columna << " y " << casilla.fila << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	return casilla;
}
void Juego::ratonjuego(int button, int state, int x, int y)
{

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) && (x > 216) && (x < 585) && (y > 116) && (y < 483))
	{
		switch (estado_juego)
		{
		case Seleccion1:
			origen = getCoord(x, y);
			//comprobar de que se ha seleccionado dentro, si no, break directamente;
			//if(turno%2!=0) estado_juego=Seleccion1://has seleccionado color incorrecto o vacio
			//else dibujo con tablero la casilla seleccionada y movimientos permitidos
			tablero.configurarTablero();
			estado_juego = Seleccion2;
			std::cout << "estoy en seleccion1";
			break;
		case Seleccion2:
			final = getCoord(x, y);
			std::cout << "estoy en seleccion2";
			estado_juego = Seleccion1;
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
	return;//hay q cambiar, dejo aqui para no saltar error
}