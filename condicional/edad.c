#include <stdio.h>
#include <string.h>
int edad;
char mensaje[50];
void main(){
 printf("Ingrese la edad de la persona para analizar si es menor o mayor de edad: \n");
 scanf("%d",&edad);
 if (edad >=18){
 strcpy(mensaje, "La edad ingresada es de una persona mayor de edad");
 }
 else if(edad>=0 && edad<18){
 strcpy(mensaje, "La edad ingresada es de una persona menor de edad");
      }else{
          strcpy(mensaje, "La edad ingresada es invalida");
      } 
 printf("%s", mensaje);
 }

