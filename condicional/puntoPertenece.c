#include <math.h>
#include <string.h>
#include <stdio.h>
float x1, x2, puntoy1, y2;
float cx1, cy1, r;
int dentroRectangulo, dentroCirculo;
float px1, py1;
float d;
char mensaje [80];
void main(){
    printf("Ingrese la coordenada x del vertice del rectangulo: \n");
    scanf("%f", &x1);
    printf("Ingrese la coordenada y del vertice del rectangulo: \n");
    scanf("%f", &puntoy1);
    printf("Ingrese la coordenada x del vertice opuesto del rectangulo: \n");
    scanf("%f", &x2);
    printf("Ingrese la coordenada y del vertice opuesto del rectangulo: \n");
    scanf("%f", &y2);
    printf("Ingrese la coordenada x del centro del circulo: \n");
    scanf("%f", &cx1);
    printf("Ingrese la coordenada y del centro del circulo: \n");
    scanf("%f", &cy1);
    printf("Ingrese el radio del circulo: \n");
    scanf("%f", &r);
    printf("Ingrese los puntos que quiere comprobar si esta dentro del circulo y/o rectangulo: \n");
    scanf("%f", &px1);
    printf("Ingrese los puntos que quiere comprobar si esta dentro del circulo y/o rectangulo: \n");
    scanf("%f", &py1);
    
    d = sqrt((px1-cx1)*(px1-cx1)+(py1-cy1)*(py1-cy1));
        if(d<=r){
            dentroCirculo = 1;
        } else {
            dentroCirculo = 0;
        }
            if(px1>= x1 && px1<=x2 && py1>=puntoy1 && py1<=y2){  
                dentroRectangulo = 1;
            } else {
                dentroRectangulo = 0;
            }
    if(dentroRectangulo==1 && dentroCirculo==1){
        strcpy(mensaje, "El punto ingresado esta dentro del circulo y del rectangulo");
    } else if(dentroCirculo==1 && dentroRectangulo!=1){
                strcpy(mensaje, "El punto ingresado esta dentro del circulo");
             } else if(dentroRectangulo==1 && dentroCirculo!=1){
                        strcpy(mensaje, "El punto esta dentro del rectangulo");
                    } else if(dentroCirculo!=1 && dentroRectangulo!=1){
                                strcpy(mensaje, "El punto esta fuera del rectangulo y del circulo");
                    }
    printf("%s", mensaje);
                    }