#include "Tablero.h"
#include"freeglut.h"
#include<iostream>
#include"ETSIDI.h"

Tablero::~Tablero() {
    for (int i = 0; i < 8; ++i) {
        delete[] casillas1[i];  // delete each row
    }
    delete[] casillas1;          // delete the array of pointers


}

void Tablero::dibuja()
{

    float dim = (float)9 / 8; //6 pq es multiplo de tamaño de ventana

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            float x = j * dim;
            float y = i * dim;
            float cen = dim * 0.25f;

            if (matrizPintarEjecucion[i][j] != 0)
            {
                glColor3f(1, 0,0);
            }
            else if ((i + j) % 2 == 0)
            {
                glColor3f(0, 1, 0);


            }
            else
            {
                glColor3f(0, 0.5, 0);


            }

            glDisable(GL_LIGHTING);
            glBegin(GL_QUADS);
            glVertex2f(x, y);        //0 0
            glVertex2f(x + dim, y);    //1 0
            glVertex2f(x + dim, y + dim);//1 1
            glVertex2f(x, y + dim);    //0 1
            glEnd();
            glEnable(GL_LIGHTING);


            if (matrizPintar[i][j] == 1 || matrizPintar[i][j] == 2 || matrizPintar[i][j] == 3)
            {
                //3d para subirlo y que se vea                       
                glColor3f(0.5f, 0.5f, 0.5f);
                glBegin(GL_QUADS);
                glVertex3f(x + cen, y + cen, 0.01f);
                glVertex3f(x + dim - cen, y + cen, 0.01f);
                glVertex3f(x + dim - cen, y + dim - cen, 0.01f);
                glVertex3f(x + cen, y + dim - cen, 0.01f);
                glEnd();

            }

            casillas1[i][j]->dibuja(x, y);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrizPintar[i][j] = 0;
        }
    }


}

void Tablero::configurarTablero()
{
    casillas1[7][0] = new Torre(Tipo::TORRE, Color::NEGRO);
    casillas1[7][1] = new Caballo(Tipo::CABALLO, Color::NEGRO);
    casillas1[7][2] = new Alfil(Tipo::ALFIL, Color::NEGRO);
    casillas1[7][3] = new Reina(Tipo::REINA, Color::NEGRO);
    casillas1[7][4] = new Rey(Tipo::REY, Color::NEGRO);
    casillas1[7][5] = new Alfil(Tipo::ALFIL, Color::NEGRO);
    casillas1[7][6] = new Caballo(Tipo::CABALLO, Color::NEGRO);
    casillas1[7][7] = new Torre(Tipo::TORRE, Color::NEGRO);
    //////////////////////////////////////////////////////////////////7
    casillas1[0][0] = new Torre(Tipo::TORRE, Color::BLANCO);
    casillas1[0][1] = new Caballo(Tipo::CABALLO, Color::BLANCO);
    casillas1[0][2] = new Alfil(Tipo::ALFIL, Color::BLANCO);
    casillas1[0][3] = new Reina(Tipo::REINA, Color::BLANCO);
    casillas1[0][4] = new Rey(Tipo::REY, Color::BLANCO);
    casillas1[0][5] = new Alfil(Tipo::ALFIL, Color::BLANCO);
    casillas1[0][6] = new Caballo(Tipo::CABALLO, Color::BLANCO);
    casillas1[0][7] = new Torre(Tipo::TORRE, Color::BLANCO);

    //std::vector<Tipo> PIEZAS = { Tipo::TORRE, Tipo::CABALLO, Tipo::ALFIL, Tipo::REINA, Tipo::REY,Tipo::ALFIL,Tipo::CABALLO,Tipo::TORRE };
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            //Casilla casilla(i, j);
            /*
            if (i == 0)
            {
                casillas1[i][j] =  new Torre( Color::NEGRO,casilla,Tipo::TORRE);

            }
            else if (i == 1)
            {

                casillas1[i][j] = new Pieza(Tipo::PEON, Color::NEGRO, casilla);
            }*/
            if (i > 1 && i < 6)
            {
                casillas1[i][j] = new Vacio(Tipo::VACIO, Color::NO_COLOR);
            }
            else if (i == 1)
            {
                casillas1[i][j] = new Peon(Tipo::PEON, Color::BLANCO);

            }
            else if (i == 6)
            {
                casillas1[i][j] = new Peon(Tipo::PEON, Color::NEGRO);
            }/*
            else
            {
                //para invertir
                casillas1[i][j] = new Pieza(PIEZAS[7-j], Color::BLANCO, casilla);
            }*/
        }
    }
    /*
    std::vector<Tipo> PIEZAS = { Tipo::TORRE, Tipo::CABALLO, Tipo::ALFIL, Tipo::REINA, Tipo::REY,Tipo::ALFIL,Tipo::CABALLO,Tipo::TORRE };
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            Casilla casilla(i, j);
            if (i == 0)
            {
                casillas1[i][j] =  new Pieza(PIEZAS[j], NEGRO,casilla);

            }
            else if (i == 1)
            {

                casillas1[i][j] = new Pieza(PEON,NEGRO, casilla);
            }
            else if (i > 1 && i < 6)
            {
                casillas1[i][j] = new Pieza(VACIO, NO_COLOR, casilla);
            }
            else if (i == 6)
            {
                casillas1[i][j] = new Pieza(PEON, BLANCO, casilla);

            }
            else
            {
                //para invertir
                casillas1[i][j] = new Pieza(PIEZAS[7-j], BLANCO, casilla);
            }
        }
    }
    */

}
int Tablero::getColor(const Casilla& casillacolor)
{
    int color;
    std::cout << "comprobando color\n";
    color = casillas1[casillacolor.fila][casillacolor.columna]->getColor();//get color de pieza pq casillas[][]es una pieza
    std::cout << "EL COLOR OBTENIDO ES\n" << color;
    return color;
}
/*
Casilla Tablero::getCasilla(const Casilla & casilla)
{
    Casilla cas;
    cas = casillas1[casilla.fila][casilla.columna]->getCasilla();
    std::cout << "LA FILA CON LA CONCION ES" << cas.fila<<std::endl;
    std::cout << "LA FILA CON LA CONCION ES" << cas.columna<< std::endl;
    return cas;
}*/


void Tablero::moverPiezasyAscenso(Casilla& origen, Casilla & final)
{
    //la filosofia es pedir dato de final y meterselo al original 
    // para ello dos ->
    Tipo miTipo = casillas1[origen.fila][origen.columna]->getTipo();
    Color miColor = casillas1[origen.fila][origen.columna]->getColor();
    //Casilla nuevoCasilla = casillas1[origen.fila][origen.columna]->getCasilla(); //funciona para otro tipo de inicializacion
    /*
    casillas1[final.fila][final.columna]->setTipo(nuevoTipo);
    casillas1[final.fila][final.columna]->setColor(nuevoColor);
    //casillas1[final.fila][final.columna]->setCasilla() //pensaba que pieza tenia 4 atributos, tipo, color, fil, col,
    //pensaba q habria madoficarr i j tambien, pero pensandolo bien creo q no es necesario

    casillas1[origen.fila][origen.columna]->setColor(NO_COLOR);
    casillas1[origen.fila][origen.columna]->setTipo(VACIO);
    */
    delete casillas1[final.fila][final.columna]; // delete 

    // mover objeto, de origen a final£¬final apunta misma direccion que origen  
    casillas1[final.fila][final.columna] = casillas1[origen.fila][origen.columna];

   //crear vacio para origen
    casillas1[origen.fila][origen.columna] = new Vacio(VACIO, NO_COLOR);

    
    if ((final.fila == 7 && miTipo == PEON && miColor == BLANCO) ||
        (final.fila == 0 && miTipo == PEON && miColor == NEGRO))
    {
        delete casillas1[final.fila][final.columna]; // delete pe¨®n
        casillas1[final.fila][final.columna] = new Reina(REINA, miColor); // crear Reina
    }
}
int Tablero::movValido(const Casilla& origen, const Casilla & final)
{

    /*if (encontrarEjecucion(turno) == true && (casillas1[origen.fila][origen.columna]->getColor() != casillas1[final.fila][final.columna]->getColor()) &&
        casillas1[final.fila][final.columna]->getColor() != NO_COLOR)*/

    //{
        for (int i = 0;i < 8;i++)
        {
            for (int j = 0;j < 8;j++)
            {
                movvalido[i][j] = 0;
            }
        }
        casillas1[origen.fila][origen.columna]->miMov(origen, casillas1, movvalido);
        std::cout << "matriz en tablero\n";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                std::cout << movvalido[i][j] << " , ";
                if (j == 7)
                {
                    std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
                }
            }
        }
        if (movvalido[final.fila][final.columna] == 0)
        {
            return 0;//no
        }
        return 1;//si
    //}
    /*
    if (encontrarEjecucion(turno) == false)
    {
        for (int i = 0;i < 8;i++)
        {
            for (int j = 0;j < 8;j++)
            {
                movvalido[i][j] = 0;
            }
        }
        casillas1[origen.fila][origen.columna]->miMov(origen, casillas1, movvalido);
        std::cout << "matriz en tablero\n";
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                std::cout << movvalido[i][j] << " , ";
                if (j == 7)
                {
                    std::cout << "\n"; //Cuando llega al final de la fila hace un salto de linea para imprimir la siguiente fila
                }
            }
        }
        if (movvalido[final.fila][final.columna] == 0)
        {
            return 0;//no
        }
        return 1;//si
    }*/
    return 0; //no
}//prueba
void Tablero::pintaMov(const Casilla& origen)
{
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            matrizPintar[i][j] = 0;
        }
    }
    casillas1[origen.fila][origen.columna]->miMov(origen, casillas1, matrizPintar);
}

int Tablero::endGame() {
    int negro = 0, blanco = 0;
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < 8;j++) {
            if (negro != 0 && blanco != 0) {
                return 0; //nobody win
            }
            if (casillas1[i][j]->getColor() == NEGRO) {
                negro++;
            }
            else if (casillas1[i][j]->getColor() == BLANCO) {
                blanco++;
            }

        }
    }
    if (negro == 0) {
        return 1; // negro win
    }
    else if (blanco == 0) {
        return 2; // white win
    }
}
bool Tablero::encontrarEjecucion(int turno)
{
    int cont = 0;
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            matrizPintarEjecucion[i][j] = 0;
        }
    }
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            if (turno == 0 && casillas1[i][j]->getColor() == BLANCO)
            {
                Casilla miCasilla;
                miCasilla.fila = i;
                miCasilla.columna = j;
                casillas1[i][j]->miMov(miCasilla, casillas1, movvalido);
                for (int x = 0;x < 8;x++)
                {
                    for (int y = 0;y < 8;y++)
                    {
                        if (movvalido[x][y] == 2)
                        {
                            matrizPintarEjecucion[i][j] = 1;
                            cont++;
                        }

                    }

                }
            }
            if (turno == 1 && casillas1[i][j]->getColor() == NEGRO)
            {
                Casilla miCasilla;
                miCasilla.fila = i;
                miCasilla.columna = j;
                casillas1[i][j]->miMov(miCasilla, casillas1, movvalido);
                for (int x = 0;x < 8;x++)
                {
                    for (int y = 0;y < 8;y++)
                    {
                        if (movvalido[x][y] == 2)
                        {
                            matrizPintarEjecucion[i][j] = 1;
                            cont++;
                        }

                    }

                }
            }

        }

    }
    if (cont != 0)
    {
        return true;
    }
    return false;
}
bool Tablero::getTableroEjecucion(Casilla& origen)
{
    if (matrizPintarEjecucion[origen.columna][origen.fila] != 0)
    {
        return true;
    }
    return false;
}