#include <stdio.h>
#define MAX 20
typedef struct{
    int s[MAX];
    int cant;
}TData;
TData reg;
int e;
int k,inf,sup,limMax,limInf;
int res;
int busqueda(int inf, int sup, int a[],int k){
    if(inf>=sup){
        if(a[inf]==e){
            return 1;
        } else {
            return 0;
        }
    } else {
      if(inf<sup){
          k = (inf+sup)/2;
          if(e>a[k]){
              inf = k+1;
          } else {
              sup = k;
          }
      }
      busqueda(inf,sup,a,k);
    }
}
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
    res =  busqueda(inf,sup,reg.s,0);
    printf("%d",res);
}
}