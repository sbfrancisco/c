#include <stdio.h>
#define MAX 20
typedef struct{
    int a[MAX];
    int cant;
}TData;
TData num;
void cargarArreglo(TData *a){
    int i;
    printf("Ingrese la cantidad de elementos a almacenar: \n"); scanf("%d",&a->cant);
    for(i=0;i<a->cant;i++){
    printf("Ingrese el elemento a almacenar: \n"); scanf("%d",&a->a[i]);
    }
}
void selectionSort(TData *a){
 int i,j,min,aux;
 i=0;
 while(i<a->cant){
     j = i;
     min = i;
     while(j<a->cant){
         if(a->a[j]<a->a[min]){
             min = j;
         }
         j++;
     }
     aux = a->a[i];
     a->a[i]=a->a[min];
     a->a[min]=aux;
     i++;
 }
 printf("La cantidad de intercambios fueron: %d \n",i);
}
void mostrarArreglo(TData a){
 int i;
 printf("Arreglo ordenado: ");
  for(i=0;i<a.cant;i++){
      printf("%d ",a.a[i]);
  }
}
void main(){
cargarArreglo(&num);
selectionSort(&num);
mostrarArreglo(num);
}
