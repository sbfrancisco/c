#include <stdio.h>
#define MAX 200
typedef int TElem;
typedef TElem TNumeros;
typedef struct{
    TNumeros a[MAX];
    int cant;
}TData;
TData misNotas;
int prom;
void cargarNotas(TData *notas){
    int i;
    printf("Ingrese la cantidad de notas a analizar: \n");
    scanf("%d", &(*notas).cant);
    for(i=0;i<((*notas).cant);i++){
    printf("Ingrese la nota %d: \n", i+1);
    scanf("%d", &(*notas).a[i]);
}
}
void calcularPromedio(TData notas, int *promedio){
    int i;
    *promedio = 0;
    i = 0;
    if(i>=notas.cant){
        printf("El arreglo esta vacio \n");
    } else {
        for(i=0;i<notas.cant;i++){
            *promedio = (notas.a[i]+*promedio);
        }
        *promedio = *promedio/notas.cant;
    }
}
void mostrarPromedio (int promedio){
    printf("El promedio obtenido es de %d", promedio);
}
void main(){
    cargarNotas(&misNotas);
    calcularPromedio(misNotas,&prom);
    mostrarPromedio(prom);
}