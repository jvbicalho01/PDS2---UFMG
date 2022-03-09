#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int x = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *ptr = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int v[10];
    int valor = 9;
    for(int i = 0; i < 10; i++){
        v[i] = valor;
        //cout << v[i] << endl;
        valor--;
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &x << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << x << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    //cout << ptr << endl;
    cout << &ptr << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    //cout << *ptr << endl;
    cout << ptr << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << v << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &v[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << v[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ptr = &x;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << (&x == ptr) << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *ptr = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << x << endl;

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    ptr = v;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ptr = &v[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i = 0; i < 10; i++){
        *ptr = (*ptr) * 10;
        ptr++;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i = 0; i < 9; i++){
        cout << v[i] << " ";
    }
    cout << v[9] << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for(int i = 0; i < 9; i++){
        cout << *(v + i) << " ";
    }
    cout << *(v + 9) << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    ptr = v;
    for(int i = 0; i < 9; i++){
        cout << *(ptr + i) << " ";
    }
    cout << *(ptr + 9) << endl;  

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    ptr = &v[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << ptr << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ptr << endl;

    // 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
    cout << *(ptr - 4) << endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **ponteiro = &ptr;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << ponteiro << endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << &ponteiro << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << *ponteiro << endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << **ponteiro << endl;
    
    return 0;
}