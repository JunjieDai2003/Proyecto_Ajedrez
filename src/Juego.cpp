#include "Juego.h"
#include <iostream>

void Juego::dibuja()
{
	//colocamos un fondo con etsidi.h
	tablero.dibuja();
}
Casilla Juego::getCoord(int x, int y)
{
	Casilla casilla;
	casilla.columna = (x - 330) / 41.25;
	casilla.fila = (y - 330) / 41.25;
	std::cout << "estoy clickeando " << casilla.columna << " y " << casilla.fila << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
	return casilla;
}
void Juego::ratonjuego(int button, int state, int x, int y)
{
	//dejo la funcion lamda pq MH lo menciono una vez en clase y lo investigue y me parecio interesante, en teoria funciona igual q getCoord que tengo arriba
	//una funcion lammba getCoord que convierte el x y en atributos de la clase Casilla definida posteriomente
	/*
	auto getCoord = [](int x, int y)->Casilla //Declararemos amistad para que juego pueda usar los atributos privados
		{

			Casilla casilla;
			casilla.columna = (x - 330) / 41.25;
			casilla.fila = (y - 330) / 41.25;
			std::cout << "estoy clickeando " << casilla.columna << " y " << casilla.fila << std::endl;//queria poner esta fila para ver si x y estan bien pero no imprime, tengo que preguntar como funciona lamda
			return casilla;//no se si es paso por valor o paso por referencia

		};*/

	if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		//conseguir las coordenadas
		std::cout << "Posicion de raton es" << x << "," << y;
	
		//pondremos abajo las comproaciones de que si la casilla seleccionada es correcta o no
		if (origen.fila == 100 && origen.columna == 100)//primera seleccion
		{
			origen = getCoord(x, y);//selecciono una pieza
			//si la pieza es seleccionada de otro color
			/*
			if(ejecucion obligatoria==true)
			{
			 //comprobar que la casilla seleccionada se puede ejecutar
			 if casilla seleccionada se puede ejecutar continuar
			 else  fila=col=100 return;
			}
			if (!turno ) 
			{
				std::cout << "no es tu turno pq has seleccionado un color";
				std::cout << "no correcto o vacio";
				fila=col=100; //reseteo la condicion
				return;
			}
			else 
			{
			dibujo con tablero la casilla seleccionada y movimientos permitidos
			
			}
			*/
		}
		else if (origen.fila != 100 && origen.columna !=100 && final.fila == 100 &&final.columna ==100)
		{
			//si he seleccionado bien la primera casilla
			//y toca seleccionar la segunda casilla
			final = getCoord(x, y);
		}

		
		
	}
	return ;//hay q cambiar, dejo aqui para no saltar error
}