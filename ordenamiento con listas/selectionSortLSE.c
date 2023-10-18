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
TNodo *pri,*min,*aux;
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
int i;
void main(){
    num.a=NULL;
    generarLSEFic(&num.a);
    agregarElementos(&num.a,&num.cant);
    printf("Lista sin ordenar: ");
    mostrar(num.a->next);
    printf("\n");
    i=0;
    pri=num.a->next;
    while(i<num.cant){
     aux = pri;
     min = pri;
      while(aux!=NULL){
      if(aux->info<min->info){
          min = aux;
      }
      aux=aux->next;
    }
    int temp;
    temp = pri->info;
    pri->info=min->info;
    min->info=temp;
    pri=pri->next;
    i++;
    }
   printf("Lista ordenada: ");
   mostrar(num.a->next);
}
