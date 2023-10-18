// Francisco Natale
#include <stdio.h>
#include <stdbool.h>
#define NMax 20
#define MMax 20
typedef int TElem;
typedef TElem TArreglo;
typedef struct{
    int cantN, cantM;
    TArreglo k[NMax][MMax];
}TData;
TData matriz;
bool repet;
void cargarMatriz(TData *a){
  int i,j;
  printf("Ingrese la cantidad de filas de la matriz: \n");
  scanf("%d", &(*a).cantN);
  printf("Ingrese la cantidad de columnas de la matriz: \n");
  scanf("%d", &(*a).cantM);
  for(i=0;i<(*a).cantN;i++){
    for(j=0;j<(*a).cantM;j++){
        printf("Ingrese el elemento de la matriz en la fila %d, columna %d: \n", i+1, j+1);
        scanf("%d", &(*a).k[i][j]);
    }
  }
}
void elementoRepetido(TData a, bool *repet){
  int i,j,num,rep;
  *repet=false;
  rep=0;
  printf("Ingrese el numero a analizar si esta repetido\n");
  scanf("%d", &num);
   for(i=0;i<a.cantN;i++){
    for(j=0;j<a.cantM;j++){
        if(num==a.k[i][j]){
          rep++;
        }
    if(rep>3){
        *repet=true;
    }
    }
   }
}
void main(){
    cargarMatriz(&matriz);
    elementoRepetido(matriz,&repet);
    if(repet){
        printf("El elemento se repite mas de 3 veces en la matriz \n");
    } else {
        printf("El elemento no se repite mas de 3 veces en la matriz \n");
    }
}