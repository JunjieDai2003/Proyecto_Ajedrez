#include "Rey.h"
#include <iostream>
Rey::~Rey()
{
    std::cout << "Rey destruida\n";
}
void Rey::miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]) {
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            matMov[i][j] = 0;
        }
    }
    int fila = origen.fila;
    int col = origen.columna;
    int color = casilla[fila][col]->getColor();

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int f = fila + i;
            int c = col + j;

            if (f >= 0 && f < 8 && c >= 0 && c < 8) {
                Pieza* p = casilla[f][c];
                if (p->getTipo() == VACIO) {
                    matMov[f][c] = 1; // Movimiento v¨¢lido
                    std::cout << "Rey puede moverse a [" << f << "," << c << "]\n";
                }
                else if (p->getColor() != color) {
                    matMov[f][c] = 2; // Puede capturar
                    std::cout << "Rey puede comer en [" << f << "," << c << "]\n";
                }
                else {
                    matMov[f][c] = 3; // Aliado (bloqueo)
                    std::cout << "Casilla bloqueada por aliado [" << f << "," << c << "]\n";
                }
            }
        }
    }

    return;
}

void Rey::dibuja(float x, float y)
{
    float dim = (float)9 / 8;
    float dim1 = (float)4.5 / 8;
    float cen = (dim - dim1) / 2;
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (color == BLANCO)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey_blanco.png").id);
    else
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/rey_negro.png").id);

    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glColor4f(1, 1, 1, 0.9);
    glTexCoord2d(0, 1); glVertex3f(x + cen, y + cen, 0.02);
    glTexCoord2d(1, 1); glVertex3f(x + cen + dim1, y + cen, 0.02f);
    glTexCoord2d(1, 0); glVertex3f(x + dim1 + cen, y + dim1 + cen, 0.02f);
    glTexCoord2d(0, 0); glVertex3f(x + cen, y + dim1 + cen, 0.02f);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
