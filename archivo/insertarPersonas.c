#include <stdio.h> // arch_binario_fwrite_Tpersona_gets_2023.c	
#include <string.h>

typedef struct {
  char nombre[30]; 
  int edad;
} TPersona;
TPersona reg; 
FILE *f;

int main() {
     f=fopen("personas.dat","a");
     printf("ingrese nombre:");
     gets(reg.nombre);
     printf("ingrese edad:");
     scanf("%d",&reg.edad);
     int tt = sizeof(reg);
     printf("%d",tt);
     fwrite(&reg,sizeof(reg),1,f);
     fclose(f);
     getchar();
     return 0;
}