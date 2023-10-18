#include <stdio.h>
#include <string.h>
int penVuel, ultVuel;
int res;
char mensaje[30];
int condAtleta(int vuelta1, int vuelta2);
void main(){
    printf("Ingrese el tiempo de la penultima vuelta \n");
    scanf("%d", &penVuel);
    printf("Ingrese el tiempo de la ultima vuelta \n");
    scanf("%d", &ultVuel);
    res = condAtleta(penVuel,ultVuel);
    if(res==1){
        strcpy(mensaje,"Mantuvo los tiempos iguales");
    }else{
        if(res==2){
            strcpy(mensaje,"Bajo su tiempo");
        }else{
            if(res==3){
                strcpy(mensaje,"Incremento su tiempo");
            }
        }
    }
    printf("%s \n", mensaje);
    }
int condAtleta(int vuelta1, int vuelta2){
    if(vuelta1==vuelta2){
        return 1;
    }else{
        if(vuelta1>vuelta2){
            return 2;
        }else{
            if(vuelta1<vuelta2){
                return 3;
            }
        }
    }
}