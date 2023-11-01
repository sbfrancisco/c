#include <stdio.h>
char temp;
int i,cant;
FILE* f;
int main(){
 f=fopen("caracteres.txt","a");
 printf("Ingrese la cantidad de caracteres a almacenar: \n"); scanf("%d",&cant);
  for(i=0;i<cant;i++){
    printf("Ingrese un caracter a almacenar: \n"); scanf(" %c",&temp);
    fputc(temp,f);
  }
  fclose(f);
}
