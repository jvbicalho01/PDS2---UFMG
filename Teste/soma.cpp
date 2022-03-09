#include "soma.h"

int soma(int n, int v[]){
    float s = 0;
    for(int i = 0; i < n; i++){
        s = s + v[i];
    }
    return s;
}