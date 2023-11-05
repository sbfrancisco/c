#include <stdio.h>
#define MAX 100
typedef struct{
    char elem[MAX];
    int cant;
}TData;
TData reg;
int pos;
void cargarArreglo(TData *q){
 int i;
  printf("Ingrese la cantidad de caracteres a almacenar\n"); scanf("%d",&q->cant);
  for(i=0;i<q->cant;i++){
    printf("Ingrese el caracter a almacenar en la posicion %d:\n",i); scanf(" %c",&q->elem[i]);
  }
}
int encontrarZ(char elem[], int cant, int i){
if(i>cant){
    return -1;
} else {
    if(elem[i]!='z'){
        return encontrarZ(elem,cant,i+1);
    } else {
        return i;
    }
}
}
void main(){
    cargarArreglo(&reg);
    if(reg.cant!=0){
    pos = encontrarZ(reg.elem,reg.cant,0);
    if(pos==-1){
        printf("El caracter z no fue encontrado en la secuencia\n");
    } else {
    printf("El caracter z se encuentra en la posicion %d",pos);
    }
    } else {
        printf("El arreglo a analizar esta vacio\n");
    }
}