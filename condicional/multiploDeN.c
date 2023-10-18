#include <string.h>
#include <stdio.h>
int n;
char mensaje[64];
int main()
{
    printf("Ingrese un numero para considerar si es multiplo de 2 o 3, o de ambos: \n");
    scanf("%d",&n);
        if(n%2==0 && n%3!=0){
            strcpy(mensaje, "El numero ingresado es multiplo de 2");
        } else if(n%2!=0 && n%3==0){
                strcpy(mensaje, "El numero ingresado es multiplo de 3");
                 } else if(n%2==0 && n%3==0){
                            strcpy(mensaje, "El numero ingresado es multiplo de 2 y 3");
                         } else {
                                strcpy(mensaje, "El numero ingresado no es multiplo de ninguno de los anteriores");
                 }
    printf("%s", mensaje);
}
     