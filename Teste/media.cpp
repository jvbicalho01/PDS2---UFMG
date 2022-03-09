#include "media.h"
#include "soma.h"

float media(int n, int v[]){
    float s = soma(n, v);
    return s / n;
}