#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 12
typedef struct{
    int a[MAX];
    int cant;
}TMayor;
typedef struct{
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;
}TCumple;
typedef struct nodo{
    struct nodo* next;
    struct nodo* back;
    TCumple info;
}TElemCumple;
TElemCumple *pri,*ult;
void inicializarLista(TElemCumple **pri, TElemCumple **ult){
  int cant,i;
  TElemCumple *r;
  r=(TElemCumple *)malloc(sizeof(TElemCumple));
  r->next=NULL;
  r->back=NULL;
  (*pri)=r;
  r=(TElemCumple *)malloc(sizeof(TElemCumple));
  r->next=NULL;
  r->back=(*pri);
  (*ult)=r;
  (*pri)->next=(*ult);
    printf("Ingrese la cantidad de nodos a crear\n"); scanf("%d",&cant);
    for(i=0;i<cant;i++){
        r=(TElemCumple *)malloc(sizeof(TElemCumple));
        printf("Ingrese el nombre del cumpleañero\n"); scanf("%s",r->info.nombre);
        printf("Ingrese el apellido del cumpleañero\n"); scanf("%s",r->info.apellido);
        printf("Ingrese el mes en que nacio el cumpleañero\n"); scanf("%d",&r->info.mes);
        printf("Ingrese el dia en que nacio el cumpleañero\n"); scanf("%d",&r->info.dia);
        r->next=(*pri)->next;
        r->back=(*pri);
        (*pri)->next=r;
    }
}
void inicializarArreglo(TMayor *reg){
 int i;
  reg->cant=MAX;
  for(i=0;i<reg->cant;i++){
    reg->a[i]=0;
  }
}
void mesMayor(TElemCumple *pri, TElemCumple *ult){
 TMayor a; TElemCumple *aux; int may,i, temp;
  aux = pri;
  if(aux->next!=ult){
    inicializarArreglo(&a);
    while(aux->next!=ult){
        aux=aux->next;
        i = aux->info.mes;
        a.a[i]++;
    }
    may = 0;
    for(i=0;i<a.cant;i++){
        if(a.a[i]>a.a[may]){
            may = i;
        }
    }
    printf("El mes en el que cumplieron años la mayor cantidad de veces fue en %d",may);
  } else {
    printf("Lista vacia\n"); 
  }
}
void main(){
    inicializarLista(&pri,&ult);
    mesMayor(pri,ult);
}