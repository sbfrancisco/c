#include <string.h>
#include <stdio.h>
float nota, promedio, n, i;
char mensaje[50];
void main(){
    printf("Ingrese la cantidad de alumnos a analizar: \n");
    scanf("%f", &n);
    promedio = 0; // inicializacion del contador de notas
    
    for(i=1; i<=n; i++){
        printf("Ingrese la nota del alumno %2.f: \n", i);
        scanf("%f", &nota);
        promedio = promedio + nota; // sumamos las notas de todos los alumnos
    }
    promedio  = promedio / n; // para hacer un promedio dividimos las notas que tenemos por los alumnos que rindieron
    if(promedio>8){
        strcpy(mensaje, "El promedio es elevado");
    } else if(promedio>=6 && promedio<=8){
                strcpy(mensaje, "El promedio es medio");
            } else if(promedio<6){
                        strcpy(mensaje, "El promedio es bajo");
            }
    printf("%s", mensaje);
}
