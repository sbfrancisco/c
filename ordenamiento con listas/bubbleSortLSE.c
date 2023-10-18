#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
                 int info;
                 struct nodo *next;
}TNodo;
typedef struct{
    TNodo *a;
    int cant;
}TData;
TData num;
TNodo *a,*anterior,*comp,*siguiente,*ult;
void generarLSEFic(TNodo **a){
    TNodo *s;
    s = (TNodo *) malloc(sizeof(TNodo));
    s->next=(*a);
    (*a)=s;
}
void agregarElementos(TNodo **a, int *cant){
    TNodo *s;
    int i = 0;
    printf("Ingrese la cantidad de nodos a crear: \n"); scanf("%d",&(*cant));
    for(i=0;i<(*cant);i++){
    s = (TNodo *) malloc(sizeof(TNodo));
    printf("Ingrese el numero a almacenar: \n"); scanf("%d",&s->info);
    s->next=(*a)->next;
    (*a)->next=s;
    }
}
void mostrar(TNodo *a){ // muestra la lista de izquierda a derecha
  TNodo *aux;
  aux = a;
  if(aux==NULL){
      printf("La lista esta vacia\n");
  } else {
  while(aux!=NULL){
      printf("%d ",aux->info);
      aux=aux->next;
  }
}
}
void main(){
    num.a=NULL;
    generarLSEFic(&num.a);
    agregarElementos(&num.a,&num.cant);
    printf("Lista sin ordenar: ");
    mostrar(num.a->next);
    printf("\n");
    int i = 0;
    int ciclos = 0;
    ult = NULL;
    while(i<num.cant){
        anterior=num.a;
        comp=anterior->next;
        siguiente=comp->next;
             while(siguiente!=ult){
                 int inter = 0;
                if(comp->info>siguiente->info){
                    comp->next=siguiente->next;
                    siguiente->next=comp;
                    anterior->next=siguiente;
                    inter = 1;
                }
                if(inter==1){
                    anterior=siguiente;
                    siguiente=comp->next;
                } else {
                    siguiente = siguiente->next;
                    comp= comp->next;
                    anterior=anterior->next;
                } 
                ciclos++;
             }
             ult = comp;
             i++;
        }
   printf("Cantidad de ciclos realizados: %d\n",ciclos);
   printf("Lista ordenada: ");
   mostrar(num.a->next);
}

