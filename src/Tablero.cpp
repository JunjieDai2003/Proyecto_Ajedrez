#include "tablero.h"
#include"freeglut.h"
#include<iostream>
Tablero::Tablero()
{
	fila = 8;
	colu = 8;
}
Tablero::~Tablero()
{
}
void Tablero::dibuja(int fil, int col)
{

	float tam = (float)1.0 / fila; // Tamano de cada casilla
	std::cout << "estoy jugando\n";
	gluLookAt(0.0, 0.0, 5,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < colu; j++)
		{

			if ((i + j) % 2 == 0)
				glColor3f(0.0f, 0.0f, 0.0f); //negro no utilizaremos estos colores, 0 ,0.5 ,0 verde oscuro
			else
				glColor3f(1.0f, 1.0f, 1.0f); //blanco 0.5 1.0 0.5 verde claro
			if (i == fil && col == j)
			{
				glColor3f(1.0f, 0.5f, 1.0f);
				glBegin(GL_QUADS);
				glVertex2f(-1.0f + j * 2 * tam, 1.0f - i * 2 * tam);             glVertex2f(-1.0f + (j + 1) * 2 * tam, 1.0f - i * 2 * tam);
				glVertex2f(-1.0f + (j + 1) * 2 * tam, 1.0f - (i + 1) * 2 * tam); glVertex2f(-1.0f + j * 2 * tam, 1.0f - (i + 1) * 2 * tam);
				glEnd();
			}
			else
			{
				// Dibujar la casilla
				glBegin(GL_QUADS);
				glVertex2f(-1.0f + j * 2 * tam, 1.0f - i * 2 * tam);             glVertex2f(-1.0f + (j + 1) * 2 * tam, 1.0f - i * 2 * tam);
				glVertex2f(-1.0f + (j + 1) * 2 * tam, 1.0f - (i + 1) * 2 * tam); glVertex2f(-1.0f + j * 2 * tam, 1.0f - (i + 1) * 2 * tam);
				glEnd();
			}

		}
	}
}
