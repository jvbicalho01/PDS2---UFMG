#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"
#include "avaliacao_basica_alocacao.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){

    QuadroAlocacao quadro_alocacao;
    string codigo, nome, dia, horario, sala;

    char opcao;

    while(cin >> opcao){

        switch (opcao){

            case 'a':
            //codigo nome dia horario sala
                cin >> codigo;
                cin >> nome;
                cin >> dia;
                cin >> horario;
                cin >> sala;

                quadro_alocacao.inserir_alocacao(codigo, nome, dia, horario, sala);
        
                break;

            case 'm': {

                vector<Disciplina> mais_ofertadas = quadro_alocacao.recuperar_disciplinas_mais_ofertadas();

                for(Disciplina &disciplina : mais_ofertadas){
                    disciplina.imprimir_alocacao();
                }

                break;

            }

            case 'r':

                cin >> codigo;
                cin >> horario;

                quadro_alocacao.remover_alocacao_disciplina(codigo, horario);

                break;

            case 'p':

                quadro_alocacao.imprimir_alocacao_completa();

                break;

            case 'b':

                avaliacao_basica();

                break;
        
        }

    }

    return 0;
}