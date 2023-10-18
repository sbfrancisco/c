#include <stdio.h>
float kmr;
float precioPagar;
float exceso1, exceso2;
void main(){
    printf("Ingrese la cantidad de kilometros recorridos:\n");
    scanf("%f",&kmr);
      exceso1 = (kmr - 300);
      exceso2 = (kmr - 1000);
        if(kmr >=0 && kmr<=300){
            precioPagar = kmr * 30;
      }else if(kmr>300 && kmr<=1000){
             precioPagar = (exceso1 * 0.75) + kmr * 30;
             }else if(kmr > 1000){
                precioPagar = (exceso2 * 0.50) + kmr * 30;     
                  } else { 
                    precioPagar = 0;
                    }
    printf("El precio a pagar es de: %2.f \n", precioPagar);
}
