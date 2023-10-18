#include <stdio.h>
#define CapacidadDisco 1024
typedef struct{
    int espacioLibre;
    int rpm;
    char fabricante[30];
}TData;
char frase[30];
int byte;
TData disco;
void cargarDatos(TData *d){
    printf("Ingrese el rpm del disco: \n");
    scanf("%d", &(*d).rpm);
    printf("Ingrese el fabricante del disco: \n");
    scanf("%s", (*d).fabricante);
    do{
        printf("Ingrese la cantidad de bytes libre que hay en el disco: \n");
        scanf("%d", &(*d).espacioLibre);
    }while(!((*d).espacioLibre>=0 && (*d).espacioLibre<=CapacidadDisco));
}
void analizarFrase(TData *d, int bytes){
if(bytes<=(*d).espacioLibre){
    (*d).espacioLibre = (*d).espacioLibre - bytes;
    printf("La frase se ha cargado con exito \n");
} else {
    printf("No se ha podido cargar la frase con exito \n ");
}
}
void main(){
    printf("Ingrese la frase que quiera analizar: \n");
    scanf("%s", frase);
    byte = sizeof(frase);
    cargarDatos(&disco);
    analizarFrase(&disco,byte);
}