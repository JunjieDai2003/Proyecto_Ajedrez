#include"Caballo.h"
#include<iostream>

void Caballo::miMov(const Casilla& origen,  Pieza* casilla[8][8], int matMov[8][8]) {
    
	//Bucle que recorre la matriz auxiliar de coordenadas haciendo que todas las casillas inicialmente sean movimientos invalidos o 0s.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (casilla[i][j]->getTipo() != VACIO)
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
			std::cout << matMov[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
			}
		}
	}

	//Matriz que representa el mov en L 

	int mov[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

	//MOV. BLANCAS

	if (tipo == CABALLO && color == BLANCO)
	{
		for (int k = 0; k < 8; ++k)
		{
			int i = origen.fila + mov[k][0];
			int j = origen.columna + mov[k][1];

			if (i >= 0 && i < 8 && j >= 0 && j < 8)
			{
				//Avanza si la casilla est?vacía
				if (casilla[i][j]->getTipo() == VACIO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 1\n";
					matMov[i][j] = 1;
				}

				//Avanza si la casilla tiene caballo del mismo color
				if (casilla[i][j]->getColor() == BLANCO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 3\n";
					matMov[i][j] = 3;
				}

				//Avanza si la casilla tiene caballo de distinto color
				if (casilla[i][j]->getColor() == NEGRO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 2\n";
					matMov[i][j] = 2;
				}
			}
		}
	}

	//MOV. NEGRAS

	if (tipo == CABALLO && color == NEGRO)
	{
		for (int k = 0; k < 8; ++k)
		{
			int i = origen.fila + mov[k][0];
			int j = origen.columna + mov[k][1];

			if (i >= 0 && i < 8 && j >= 0 && j < 8)
			{
				// Avanza si la casilla est?vacía o contiene una pieza enemiga
				if (casilla[i][j]->getTipo() == VACIO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 1\n";
					matMov[i][j] = 1;
				}

				//Avanza si la casilla tiene caballo del mismo color
				if (casilla[i][j]->getColor() == NEGRO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 3\n";
					matMov[i][j] = 3;
				}

				//Avanza si la casilla tiene caballo de distinto color
				if (casilla[i][j]->getColor() == BLANCO)
				{
					std::cout << "El caballo puede desplazarse a la casilla [" << i << "," << j << "] Que toma el valor de matriz auxiliar: 2\n";
					matMov[i][j] = 2;
				}
			}
		}
	}

	//Una vez recorridos los IFs la Matriz Auxiliar (que hemos inicializado en cero con el primer bucle) tendra unos doses y treses; 
	//Imprimimos para ver que queda;
	//Bucle comprobación (Solo imprime la matriz)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << matMov[i][j] << " , ";
			if (j == 7)
			{
				std::cout << "\n";
			}
		}
	}

    return;
}
void Caballo::dibuja(float x, float y)
{
	float dim = (float)9 / 8;
	float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
	float cen = (dim - dim1) / 2;
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo_blanco.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo_negro.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glColor4f(1, 1, 1, 0.9);
	glTexCoord2d(0, 1); glVertex3f(x + cen, y + cen, 0.01);
	glTexCoord2d(1, 1); glVertex3f(x + cen + dim1, y + cen, 0.01);
	glTexCoord2d(1, 0); glVertex3f(x + dim1 + cen, y + dim1 + cen, 0.01);
	glTexCoord2d(0, 0); glVertex3f(x + cen, y + dim1 + cen, 0.01);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
