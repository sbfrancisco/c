
#include <string.h>
#include <stdio.h>
int mes;
char mensaje[35];
void main()
{
    printf("Ingrese el mes que desea consultar la cantidad de dias que tiene \n");
    scanf("%d", &mes);
        if(mes==2){
            strcpy(mensaje, "El mes ingresado tiene 28 dias");
        } else if(mes==4 || mes==6 || mes==9 || mes ==11){
                strcpy(mensaje, "El mes ingresado tiene 30 dias");
                } else if( mes==1 || mes==5 || mes==7 || mes==10 || mes==12){
                        strcpy(mensaje, "El mes ingresado tiene 31 dias");
                      } else{
                            strcpy(mensaje, "El mes ingresado no es existente");
                
        }
                                 printf("%s", mensaje);
  }

