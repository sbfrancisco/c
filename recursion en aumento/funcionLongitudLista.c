// longitud de una lista en aumento
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    struct nodo *next;
    int info;
}TNodo;
TNodo *r;
int longitud(TNodo *list){
    if(list==NULL){
        return 0;
    } else {
        return 1+longitud((*list).next);
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
    elem = longitud(r);
    printf("Hay %d elementos en la lista",elem);
    
}