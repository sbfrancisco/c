#include <stdio.h>
float y, a, base, resultado, i;
void main(){
    printf("Ingrese un numero que quiere utilizar de base: \n");
    scanf("%f", &a);
    printf("Ingrese un numero que quiere utilizar de exponente: \n");
    scanf("%f", &y);
    i = 1;
    resultado= 1;
    while(y>=i){
        base = a;
        resultado=base*resultado;
        i++;
    }
printf("El resultado de elevar %2.f a la %2.f es de: %2.f ", a, y, resultado);
}
