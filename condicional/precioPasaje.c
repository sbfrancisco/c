#include <stdio.h>
int diasFaltantes;
int montoPagar;
int idaYVuelta;

void main(){
   printf("Ingresar los dias restantes del vuelo que desea reservar: \n");
   scanf("%d", &diasFaltantes);
   printf("Ingrese el numero 1 si el vuelo es de ida y vuelta, de lo contrario ingrese el numero 0: \n");
   scanf("%d", &idaYVuelta);
   if(diasFaltantes >= 30){
       montoPagar = 4650;
   } else if(diasFaltantes >=15 && diasFaltantes < 30){
       montoPagar = 5350;
        } else if(diasFaltantes >= 1 && diasFaltantes <15) {
              montoPagar = 6875;
          }
             if(idaYVuelta == 1){
                 montoPagar = (montoPagar * 2);
              }
    printf("El monto a pagar es de: %d \n", montoPagar);
}
   
