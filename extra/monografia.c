#include <stdio.h>
char a,temp;
int cantCar;
FILE *f;
void cargarArchivo(FILE* f){
  int i,cant;
  char temp;
  f = fopen("monografia.txt","a");
  printf("Ingrese los caracteres a almacenar en el archivo: \n"); scanf("%d",&cant);
  for(i=0;i<cant;i++){
    scanf(" %c",&temp);
    fputc(temp,f);
  }
  fclose(f);
}
void main(){
 cargarArchivo(f);
 f = fopen("monografia.txt","r");
 if(f!=NULL){
    cantCar=0;
    printf("Ingrese el caracter a analizar cuantas veces esta repetido: \n"); scanf(" %c",&a);
    while(!feof(f)){
    temp = fgetc(f);
     if(!feof(f)){
        if(a==temp){
            cantCar++;
        }
     }
    }
    printf("El caracter %c se repite %d veces\n",a,cantCar);
 } else {
    printf("El archivo esta vacio\n");
 }
 fclose(f);
}