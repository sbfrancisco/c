#include <string.h>
#include <stdio.h>
int a, b, c;
int d;
char mensaje[50];
void main()
{
    printf("Ingrese el coeficiente A de la ecuacion: \n");
    scanf("%d", &a);
    printf("Ingrese el coeficiente B de la ecuacion: \n");
    scanf("%d", &b);
    printf("Ingrese el coeficiente C de la ecuacion: \n");
    scanf("%d", &c);
        if(a==0 && b==0){
            strcpy(mensaje, "La ecuacion es degenerada");
        } else if(a==0 && b!=0){
                strcpy(mensaje, "Existe una raiz unica");
        }       else if(a!=0 && b!=0){
               d = (b*b-4*a*c);
               } 
        if(d>0){
            strcpy(mensaje, "Hay dos raices");
        } else if(d==0){
                strcpy(mensaje, "Hay una sola raiz");
            } else if(d<0){
                    strcpy(mensaje, "Hay dos raices complejas");
            }
    printf("%s", mensaje);
}
        
