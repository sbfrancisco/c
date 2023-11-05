#include <stdio.h>
#include <stdlib.h>
typedef struct{char nombre[50]; char apellido[50]; int dia; int mes;
}TCumple;
typedef struct nodo{TCumple info; struct nodo *next;
}TCumpleElem;
TCumpleElem *reg,*aux;
int contMarzo;
void cargarLista(TCumpleElem **q){
    TCumpleElem *r; int i,cant;
    (*q)=NULL;
    printf("Ingrese la cantidad de nodos a agregar:\n"); scanf("%d",&cant);
    for(i=0;i<cant;i++){
    r = (TCumpleElem *) malloc(sizeof(TCumpleElem));
    printf("Ingrese el mes en que nacio la persona a ingresar\n"); scanf("%d",&r->info.mes);
    r->next=(*q);
    (*q)=r;
    }
}
void cantMarzo(TCumpleElem *q, int *cont){
 TCumpleElem *aux;
  aux = q;
  while(aux!=NULL){
    if(aux->info.mes==3){
        (*cont)++;
    }
    aux=aux->next;
  }
}
void main(){
    cargarLista(&reg);
    aux = reg;
    if(aux==NULL){
      printf("La lista esta vacia\n");
    } else {
        contMarzo = 0;
        cantMarzo(reg,&contMarzo);
    }
    printf("La cantidad de personas nacidas en marzo son %d", contMarzo);
}