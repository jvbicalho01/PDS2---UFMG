#ifndef LISTAPROCESSO_H
#define LISTAPROCESSO_H

#include "Processo.hpp"

#include <iostream>
#include <string>

struct ListaProcessos{
    
    Processo* head = nullptr;
    //Processo* tail = nullptr;

    void adicionar_processo(Processo* proc);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void imprimir_lista();

};

#endif