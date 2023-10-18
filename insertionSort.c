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
void insertionSort(TData *a){
 int i,j,aux,inter;
 inter=0;
 i = 1;
 while(i<a->cant){
    aux = a->a[i];
    j=i-1;
    while(j>=0 && a->a[j]>aux){
        a->a[j+1]=a->a[j];
        j--;
        inter++;
    }
    a->a[j+1]=aux;
    i++;
 }
 printf("La cantidad de intercambios realizados fueron: %d\n",inter);
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
 insertionSort(&num);
 mostrarArreglo(num);
}
