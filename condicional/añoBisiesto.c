/******************************************************************************

           Algoritmo añoBisiesto
Léxico   
año E Z
mensaje E cadena
Inicio 
  entrada: año
		si (año mod 4=0 y año mod 100<>0) entonces
			mensaje  “El año es bisiesto”
		sino
			si (año mod 100=0 y año mod 400=0) entonces
			   mensaje  “El año es bisiesto”
			sino
				mensaje  “El año no es bisiesto”
			fsi
		fsi
salida: mensaje 
Fin

*******************************************************************************/
#include <string.h>
#include <stdio.h>
int anio;
char mensaje[50];
void main()
{
    printf("Ingrese el año que quiere comprobar si es bisiesto o no: \n");
    scanf("%d", &anio);
        if(anio%4==0 && anio%100!=0){
            strcpy(mensaje, "El año es bisiesto");
        } else if(anio%100==0 && anio%400==0){
                    strcpy(mensaje, "El año es bisiesto");
             } else {
                        strcpy(mensaje, "El año no es bisiesto");
             }
    printf("%s", mensaje);    
    
}
   
