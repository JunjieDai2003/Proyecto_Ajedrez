#include "Reina.h"
#include <iostream>

void Reina::miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]) {
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

    // 8 direcciones: ¡ü ¡ý ¡û ¡ú ¨I ¨J ¨L ¨K
    const int dirs[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (int d = 0; d < 8; ++d) {
        int df = dirs[d][0];
        int dc = dirs[d][1];
        int f = fila + df;
        int c = col + dc;

        while (f >= 0 && f < 8 && c >= 0 && c < 8) {
            Pieza* p = casilla[f][c];
            if (p->getTipo() == VACIO) {
                matMov[f][c] = 1;
                std::cout << "Reina puede moverse a [" << f << "," << c << "]\n";
            }
            else if (p->getColor() != color) {
                matMov[f][c] = 2;
                std::cout << "Reina puede capturar en [" << f << "," << c << "]\n";
                break;
            }
            else {
                matMov[f][c] = 3;
                std::cout << "Reina bloqueada por aliado en [" << f << "," << c << "]\n";
                break;
            }
            f += df;
            c += dc;
        }
    }
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
