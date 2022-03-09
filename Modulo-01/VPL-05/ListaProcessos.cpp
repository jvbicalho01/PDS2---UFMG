#include "ListaProcessos.hpp"

#include <iostream>

using namespace std;

void ListaProcessos::adicionar_processo(Processo* proc){

    Processo *novoValor;

    novoValor = new Processo(proc->_id, proc->_nome, proc->_prioridade);
    novoValor->proximo = nullptr;
    
    if(this->head == nullptr || novoValor->_prioridade > this->head->_prioridade){
        novoValor->proximo = this->head;
        this->head = novoValor;
        return;
    }
    
    Processo *atual = this->head;
    
    while(atual->proximo != nullptr && atual->proximo->_prioridade >= novoValor->_prioridade){
        atual = atual->proximo;
    }

    novoValor->proximo = atual->proximo;
    atual->proximo = novoValor;
    
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){

    Processo *aux;
    aux = this->head;

    if(aux != nullptr){
        this->head = aux->proximo;
    }

    return aux;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){

    Processo *ptr;
    Processo *aux;

    ptr = this->head;

    while(ptr->proximo != nullptr){
        aux = ptr;
        ptr = ptr->proximo;
    }

    aux->proximo = nullptr;

    return ptr;
}

Processo* ListaProcessos::remover_processo_por_id(int id){

    Processo *atual = this->head;
    Processo *anterior;

    if(atual != nullptr && atual->_id == id){
        this->head = atual->proximo;
    }else{
        while(atual != nullptr && atual->_id != id){
            anterior = atual;
            atual = atual->proximo;
        }
        
        if (atual == nullptr)
            return atual;
        
        anterior->proximo = atual->proximo;
    }

    return atual;
}

void ListaProcessos::imprimir_lista(){

    Processo *aux = this->head;

    while (aux != nullptr){
        
        aux->imprimir_dados();

        aux = aux->proximo;

    }
    
}