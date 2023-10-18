// contador de caracteres recursividad en aumento
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
 int contOcu(TArreglo a[], int cant, char c){
     if(cant==-1){
         return 0;
     } else {
         if(a[cant]==c){
             return 1+contOcu(a,cant-1,c);
         } else {
             return contOcu(a,cant-1,c);
         }
     }
 }
void main(){
    char car;
    cargarArreglo(&reg);
    printf("Ingrese el caracter a analizar\n"); scanf(" %c",&car);
    res = contOcu(reg.a,reg.cant,car);
    printf("El caracter %c se repite %d veces\n",car, res);
}
