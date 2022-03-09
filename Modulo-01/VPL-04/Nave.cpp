#include "Nave.hpp"
#include <iostream>

using namespace std;

Nave::Nave(Ponto2D posicao, double forca){

    this-> _posicao = posicao;
    this-> _forca = forca;

}

void Nave::mover(double dx, double dy){

    this-> _posicao._x += dx;
    this-> _posicao._y += dy;

}

double Nave::calcular_distancia(Nave* nave){

    return this-> _posicao.calcular_distancia(&nave-> _posicao);

}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){

    double menorDistancia = 5000;
    int mais_proxima = 0;
    
    for (int i = 0; i < n; i++){
        if (menorDistancia > calcular_distancia(naves[i]) && 
            ((naves[i])->_posicao._x != this->_posicao._x || (naves[i])->_posicao._y != this->_posicao._y))
        {
            menorDistancia = calcular_distancia(naves[i]);
            mais_proxima = i;
        }
    }
    return naves[mais_proxima];

}

void Nave::atacar(Nave** naves, int n){

    Nave* mais_proxima = determinar_nave_mais_proxima(naves, n);
    double distancia;
    double dano;
    
    distancia = this-> _posicao.calcular_distancia(&mais_proxima-> _posicao);
    dano = this-> _forca * (100 / distancia);

    if(dano > 30){
        dano = 30;
    }

    mais_proxima-> energia -= dano;

    if(mais_proxima-> energia <= 50){
        cout << "Energia baixa!" << endl;
    }

}

void Nave::imprimir_status(){

    cout << this-> _posicao._x << " " << this-> _posicao._y << " " << this-> energia << endl;

}