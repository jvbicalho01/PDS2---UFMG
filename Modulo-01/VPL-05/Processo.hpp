#ifndef PROCESSO_H
#define PROCESSO_H

#include <iostream>
#include <string>

using namespace std;

struct Processo{

    int _id;
    string _nome;
    int _prioridade;

    Processo *proximo;

    Processo(int id, string nome, int prioridade);

    void imprimir_dados();

};

#endif