#include <stdio.h>
#define MAX 100
typedef int TElem;
typedef TElem TArreglo;
typedef struct{
    TArreglo a[MAX];
    int cant;
}TData;
TData numeros;
void cargarArreglo(TData *a){
    int i;
    printf("Ingrese la cantidad de elementos del arreglo: \n");
    scanf("%d",&(*a).cant);
    for(i=0;i<(*a).cant;i++){
    printf("Ingrese el elemento %d del arreglo: \n",i);
    scanf("%d", &(*a).a[i]);
  }
}
void agregarElemento (TData *a){
    int i;
    int pe;
    printf("Ingrese el elemento a agregar en el arreglo: \n");
    scanf("%d", &pe);
    i=(*a).cant-1;
    (*a).a[i+1]=pe;
    (*a).cant++;

}
void mostrarArreglo(TData a){
    int i;
    for(i=0;i<a.cant;i++){
        printf("En la posicion %d el arreglo tiene el valor %d \n", i, a.a[i]);
    }
}
void main(){
    cargarArreglo(&numeros);
    agregarElemento(&numeros);
    mostrarArreglo(numeros);
}