#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Alocacao.hpp"

using namespace std;

struct Disciplina{
    
    string _codigo, _nome;
    vector<Alocacao> _alocacao;

    Disciplina(string codigo, string nome);
    //Disciplina() = default;

    void inserir_alocacao(string dia, string horario, string sala);

    void remover_alocacao(string horario);

    void imprimir_alocacao();

};

#endif