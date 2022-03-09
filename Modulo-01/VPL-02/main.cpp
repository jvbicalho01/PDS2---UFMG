#include <iostream>
#include <string.h>
#include "vogal.h"

using namespace std;

int main(){

    char palavra[255];
    //cout << "digite uma palavra: ";
    cin >> palavra;
    int tamanho = strlen(palavra);
    //int tamanho = palavra.length()
    //cout << tamanho;

    contaVogal(palavra, 'a', tamanho);
    contaVogal(palavra, 'e', tamanho);
    contaVogal(palavra, 'i', tamanho);
    contaVogal(palavra, 'o', tamanho);
    contaVogal(palavra, 'u', tamanho);
    
    return 0;
}