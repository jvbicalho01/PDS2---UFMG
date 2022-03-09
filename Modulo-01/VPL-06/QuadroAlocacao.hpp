#ifndef QUADROALOCACAO_H
#define QUADROALOCACAO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Alocacao.hpp"
#include "Disciplina.hpp"

struct QuadroAlocacao{
    
    //Atributos: crie um atributo para guardar as alocações de todas as disciplinas. 
    //Você deve escolher a estrutura que julgar mais adequada para usar (dica: um map é bem útil!).
    map<string, Disciplina> _alocacao;

    void inserir_alocacao(string codigo, string nome, string dia, string horario, string sala);

    void remover_alocacao_disciplina(string codigo, string horario);

    vector<Disciplina> recuperar_disciplinas_mais_ofertadas();

    void imprimir_alocacao_completa();

};

#endif