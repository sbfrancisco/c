#include <stdio.h>
#define MAX 20
typedef struct{
    int s[MAX];
    int cant;
}TData;
TData reg;
int e;
int k,inf,sup,limMax,limInf;
void cargarArreglo(TData *a){
  int i;
    printf("Ingrese la cantidad de elementos a almacenar: \n"); scanf("%d",&a->cant);
    for(i=0;i<a->cant;i++){
        printf("Ingrese el elemento a almacenar: \n"); scanf("%d",&a->s[i]);
    }
}
void main(){
  cargarArreglo(&reg);
  limInf=0;
  limMax=reg.cant-1;
  printf("Ingrese el elemento a buscar: \n"); scanf("%d",&e);
    if(e<reg.s[limInf] || e>reg.s[limMax]){
        printf("Este elemento no pertenece al arreglo \n");
    } else {
      inf = limInf;
      sup = limMax;
      while(inf<sup){
          k = (inf+sup)/2;
          if(e>reg.s[k]){
              inf = k+1;
          } else {
              sup = k;
          }
      }
    }
    if(reg.s[inf]==e){
        printf("El elemento esta en la posicion %d \n",inf);
    } else {
        printf("El elemento no se encuentra en el registro\n");
    }
}