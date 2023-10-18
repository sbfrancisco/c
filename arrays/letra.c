#include <stdio.h>
#define MAX 100
typedef char TElem;
typedef TElem TArreglo;
typedef struct{
    TArreglo l[MAX];
    int cant;
    }TData;
TData letras;
int indice;
void main(){
indice = 1;
  printf("Ingrese la cantidad de letras a analizar: \n");
  scanf("%d", &letras.cant);
    while(indice<=letras.cant){
  printf("Ingrese la letra a analizar: \n");
  scanf(" %c", &letras.l[indice]);
  indice++;
 }

indice= 1;
   while(indice<=letras.cant){
    printf(" %c \n", letras.l[indice]);
    indice++;
 }
}