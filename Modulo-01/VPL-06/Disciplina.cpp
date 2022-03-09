#include "Disciplina.hpp"

struct compara_alocacao{

    bool operator()(const Alocacao& a1, Alocacao& a2){

        return a1._horario < a2._horario;

    }

};

Disciplina::Disciplina(string codigo, string nome){

    this->_codigo = codigo;
    this->_nome = nome;

}

void Disciplina::inserir_alocacao(string dia, string horario, string sala){

    this->_alocacao.push_back(Alocacao(dia, horario, sala));

}

void Disciplina::remover_alocacao(string horario){

    for (int i = 0; i < _alocacao.size(); i++){

        if (_alocacao[i]._horario == horario){
            _alocacao.erase(_alocacao.begin() + i);
        }

    }

}

void Disciplina::imprimir_alocacao(){

    sort(_alocacao.begin(), _alocacao.end(), compara_alocacao());

    for (Alocacao &alocacao : this->_alocacao){
        
        cout << this->_codigo << " " << this->_nome << " ";
        alocacao.imprimir_dados();

    }

}