#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50
typedef char TElem;
typedef TElem TArreglo;
typedef struct{
    TArreglo a[MAX];
    int cant;
}TData;
TData capi;
bool res;
void recibirArreglo(TData *d){
    int i;
    printf("Ingrese la palabra que quiere analizar \n");
    scanf("%s", (*d).a);
    (*d).cant=strlen(((*d).a))-1;
    }
bool capicua(TData d){
    int i;
    TData aux;
    int letrasIguales;
    i=0;
    letrasIguales=0;
    while(i<d.cant){
        aux.a[i] = d.a[i];
        i++;
    }
    aux.cant=i;
    i=0;
    while(0<=aux.cant){
        if(aux.a[aux.cant]==d.a[i]){
            letrasIguales= letrasIguales+1;
        }
        i++;
        aux.cant--;
    }
    return (letrasIguales==d.cant);
}
void main(){
    recibirArreglo(&capi);
    res=capicua(capi);
    if(res){
        printf("La palabra es capicua \n");
    } else {
        printf("La palabra no es capicua \n");
    }
}