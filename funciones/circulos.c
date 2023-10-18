#include <stdio.h>
#include <math.h>
float AreaCirc(float r);
float PerimCirc(float r);
float lado;
float radio1, radio2;
float areaCirculo, areaCirculo2, perim;
void main(){
    printf("Ingrese el lado de su cuadrado: \n");
    scanf("%f", &lado);
    radio1=lado/2;
    radio2=(lado*sqrt(2))/2;
    areaCirculo = AreaCirc(radio1);
    areaCirculo2 = AreaCirc(radio2);
    perim = PerimCirc(radio2);
    printf("El área del círculo inscripto es %.2f \n", areaCirculo);
    printf("El área del círculo circunscripto es %.2f \n", areaCirculo2);
    printf("El perímetro del círculo circunscripto es %.2f \n", perim);
}

float AreaCirc(float r){
    const float PI=3.1416;
    return PI*r*r;
}
float PerimCirc(float r){
    const float PI=3.1416;
    return 2*PI*r;
}