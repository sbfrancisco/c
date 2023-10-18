#include <string.h>
#include <math.h>
#include <stdio.h>
int contador, i, numero, divisor;
char mensaje[50];
void main(){
    i=1;
    contador=1;
    printf("Ingrese el numero a analizar si es primo o no; \n");
    scanf("%d", &numero);
    divisor = sqrt(numero);
    while(i<=divisor){
        if(numero%i==0){
            contador = contador+1;
        }
        i++;
    }
    if(contador>2){
        strcpy(mensaje, "El numero es compuesto");
    } else { 
        strcpy(mensaje, "El numero es primo");
    }
    printf("%s", mensaje);
}
