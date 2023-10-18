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
void bubbleSort(TData *a){ // acomoda el menor primero
 int aux,i,j,cant,inter;
 inter = 0;
 cant=a->cant-1;
  i = cant;
 while(i>0){
     j=0;
     while(j<i){
         if(a->a[j]>a->a[j+1]){
           aux = a->a[j];
           a->a[j] = a->a[j+1];
           a->a[j+1] = aux;
           inter++;
         }
         j++;
 }
 i--;
 }
 printf("Los intercambios que se realizaron fueron %d \n",inter);
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
bubbleSort(&num);
mostrarArreglo(num);
}
