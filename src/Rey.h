#pragma once
#include "Pieza.h"
class Rey :
    public Pieza
{
public:
    Rey(Tipo tipo, Color color) :Pieza(tipo, color) {};
    void miMov(const Casilla& origen, Pieza* casilla[8][8], int matMov[8][8]) override;
    void dibuja(float x, float y) override;
    ~Rey()override;
};

