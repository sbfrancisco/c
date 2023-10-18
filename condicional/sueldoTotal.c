#include <stdio.h>
float horasTrabajadas;
float extra, horasBase;
float sueldoTotal;
void main(){
 printf("Ingrese la cantidad de horas trabajadas en la semana: \n");
 scanf("%f", &horasTrabajadas);
        if(horasTrabajadas <= 40){
            sueldoTotal = horasTrabajadas * 10;
        }else{
            extra = ((horasTrabajadas*10-400)*1.5);
            sueldoTotal = (horasTrabajadas * 10)+extra;
        }
 printf("El sueldo que le corresponde al trabajador es de %2.f", sueldoTotal);
}
  
