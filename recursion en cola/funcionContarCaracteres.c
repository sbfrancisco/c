// contador de caracteres recursividad en cola
#include <stdio.h>
#define Max 254
typedef char TArreglo;
typedef struct {
    TArreglo a[Max];
    int cant;
}TData;
TData reg;
int res;
 void cargarArreglo (TData *list){
  int i;
  list->cant=4;
  for(i=0;i<list->cant;i++){
      printf("Ingrese el caracter a almacenar: \n"); scanf(" %c",&(*list).a[i]);
  }
 }
 int contOcu(TArreglo a[], int cant, char c, int acum){
     if(cant==-1){
         return acum;
     } else {
         if(a[cant]==c){
             return contOcu(a,cant-1,c,acum+1);
         } else {
             return contOcu(a,cant-1,c,acum);
         }
     }
 }
void main(){
    char car;
    cargarArreglo(&reg);
    printf("Ingrese el caracter a analizar\n"); scanf(" %c",&car);
    res = contOcu(reg.a,reg.cant,car,0);
    printf("El caracter %c se repite %d veces\n",car, res);
}
