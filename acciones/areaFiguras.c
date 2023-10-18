#include <stdio.h>
float x,y,sup;
char z;
void Cargar(float *a, float *b, char *f){    
printf("Ingrese una t si es un triangulo y una r si es un rectangulo: \n");
scanf(" %c", &(*f));
    if(*f =='r'){
    printf("Ingrese el primer lado: \n");
    scanf("%f", &(*a));
    printf("Ingrese el primer lado: \n");
    scanf("%f", &(*b));
    } else {
    printf("Ingrese la base del triangulo: \n");
    scanf("%f", &(*a));
    printf("Ingrese la altura del triangulo: \n");
    scanf("%f", &(*b));
    }
}
void Calcular(float a, float b, char f, float *area){
if(f =='r'){
    *area= a*b;
} else {
    *area= (a*b)/2;
}
}
void Mostrar (float a, float b, char f, float area){
    if(f=='r'){
    printf("El área del rectangulo dado por los lados %2.f %2.f %2.f", a, b, area);
    } else {
    printf("El área del triangulo dado por la altura y la base %2.f %2.f %2.f", a, b, area);
}
}
void main(){
Cargar (&x,&y,&z);
Calcular(x,y,z,&sup);
Mostrar (x,y,z,sup);
}