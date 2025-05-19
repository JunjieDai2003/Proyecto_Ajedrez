#pragma once
#include "Pieza.h"
class Torre :
    public Pieza
{
public:
    Torre(Tipo tipo, Color color) :Pieza(tipo, color) {};
    void miMov(const Casilla& origen, const Pieza* casilla[8][8], int matMov[8][8]) override;
};


