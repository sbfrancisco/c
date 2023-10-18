// sumatoria con accion recursiva en cola
#include <stdio.h>
#define MAX 20
typedef struct{
    int a[MAX];
    int cant;
}TData;
TData reg;
void cargarArreglo(TData *a){
    int i;
    printf("Ingrese la cantidad de elementos a almacenar: \n"); scanf("%d",&a->cant);
    for(i=0;i<a->cant;i++){
    printf("Ingrese el elemento a almacenar: \n"); scanf("%d",&a->a[i]);
    }
}
void sumatoria(int a[], int cant, int *suma){
  if(cant!=-1){
      (*suma)=(*suma)+a[cant];
      sumatoria(a,cant-1,suma);
  }
}
int res;
void main(){
cargarArreglo(&reg);
sumatoria(reg.a,reg.cant,&res);
printf("%d", res);
}