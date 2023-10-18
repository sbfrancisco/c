#include <string.h>
#include <stdio.h>
float t1, t2, t3;
char mensaje[47];
void main (){
    printf("Ingrese el tiempo en el que el primer nadador termino la carrera: \n");
    scanf("%f", &t1);
    printf("Ingrese el tiempo en el que el segundo nadador termino la carrera: \n");
    scanf("%f", &t2);
    printf("Ingrese el tiempo en el que el tercer nadador termino la carrera: \n");
    scanf("%f", &t3);

        if(t1>t2 && t2>t3){
            strcpy(mensaje, "El orden de los nadadores es descendente");
        } else if(t1>t2 && t2==t3){
                strcpy(mensaje, "El orden de los nadadores es descendente");
                } else if(t1>t3 && t3==t2){
                      strcpy(mensaje, "El orden de los nadadores es descendente");
                     } else if(t1<t2 && t2<t3){
                                strcpy(mensaje, "El orden de los nadadores es ascendente");
                            } else if(t1==t2 && t2<t3){
                                        strcpy(mensaje, "El orden de los nadadores es ascendente");
                                    } else if(t1<t3 && t3==t2){
                                                strcpy(mensaje, "El orden de los nadadores es ascendente");
                                            } else if(t1==t2 && t2==t3){
                                                        strcpy(mensaje, "Los nadadores llegaron al mismo tiempo");
                                                    } else if(t1!=t2 && t2!=t3){
                                                                strcpy(mensaje, "Los nadadores llegaron en tiempos desordenados");
                                                    }
    printf("%s", mensaje);
 }
                                            
