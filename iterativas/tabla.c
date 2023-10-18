/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int i, tabla, resultado;
void main(){
    printf("Ingrese el valor del que quiera conocer la tabla de multiplicar: \n");
    scanf("%d", &tabla);
    for(i=1;i<=10;i++){
        resultado = tabla * i;
            printf("El resultado de hacer %d x %d es de= %d \n", tabla, i, resultado);
    }    
}
    
    
