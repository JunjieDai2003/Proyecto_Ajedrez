#include "Tablero.h"
#include"freeglut.h"
#include<iostream>
#include"ETSIDI.h"

void Tablero::dibuja()
{

    float dim = (float)9 / 8; //6 pq es multiplo de tamano de ventana
    float dim1 = (float)4.5 / 8; //6 pq es multiplo de tamano de ventana
    float cen = (dim - dim1) / 2;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            /* if (ejecucion[i][j] == 1)
             {
                 glColor3f(1,0,0);
             }
             else if (movvalido[i][j] == 1)
             {
                 glColor3f(0, 1, 0);
             }
             else */if ((i + j) % 2 == 0)
             {
                 glColor3f(0, 1, 0);
             }
             else
             {
                 glColor3f(0, 0.5, 0);
             }
             float x = j * dim;
             float y = i * dim;

             glBegin(GL_QUADS);
             glVertex2f(x, y);        //0 0
             glVertex2f(x + dim, y);    //1 0
             glVertex2f(x + dim, y + dim);//1 1
             glVertex2f(x, y + dim);    //0 1
             glEnd();
             glEnable(GL_LIGHTING);
             casillas1[i][j]->dibuja(x, y);
             //casillas1[i][j]->getTipo();
        }
    }

}

void Tablero::configurarTablero()
{
    std::vector<Tipo> PIEZAS = { Tipo::TORRE, Tipo::CABALLO, Tipo::ALFIL, Tipo::REINA, Tipo::REY,Tipo::ALFIL,Tipo::CABALLO,Tipo::TORRE };
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (i == 0)
            {
                casillas1[i][j] = new Pieza(Tipo::PEON, Color::NEGRO, i, j);
            }
            else if (i == 1)
            {
                //casillas1[i][j] = new Pieza(casilla, PIEZAS[j], Color::NEGRO); //otra forma de inicializacion pero tiene error
                casillas1[i][j] = new Pieza(PIEZAS[j], Color::NEGRO, i, j);
            }
            else if (i > 1 && i < 6)
            {
                casillas1[i][j] = new Pieza(Tipo::VACIO, Color::NO_COLOR, i, j);
            }
            else if (i == 6)
            {
                casillas1[i][j] = new Pieza(PIEZAS[j], Color::BLANCO, i, j);
            }
            else
            {
                casillas1[i][j] = new Pieza(Tipo::PEON, Color::BLANCO, i, j);
            }
        }
    }

}
int Tablero::getColor(Casilla& casillacolor)
{
    int color;
    std::cout << "comprobando color";
    color=casillas1[casillacolor.fila][casillacolor.columna]->getColor();//get color de pieza pq casillas[][]es una pieza
    std::cout <<"EL COLOR OBTENIDO ES" << color;
    return color;
}
void Tablero::moverPiezas(Casilla& origen, Casilla & final)
{
    //la filosofia es pedir dato de final y meterselo al original 
    // para ello dos ->
    Tipo nuevoTipo = casillas1[origen.fila][origen.columna]->getTipo();
    Color nuevoColor = casillas1[origen.fila][origen.columna]->getColor();
    //Casilla nuevoCasilla = casillas1[origen.fila][origen.columna]->getCasilla(); //funciona para otro tipo de inicializacion
    casillas1[final.fila][final.columna]->setTipo(nuevoTipo);
    casillas1[final.fila][final.columna]->setColor(nuevoColor);
    //casillas1[final.fila][final.columna]->setCasilla() //pensaba que pieza tenia 4 atributos, tipo, color, fil, col,
    //pensaba q habria madoficarr i j tambien, pero pensandolo bien creo q no es necesario

    casillas1[origen.fila][origen.columna]->setColor(NO_COLOR);
    casillas1[origen.fila][origen.columna]->setTipo(VACIO);

}