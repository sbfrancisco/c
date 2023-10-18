#include <stdbool.h>
#include <stdio.h>

bool anioBisiesto(int a);
int anio;
int res;
void main(){
    printf("Ingrese el anio a analizar: \n");
    scanf("%d", &anio);
    if(anioBisiesto(anio)){
        printf("El anio es bisiesto \n");
    } else {
        printf("El anio no es bisiesto \n");
    }
}

bool anioBisiesto(int a){
    return (((a%4==0) && (a%100!=0))||((a%100==0) && (a%400==0)));
}