#include "Tablero.h"
#include"freeglut.h"
#include<iostream>
#include"ETSIDI.h"
void Tablero::dibuja()
{

    float dim = (float)6 / 8; //6 pq es multiplo de tamano de ventana
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            if (ejecucion[i][j] == 1)
            {
                glColor3f(1,0,0);
            }
            else if (movvalido[i][j] == 1)
            {
                glColor3f(0, 1, 0);
            }
            else if ((i + j) % 2 == 0)
            {
                glColor3f(1, 1, 1);
            }
            else
            {
                glColor3f(0, 0, 0);
            }
            float x = j*dim;
            float y = i*dim;
            glBegin(GL_QUADS);
            glVertex2f(x,y);        //0 0
            glVertex2f(x+dim,y);    //1 0
            glVertex2f(x+dim,y+dim);//1 1
            glVertex2f(x,y+dim);    //0 1
            glEnd();
            
            if (j == 3)
            {
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peon_blanco.png").id);
                glDisable(GL_LIGHTING);
                glBegin(GL_POLYGON);
                glColor3f(1, 1, 1);
                glTexCoord2d(0, 1); glVertex3f(x, y,0.5);
                glTexCoord2d(1, 1); glVertex3f(x + dim, y,0.5);
                glTexCoord2d(1, 0); glVertex3f(x + dim, y + dim, 0.5);
                glTexCoord2d(0, 0); glVertex3f(x, y + dim, 0.5);
                glEnd();
                glEnable(GL_LIGHTING);
                glDisable(GL_TEXTURE_2D);
            }
        }
    }

}