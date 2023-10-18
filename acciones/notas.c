#include <stdio.h>
int menor(int a, int b);
int promedio(int a, int b, int c);
void condicionAlumno(int n1, int n2, int n3);
int nota1, nota2, nota3;
void main(){
do{
printf("Ingrese la primera nota a analizar: \n");
scanf("%d", &nota1);
 }while(nota1<=0 && nota1>10);
do{
printf("Ingrese la segunda nota a analizar: \n");
scanf("%d", &nota2);
 }while(nota2<=0 && nota2>10);
do{
printf("Ingrese la tercera nota a analizar: \n");
scanf("%d", &nota3);
 }while(nota3<=0 && nota3>10);
    condicionAlumno(nota1,nota2,nota3);
}

int menor(int a, int b){
    int men;
    if(a<b){
        men=a;
    } else {
        men=b;
    }
    return men;
}
int promedio(int a, int b, int c){
    return ((a+b+c)/3);
}
void condicionAlumno(int n1, int n2, int n3){
    int menor1, menor2, prom;
    prom = promedio(n1,n2,n3);
    menor1 = menor(n1,n2);
    menor2 = menor(menor1,n3);
    if(menor2<4){
        printf("Libre");
    } else {
        if((menor2>=4 && menor2<6) && (prom<7)){
            printf("Regular");
        } else {
            if(menor2>=6 && prom>=7){
                printf("Promocionado");
            }
        }
    }
}