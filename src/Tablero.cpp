#include "Tablero.h"
#include"freeglut.h"
#include<iostream>
#include"ETSIDI.h"
// destructor de tablero, lo llamaremos cuando termina el juego

Tablero::~Tablero() {
    for (int i = 0; i < 8; ++i) {
        delete[] casillas1[i];  // delete each row
    }
    delete[] casillas1;          // delete the array of pointers
}
void Tablero::destruir()
{
    delete casillas1;
}
/*
Tablero::~Tablero() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
        {
            delete[] casillas1[i][j];  // delete each row
        }
        delete[] casillas1[i];  // delete each row
    }
    delete[] casillas1;          // delete the array of pointers


}*/


//funcion para dibujar el tablero con los pasos, casilla roja de ejecucion
//tambien llama a la funcion dibuja de la pieza
void Tablero::dibuja()
{

    float dim = (float)9 / 8; //divisor pq es multiplo de tamaño de ventana 600

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            float x = j * dim;
            float y = i * dim;
            float cen = dim * 0.25f;

            if (matrizPintarEjecucion[i][j] != 0)
            {
                glColor3f(1, 0,0); //si hay ejecucion rojo
            }
            else if ((i + j) % 2 == 0)
            {
                glColor3f(0, 1, 0); //Verde


            }
            else
            {
                glColor3f(0, 0.5, 0); //verde claro


            }

            glDisable(GL_LIGHTING);
            glBegin(GL_QUADS);
            glVertex2f(x, y);        //0 0
            glVertex2f(x + dim, y);    //1 0
            glVertex2f(x + dim, y + dim);//1 1
            glVertex2f(x, y + dim);    //0 1
            glEnd();
            glEnable(GL_LIGHTING);


            if (matrizPintar[i][j] == 1 || matrizPintar[i][j] == 2 || matrizPintar[i][j] == 3) //si se puede avanzar, dibujar camino
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

            casillas1[i][j]->dibuja(x, y); //dibujar pieza en la posicion de la casilla
        }
    }
    //resetamos la matriz pintar 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrizPintar[i][j] = 0;
        }
    }


}
//Crear el objeto
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
 
    
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
           
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
            }
         
        }
    }
}
//funcion para ver el atributo privado de la pieza atraves de getColor de Pieza
int Tablero::getColor(const Casilla& casillacolor)
{
    int color;
    std::cout << "comprobando color\n";
    color = casillas1[casillacolor.fila][casillacolor.columna]->getColor();//get color de pieza pq casillas[][]es una pieza
    std::cout << "EL COLOR OBTENIDO ES\n" << color;
    return color;
}
void Tablero::moverPiezasyAscenso(Casilla& origen, Casilla & final)
{
    //la filosofia es pedir dato de final y meterselo al original 
    // para ello dos ->
    Tipo miTipo = casillas1[origen.fila][origen.columna]->getTipo();
    Color miColor = casillas1[origen.fila][origen.columna]->getColor();
 
    delete casillas1[final.fila][final.columna]; // delete 

    // mover objeto, de origen a final£¬final apunta misma direccion que origen  
    casillas1[final.fila][final.columna] = casillas1[origen.fila][origen.columna];

   //crear vacio para origen
    casillas1[origen.fila][origen.columna] = new Vacio(VACIO, NO_COLOR);

    //Convertir por en reina
    if ((final.fila == 7 && miTipo == PEON && miColor == BLANCO) ||
        (final.fila == 0 && miTipo == PEON && miColor == NEGRO))
    {
        delete casillas1[final.fila][final.columna]; // delete pe¨®n
        casillas1[final.fila][final.columna] = new Reina(REINA, miColor); // crear Reina
    }
}
//una funcion que retorna 0 cuando es un movimiento invalido y 1 cuando es valido
int Tablero::movValido(const Casilla& origen, const Casilla & final)
{
    //si hay ejecucion y el origen y final es de distinto color sin ser el final un vacio
    if ((encontrarEjecucion(turno) == true && (casillas1[origen.fila][origen.columna]->getColor() != casillas1[final.fila][final.columna]->getColor()) &&
        casillas1[final.fila][final.columna]->getColor() != NO_COLOR)||encontrarEjecucion(turno)==false)

    {
        //researamos matriz de mov valido"en teoria no es necesario pq miMov ya lo hace, lo dejamos por si alguna pieza no lo resetea
        for (int i = 0;i < 8;i++)
        {
            for (int j = 0;j < 8;j++)
            {
                movvalido[i][j] = 0;
            }
        }
        // generar matriz de movimiento
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
        //verificacion 
        if (movvalido[final.fila][final.columna] == 0)
        {
            return 0;//no
        }
        return 1;//si
    }
    return 0; //no
}
//funcion para rellenar la matriz de movimiento
void Tablero::pintaMov(const Casilla& origen)
{
    //reseteamos a 0
    for (int i = 0;i < 8;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            matrizPintar[i][j] = 0;
        }
    }
    //rellenar con la funcion miMov de la pieza
    casillas1[origen.fila][origen.columna]->miMov(origen, casillas1, matrizPintar);
}
//condicion de finn de juego
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
    return 0;
}
//funcion para encontrar si hay una ejecicion obligatoria
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
            //analizar fichas blancas en turno de los blancos
            if (turno == 0 && casillas1[i][j]->getColor() == BLANCO)
            {
                Casilla miCasilla;
                miCasilla.fila = i;
                miCasilla.columna = j;
                //relleno la matriz de movimiento de cada ficha
                casillas1[i][j]->miMov(miCasilla, casillas1, movvalido);
                for (int x = 0;x < 8;x++)
                {
                    for (int y = 0;y < 8;y++)
                    {
                        if (movvalido[x][y] == 2)
                        {
                            //si en la matriz hay un 1, significa que hay ejecucion obligatoria, el contador no retorna 0
                            //guardamos la posicion de la pieza con ejecucion 
                            matrizPintarEjecucion[i][j] = 1;
                            cont++;
                        }

                    }

                }
            }
            //misma filosofia que la pieza blanca
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
// avisa a juego que hay ejecucion 
bool Tablero::getTableroEjecucion(Casilla& origen)
{
    if (matrizPintarEjecucion[origen.fila][origen.columna] != 0)
    {
        return true;
    }
    return false;
}
