#include <stdio.h> // arch_binario_fwrite_Tpersona_gets_2023.c	
#include <string.h>

typedef struct {
  char nombre[30]; 
  int edad;
} TPersona;
TPersona reg; 
FILE *f;

int main() {
     f=fopen("personas.dat","r");
     if(f!=NULL){
     while(fread(&reg,sizeof(reg),1,f)!=0){
     printf("%s",reg.nombre);
     printf("%d",reg.edad); 
      }
     }
     fclose(f);
}