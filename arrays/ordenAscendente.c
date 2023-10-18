#include <stdio.h>
#define MAX 100
typedef int TElem;
typedef TElem TArreglo;
typedef struct{
    TArreglo a[MAX];
    int cant;
}TData;
TData numeros;
void cargarArreglo(TData *a);
void mantenerOrden (TData *a);
void mostrarArreglo(TData a);
void main(){
    cargarArreglo(&numeros);
    mantenerOrden(&numeros);
    mostrarArreglo(numeros);
}
void cargarArreglo(TData *a){
int i;
    printf("Ingrese la cantidad de elementos del arreglo: \n");
    scanf("%d",&(*a).cant);
    for(i=0;i<(*a).cant;i++){
    printf("Ingrese el elemento %d del arreglo: \n",i);
    scanf("%d", &(*a).a[i]);
  }
}
void mantenerOrden (TData *a){
 int i;
 int elem;
printf("Ingrese el numero a insertar en el arreglo: \n");
scanf("%d", &elem);
    for(i=(*a).cant-1;(*a).a[i]>elem;i--){
    (*a).a[i+1]=(*a).a[i];
 }
  if(i==0){
  (*a).a[i+1]=elem;
 } 
  (*a).a[i+1]=elem;
  (*a).cant++;
}
void mostrarArreglo(TData a){
    int i;
    for(i=0;i<a.cant;i++){
        printf("En la posicion %d el arreglo tiene el valor %d \n", i, a.a[i]);
    }
}