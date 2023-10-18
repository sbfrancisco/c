#include <stdio.h>
int segundos, minutos, horas;
void main()
{
    printf("Ingrese los segundos de la hora que desee calcular un segundo después: \n");
    scanf("%d", &segundos);
    printf("Ingrese los minutos de la hora que desee calcular un segundo después: \n");
    scanf("%d", &minutos);
    printf("Ingrese la hora de la hora que desee calcular un segundo después: \n");
    scanf("%d", &horas);
        segundos = segundos + 1;
            if(segundos > 59){
                minutos = minutos + 1;
                segundos = 0;
            }
            if(minutos==60){
                minutos = 0;
                horas = horas+1;
                }
                if(horas==24){
                   horas=0;
                }
    printf("La hora siguiente a la ingresada es, segundos=%d, minutos=%d, horas=%d", segundos, minutos, horas);
    }
