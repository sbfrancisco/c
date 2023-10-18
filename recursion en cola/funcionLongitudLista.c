// longitud de una lista en cola
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    struct nodo *next;
    int info;
}TNodo;
TNodo *r;
int longitud(TNodo *list, int acum){
    if(list==NULL){
        return acum;
    } else {
        return longitud((*list).next,acum+1);
    }
}
void crearLista(TNodo **list, int cant){
 int i;
 TNodo *r;
 for(i=0;i<cant;i++){
     r = (TNodo *) malloc(sizeof(TNodo));
     printf("Ingrese el elemento a almacenar: \n"); scanf("%d",&r->info);
     r->next=(*list);
     (*list)=r;
 }
}
int res, elem;
void main(){
    crearLista(&r,4);
    elem = longitud(r,0);
    printf("Hay %d elementos en la lista",elem);
    
}