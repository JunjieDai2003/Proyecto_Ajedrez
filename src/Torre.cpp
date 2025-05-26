#include"Torre.h"
#include <math.h>
#include<iostream>

void Torre::dibuja(float x, float y)
{
	float dim = (float)9 / 8;
	float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
	float cen = (dim - dim1) / 2;
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torre_blanco.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torre_negro.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glColor4f(1, 1, 1, 0.9);
	glTexCoord2d(0, 1); glVertex3f(x + cen, y + cen, 0.02f);
	glTexCoord2d(1, 1); glVertex3f(x + cen + dim1, y + cen, 0.02f);
	glTexCoord2d(1, 0); glVertex3f(x + dim1 + cen, y + dim1 + cen, 0.02f);
	glTexCoord2d(0, 0); glVertex3f(x + cen, y + dim1 + cen, 0.02f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void Torre::miMov(const Casilla& origen, Pieza* coordenadas[8][8], int matrix[8][8])
{
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			matrix[i][j] = 0;
		}
	}
	//int matrix[8][8];
	//Bucle que recorre la matriz auxiliar de coordenadas haciendo que todas las casillas inicialmente sean movimientos invalidos o 0s.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (coordenadas[i][j]->getTipo() != VACIO)
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			}
		}
		std::cout << std::endl;
	}
	//Ahora la Matriz auxiliar imprime todo ceros

	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matrix[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
			}
		}
	}

	////BLANCO ARRIBA ABAJO
	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && coordenadas[origen.fila][origen.columna]->getTipo() == TORRE)
	{
		for (int j = origen.columna + 1; j < 8; j++) //Caso 1) Cuando permanecen igual las columnas AVANZO LAS FILAS // TORRE BLANCA que SUBE
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 3; //TORRE BLANCA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 2; //TORRE BLANCA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;

			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}

		for (int j = origen.columna - 1; j >= 0; j--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS FILAS // TORRE BLANCA QUE BAJA
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 3; //TORRE BLANCA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 2; //TORRE BLANCA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;
			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}
	}


	//NEGRO ARRIBA ABAJO
	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && coordenadas[origen.fila][origen.columna]->getTipo() == TORRE)
	{
		for (int j = origen.columna + 1; j < 8; j++) //Caso 1) Cuando permanecen igual las columnas AVANZO LAS FILAS // TORRE BLANCA que SUBE
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 2; //TORRE NEGRA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 3; //TORRE NEGRA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;

			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}

		for (int j = origen.columna - 1; j >= 0; j--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS FILAS // TORRE BLANCA QUE BAJA
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 2; //TORRE NEGRA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 3; //TORRE NEGRA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;
			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}
	}







	//BLANCO DERECHA IZQUIERDA

	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && coordenadas[origen.fila][origen.columna]->getTipo() == TORRE)
	{
		for (int i = origen.fila + 1; i < 8; i++) //Caso 1) Cuando permanecen igual las filas AVANZO LAS COLUMNAS // TORRE BLANCA DERECHA
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 3; //TORRE BLANCA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 2; //TORRE BLANCA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;

			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}

		for (int i = origen.fila - 1; i >= 0; i--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS COLUMNAS // TORRE BLANCA IZQUIERDA
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 3; //TORRE BLANCA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 2; //TORRE BLANCA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;
			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; //TORRE BLANCA puede MOVER
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}
	}


	//NEGRO DERECHA IZQUIERDA 

	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && coordenadas[origen.fila][origen.columna]->getTipo() == TORRE)
	{
		for (int i = origen.fila + 1; i < 8; i++) //Caso 1) Cuando permanecen igual las filas AVANZO LAS COLUMNAS // TORRE NEGRA DERECHA
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 2; //TORRE NEGRA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 3; //TORRE NEGRA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;

			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; //TORRE NEGRA puede MOVER
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}

		for (int i = origen.fila - 1; i >= 0; i--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS COLUMNAS // TORRE NEGRA IZQUIERDA
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 2; //TORRE NEGRA COME algo BLANCO
				std::cout << "La Torre puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 3; //TORRE NEGRA COME algo NEGRO
				std::cout << "La Torre puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;
			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; //TORRE NEGRA puede MOVER
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}
	}

	return;
}