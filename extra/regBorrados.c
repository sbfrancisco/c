#include <stdio.h>
#define MAX 250
typedef struct{
  int pos[MAX];
  int cant;
}TData;
typedef struct{
    char nombre[30];
    int edad;
    int borrado;
}TPersona;
TData reg;
FILE* f;
void posRegSup(FILE* f, TData *q){
    int i; TPersona pers;
    i = 0;
    f = fopen("registros.dat","r");
    while(!feof(f)){
    fread(&pers,sizeof(pers),1,f);
    if(!feof(f)){

    if(pers.borrado==1){
        q->pos[i]=ftell(f)-1;
        i++;
    }
    }
    }
    fclose(f);
    q->cant=i;
}
void cargarArchivo(FILE *f){
  TPersona temp;
    f = fopen("registros.dat","a");
    printf("Ingrese el nombre de la persona a almacenar"); scanf("%s",temp.nombre);
    printf("Ingrese la edad de la persona a almacenar"); scanf("%d",&temp.edad);
    printf("Ingrese si esta borrado o no (0/1)"); scanf("%d",&temp.borrado);
    fwrite(&temp,sizeof(temp),1,f);
    fclose(f);
 }
void main(){
    cargarArchivo(f);
    posRegSup(f,&reg);
    printf("%d",reg.cant);
}
