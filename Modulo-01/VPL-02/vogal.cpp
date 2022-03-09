#include <iostream>

using namespace std;

void contaVogal(char palavra[], char c, int tamanho){

    int quantidade = 0;

    for(int i = 0; i < tamanho; i++){
        if(palavra[i] == c){
            quantidade++;
        }
    }
    if(quantidade > 0){
        cout << c << " " << quantidade << endl;
    }

}