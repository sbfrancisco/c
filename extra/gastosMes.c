#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int gastoMensual;
    int mes;
    int año;
}TMes;
typedef struct nodo{   
    struct nodo* next;
    TMes info;
}TNodo;
TNodo *list;
void crearLista(TNodo **list){
 int cant,i;
  TNodo *r;
  (*list)=NULL;
  printf("Ingrese la cantidad de nodos que quiere crear\n"); scanf("%d",&cant);
  for(i=0;i<cant;i++){
  r = (TNodo *)malloc(sizeof(TNodo));
  printf("Ingrese el gasto del mes: \n"); scanf("%d",&r->info.gastoMensual);
  printf("Ingrese el mes: \n"); scanf("%d",&r->info.mes);
  printf("Ingrese el año: \n"); scanf("%d",&r->info.año);
  r->next = (*list);
  (*list) = r;
  }
}
void gastosMayor(TNodo *list, int *acum){
    if(list!=NULL){
        if(list->info.gastoMensual>60000){
            (*acum)++;
            gastosMayor(list->next,acum);
        } else {
            gastosMayor(list->next,acum);
        }
    }
}
void main(){
    int acum = 0;
    crearLista(&list);
    gastosMayor(list,&acum);
    printf("Se gasto mas de 60.000$ en %d meses",acum);
}