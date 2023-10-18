#include <stdio.h>
int resProb;
int probFall;
void main(){
probFall = 0;
resProb = 0;
while(resProb!=9999){
printf("Ingrese el resultado de la probeta: \n");
scanf("%d", &resProb);
    if(resProb<230){
        probFall++;
    }
}
printf("Se han encontrado %d probetas falladas \n", probFall);
}