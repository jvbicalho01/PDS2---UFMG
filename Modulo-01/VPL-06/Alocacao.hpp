#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <string>

using namespace std;

struct Alocacao{
    
    string _dia, _horario, _sala;

    Alocacao(string dia, string horario, string sala);
    //Alocacao() = default;

    void imprimir_dados();

};

#endif