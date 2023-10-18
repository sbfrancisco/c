#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 30
typedef int TElem;
typedef TElem TLot;
typedef struct{
    TLot a[MAX];
    int cant;
}TData;
TData loteria;
bool esta;
int num;
void generarNum (int *q){
    srand(time(NULL));
    *q = rand()%1000;
}
void verificar(int q, TData l, bool *yaEsta){
    int i;
    *yaEsta = false;
    for(i=0;i<l.cant;i++){
        if((l.a[i])==q){
            *yaEsta = true;
        }
    }
}
void cargarNumeros(bool yaEsta, int q, TData *l){
    if(!(yaEsta)){
        (*l).a[(*l).cant]=q;
        (*l).cant++;
    }
}
void main(){
    loteria.cant=0;
    while(loteria.cant<MAX){
        generarNum(&num);
        verificar(num,loteria,&esta);
        cargarNumeros(esta,num,&loteria);
    }
    int i;
    for(i=0;i<MAX;i++){
        printf("En la posicion %d el numero que salio es: %d \n", i+1, loteria.a[i]);
    }
}