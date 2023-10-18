#include <stdio.h>
#define MAX 50
typedef struct{
    int info[MAX];
    int cant;
}TData;
TData num;
void cargarArreglo(TData *a){
 int i;
  printf("Ingrese la cantidad de elementos a almacenar en el arreglo: \n"); scanf("%d",&a->cant);
  for(i=0;i<a->cant;i++){
    printf("Ingrese el elemento a almacenar en la posicion %d",i); scanf("%d",&a->info[i]);
  }
}
void numerosParesImpares(int a[],int cant, int *cond, int *ciclos){
 if(cant>0 && a[cant]%2==0){
         (*ciclos)=(*ciclos+1);
         numerosParesImpares(a,cant-1,cond,ciclos);
     } else {
         if(cant>0 && a[cant]%2!=0){
         (*cond)=0;
     }
 }
}
void main(){
    cargarArreglo(&num);
    int cond=1;
    int ciclos=0;
    numerosParesImpares(num.info,num.cant-1,&cond,&ciclos);
    printf("%d %d",cond, ciclos);
}