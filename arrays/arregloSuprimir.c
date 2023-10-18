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
void suprimirPosicion (TData *a){
    int i;
    int k;
    int pe;
    printf("Ingrese la posicion a sacar del arreglo: \n");
    scanf("%d", &pe);
    k = pe+1;
    for(i=k;i<(*a).cant;i++){
        (*a).a[k-1]=(*a).a[k];
    }
    (*a).cant--;
}
void mostrarArreglo(TData a){
    int i;
    for(i=0;i<a.cant;i++){
        printf("En la posicion %d el arreglo tiene el valor %d \n", i, a.a[i]);
    }
}
void main(){
    cargarArreglo(&numeros);
    suprimirPosicion(&numeros);
    mostrarArreglo(numeros);
}