#include <stdio.h>
#include <string.h>
char a;
void main(){
    do{
        printf("¿Desea continuar S/N? \n");
        a= getchar();
    } while(!(a=='n'));

}
