#include <stdio.h>
#define MAX 100
typedef struct{
    int a[MAX];
    int cant;
}TData;
TData num;
int pos, buscado;
void cargarArreglo(TData *a){
 int i;
  printf("Ingrese la cantidad de elementos a almacenar: \n"); scanf("%d",&(*a).cant);
  for(i=0;i<(*a).cant;i++){
      printf("Ingrese el elemento a añadir en la posicion %d \n",i); scanf("%d",&(*a).a[i]);
  }
}
void busquedaBinaria(TData a, int busq, int *pos){
 int sup,inf,k;
 sup = a.cant-1;
  if(busq<a.a[0] || busq>a.a[sup]){
      (*pos)=-1;
  } else {
      inf = 0;
      sup = a.cant;
       while(inf<sup){
           k = ((inf+sup)/2);
           if(busq>a.a[k]){
               inf = k+1;
           } else {
               sup = k;
           }
       }
  }
       if(a.a[k]==busq){
           (*pos)=k;
       } else {
           (*pos)=-1;
       }
}
void main(){
cargarArreglo(&num);
 if(num.cant<0){
  printf("Arreglo vacio\n");
 } else {
     printf("Ingrese el valor buscado: \n"); scanf("%d",&buscado);
     busquedaBinaria(num,buscado,&pos);
    if(pos==-1){
        printf("Elemento no encontrado en el arreglo\n");
    } else {
        printf("La posicion en la que fue encontrado el elemento fue en %d",pos);
    }
 }  
}