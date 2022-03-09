#include "avaliacao_basica_escalonador.hpp"
#include "Processo.hpp"
#include "ListaProcessos.hpp"

#include <iostream>
#include <string>
#include <new>

using namespace std;

int main(){

    int id, prioridade;
    string nome;

    ListaProcessos lista;

    Processo *proc;

    char opcao;

    while(cin >> opcao){

        switch (opcao){
        
            case 'a':

                cin >> id;
                cin >> nome;
                cin >> prioridade;

                proc = new Processo(id, nome, prioridade);

                lista.adicionar_processo(proc);

                break;

            case 'm':

                lista.remover_processo_maior_prioridade();

                break;

            case 'n':

                lista.remover_processo_menor_prioridade();

                break;

            case 'r':

                cin >> id;
                lista.remover_processo_por_id(id);
            
                break;

            case 'p':

                lista.imprimir_lista();

                break;

            case 'b':

                avaliacao_basica();

                break;
        
            
        }


    }

    return 0;
}