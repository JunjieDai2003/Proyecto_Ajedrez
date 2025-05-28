#include "Reina.h"
#include <iostream>
Reina::~Reina()
{
	std::cout << "Reina destruida\n";
}
void Reina::miMov(const Casilla& origen, Pieza* coordenadas[8][8], int matrix[8][8]) 
{
	std::cout << "Soy una REINA\n";
	std::cout << "COMPRUEBO REINA \n";

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


	//MOVIMIENTO RELACIONADO CON ALFIL

	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && (coordenadas[origen.fila][origen.columna]->getTipo() == REINA))
	{

		//CASO 1) DERECHA/ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna + 1) <= 7))
		{
			int i = origen.fila + 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA BLANCA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA BLANCA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA BLANCA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA BLANCA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA BLANCA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA BLANCA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA BLANCA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA BLANCA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA BLANCA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA BLANCA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA BLANCA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA BLANCA puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i--;
				j--;

			} while ((i >= 0) && (j >= 0));
		}
	}




	//HAGO LO MISMO CON EL COLOR NEGRO




	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && (coordenadas[origen.fila][origen.columna]->getTipo() == REINA))
	{

		//CASO 1) DERECHA/ARRIBA
		if (((origen.fila + 1) <= 7) && ((origen.columna + 1) <= 7))
		{
			int i = origen.fila + 1;
			int j = origen.columna + 1;
			do
			{
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA NEGRA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA NEGRA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA NEGRA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA NEGRA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA NEGRA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA NEGRA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA NEGRA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA NEGRA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA NEGRA puede moverse a casilla" << "[" << i << "," << j << "] \n";
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
				if ((coordenadas[i][j]->getColor() == BLANCO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 2;
					std::cout << "La REINA NEGRA puede comer Pieza BLANCA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getColor() == NEGRO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 3;
					std::cout << "La REINA NEGRA puede comer pieza NEGRA en casilla" << "[" << i << "," << j << "] \n";
					break;
				}
				else if ((coordenadas[i][j]->getTipo() == VACIO) && ((abs(i - origen.fila)) == (abs(j - origen.columna))))
				{
					matrix[i][j] = 1;
					std::cout << "La REINA NEGRA puede moverse a casilla" << "[" << i << "," << j << "] \n";
				}
				i--;
				j--;

			} while ((i >= 0) && (j >= 0));
		}
	}


	//EMPIEZA COMPORTAMIENTO TORRE

	////BLANCO ARRIBA ABAJO
	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && coordenadas[origen.fila][origen.columna]->getTipo() == REINA)
	{
		for (int j = origen.columna + 1; j < 8; j++) //Caso 1) Cuando permanecen igual las columnas AVANZO LAS FILAS // TORRE BLANCA que SUBE
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 3; 
				std::cout << "La REINA BLANCA puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 2; 
				std::cout << "La REINA BLANCA puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;

			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; 
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}

		for (int j = origen.columna - 1; j >= 0; j--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS FILAS // 
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 3; 
				std::cout << "La REINA BLANCA puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 2; 
				std::cout << "La REINA BLANCA puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;
			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; 
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}
	}


	//NEGRO ARRIBA ABAJO
	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && coordenadas[origen.fila][origen.columna]->getTipo() == REINA)
	{
		for (int j = origen.columna + 1; j < 8; j++) //Caso 1) Cuando permanecen igual las columnas AVANZO LAS FILAS 
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 2;
				std::cout << "La REINA NEGRA puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 3; 
				std::cout << "La REINA NEGRA puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;

			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; 
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}

		for (int j = origen.columna - 1; j >= 0; j--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS FILAS // TORRE BLANCA QUE BAJA
		{
			if (coordenadas[origen.fila][j]->getColor() == BLANCO)
			{
				matrix[origen.fila][j] = 2; 
				std::cout << "La REINA NEGRA puede comer Pieza blanca en casilla" << "[" << origen.fila << "," << j << "] \n";
				break; 
			}
			else if (coordenadas[origen.fila][j]->getColor() == NEGRO)
			{
				matrix[origen.fila][j] = 3; 
				std::cout << "La REINA NEGRA puede comer Pieza negra en casilla" << "[" << origen.fila << "," << j << "] \n";
				break;
			}
			else if (coordenadas[origen.fila][j]->getTipo() == VACIO)
			{
				matrix[origen.fila][j] = 1; 
				std::cout << "La casilla" << "[" << origen.fila << "," << j << "]" << "esta vacia \n";
			}
		}
	}







	//BLANCO DERECHA IZQUIERDA

	if ((coordenadas[origen.fila][origen.columna]->getColor() == BLANCO) && coordenadas[origen.fila][origen.columna]->getTipo() == REINA)
	{
		for (int i = origen.fila + 1; i < 8; i++) //Caso 1) Cuando permanecen igual las filas AVANZO LAS COLUMNAS 
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 3; 
				std::cout << "La REINA BLANCA puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; //Break para salir del bucle ya que si encuentra algo en el camino y que el resto permanezca 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 2; 
				std::cout << "La REINA BLANCA puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;

			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; 
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}

		for (int i = origen.fila - 1; i >= 0; i--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS COLUMNAS 
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 3; 
				std::cout << "La REINA BLANCA puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 2; 
				std::cout << "La REINA BLANCA puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;
			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1;
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}
	}


	//NEGRO DERECHA IZQUIERDA 

	if ((coordenadas[origen.fila][origen.columna]->getColor() == NEGRO) && coordenadas[origen.fila][origen.columna]->getTipo() == REINA)
	{
		for (int i = origen.fila + 1; i < 8; i++) //Caso 1) Cuando permanecen igual las filas AVANZO LAS COLUMNAS 
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 2; 
				std::cout << "La REINA NEGRA puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break; 
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 3; 
				std::cout << "La REINA NEGRA puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;

			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; 
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}

		for (int i = origen.fila - 1; i >= 0; i--) //Caso 2) Cuando permanecen igual las columnas REDUZCO LAS COLUMNAS 
		{
			if (coordenadas[i][origen.columna]->getColor() == BLANCO)
			{
				matrix[i][origen.columna] = 2; 
				std::cout << "La REINA NEGRA puede comer Pieza blanca en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;
			}
			else if (coordenadas[i][origen.columna]->getColor() == NEGRO)
			{
				matrix[i][origen.columna] = 3;
				std::cout << "La REINA NEGRA puede comer Pieza negra en casilla" << "[" << i << "," << origen.columna << "] \n";
				break;
			}
			else if (coordenadas[i][origen.columna]->getTipo() == VACIO)
			{
				matrix[i][origen.columna] = 1; 
				std::cout << "La casilla" << "[" << i << "," << origen.columna << "]" << "esta vacia \n";
			}
		}
	}

	std::cout << "IMPRIMO MATRIZ: \n";
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
}

void Reina::dibuja(float x, float y)
{
    float dim = (float)9 / 8;
    float dim1 = (float)4.5 / 8;
    float cen = (dim - dim1) / 2;
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (color == BLANCO)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reina_blanca.png").id);
    else
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reina_negra.png").id);

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glColor4f(1, 1, 1, 0.9);
    glTexCoord2d(0, 1); glVertex3f(x + cen, y + cen, 0.02f);
    glTexCoord2d(1, 1); glVertex3f(x + cen + dim1, y + cen, 0.02f);
    glTexCoord2d(1, 0); glVertex3f(x + cen + dim1, y + cen + dim1, 0.02f);
    glTexCoord2d(0, 0); glVertex3f(x + cen, y + cen + dim1, 0.02f);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
