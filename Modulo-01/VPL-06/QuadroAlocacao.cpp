#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao(string codigo, string nome, string dia, string horario, string sala){

    //MAP -> DISCIPLINA
    //DISCIPLINA -> VARIAS ALOCACOES

    //A disciplina esta no map?
    if (!_alocacao.count(codigo)){

        //se nao, deve inserir
        _alocacao.insert(pair<string, Disciplina>(codigo, Disciplina(codigo, nome)));

    }
    
    //se estiver, adicionar uma lova alocacao para ela 
    _alocacao.find(codigo)->second.inserir_alocacao(dia, horario, sala);

}

void QuadroAlocacao::remover_alocacao_disciplina(string codigo, string horario){

    _alocacao.find(codigo)->second.remover_alocacao(horario);

}

vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){

    vector<Disciplina> mais_ofertadas;
    int max_ofertas = -1;

    //contar o maior numero de ofertas
    map<string, Disciplina>::iterator it;

    for(it = _alocacao.begin(); it != _alocacao.end(); ++it){

        Disciplina disciplina = it->second;
        int num = disciplina._alocacao.size();

        if (max_ofertas < 0 || num > max_ofertas){

            max_ofertas = num;

        }

    }

    //retornar so as mais ofertadas
    for(it = _alocacao.begin(); it != _alocacao.end(); ++it){

        Disciplina disciplina = it->second;
        int num = disciplina._alocacao.size();

        if (num == max_ofertas){

            mais_ofertadas.push_back(disciplina);

        }

    }
    
    return mais_ofertadas;
}

void QuadroAlocacao::imprimir_alocacao_completa(){

    map<string, Disciplina>::iterator it;

    for(it = _alocacao.begin(); it != _alocacao.end(); ++it){

        string codigo = it->first;
        Disciplina disciplina = it->second;

        disciplina.imprimir_alocacao();

    }

}