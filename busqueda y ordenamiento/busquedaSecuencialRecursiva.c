#include <stdio.h>
#define MAX 100
typedef struct{
    int a[MAX];
    int cant;
}TData;
TData num;
int pos, buscado;
void cargarArreglo(TData *a){
 int i;
  printf("Ingrese la cantidad de elementos a almacenar: \n"); scanf("%d",&(*a).cant);
  for(i=0;i<(*a).cant;i++){
      printf("Ingrese el elemento a añadir en la posicion %d \n",i); scanf("%d",&(*a).a[i]);
  }
}
void busquedaSecuencial(int a[], int cant, int i, int busq, int *pos){
    if(i!=cant){
        if(a[i]==busq){
            (*pos)=i;
        } else {
            busquedaSecuencial(a,cant,i+1,busq,pos);
        }
    } else {
        if(i==cant){
            if(a[i]==busq){
                (*pos)=i;
            } else {
                (*pos)=-1;
            }
        }
        }
    }
void main(){
 cargarArreglo(&num);
 printf("Ingrese el elemento a buscar\n"); scanf("%d",&buscado);
 busquedaSecuencial(num.a,num.cant,0,buscado,&pos);
 printf("El elemento buscado fue encontrado en la posicion %d \n",pos);
}