#include <stdio.h>
#include <math.h>
struct TPunto{
    float x;
    float y;
};
float distancia(struct TPunto c, struct TPunto d);
struct TPunto a,b;
float res;
void main(){
    printf("Ingrese la coordenada x del primer punto: \n");
    scanf("%f", &a.x);
    printf("Ingrese la coordenada y del primer punto: \n");
    scanf("%f", &a.y);
    printf("Ingrese la coordenada x del segundo punto: \n");
    scanf("%f", &b.x);
    printf("Ingrese la coordenada y del segundo punto: \n");
    scanf("%f", &b.y);

    res = distancia(a,b);
    printf("La distancia entre estos puntos es de %.2f \n", res);
}

float distancia(struct TPunto c, struct TPunto d){
    return sqrt(((d.y-c.y)*(d.y-c.y))+((d.x-c.x)*(d.x-c.x)));
}