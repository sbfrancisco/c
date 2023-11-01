#include <stdio.h>
#include <string.h>
typedef struct{ char nombre[30]; int edad;}
TPersona;
TPersona temp;
FILE *f;
int main(){
     f=fopen("personas.dat","r+b");
     if(f!=NULL){  
       while(fread(&temp,sizeof(temp),1,f)!=0){
         fseek(f,-sizeof(temp),SEEK_CUR);
         printf("Ingrese la edad a modificar:"); scanf("%d",&temp.edad);
         fwrite(&temp,sizeof(temp),1,f);
       }
     }
     fclose(f);
}
