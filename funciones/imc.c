#include <stdio.h>
#include <math.h>
void indice(float peso, float altura, float *aux){

    *aux = peso/(altura*altura);

    if(*aux<25){
        printf("Normal \n");
    } else {
        if(*aux>=25 && *aux<30){
            printf("Sobrepeso \n");
        } else {
            if(*aux>30){
                printf("Obesidad \n");
            }
        }
    }
}
float p,a;
float i;
void main(){
    printf("Ingrese el peso en kilogramos de la persona: \n");
    scanf("%f", &p);
    printf("Ingrese la altura en metros de la persona: \n"); // usando decimales, ej 1.60
    scanf("%f", &a);
    indice(p,a,&i);
    printf("El indice de masa muscular de la persona es de: %.2f", i);
}