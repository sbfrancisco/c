#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    char info;
    struct nodo *next;
}TNodo;
TNodo *list;
void cargarLista(TNodo **q){
 TNodo *r; 
 int i,cant;
   printf("Ingrese la cantidad de elementos a almacenar el la secuencia\n"); scanf("%d",&cant);
   for(i=0;i<cant;i++){
   r = (TNodo *) malloc (sizeof(TNodo));
   printf("Ingrese el caracter a almacenar en la lista: \n"); scanf(" %c",&r->info);
   r->next = (*q);
   (*q)=r;
   }
}
void mostrar(TNodo *q){
 TNodo *aux;
   aux = q;
    while(aux!=NULL && aux->info!='x'){ // busqueda del primer caracter 'x'
        aux=aux->next;
    }
      if(aux==NULL){ // en caso de que no haya sido encontrado el caracter 'x' 
        printf("No se encontro el caracter x en la secuencia\n");
      } else {
        aux = aux->next;
        if(aux==NULL){
            printf("El primer caracter x es el ultimo de la lista\n");
      } else {
        printf("Elementos posteriores al caracter 'x': ");
        while(aux!=NULL){
            printf("%c ",aux->info);
            aux=aux->next;
        }
      }
}
}
void main(){
cargarLista(&list);
mostrar(list);
}