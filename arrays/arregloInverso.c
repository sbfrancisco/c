#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char TElem;
typedef TElem TArreglo;
typedef struct{
    TArreglo a[MAX];
    int cant;
}TData;
TData arreglo, arregloInverso;
void obtenerArreglo(TData *a){
    printf("Ingrese el arreglo que quiera invertir \n");
    scanf("%s", (*a).a);
    (*a).cant=strlen((*a).a)-1;
}
TData inverso (TData a){
    int i,j;
    TData aux;
    i = a.cant;
    j=0;
    while(0<=i){
        aux.a[j] = a.a[i];
        i--;
        j++;
    }
    aux.cant=a.cant;
    return aux;
}
void mostrarArreglo(TData a){
    int i;
    for(i=0;i<=a.cant;i++){
        printf("%c \n", a.a[i]);
    }
}
void main(){
    obtenerArreglo(&arreglo);
    arregloInverso=inverso(arreglo);
    mostrarArreglo(arregloInverso);
}