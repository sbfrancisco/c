#include <stdio.h>
float acum, monto, perdidas;
void main(){
    acum = 0;
    monto = 0;
    while(monto!=999999){
        printf("Ingrese el monto que quiera analizar \n");
        scanf("%f", &monto);
        if(monto<0){
            acum = acum+monto;
        }
    }
    acum = acum * (-1);
    printf("El monto perdido es de %f", acum);
}
