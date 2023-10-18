#include <stdio.h>
#include <math.h>
#include <stdbool.h>
struct TRectangulo{
    float x;
    float y;
};
struct TCirculo{
    float x;
    float y;
    float r;
};
struct TPunto{
    float x;
    float y;
};

bool DentroCirculo(struct TCirculo e, struct TPunto g){
    float f;
    f = sqrt(((g.x-e.x)*(g.x-e.x))+((g.y-e.y)*(g.y-e.y)));
    if(f<=e.r){
        return true;
    } else { 
        return false;
    }
}
bool DentroRectangulo(struct TRectangulo h, struct TRectangulo i, struct TPunto g){
    if(((g.x>=h.x) && (g.x<=i.x))&&((g.y>=h.y)&&(g.y<=i.y))){
        return true;
    } else {
        return false;
    }
}
struct TRectangulo a,b;
struct TCirculo c;
struct TPunto d;
void main(){
    printf("Ingrese la coordenada x del vertice del rectangulo: \n");
    scanf("%f", &a.x);
    printf("Ingrese la coordenada y del vertice del rectangulo: \n");
    scanf("%f", &a.y);
    printf("Ingrese la coordenada x del vertice opuesto del rectangulo: \n");
    scanf("%f", &b.x);
    printf("Ingrese la coordenada y del vertice opuesto del rectangulo: \n");
    scanf("%f", &b.y);
    printf("Ingrese la coordenada x del centro del circulo: \n");
    scanf("%f", &c.x);
    printf("Ingrese la coordenada y del centro del circulo: \n");
    scanf("%f", &c.y);
    printf("Ingrese el radio del circulo: \n");
    scanf("%f", &c.r);
    printf("Ingrese el punto x que quiere comprobar si esta dentro del circulo y/o rectangulo: \n");
    scanf("%f", &d.x);
    printf("Ingrese los punto y que quiere comprobar si esta dentro del circulo y/o rectangulo: \n");
    scanf("%f", &d.y);
    if((DentroCirculo(c,d)) && (DentroRectangulo(a,b,d))){
        printf("El punto esta dentro del circulo y del rectangulo \n");
    } else {
        if((DentroCirculo(c,d)) && (!(DentroRectangulo(a,b,d)))){
            printf("El punto esta dentro del circulo \n");
        } else {
            if(!(DentroCirculo(c,d)) && (DentroRectangulo(a,b,d))){
                 printf("El punto esta dentro del rectangulo \n");
        } else {
            if(!(DentroCirculo(c,d)) && (!(DentroRectangulo(a,b,d)))){
                printf("El punto no esta dentro del rectangulo ni del circulo\n");
                }
            }
        }
    }
}