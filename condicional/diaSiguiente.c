#include <stdio.h>
int dia, mes, año;
int cantDias;
void main()
{
    printf("Ingrese el dia del cual desea saber la fecha siguiente: \n");
    scanf("%d", &dia);
    printf("Ingrese el mes del cual desea saber la fecha siguiente: \n");
    scanf("%d", &mes);
    printf("Ingrese el año del cual desea saber la fecha siguiente: \n");
    scanf("%d", &año);
    if(mes == 2 && año%4==0 && año%100!=0 || mes == 2 && año%100==0 && año%400==0){
        cantDias = 29;
    } else if(mes==2){
            cantDias = 28;
         } else if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
                    cantDias = 30;
                } else if(mes==4 || mes==6 || mes==9 || mes==11){
                            cantDias = 31;
                }
    dia = dia + 1;
        if(dia>cantDias){
            mes = mes+1;
            dia = 1;
            
        }
        if(mes==13){
            año = año+1;
            mes= 1;
        }
    printf("La fecha siguiente a la ingresada es, dia=%d, mes=%d, año=%d", dia, mes, año);
}