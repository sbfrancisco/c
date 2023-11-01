#include <stdio.h>
char temp,buscado;
int i,d;
FILE* f;
int main(){
 f=fopen("caracteres.txt","r");
    if(f==NULL){
        printf("El archivo no contiene informacion\n");
    } else {
        printf("Ingrese el caracter a analizar en el archivo\n"); scanf("%c",&buscado);
        while(!feof(f)){
        temp = fgetc(f);
        if(!feof(f)){
            if(temp==buscado){
                i++;
            } else {
                d++;
            }
        }
      }
    }
    printf("Hay %d caracteres iguales al buscado, y %d caracteres diferentes a el\n",i,d);
    fclose(f);
  }
  
