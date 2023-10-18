#include <stdio.h>
#include <string.h>
void Calculadora(int a, int b, char c, int *d);
int e,f,h;
char g;
int main(){
    printf("Ingrese el primer operando: \n");
    scanf("%i",&e);
    printf("Ingrese el segundo operando: \n");
    scanf("%i",&f);
    printf("Ingrese el operador: \n");
    scanf(" %c", &g);
    Calculadora(e,f,g,&h);
    printf("El resultado de la operacion es %i", h);
}
void Calculadora(int a, int b, char c, int *d){
    if (c == '+'){
        *d = a+b;
    } else {
        if(c == '-'){
            *d = a-b;
        } else {
            if(c == '*'){
                *d = a*b;
            } else {
                if(c == '/'){
                    if(b!=0){
                        *d=a/b;
                    } else {
                        *d=999999999;
                        printf("ERROR \n");
                    }
                 }
               }
            }
        }
}