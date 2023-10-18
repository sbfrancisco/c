#include <stdio.h>
#include <string.h>
int NotaFinal(int a, int b, int c){
    if(a<4 || b<4 || c<4){
        return 2;
    } else {
        return (a+b+c)/3;
    }
}
int nota1, nota2, nota3;
int promedio;
char mensaje[11];
void main(){
    do{
        printf("Ingrese la nota 1: \n");
        scanf("%d", &nota1);
    }while(nota1<=0 || nota1>10);

    do{
        printf("Ingrese la nota 2: \n");
        scanf("%d", &nota2);
    }while(nota2<=0 || nota2>10);

    do{
        printf("Ingrese la nota 3: \n");
        scanf("%d", &nota3);
    }while(nota3<=0 || nota3>10);

    promedio = NotaFinal(nota1, nota2, nota3);

    if(promedio<5){
        strcpy(mensaje, "Libre");
    } else {
        if(promedio>=5 && promedio<7){
            strcpy(mensaje, "Regular");
        } else {
            if(promedio>=7 && promedio<=10){
                strcpy(mensaje, "Promoción");
             }
        }
    }
    printf("%s\n", mensaje);
}

