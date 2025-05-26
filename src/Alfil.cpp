#include"Alfil.h"
#include<iostream>

void Alfil::miMov(const Casilla& origen, Pieza* coordenadas[8][8], int matrix[8][8]) {
	std::cout << "soy alfil\n";
	std::cout << "COMPRUEBO ALFIL \n";
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			matrix[i][j] = 0;
		}
	}

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

	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && (coordenadas[origen.fila][origen.columna]->getTipo() == ALFIL))
	{

		//CASO 1) DERECHA/ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna + 1) <= 7))
		{
			int i = origen.fila + 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL BLANCO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL BLANCO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL BLANCO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}

				i++;
				j++;

			} while ((i <= 7) && (j <= 7));
		}


		//CASO 2) DERECHA ABAJO
		if (((origen.fila - 1) >= 0) && ((origen.columna + 1) <= 7))
		{
			int i = origen.fila - 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL BLANCO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL BLANCO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL BLANCO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i--;
				j++;

			} while ((i >= 0) && (j <= 7));
		}


		//CASO 3) IZQUIERDA ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna - 1) >= 0))
		{
			int i = origen.fila + 1;
			int j = origen.columna - 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL BLANCO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL BLANCO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL BLANCO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i++;
				j--;
			} while ((i <= 7) && (j >= 0));

		}


		//CASO 4) IZQUIERDA ABAJO
		if (((origen.fila - 1) >= 0) && ((origen.columna - 1) >= 0))
		{
			int i = origen.fila - 1;
			int j = origen.columna - 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL BLANCO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL BLANCO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL BLANCO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i--;
				j--;

			} while ((i >= 0) && (j >= 0));
		}
	}




	//HAGO LO MISMO CON EL COLOR NEGRO





	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && (coordenadas[origen.fila][origen.columna]->getTipo() == ALFIL))
	{
		//CASO 1) DERECHA/ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna) <= 7))
		{
			int i = origen.fila + 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL NEGRO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL NEGRO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL NEGRO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}

				i++;
				j++;

			} while ((i <= 7) && (j <= 7));
		}

		//CASO 2) DERECHA ABAJO
		if (((origen.fila - 1) >= 0) && ((origen.columna + 1) <= 7))
		{
			int i = origen.fila - 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL NEGRO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL NEGRO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL NEGRO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i--;
				j++;

			} while ((i <= 7) && (i >= 0));
		}

		//CASO 3) IZQUIERDA ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna - 1) >= 0))
		{
			int i = origen.fila + 1;
			int j = origen.columna - 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL NEGRO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL NEGRO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL NEGRO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}

				i++;
				j--;
			} while ((i <= 7) && (j >= 0));
		}

		//CASO 4) IZQUIERDA ABAJO
		if (((origen.fila - 1) >= 0) && ((origen.columna - 1) >= 0))
		{
			int i = origen.fila - 1;
			int j = origen.columna - 1;
			do
			{
				if ((coordenadas[i][j]->getTipo() == VACIO))
				{
					matrix[i][j] = 1;
					std::cout << "El ALFIL NEGRO puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO))
				{
					matrix[i][j] = 3;
					std::cout << "El ALFIL NEGRO puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == BLANCO))
				{
					matrix[i][j] = 2;
					std::cout << "El ALFIL NEGRO puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}

				i--;
				j--;
			} while ((i >= 0) && (j >= 0));
		}

	}

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

	return;

	return;
}

void Alfil::dibuja(float x, float y)
{
	float dim = (float)9 / 8;
	float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
	float cen = (dim - dim1) / 2;
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfil_blanco.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfinal_negro.png").id);
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


