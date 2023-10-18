#include <string.h>
#include <stdio.h>
char mensaje[35];
int lado1, lado2, lado3;
void main()
{
    printf("Ingrese el valor del primer lado: \n");
    scanf("%d", &lado1);
    printf("Ingrese el valor del segundo lado:\n");
    scanf("%d", &lado2);
    printf("Ingrese el valor del tercer lado:\n");
    scanf("%d", &lado3);
        if(lado1==lado2 && lado2!=lado3){
            strcpy(mensaje, "El triangulo es isósceles");
        } else if(lado1==lado3 && lado3!=lado2){
                 strcpy(mensaje, "El triangulo es isósceles");
                    } else if(lado2==lado3 && lado3 !=lado1){
                        strcpy(mensaje, "El triangulo es isósceles");
                            } else if(lado1==lado2 && lado2==lado3){
                                strcpy(mensaje, "El triangulo es un equilátero");
                                    } else {
                                        strcpy(mensaje, "El triangulo es escaleno");
                                    }
    printf("%s", mensaje);
                            }       
                    
