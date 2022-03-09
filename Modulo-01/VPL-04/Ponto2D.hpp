#ifndef PONTO2D_H
#define PONTO2D_H

#include <cmath>

using namespace std;

struct Ponto2D{

    double _x;
    double _y;

    Ponto2D(double x = 0, double y = 0);
    
    double calcular_distancia(Ponto2D* ponto);

};

#endif