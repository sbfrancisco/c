

#include <stdio.h>
int digito1, digito2;
int maximoNumero;
void main()
{
    printf("Ingrese el primer digito: \n");
    scanf("%d", &digito1);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &digito2);
     if(digito2>digito1){
        maximoNumero = (digito2*10) + digito1;
    } else {
        maximoNumero = (digito1*10) + digito2;
     }
     printf("El maximo numero entre estos dos digitos es: %d \n ", maximoNumero);
    }