#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct{char titulo[30]; char autor[30]; int ISBN;
}TLibro;
typedef struct nodo{ TLibro info; struct nodo *next;
}TNodo;
TNodo *list;
typedef struct{TLibro a[MAX]; int cant; int ultPos;
}TLib; 
TLib reg;
char nom[30];
void crearLista(TNodo **list){
 int cant,i;
  TNodo *r;
  (*list)=NULL;
  printf("Ingrese la cantidad de nodos que quiere crear\n"); scanf("%d",&cant);
  for(i=0;i<cant;i++){
  r = (TNodo *)malloc(sizeof(TNodo));
  printf("Ingrese el titulo del libro: \n"); scanf("%s",r->info.titulo);
  printf("Ingrese el autor que lo realizo: \n"); scanf("%s",r->info.autor);
  printf("Ingrese el ISBN: \n"); scanf("%d",&r->info.ISBN);
  r->next = (*list);
  (*list) = r;
  }
}
void titulosIguales(char nom[30],TNodo *aux,TLib *reg){
  int pos;
    if(aux==NULL){
        printf("La lista esta vacia\n");
    } else {
        pos = 0;
        while(aux!=NULL && (strcmp(nom,aux->info.titulo)!=0)){
            pos++;
            aux = aux->next;
        }
        if(aux!=NULL){
            reg->cant=0;
            while(aux!=NULL && (strcmp(nom,aux->info.titulo)==0)){
                reg->a[reg->cant]=aux->info;
                pos++;
                reg->cant++;
                aux = aux->next;
            }
            reg->ultPos = pos;
        } else {
            printf("El libro no se encontro \n");
        }
    }
}
void main(){
    crearLista(&list);
    printf("Ingrese el titulo a analizar\n"); scanf("%s",nom);
    titulosIguales(nom,list,&reg);
    printf("La ultima posicion de la lista en donde se encontro un libro fue en %d \n",reg.ultPos);
    printf("Se encontraron %d libros iguales\n",reg.cant);
    for(int i=0;i<reg.cant;i++){
        printf("Libro: \n");
        printf("Titulo: %s\n",reg.a[i].titulo);
        printf("Autor:%s\n",reg.a[i].autor);
        printf("ISBN:%d\n",reg.a[i].ISBN);
    }
}