#pragma once
#include "Pieza.h"
class Reina :
    public Pieza
{
public:
    Reina(Tipo tipo, Color color) :Pieza(tipo, color) {};
    void miMov(const Casilla& origen,  Pieza* casilla[8][8], int matMov[8][8]) override;
};

