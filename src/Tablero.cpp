#include "Tablero.h"
#include"freeglut.h"
#include<iostream>
#include"ETSIDI.h"

void Tablero::dibuja()
{
    //qwq
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
            Casilla casilla(i, j);
            if (i == 0)
            {
                casillas1[i][j] =  new Pieza(PIEZAS[j], Color::NEGRO,casilla);
               
            }
            else if (i == 1)
            {
                
                casillas1[i][j] = new Pieza(Tipo::PEON, Color::NEGRO, casilla);
            }
            else if (i > 1 && i < 6)
            {
                casillas1[i][j] = new Pieza(Tipo::VACIO, Color::NO_COLOR, casilla);
            }
            else if (i == 6)
            {
                casillas1[i][j] = new Pieza(Tipo::PEON, Color::BLANCO, casilla);
                
            }
            else
            {
                //para invertir
                casillas1[i][j] = new Pieza(PIEZAS[7-j], Color::BLANCO, casilla);
            }
        }
    }

}
int Tablero::getColor(const Casilla& casillacolor)
{
    int color;
    std::cout << "comprobando color\n";
    color=casillas1[casillacolor.fila][casillacolor.columna]->getColor();//get color de pieza pq casillas[][]es una pieza
    std::cout <<"EL COLOR OBTENIDO ES\n" << color;
    return color;
}
Casilla Tablero::getCasilla(const Casilla & casilla)
{
    Casilla cas;
    cas = casillas1[casilla.fila][casilla.columna]->getCasilla();
    std::cout << "LA FILA CON LA CONCION ES" << cas.fila<<std::endl;
    std::cout << "LA FILA CON LA CONCION ES" << cas.columna<< std::endl;
    return cas;
}


void Tablero::moverPiezasyAscenso(Casilla& origen, Casilla & final)
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
int Tablero::movValido(const Casilla&origen,const Casilla&final)
{
    //if(ejecucion==1 && (casillas->getColor!=casillas->getColor)
    //return 0;
    //salir de funcion directamente si hay una ejecucion pero no ejecutamos
    Tipo pieza;
    pieza = (casillas1[origen.fila][origen.columna])->getTipo();
    switch (pieza)
    {
    case PEON:
        //mov matriz=Peon::comprobacionmov(origen,const &matriz);
        //if
        return 0;
    }
    return 1;
}