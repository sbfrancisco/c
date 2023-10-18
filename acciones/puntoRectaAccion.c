#include <stdio.h>
#include <math.h>
#include <string.h>
struct TPunto {
    float x;
    float y;
}; 
struct TCoef {
    float a;
    float b;
};
float k;
struct TPunto c;
struct TCoef d;
void dentroRecta(struct TPunto a, struct TCoef b, float *i);
void obtenerPuntos(struct TPunto *a);
void obtenerCoeficiente(struct TCoef *b);
char mensaje[50];
void main(){
 obtenerPuntos(&c);
 obtenerCoeficiente(&d);
 dentroRecta(c,d,&k);
 if(k==1){
     strcpy(mensaje, "El punto ingresado esta en la recta \n ");
 } else {
     strcpy(mensaje, "El punto ingresado no esta en la recta \n ");
 }
 printf("%s", mensaje);
}

void obtenerPuntos(struct TPunto *a){
 printf("Ingrese el x de la formula a analizar: \n");
 scanf("%f",&(*a).x);
  printf("Ingrese el y de la formula a analizar: \n");
 scanf("%f",&(*a).y);
}

void obtenerCoeficiente(struct TCoef *b){
 printf("Ingrese el coeficiente a de la formula: \n");
 scanf("%f",&(*b).a);
 printf("Ingrese el coeficiente b de la formula: \n");
 scanf("%f",&(*b).b);
}
void dentroRecta(struct TPunto a, struct TCoef b, float *i){
    if(a.y=b.a*a.x+b.b){
        *i=1;
    } else {
        *i=0;
    }
}